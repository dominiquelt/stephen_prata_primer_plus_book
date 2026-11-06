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

namespace ex3 {
void ConcatenationCString() {
  const int ArrSize = 20;
  char FirstName[ArrSize];
  char LastName[ArrSize];
  char FullName[ArrSize * 2 + 2];

  std::cout << "Enter your first name:" << std::endl;
  std::cin.getline(FirstName, ArrSize);
  std::cout << "Enter your last name:" << std::endl;
  std::cin.getline(LastName, ArrSize);
  std::strcpy(FullName, LastName);
  std::strcat(FullName, ", ");
  std::strcat(FullName, FirstName);
  std::cout << "Here’s the information in a single string: " << FullName
            << std::endl;
}
}  // namespace ex3

namespace ex4 {
void ConcatenationString() {
  std::string FirstName;
  std::string LastName;
  std::string FullName;

  std::cout << "Enter your first name:" << std::endl;
  std::getline(std::cin, FirstName);
  std::cout << "Enter your last name:" << std::endl;
  std::getline(std::cin, LastName);
  FullName = LastName + ", " + FirstName;
  std::cout << "Here’s the information in a single string: " << FullName
            << std::endl;
}
}  // namespace ex4
