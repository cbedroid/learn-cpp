/*
 * @brief Simple console audio player.
 * @author Cornelius Brooks
 * @date Aug 23, 2021
 * @requires c++17
 */
#include <exception>
#include <iostream>
#include <vector>

#include "../include/helper.h"
#include "../include/musicplayer.h"

using namespace std;

void Run(MusicPlayer musicplayer) {
  // Initialized MusicPlayer class
  musicplayer.displayTracks();

  if (musicplayer.total_tracks == 0) {
    cout << "No Track(s) Available..." << endl;
    exit(0);
  }

  do {
    // Print Menu
    cout << "\n*** Enter track number ***\n\tQ or q to Quit \n"
         << "\tList songs: l"
         << "\n"
         << endl;

    // Get and parse  user input
    string user_input;
    getline(cin, user_input);

    user_input = trim(lowerCase(user_input));
    if (user_input == "") {
      continue;

    } else if (user_input == "quit" || user_input == "q") {
      // Quit program
      cout << "Quitting..." << endl;
      exit(0);

    } else if (user_input == "l") {
      // Display track to screen
      musicplayer.displayTracks();
      continue;

    } else if (isNumber(user_input) &&
               stoi(user_input) > musicplayer.total_tracks) {
      cout << "Track out of range..." << endl;
      continue;
    }

    try {
      musicplayer.playTrack(stoi(user_input));
    } catch (exception& e) {
      cout << "Invalid option... Please try again." << endl;
    }
  } while (musicplayer.total_tracks > 0);
}

int main(int argc, char* argv[]) {
  // Set Audio engine and Audio source path
  string audio_engine, audio_path;

  /* Set Audio engine and Audio source path */
  audio_engine = argc > 1 ? argv[1] : "";
  audio_path = argc > 2 ? argv[2] : "";

  // Start Music Player
  MusicPlayer musicplayer(audio_engine, audio_path);
  Run(musicplayer);
  return 0;
}
