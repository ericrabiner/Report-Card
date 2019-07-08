/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#ifndef SICT_FILEREADER_H
#define SICT_FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Test.h"
#include "Mark.h"

namespace sict {
	class FileReader {
		std::vector<Student> studentData;
        std::vector<Course> courseData;
		std::vector<Test> testData;
		std::vector<Mark> markData;
		const char* fStudents { nullptr };
        const char* fCourses { nullptr };
		const char* fTests { nullptr };
		const char* fMarks { nullptr };
	public:
		FileReader(char* filename[], int nfiles);
		std::vector<Student>& loadStudents(std::ostream& os);
        std::vector<Course>& loadCourses(std::ostream& os);
		std::vector<Test>& loadTests(std::ostream& os);
		std::vector<Mark>& loadMarks(std::ostream& os);
	};
}
#endif