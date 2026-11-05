#include <iostream>
#include <string>

#include "dec.h"
namespace ex1 {

void StudentRecord() {
  std::string FirstName;
  std::string LastName;
  char grade;
  int age;
  std::cout << "What is your first name?" << std::endl;
  std::getline(std::cin, FirstName);
  std::cout << "What is your last name?" << std::endl;
  std::getline(std::cin, LastName);
  std::cout << "What letter grade do you deserve?" << std::endl;
  std::cin >> grade;
  std::cout << "What is your age?" << std::endl;
  std::cin >> age;

  grade = grade + 1;
  std::cout << "Name: " << LastName << ", " << FirstName << std::endl;
  std::cout << "Grade: " << grade << std::endl;
  std::cout << "Age: " << age << std::endl;
}
}  // namespace ex1

namespace ex2 {
void RewritingCharToString() {
  std::string name;
  std::string dessert;

  std::cout << "Enter your name:\n";
  std::getline(std::cin, name);

  std::cout << "Enter your favorite dessert:\n";
  std::getline(std::cin, dessert);

  std::cout << "I have some delicious " << dessert;
  std::cout << " for you, " << name << ".\n";
}
}  // namespace ex2
