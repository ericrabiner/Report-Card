/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "Mark.h"

namespace sict {

    Mark::Mark(const std::string& str) {
        size_t pos = 0;
        testId = std::stoi(_utility.extractToken(str, pos));
        studentId = std::stoi(_utility.extractToken(str, pos));
        mark = std::stoi(_utility.extractToken(str, pos));
    }

    const unsigned int Mark::getTestId() const {
        return testId;
    }

    const unsigned int Mark::getStudentId() const {
        return studentId;
    }
    const unsigned int Mark::getMark() const {
        return mark;
    }

    void Mark::display(std::ostream& os) const {
        os << "Test Id: " << getTestId() << ", studentId: " << getStudentId() << ", Mark: " << getMark() << std::endl;
    }

    Mark::Mark(Mark&& src) {
        *this = std::move(src);
    }

    Mark& Mark::operator=(Mark&& src) {
        if (this != &src) {
            testId  = src.testId;
            studentId = src.studentId;
            mark = src.mark;
            src.testId = 0;
            src.studentId = 0;
            src.mark = 0;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Mark& obj) {
        obj.display(os);
        return os;
    }
}