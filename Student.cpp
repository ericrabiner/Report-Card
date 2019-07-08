/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "Student.h"

namespace sict {

    Student::Student(const std::string& str) {
        size_t pos = 0;
        id = std::stoi(_utility.extractToken(str, pos));
        name = _utility.extractToken(str, pos);
    }

    const unsigned int Student::getId() const {
        return id;
    }

    const std::string& Student::getName() const {
        return name;
    }

    void Student::display(std::ostream& os) const {
        os << "Student ID: " << getId() << ", name: " << getName() << std::endl;
    }

    Student::Student(Student&& src) {
        *this = std::move(src);
    }

    Student& Student::operator=(Student&& src) {
        if (this != &src) {
            id  = src.id ;
            name = src.name;
            src.id = 0;
            src.name = "";
        }
    }

    std::ostream& operator<<(std::ostream& os, const Student& obj) {
        obj.display(os);
        return os;
    }
}