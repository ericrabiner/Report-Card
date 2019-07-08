/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "Test.h"

namespace sict {

    Test::Test(const std::string& str) {
        size_t pos = 0;
        id = std::stoi(_utility.extractToken(str, pos));
        courseId = std::stoi(_utility.extractToken(str, pos));
        testWeight = std::stoi(_utility.extractToken(str, pos));
    }

    const unsigned int Test::getId() const {
        return id;
    }

    const unsigned int Test::getCourseId() const {
        return courseId;
    }

    const unsigned int Test::getTestWeight() const {
        return testWeight;
    }

    void Test::display(std::ostream& os) const {
        os << "Test Id: " << getId() << ", Course Id: " << getCourseId() << ", Test Weight: " << getTestWeight() << std::endl;
    }

    Test::Test(Test&& src) {
        *this = std::move(src);
    }

    Test& Test::operator=(Test&& src) {
        if (this != &src) {
            id  = src.id ;
            courseId = src.courseId;
            testWeight = src.testWeight;
            src.id = 0;
            src.courseId = 0;
            src.testWeight = 0;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Test& obj) {
        obj.display(os);
        return os;
    }
}