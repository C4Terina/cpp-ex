#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "student.h"
#include "subject.h"

std::ostream& operator << (std::ostream &obj, const Student &std);

int main(int argc, char *argv[]) {
  Student stud1("19390185", "Αικατερίνη Παπαχριστοδούλου", 8);
  Student stud2("17380003", "Ιάσων Χαραλαμπίδης");
  Student stud3("18390045", "Βασιλίου Γεώργιος", 5);
  Student stud4 = stud3;
  std::cout << stud1 << '\n' << stud2 << '\n' << stud3 << '\n';
  
  std::cout << "Changing student3's AM, semester and name";
  stud3.setAM("19390127");
  stud3.setName("Παπαδέα Ευαγγελία");
  stud3.setSemester(10);
  
  std::cout << stud3 << '\n';

  //continue showcasing more fuctionalities
  return 0; 
}
