#ifndef STUDENT_H
#define STUDENT_H 

#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "subject.h"

class Student {
  private:
    char *AM = nullptr; //code of student 
    std::string name; //name of student 
    unsigned int semester; //semester of student 
    std::vector<Subject*> declared_subjects;
    std::vector<std::pair<Subject*, float>> passed_subjects;

  public:
    //Constructors 
    Student(const char *AM, std::string name);
    Student(const char *AM, std::string name, unsigned int semester);
    Student(const Student &std);
    virtual ~Student(); // virtual destructor 
    
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
    Student operator+= (const Subject &subject);
    constexpr bool operator==(const Student &std);
    constexpr bool operator!=(const Student &std);
    constexpr bool operator<(const Student &std);
    constexpr bool operator<=(const Student &std);
    constexpr bool operator>(const Student &std);
    constexpr bool operator>=(const Student &std);
    void writestd2file(const char* filename);

    
};

#endif 