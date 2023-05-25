#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

class Student 
{
    private:
        char *AM = nullptr;
        std::string name;
        unsigned int semester;
    public:
        Student(const char *AM, std::string name);
        Student(const char *AM, std::string name, unsigned int semester);
        // Rule of three
        Student(const Student &std); // 1
        Student& operator=(const Student&); // 2
        ~Student(); // 3
        void setAM(const char *AM);
        void setName(std::string name);
        void setSemester(unsigned int semester);
        char* getAM() const;
        std::string getName() const;
        unsigned int getSemester() const;
        Student operator+=(const Student &std);
        Student operator-=(const Student &std);
        //Student operator++();       ++std
        Student operator++(int x); // std++, η παράμετρος για να επιτευχθεί η υπερφόρτωση 
};

std::ostream& operator<<(std::ostream &obj, const Student &std);

using namespace std;

int main(int argc, char *argv[]) 
{
    Student std1 ("001", "Χαράλαμπος Παπαγεωργίου");
    Student std2 ("002", "Ελένη Θεοχάρη", 2);
    Student std3 = std2;
    
    cout << std1;
    cout << std2;
    cout << std3;
    cout << "Changing std3's AM" << endl;
    std3.setAM("003");
    cout << "Changing std3's name" << endl;
    std3.setName("Ελένη-Μαρία Θεοχάρη");
    cout << "Changing std3's semester" << endl;
    std3.setSemester(4);
    cout << "std2 :" << endl;
    cout << std2;
    cout << "std3 :" << endl;
    cout << std3;
    cout << "Operator++ in std1's semester" << endl;
    std1++;
    cout << std1;
    cout << "Operator+= in std1's semester with std2's semester" << endl;
    std1 += std2;
    cout << std1;
    cout << "Operator-= in std3's semester with std2's semester" << endl;
    std3 -= std2;
    cout << std3;

    //std3 = std1;
    //cout << std3;

    return 0;
}

Student::Student(const char *AM, string name)
{
    cout << "Constructing student " << AM << "...\n";

    this->AM = new (nothrow) char [strlen(AM) + 1];
    if (this->AM == nullptr)
    {
        cout << "Error while allocating memory" << endl;
        exit(1);
    }
    strcpy(this->AM, AM);
    this->name = name;
    this->semester = 1;
}

Student::Student(const char *AM, string name, unsigned int semester)
    : Student(AM, name) 
{
    this->semester = semester;
}

Student::Student(const Student &std)
{
    cout << "Constructing student " << std.AM << "...\n";

    *this = std;
}

Student::~Student()
{
    cout << "Destructing student " << this->AM << "...\n";
    delete [] this->AM;
}

void Student::setAM (const char *AM)
{
    if (this->AM != nullptr)
        delete [] this->AM;
    this->AM = new (nothrow) char [strlen(AM) + 1];
    if (this->AM == nullptr)
    {
        cout << "Error while allocating memory" << endl;
        exit(1);
    }
    strcpy(this->AM, AM);
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setSemester(unsigned int semester)
{
    this->semester = semester;
}

char* Student::getAM() const
{
    return this->AM;
}

string Student::getName() const
{
    return this->name;
}

unsigned int Student::getSemester() const
{
    return this->semester;
}

ostream& operator<<(ostream &obj, const Student &std)
{
    obj << "Στοιχεία φοιτητή" << endl;
    obj << "-------------------------------------------------------------------------" << endl;
    obj << "Αριθμός Μητρώου : " << std.getAM() << endl;
    obj << "Ονοματεπώνυμο   : " << std.getName() << endl;
    obj << "Τρέχον εξάμηνο  : " << std.getSemester() << endl << endl;
    
    return obj;    
}

/*Student Student::operator++()
{
    ++this->semester;
    return *this;
}*/

Student Student::operator++(int x)
{
    this->semester++;
    return *this;
}

Student Student::operator+=(const Student &std)
{
    this->semester += std.semester;
    return *this;
}

Student Student::operator-=(const Student &std)
{
    this->semester -= std.semester;
    return *this;
}

Student& Student::operator=(const Student& s) {
    if (this->AM) {
        delete [] this->AM;
    }

    this->AM = new (nothrow) char [strlen(s.AM) + 1];
    if (this->AM == nullptr)
    {
        cout << "Πρόβλημα στην δέσμευση μνήμης" << endl;
        exit(1);
    }
    strcpy(this->AM, s.AM);
    this->name = s.name;
    this->semester = s.semester;

    return *this;
}
