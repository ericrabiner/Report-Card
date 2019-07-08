/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include "FileReader.h"

namespace sict {

    FileReader::FileReader(char* filename[], int nFiles) : 
        fStudents(nFiles > 0 ? filename[0] : nullptr),
        fCourses(nFiles > 1 ? filename[1] : nullptr),
        fTests(nFiles > 2 ? filename[2] : nullptr),
        fMarks(nFiles > 3 ? filename[3] : nullptr)
        {
		if (nFiles != 4) {
            throw std::string("*** Incorrect number of command line arguments ***\n");
        }
	}

    std::vector<Student>& FileReader::loadStudents(std::ostream& os) {
		std::ifstream file(fStudents);
		if (!file) {
            throw std::string("*** Unable to open Students file ") + std::string(fStudents);
        }
		std::string record;
        size_t lineNum = 0;
		while (!file.eof()) {
			std::getline(file, record);
            if (lineNum != 0 && record != "") {
                studentData.push_back(std::move(Student(record)));
            }
            lineNum++;
		}
		file.close();
        os << "Students Loaded.\n";
		// os << "Students\n";
		// os << "--------------\n";
		// for (size_t i = 0; i < studentData.size(); i++) {
        //     studentData[i].display(os);
        // }
        return studentData;
    }

    std::vector<Course>& FileReader::loadCourses(std::ostream& os) {
		std::ifstream file(fCourses);
		if (!file) {
            throw std::string("*** Unable to open Courses file ") + std::string(fCourses);
        }
		std::string record;
        size_t lineNum = 0;
		while (!file.eof()) {
			std::getline(file, record);
            if (lineNum != 0 && record != "") {
                courseData.push_back(std::move(Course(record)));
            }
            lineNum++;
		}
		file.close();
        os << "Courses Loaded.\n";
		// os << "Courses\n";
		// os << "--------------\n";
		// for (size_t i = 0; i < courseData.size(); i++) {
        //     courseData[i].display(os);
        // }
        return courseData;
    }

    std::vector<Test>& FileReader::loadTests(std::ostream& os) {
		std::ifstream file(fTests);
		if (!file) {
            throw std::string("*** Unable to open Courses file ") + std::string(fTests);
        }
		std::string record;
        size_t lineNum = 0;
		while (!file.eof()) {
			std::getline(file, record);
            if (lineNum != 0 && record != "") {
                testData.push_back(std::move(Test(record)));
            }
            lineNum++;
		}
		file.close();
        os << "Tests Loaded.\n";
		// os << "Tests\n";
		// os << "--------------\n";
		// for (size_t i = 0; i < testData.size(); i++) {
        //     testData[i].display(os);
        // }
        return testData;
    }

    std::vector<Mark>& FileReader::loadMarks(std::ostream& os) {
		std::ifstream file(fMarks);
		if (!file) {
            throw std::string("*** Unable to open Courses file ") + std::string(fMarks);
        }
		std::string record;
        size_t lineNum = 0;
		while (!file.eof()) {
			std::getline(file, record);
            if (lineNum != 0 && record != "") {
                markData.push_back(std::move(Mark(record)));
            }
            lineNum++;
		}
		file.close();
        os << "Marks Loaded.\n";
		// os << "Marks\n";
		// os << "--------------\n";
		// for (size_t i = 0; i < markData.size(); i++) {
        //     markData[i].display(os);
        // }
        return markData;
    }
}