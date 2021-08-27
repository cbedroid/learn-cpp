#include <iostream>
using namespace std;


class User {
  // Declared private by default
  // Must explicity  make member public
 public:
  std::string firstname;
  std::string lastname;
  std::string full_name();
};

std::string User::full_name() { return firstname + " " + lastname; }

std::ostream& operator<< (std::ostream& output ,User user){
    output << "\nFullname from overloaded ostream: " << user.full_name();
    return output;
  
  }

int main() {
  User user;
  user.firstname = "Jane";
  user.lastname = "Doe";
  std::cout << "Fullname: " << user.full_name() << std::endl;

  // overloading ostream insertion method
  std::cout << user << std::endl;

  return 0;
}
