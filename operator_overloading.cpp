#include <iostream>
using namespace std;

struct Position {
  int x = 5;
  int y = 3;
};

struct Position_2 {
  int x = 4;
  int y = 2;

  Position_2 operator+(Position_2 pos) {
    Position_2 new_pos;
    new_pos.x = x + pos.x;
    new_pos.y = y + pos.y;
    return new_pos;
  }
};

int main() {
  Position pos1, pos2;
  /*
   Position new_pos = x + y;
    This will throw an error, because the operator does not know how to add
   together object types "struct".

   You should get a compile error message like this:
   Position. operator_overload.cpp:10:18: error: no match for ‘operator+’
   operand types are ‘Position’ and ‘Position’)
  */

  /*
   * "Although we can not add together two or more struct object,
   * We still can add together its members, "pos1.x and pos1.y" .
   * This is because we are going inside the struct; and adding together the
   * struct values instead of the struct itself..
   * so operation int pos1.x + int pos1.y is a valid operation.
   */
  std::cout << "\n\nExample 1 - pos1 and pos2" << std::endl;
  std::cout << "\tx + x =  overload error" << std::endl;
  std::cout << "\ty + y =  overload error" << std::endl;
  std::cout << "\n\tx + y = " << pos1.x + pos1.y << std::endl;
  std::cout << "\t" << pos1.x << " + " << pos1.y << " = " 
            << pos1.x + pos1.y
            << std::endl;

  // Correct way: overload Position operator
  Position_2 pos3, pos4;
  Position_2 new_pos = pos3 + pos4;

  /*  What does this operation means and how does it work?
     pos3.x + pos4.x = 8
     pos3.x + pos3.y = 4
     It does NOT mean: pos3.x + pos3.y, because pos3 and pos4 have both x and y
     values
   */

  std::cout << "\n\nExample 2 - pos3 pos4 with Operator Overload" << std::endl;
  std::cout << "\tx + x = " << new_pos.x << std::endl;
  std::cout << "\t" << pos3.x << " + " << pos4.x << " = " << new_pos.x
            << std::endl;

  std::cout << "\n\ty + y = " << new_pos.y << std::endl;
  std::cout << "\t" << pos3.y << " + " << pos4.y << " = " << new_pos.y
            << std::endl;

  return 0;
}
