/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "Course.h"

namespace sict {

    Course::Course(const std::string& str) {
        size_t pos = 0;
        id = std::stoi(_utility.extractToken(str, pos));
        name = _utility.extractToken(str, pos);
        teacher = _utility.extractToken(str, pos);
    }

     const unsigned int Course::getId() const {
        return id;
    }

    const std::string& Course::getName() const {
        return name;
    }

    const std::string& Course::getTeacher() const {
        return teacher;
    }

    void Course::display(std::ostream& os) const {
        os << "Course: " << getName() << ", Teacher: " << getTeacher() << std::endl;
    }

    Course::Course(Course&& src) {
        *this = std::move(src);
    }

    Course& Course::operator=(Course&& src) {
        if (this != &src) {
            id  = src.id ;
            name = src.name;
            teacher = src.teacher;
            src.id = 0;
            src.name = "";
            src.teacher = "";
        }
    }

    std::ostream& operator<<(std::ostream& os, const Course& obj) {
        obj.display(os);
        return os;
    }
}