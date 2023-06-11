#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "student.h"
#include "subject.h"


int main(int argc, char *argv[]) { 
  Student stud1("19390185", "Αικατερίνη Παπαχριστοδούλου", 8);
  Student stud2("17380003", "Ιάσων Χαραλαμπίδης");
  Student stud3("18390045", "Βασιλίου Γεώργιος", 5);
  Student stud4 = stud3;

  Subject* cpp = new Subject(std::string("ICE-2000"), std::string("Αντικειμενοστραφής προγραμματισμός"), 6, 1);
  Subject* c = new Subject(std::string("ICE-2001"), std::string("Προγραμματισμός Υπολογιστών"), 5,  0);
  Subject* mips = new Subject(std::string("ICE-2002"), std::string("Αρχιτεκτονική Υπολογιστών"), 5,  0);
  Subject*  advanced_mips = new Subject(std::string("ICE-2003"), std::string("Προηγμένη αρχιτεκτονική υπολογστων"), 5,  1);
  
  //Print the students 
  std::cout << "<============================ΦΟΙΤΗΤΕΣ=======================================>" << '\n';
  std::cout << stud1 << '\n' << stud2 << '\n' << stud3 << '\n';
  std::cout << "<============================ΜΑΘΗΜΑΤΑ=======================================>" << '\n';
  std::cout << *cpp << '\n' << *c << '\n' << *mips << '\n' << *advanced_mips << '\n';

  std::cout << "Operator++ με πρώτο και δεύτερο φοιτητή " << '\n';
  stud1++;
  std::cout << stud1;
  std::cout << "Operator+= με πρώτο και δεύτερο φοιτητή" << '\n';
  stud1 += stud2;
  std::cout << stud1;
  std::cout << "Operator-= με τρίτο και δεύτερο φοιτητή" << '\n';
  stud3 -= stud2;
  std::cout << stud3;

  std::cout << "Αλλάζω το AM, όνομα και εξάμηνο του τρίτου φοιτητή" << '\n';
  stud3.setAM("19390127");
  stud3.setName("Παπαδέα Ευαγγελία");
  stud3.setSemester(10);
  stud3 += cpp;
  stud3 += c;
  stud3.add_Passed_Subject(std::make_pair(cpp, 9.5));
  stud3.add_Passed_Subject(std::make_pair(c, 5.5));

  stud3.getAverage();
  
  std::cout << stud3 << '\n';

  stud1.writestd2file("stud1.txt");
  stud2.writestd2file("stud2.txt");
  stud3.writestd2file("stud3.txt");
  //continue showcasing more fuctionalities
  return 0; 
}
