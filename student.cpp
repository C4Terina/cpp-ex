#include "student.h"

//Getters & Setters 
void Student::setAM (const char *AM) {
  if (this->AM != nullptr)
    delete [] this->AM;
    
  this->AM = new (std::nothrow) char [strlen(AM) + 1];
  if (this->AM == nullptr) {
    std::cout << "Error while allocating memory" << '\n';
        exit(1);
  }
  strcpy(this->AM, AM);
}

void Student::setName(std::string name) {
  this->name = name;
}

void Student::setSemester(unsigned int semester) {
    this->semester = semester;
}

char* Student::getAM() const {
  return this->AM;
}

std::string Student::getName() const {
  return this->name;
}

unsigned int Student::getSemester() const {
  return this->semester;
}

//Constructors & Deconstructor
Student::Student(const char *AM, std::string name) {
  this->AM = new (std::nothrow) char [strlen(AM) + 1];
    if (this->AM == nullptr) {
        std::cout << "Error while allocating memory" << '\n';
        exit(1);
    }
    
  strcpy(this->AM, AM);
  this->name = name;
  this->semester = 1;
}

Student::Student(const char *AM, std::string name, unsigned int semester) : Student(AM, name) {
  this->semester = semester;
}

Student::Student(const Student &std) {
  *this = std;
}

Student::~Student() {
  delete [] this->AM;
}

//Operators overloading 
Student Student::operator++(int x) {
  this->semester++;
  return *this;
}

Student Student::operator+=(const Student &std) {
  this->semester += std.semester;
  return *this;
}

Student Student::operator-=(const Student &std) {
  this->semester -= std.semester;
  return *this;
}

Student& Student::operator=(const Student& std) {
  if (this->AM) {
      delete [] this->AM;
  }
  
  this->AM = new (std::nothrow) char [strlen(std.AM) + 1];
  if (this->AM == nullptr) {
      std::cout << "Error allocating memory" << '\n';
      exit(1);
    }
    
  strcpy(this->AM, std.AM);
  this->name = std.name;
  this->semester = std.semester;

  return *this;
}

constexpr bool Student::operator==(const Student &std) {
  return this->semester == std.semester;
}

constexpr bool Student::operator!=(const Student &std) {
  return this->semester != std.semester;
}

constexpr bool Student::operator<(const Student &std) {
  return this->semester < std.semester;
}

constexpr bool Student::operator<=(const Student &std) {
  return this->semester <= std.semester;
}

constexpr bool Student::operator>(const Student &std) {
  return this->semester > std.semester;
}

constexpr bool Student::operator>=(const Student &std) {
  return this->semester >= std.semester;
}

std::ostream& operator<<(std::ostream &obj, const Student &std) {
  obj << "AM: " << std.getAM() << '\n';
  obj << "Name: " << std.getName() << '\n';
  obj << "Semester: " << std.getSemester() << '\n';
    
  return obj;    
}


