#include "subject.h"

Subject::Subject(const std::string& code, const std::string& subname, const unsigned int hours, bool subsem)
    :code(code), subname(subname), hours(hours), subsem(subsem) {}

Subject::Subject(const Subject &s)
    :code(code), subname(subname), hours(hours), subsem(subsem) {}

//Getters
const std::string& Subject::getCode() const {
    return this->code;
 }

const std::string& Subject::getSubname() const {
    return this->subname;
}

const unsigned int Subject::getHours() const {
    return this->hours;
}

const bool Subject::getSubsem() const {
    return this->subsem;
 }

std::string Subject::getSem() const {
    return (subsem) ? std::string("Spring") : std::string("Winter"); 
}
//Setters
void Subject::setCode(std::string& code) {
    this->code = code;
}

void Subject::setSubname(std::string& subname) {
    this->subname = subname;
}

void Subject::setHours(unsigned int hours) {
    this->hours = hours;
}

void Subject::setSubsem(bool subsem) {
    this->subsem = subsem;
}



std::ostream& operator << (std::ostream &os, const Subject &sub){
  os << "Codename: " << sub.getCode() << '\n';
  os << "Subject name: " << sub.getSubname() << '\n';
  os << "Hours: " << sub.getHours() << '\n';
  os << "Semester: " << sub.getSem() << '\n'; 
  return os;    
}