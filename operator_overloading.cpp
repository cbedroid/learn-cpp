#include <exception>
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

  bool operator==(Position_2 pos) { 
    return ((x == pos.x) && (y == pos.y)); 
  }
};

void Example_1(Position pos1, Position pos2 ){
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
  std::cout << "\n\nExample 1 - pos1 +  pos2 without Operator Overloading"
            << std::endl;
  std::cout << "\tx + x =  overload error" << std::endl;
  std::cout << "\ty + y =  overload error" << std::endl;
  std::cout << "\n\tx + y = " << pos1.x + pos1.y << std::endl;
  std::cout << "\t" << pos1.x << " + " << pos1.y << " = " << pos1.x + pos1.y
            << std::endl;
  }


void Example_2(Position_2 pos1, Position_2 pos2 ){
  Position_2 new_pos = pos1 + pos2;

  // Correct way: overload Position operator

  /*  What does this operation means and how does it work?
     pos1.x + pos2.x = 8
     pos1.x + pos1.y = 4
     It does NOT mean: pos1.x + pos1.y, because pos1 and pos2 have both x and y
     values
   */

  std::cout << "\n\nExample 2 - pos1 + pos2 with Operator Overloading"
            << std::endl;
  std::cout << "\tx + x = " << new_pos.x << std::endl;
  std::cout << "\t" << pos1.x << " + " << pos2.x << " = " << new_pos.x
            << std::endl;


  std::cout << "\n\ty + y = " << new_pos.y << std::endl;
  std::cout << "\t" << pos1.y << " + " << pos2.y << " = " << new_pos.y
            << std::endl;
};

void Example_3(Position pos1, Position pos2 ){
  std::cout << "\n\nExample 3 - pos1 == pos2 with Operator Overload"
            << std::endl;
  std::cout << "\tif (pos1 == pos2){ <--  This will throw an Operator== "
               "error\n\t do something...\n\t} "
            << std::endl;

  /* uncomment to test
  if (pos1 == pos2) { // This will throw an operator == error
    std::cout << "Positon 1 and Position 2 are the same" << std::endl;
  }
  */
}

void Example_4(Position_2 pos1, Position_2 pos2 ){
  std::cout << "\n\nExample 4 - pos1 == pos2 with Operator Overload"
            << std::endl;
  if (pos1 == pos2) {
    std::cout << "\tPositon 3 and Position 4 are the same" << std::endl;
  }
}

int main() {

  Position pos1, pos2;
  Position_2 pos3, pos4;

  Example_1(pos1 ,pos2);
  Example_2(pos3 ,pos4);

  Example_3(pos1 ,pos2);
  Example_4(pos3 ,pos4);

  return 0;
}
