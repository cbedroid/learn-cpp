// uncomment for window systems
#ifndef HELPER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define HELPER_H

#include <cctype>
#include <algorithm>
#include <filesystem>
#include <locale>

namespace fs = std::filesystem;
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";


string ltrim(const string &s)
{
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
  return rtrim(ltrim(s));
}

string lowerCase(const string str){
  string temp_str; 
  for (char const c : str) {
    temp_str.push_back(tolower(c));
  }
  return temp_str;
}

bool isNumber(const string str)
{
  for (char const c : str) {
    if (isdigit(c) == 0) return false;
  }
  return true;
}

bool dirExists(const string path){
  fs::directory_entry dir(path);
  if (dir.is_directory()) return true;
    return false;
}

#endif
