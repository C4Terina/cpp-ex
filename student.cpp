#include "student.h"
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

// Getters & Setters
void Student::setAM(const char *AM) {
  if (this->AM != nullptr)
    delete[] this->AM;

  this->AM = new (std::nothrow) char[strlen(AM) + 1];
  if (this->AM == nullptr) {
    std::cout << "Error while allocating memory" << '\n';
    exit(1);
  }
  strcpy(this->AM, AM);
}

void Student::setName(std::string name) { this->name = name; }

void Student::setSemester(unsigned int semester) { this->semester = semester; }

char *Student::getAM() const { return this->AM; }

std::string Student::getName() const { return this->name; }

unsigned int Student::getSemester() const { return this->semester; }

std::vector<Subject *> Student::getDeclared() const {
  return declared_subjects;
}

// Constructors & Deconstructor
Student::Student(const char *AM, std::string name) {
  this->AM = new (std::nothrow) char[strlen(AM) + 1];
  if (this->AM == nullptr) {
    std::cout << "Error while allocating memory" << '\n';
    exit(1);
  }

  strcpy(this->AM, AM);
  this->name = name;
  this->semester = 1;
}

Student::Student(const char *AM, std::string name, unsigned int semester)
    : Student(AM, name) {
  this->semester = semester;
}

Student::Student(const Student &std) { *this = std; }

Student::~Student() { delete[] this->AM; }

// Operators overloading
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

Student &Student::operator=(const Student &std) {
  if (this->AM) {
    delete[] this->AM;
  }

  this->AM = new (std::nothrow) char[strlen(std.AM) + 1];
  if (this->AM == nullptr) {
    std::cout << "Error allocating memory" << '\n';
    exit(1);
  }

  strcpy(this->AM, std.AM);
  this->name = std.name;
  this->semester = std.semester;

  return *this;
}

Student Student::operator+=(Subject *subject) {
  auto it = find(declared_subjects.begin(), declared_subjects.end(), subject);

  if (it == declared_subjects.end()) {
    declared_subjects.push_back(subject);
  }

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

std::ostream &operator<<(std::ostream &obj, const Student &std) {
  obj << "AM: " << std.getAM() << '\n';
  obj << "Όνομα: " << std.getName() << '\n';
  obj << "Εξάμηνο: " << std.getSemester() << '\n';

  // Print declared subjects
  std::cout << "Δηλωμένα μαθήματα " << '\n';
  for (const auto &declared : std.getDeclared()) {
    obj << *declared << '\n';
  }

  Subject *subject;
  float grade;

  std::cout << "Βαθμοί από τα περασμένα μαθήματα  " << '\n';

  for (const auto &passed : std.getPassed()) {
    subject = std::get<Subject *>(passed);
    grade = std::get<float>(passed);
    obj << subject->getSubname() << ": " << grade << '\n';
  }

  obj << "Μ.Ο: " << std.getAverage() << '\n';

  return obj;
}

void Student::add_Passed_Subject(std::pair<Subject *, float> passed_subject) {
  passed_subjects.push_back(passed_subject);
}

std::vector<std::pair<Subject *, float>> Student::getPassed() const {
  return passed_subjects;
}

float Student::getAverage() const {
  std::size_t const cnt = getPassed().size();
  if (not cnt) {
    return 0.0f;
  }

  float sum = 0.0f;
  for (const auto &passed : getPassed()) {
    sum += std::get<float>(passed);
  }

  return (float)sum / cnt;
}

void Student::writestd2file(const char *filename) {
  std::ofstream outputFile(filename);

  if (!outputFile.is_open()) {
    outputFile << "Error file not opened " << filename << '\n';
    exit(1);
  }

  outputFile << "AM: " << this->getAM() << '\n';
  outputFile << "Όνομα: " << this->getName() << '\n';
  outputFile << "Εξάμηνο: " << this->getSemester() << '\n';
  outputFile << "Δηλωμένα μαθήματα " << '\n';
  for (const auto &declared : this->getDeclared()) {
    outputFile << *declared << '\n';
  }

  Subject *subject;
  float grade;

  outputFile << "Βαθμοί από τα περασμένα μαθήματα  " << '\n';

  for (const auto &passed : this->getPassed()) {
    subject = std::get<Subject *>(passed);
    grade = std::get<float>(passed);
    outputFile << subject->getSubname() << ": " << grade << '\n';
  }

  outputFile << "Μ.Ο: " << this->getAverage() << '\n';


  outputFile.close();
}
