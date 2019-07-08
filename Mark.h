/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#ifndef sict_MARK_H
#define sict_MARK_H

#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sict {
    class Mark {
        unsigned int testId;
        unsigned int studentId;
        unsigned int mark;
        Utilities _utility;
    public:
        Mark(const std::string&);
        const unsigned int getTestId() const;
        const unsigned int getStudentId() const;
        const unsigned int getMark() const;
        void display(std::ostream&) const;
        
        Mark(const Mark&) = delete; // Do not allow Copy Construction
        Mark& operator=(const Mark&) = delete; //Do not allow Copy Assignment
        Mark(Mark&&); // Allow Move Construction
        Mark& operator=(Mark&&); // Allow Move Assignment
    };
    std::ostream& operator<<(std::ostream&, const Mark&);
}

#endif