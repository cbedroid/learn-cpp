// uncomment for window systems
//#include <window.h>

#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYER_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "../include/musicplayer.h"
#include <cstdlib>

namespace fs = std::filesystem;
using namespace std;

std::string MusicPlayer::DEFAULT_AUDIO_ENGINE = "mplayer";
std::string MusicPlayer::DEFAULT_AUDIO_PATH = getenv("HOME");

void MusicPlayer::setTracks(std::string path){
  /* Collect audio tracks */
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
  //TODO: Catch error when track out of range 
  this-> current_track = tracklist[track_index-1];
  std::string cmd = this-> player + " " + this->current_track;
  system(cmd.c_str());
}

void MusicPlayer::stopTrack(){
  std::string kill_cmd = std::string("pkill -9") + std::string(player);
  system(kill_cmd.c_str());
}

MusicPlayer::MusicPlayer(std::string music_path, std::string player){
  this-> setTracks(music_path);
  this-> player = player != "" ? player : this-> DEFAULT_AUDIO_ENGINE;
}

MusicPlayer::MusicPlayer(){
  // Set default audio engine and audio source path
  this-> player = this-> DEFAULT_AUDIO_ENGINE;
  this-> setTracks(this-> DEFAULT_AUDIO_PATH);
  std::cout << "Music player initialized" << std::endl;

}
#endif
