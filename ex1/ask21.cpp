#include <iostream>
#include <cstring>
#include <ostream>
#include <string>

using namespace std;

class Student{
  private:
    char *AM;
    string name;
    unsigned int semester;
  public:
    //Getters and Setters for AM, semester and name 
    char* getAM() const;
    void setAM(const char * AM);
    void setSemester(unsigned int);
    unsigned int getSemester() const;
    string getName() const;
    void setName(string);

    //Constructors
    Student(const char *AM, string name);
    Student(const char *AM, string name, unsigned semester);
    Student(const Student &stud);
    ~Student();

    //Operators 
    Student operator-=(const Student &stud);
    Student operator+=(const Student &stud);
    Student operator=(const Student &stud);
};

ostream& operator<<(ostream &obj, const Student &stud);

//Getter and Setter for AM
char* Student::getAM() const {
  return this->AM;
}

void Student::setAM(const char * AM){
  if(this->AM)
    delete [] this->AM;

  this->AM = new char[strlen(AM)+1];
  strcpy(this->AM, AM);
}

//Getter and Setter for Semester
void Student::setSemester(unsigned int e){
  semester = e;
}

unsigned int Student::getSemester() const{
  return semester; 
}

//Getter and Setter for name
string Student::getName() const {
  return this->name;
}

void Student::setName(string n){
  this->name = n;
}


//Constructors
Student::Student(const char *AM, string name){
  this->AM = new char[strlen(AM)+1];

  strcpy(this->AM, AM);
  this->name = name;
  this->semester = 1;
}

Student::Student(const char *AM, string name, unsigned int semester){
  this->AM = new char[strlen(AM)+1];

  strcpy(this->AM, AM);
  this->name = name;
  this->semester = semester;
}

Student::~Student(){
  delete [] this->AM;
}

Student::Student(const Student &stud){
  this->AM = new char[strlen(stud.AM)+1];
  strcpy(this->AM, stud.AM);
  this->name = stud.name;
  this->semester = stud.semester;
}


//Operators 
Student Student::operator+=(const Student &stud){
  this->semester += stud.semester;
  return *this;
}

Student Student::operator-=(const Student &stud){
  this->semester -= stud.semester;
  return *this;
}

Student Student::operator=(const Student &stud){
  this->AM = new char[strlen(stud.AM)+1];
  strcpy(this->AM, stud.AM);
  this->name = stud.name;
  this->semester = stud.semester;

  return *this;
}

ostream& operator<<(ostream &obj, const Student &stud){
  obj << "Foithths" << endl;
  obj << "AM: " << stud.getAM() << endl;
  obj << "Name: " << stud.getName() << endl;
  obj << "Semester: " << stud.getSemester() << endl;

  return obj;
}
int main(int argc, char **argv){
  Student stud1("19390185", "Katerina P", 8);
  Student stud2("19390186", "Jason X", 10);
  Student stud3 = stud1;

  cout << stud1 << "    " << stud2 << "   " << stud3 << endl;
 
  cout << "Changing student 3's credentials" << endl;
  stud3.setAM("19390187");
  stud3.setName("Giannhs V");
  stud3.setSemester(6);
  cout << "The new student is: "<< stud3 << endl;

  cout << "Changing student 1 semester and student 3 semester" << endl;
  stud1 -= stud2;
  stud3 += stud1;
  cout << "Their new semesters are: " << stud1 << stud3 << endl;

  return 0;
}
