#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "student.h"
#include "subject.h"


int main(int argc, char *argv[]) { // <------ main :3 
  Student stud1("19390185", "Αικατερίνη Παπαχριστοδούλου", 8);
  Student stud2("17380003", "Ιάσων Χαραλαμπίδης");
  Student stud3("18390045", "Βασιλίου Γεώργιος", 5);
  Student stud4 = stud3;

  Subject* cpp = new Subject(std::string("ICE-2000"), std::string("Object Oriented Programming"), 6, 1);
  Subject* c = new Subject(std::string("ICE-2001"), std::string("Computer Programming"), 5,  0);
  Subject* mips = new Subject(std::string("ICE-2002"), std::string("Computer Architecture"), 5,  0);
  Subject*  advanced_mips = new Subject(std::string("ICE-2003"), std::string("Advanced Computer Architecture"), 5,  1);
  
  //Print the students 
  std::cout << "<============================STUDENTS=======================================>" << '\n';
  std::cout << stud1 << '\n' << stud2 << '\n' << stud3 << '\n';
  std::cout << "<============================SUBJECTS=======================================>" << '\n';
  std::cout << *cpp << '\n' << *c << '\n' << *mips << '\n' << *advanced_mips << '\n';

  std::cout << "Changing student3's AM, semester and name" << '\n';
  stud3.setAM("19390127");
  stud3.setName("Παπαδέα Ευαγγελία");
  stud3.setSemester(10);
  stud3 += cpp;
  
  std::cout << stud3 << '\n';





  stud1.writestd2file("meow1.txt");
  stud2.writestd2file("meow2.txt");
  stud3.writestd2file("meow3.txt");
  //continue showcasing more fuctionalities
  return 0; 
}
