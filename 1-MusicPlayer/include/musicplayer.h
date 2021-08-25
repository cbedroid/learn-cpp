#ifndef MUSIC_PLAYER_H 
#define MUSIC_PLAYER_H

// uncomment for window systems
//#include <window.h>
#include <iostream>
#include <vector>

class MusicPlayer{
  private:
    std::vector <std::string> tracklist;
    std::string current_track;
    std::string player;
    void setDefault();
    
  public:
    static std::string DEFAULT_AUDIO_ENGINE;
    static std::string DEFAULT_AUDIO_PATH;
    unsigned int total_tracks; 
    void setTracks(std::string path);
    void playTrack(unsigned int track_index);
    void stopTrack();
    void displayTracks();
    MusicPlayer();
    MusicPlayer(std::string music_path, std::string player);

};
#endif
