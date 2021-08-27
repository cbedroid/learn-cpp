#include <iostream>
using namespace std;

struct User {
  // Declared public by default
  std::string firstname;
  std::string lastname;
};

class User_2 {
  // Declared private by default
  // Must explicity  make member public
 public:
  std::string firstname;
  std::string lastname;
  std::string full_name();
};

std::string User_2::full_name() { return firstname + " " + lastname; }

int main() {
  // struct
  User user;
  user.firstname = "John";
  user.lastname = "Doe";

  std::cout << "Example - Struct\n" << std::endl;
  std::cout << "firstname: " << user.firstname 
            << " lastname: " << user.lastname
            << std::endl;

  // Class
  User_2 user2;
  user2.firstname = "Jane";
  user2.lastname = "Doe";

  std::cout << "\n\nExample - Class\n" << std::endl;
  std::cout << "firstname: " << user2.firstname
            << " lastname: " << user2.lastname 
            << std::endl;

  std::cout << "Fullname: " << user2.full_name() << std::endl;

  return 0;
}
