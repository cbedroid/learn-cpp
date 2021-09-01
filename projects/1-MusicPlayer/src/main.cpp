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

void show_usage(string name) {
  std::cerr << "Usage: " << name << " <option(s)> SOURCES "
            << "Options:\n"
            << "\t-h,--help\t\tShow this help message\n"
            << "\t-e, --engine Audio\tSpecify the audio player to use.\n"
            << "\t-p,--path Audio Path\tSpecify the audio path\n"
            << std::endl;
}
int main(int argc, char* argv[]) {
  // Set Audio engine and Audio source path
  string audio_engine, audio_path;

  if (argc < 3) {
    show_usage(argv[0]);
    return 1;
  }

  vector<string> sources;
  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      show_usage(argv[0]);
      return 0;
    } else if ((arg == "-e") || (arg == "--engine") || (arg == "--player")) {
      if (i < argc) {                // Make sure we aren't at the end of argv!
        audio_engine = argv[i + 1];  // Increment 'i' so we don't get the
                                     // argument as the next argv[i].
      }
    } else if ((arg == "-p") || (arg == "--path")) {
      if (i + 1 < argc) {          // Make sure we aren't at the end of argv!
        audio_path = argv[i + 1];  // Increment 'i' so we don't get the argument
                                   // as the next argv[i].

      } else {  // Uh-oh, there was no argument to the audio_path option.
        cerr << "--path option requires one argument." << std::endl;
        return 1;
      }
    } else {
      sources.push_back(argv[i]);
    }
  }

  // Start Music Player
  MusicPlayer musicplayer(audio_engine, audio_path);
  Run(musicplayer);
  return 0;
}
