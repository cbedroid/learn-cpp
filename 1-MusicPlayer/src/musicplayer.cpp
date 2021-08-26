// uncomment for window systems
//#include <window.h>

#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYER_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "../include/helper.h"
#include "../include/musicplayer.h"

namespace fs = std::filesystem;
using namespace std;


void MusicPlayer::setTracks(std::string path=""){
  /* Collect audio tracks */

  path = path != "" ? path : this -> DEFAULT_AUDIO_PATH;
  std::vector <std::string> audio_exts = {".ogg",".mp3",".m4a",".wav",".wma"};
  for (const auto & entry : fs::recursive_directory_iterator(path)){
    fs::path file = entry.path();
    std::string f_ext = file.extension();
    if (std::find(audio_exts.begin(),audio_exts.end(),f_ext) != audio_exts.end()) {
      this->tracklist.push_back(file);
    }

  }
  this-> total_tracks  = this-> tracklist.size();
}

void MusicPlayer::displayTracks(){
  /* 
   * Iterates and print track's filename to std::cout
   */
  unsigned int counter = 1; 
  // foreach loop
  for (fs::path n: tracklist){
    std::cout 
      << "(" << counter++ << "). "
      << n.filename().c_str() 
      << std::endl;
  }
}

void MusicPlayer::playTrack(unsigned int track_index){
  const std::string DEVNULL_POSTFIX = " > /dev/null 2>&1";

  // Set the current path and filename
  fs::path track  = (tracklist[track_index-1]);
  this-> current_track = track.filename().c_str();

  // Play track
  std::string cmd = this-> engine + " " + track.c_str() + DEVNULL_POSTFIX;
  std::cout << "Now playing: " << current_track << std::endl;
  system(cmd.c_str());
}

void MusicPlayer::init(std::string engine="", std::string music_path="."){
  this-> engine = engine != "" ? engine : DEFAULT_AUDIO_ENGINE;
  if(music_path == "") music_path = ".";
  this-> audio_path = music_path != "." ? music_path : DEFAULT_AUDIO_PATH;

  // Check if audio path is a valid directory
  if (dirExists(music_path)) this-> setTracks(music_path);
  else{
    std::cout 
      << "Directory: " << fs::path(music_path).relative_path()
      << " does not exists!"
      << "\nSetting default path: "
      << this-> DEFAULT_AUDIO_PATH
      << std::endl;
  }
}

void MusicPlayer::initMessage(){
  std::cout << "MusicPlayer initialized" << std::endl;
  std::cout 
    << "Engine: "
    << engine
    << " Source: "
    << fs::path(audio_path).relative_path()
    << "\n" << std::endl;
}


void MusicPlayer::setAudioDefault(){
  this-> engine = DEFAULT_AUDIO_ENGINE;
  this-> audio_path = DEFAULT_AUDIO_PATH;
}

void MusicPlayer::stopTrack(){
  std::string kill_cmd = std::string("pkill -9") + std::string(engine);
  system(kill_cmd.c_str());
}

MusicPlayer::MusicPlayer(std::string engine, std::string music_path="."){
  this-> init(engine,music_path);
  initMessage();
}

MusicPlayer::MusicPlayer(){
  // Set default audio engine and audio source path
  this-> setAudioDefault();
  initMessage();
}
#endif
