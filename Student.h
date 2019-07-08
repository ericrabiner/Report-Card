/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#ifndef sict_Student_H
#define sict_Student_H

#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sict {
    class Student {
        unsigned int id;
        std::string name;
        Utilities _utility;
    public:
        Student(const std::string&);
        const unsigned int getId() const;
        const std::string& getName() const;
        void display(std::ostream&) const;
        
        Student(const Student&) = delete; // Do not allow Copy Construction
        Student& operator=(const Student&) = delete; //Do not allow Copy Assignment
        Student(Student&&); // Allow Move Construction
        Student& operator=(Student&&); // Allow Move Assignment
    };
    std::ostream& operator<<(std::ostream&, const Student&);
}

#endif