/*
 * @brief Simple console Audio player.
 * @author Cornelius Brooks
 * @date Aug 23, 2021
 * @requires c++17
 */
#include <iostream>
#include <exception>
#include <vector>

using namespace std;
string ltrim(const string &s);
string rtrim(const string &s);
string trim(const string &s);
string lowerCase(const string str);
bool isNumber(const string str);

#include "../include/musicplayer.h"


void Run( string audio_engine, string audio_path){
  // Initialized MusicPlayer class 
  MusicPlayer musicplayer(audio_path,audio_engine);
  musicplayer.displayTracks();

  if (musicplayer.total_tracks == 0 ){
    cout << "No Track(s) Available..." << endl;
    exit(0);
  }

  do{
    // Print Menu 
    cout 
      << "\n*** Enter track number ***\n\tQ or q to Quit \n"
      << "\tList songs: l"
      << "\n" 
      << endl;

    // Get and parse  user input
    string user_input;
    getline(cin, user_input);

    user_input = trim(lowerCase(user_input));
		if(user_input == ""){
			continue;
		}

    else if (user_input == "quit" || user_input == "q"){ // Quit program
      cout
        << "Quitting..." 
        << endl;
      exit(0);
    }else if (user_input == "l"){ // Display track
      musicplayer.displayTracks();
      continue;
    }else if (isNumber(user_input) && stoi(user_input) > musicplayer.total_tracks ){
      cout << "Track out of range..." << endl;
      continue;
    }

    try{
      musicplayer.playTrack(stoi(user_input));
    }catch(exception& e){
      cout << "Invalid option... Please try again." << endl;
    }

  }
  while(musicplayer.total_tracks > 0 );
}


int main(int argc, char *argv[])
{
  // Set Audio engine and Audio source path 
  string audio_engine, audio_path;

  /* Set Audio engine and Audio source path */ 
  try{
    audio_engine = argc > 0 ? argv[1] : MusicPlayer::DEFAULT_AUDIO_ENGINE;
    audio_path = argc > 1  ? argv[2] : MusicPlayer::DEFAULT_AUDIO_PATH;
  }catch(exception& e) {
    audio_engine = MusicPlayer::DEFAULT_AUDIO_ENGINE;
    audio_path = MusicPlayer::DEFAULT_AUDIO_PATH; 
  }
  cout << "Engine: " << audio_engine << " Source: " << audio_path << endl;

  // Start Music Player 
  Run(audio_engine,audio_path);

  return 0;
}
