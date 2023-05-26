#ifndef STUDENT_H
#define STUDENT_H 

#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

#include "subject.h"

class Student {
  private:
    char *AM = nullptr; //code of student 
    std::string name; //name of student 
    unsigned int semester; //semester of student 

  public:
    //Constructors 
    Student(const char *AM, std::string name);
    Student(const char *AM, std::string name, unsigned int semester);
    Student(const Student &std);
    ~Student(); //Destructor 
    //Setters & Getters 
    void setAM(const char *AM);
    void setName(std::string name);
    void setSemester(unsigned int semester);
    char* getAM() const;
    std::string getName() const;
    unsigned int getSemester() const;
    //Overloading 
    Student& operator=(const Student &std); 
    Student operator+=(const Student &std);
    Student operator-=(const Student &std);
    Student operator++(int x);
    void operator+=(Subject *subj);
    constexpr bool operator==(const Student &std);
    constexpr bool operator!=(const Student &std);
    constexpr bool operator<(const Student &std);
    constexpr bool operator<=(const Student &std);
    constexpr bool operator>(const Student &std);
    constexpr bool operator>=(const Student &std);
};

#endif 