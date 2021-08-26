#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

// uncomment for window systems
//#include <window.h>
#include <cstdlib>
#include <iostream>
#include <vector>

class MusicPlayer {
 private:
  std::string DEFAULT_AUDIO_ENGINE = "mplayer";
  std::string DEFAULT_AUDIO_PATH = std::getenv("HOME");
  std::string current_track;
  std::vector<std::string> tracklist;
  void setDefaultAudio();

 public:
  std::string engine;
  std::string audio_path;
  int total_tracks;
  void initMessage();
  void stopTrack();
  void displayTracks();
  void setTracks(std::string path);
  void playTrack(unsigned int track_index);
  void init(std::string engine, std::string audo_path);

  MusicPlayer();
  MusicPlayer(std::string engine, std::string audo_path);
};
#endif
