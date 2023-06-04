#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
class Subject {
private:
  std::string code;    // code of the subject
  std::string subname; // Name of the subject
  unsigned int hours;  // Hours of the subject
  bool subsem;         // Winter semester is 0 and Spring semester is 1
public:
  // Constructors
  Subject() = default;
  Subject(const std::string &code, const std::string &subname,
          const unsigned int hours, bool subsem);
  Subject(const Subject &s);

  // Getters & setters
  void setCode(std::string &code);
  void setSubname(std::string &subname);
  void setHours(unsigned int hours);
  void setSubsem(bool subsem);

  const std::string &getCode() const;
  const std::string &getSubname() const;
  const unsigned int getHours() const;
  const bool getSubsem() const;

  std::string getSem() const;
};

std::ostream &operator<<(std::ostream &os, const Subject &sub);

#endif
