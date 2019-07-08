/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#ifndef sict_TEST_H
#define sict_TEST_H

#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sict {
    class Test {
        unsigned int id;
        unsigned int courseId;
        unsigned int testWeight;
        Utilities _utility;
    public:
        Test(const std::string&);
        const unsigned int getId() const;
        const unsigned int getCourseId() const;
        const unsigned int getTestWeight() const;
        void display(std::ostream&) const;
        
        Test(const Test&) = delete; // Do not allow Copy Construction
        Test& operator=(const Test&) = delete; //Do not allow Copy Assignment
        Test(Test&&); // Allow Move Construction
        Test& operator=(Test&&); // Allow Move Assignment
    };
    std::ostream& operator<<(std::ostream&, const Test&);
}

#endif