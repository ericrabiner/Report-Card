/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "Utilities.h"

namespace sict {
    char Utilities::_delimiter = ',';
    size_t Utilities::_fieldwidth = 0;

    Utilities::Utilities() {};

    const std::string Utilities::extractToken(const std::string& str, size_t& pos) {
        size_t next_pos = str.find(_delimiter, pos) + 1;
        std::string token = str.substr(pos, next_pos - pos - 1);
        pos = next_pos;
        return token;
    }

    const char Utilities::getDelimiter() const {
        return _delimiter;
    }

    size_t Utilities::getFieldWidth() const {
        return _fieldwidth;
    }

    void Utilities::setDelimiter(const char d) {
        _delimiter = d;
    }

    void Utilities::setFieldWidth(size_t fw) {
        _fieldwidth = fw;
    }
}