/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#ifndef sict_Course_H
#define sict_Course_H

#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sict {
    class Course {
        unsigned int id;
        std::string name;
        std::string teacher;
        Utilities _utility;
    public:
        Course(const std::string&);
        const unsigned int getId() const;
        const std::string& getName() const;
        const std::string& getTeacher() const;
        void display(std::ostream&) const;
        
        Course(const Course&) = delete; // Do not allow Copy Construction
        Course& operator=(const Course&) = delete; //Do not allow Copy Assignment
        Course(Course&&); // Allow Move Construction
        Course& operator=(Course&&); // Allow Move Assignment
    };
    std::ostream& operator<<(std::ostream&, const Course&);
}

#endif