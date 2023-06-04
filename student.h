#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "subject.h"

class Student {
private:
  char *AM = nullptr;    // code of student
  std::string name;      // name of student
  unsigned int semester; // semester of student
  std::vector<Subject *> declared_subjects;
  std::vector<std::pair<Subject *, float>> passed_subjects;

public:
  // Constructors
  Student(const char *AM, std::string name);
  Student(const char *AM, std::string name, unsigned int semester);
  Student(const Student &std);
  virtual ~Student(); // virtual destructor

  // Method
  void add_Passed_Subject(std::pair<Subject *, float> passed_subject);

  // Setters & Getters
  void setAM(const char *AM);
  void setName(std::string name);
  void setSemester(unsigned int semester);
  char *getAM() const;
  std::string getName() const;
  unsigned int getSemester() const;
  std::vector<Subject *> getDeclared() const;
  std::vector<std::pair<Subject *, float>> getPassed() const;
  float getAverage() const;

  // Overloading
  Student &operator=(const Student &std);
  Student operator+=(const Student &std);
  Student operator-=(const Student &std);
  Student operator++(int x);
  Student operator+=(Subject *subject);
  constexpr bool operator==(const Student &std);
  constexpr bool operator!=(const Student &std);
  constexpr bool operator<(const Student &std);
  constexpr bool operator<=(const Student &std);
  constexpr bool operator>(const Student &std);
  constexpr bool operator>=(const Student &std);
  void writestd2file(const char *filename);
};

std::ostream &operator<<(std::ostream &obj, const Student &std);

#endif
