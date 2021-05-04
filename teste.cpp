// #include <iostream>
// #include <string>
// #include <sstream>

// using namespace std;

// struct Student {
//     std::string name;
//     int age;
//     double finalGrade;

//     std::string toString() const;
// };

// ostream& operator << (ostream &os, const Student &s) {
//     return (os << "Name: " << s.name << "\n Age: " << s.age << "\n Final Grade: " << s.finalGrade  << std::endl);
// }

// std::string Student::toString() const {
//     stringstream ss;
//     ss << (*this);
//     return ss.str();
// }

// int main() {

//     Student stud { "john baker", 25, 1.2 };
//     std::cout << "stud directly: " << stud << endl;
//     std::string studStr = stud.toString();
//     std::cout << "stud toString:" << studStr << endl;
// }

// imbue example
#include <iostream>     // std::cout
#include <locale>       // std::locale

int main()
{
  std::locale mylocale("");   // get global locale
  std::cout.imbue(mylocale);  // imbue global locale
  std::cout << 3.14159 << '\n';
  return 0;
}