/*
Name: Eric Rabiner
Email: ericrabiner@gmail.com
Date: July 6, 2019
*/

#include <numeric>
#include <iomanip>
#include "Utilities.h"
#include "FileReader.h"
#include "Student.h"
#include "Course.h"
#include "Test.h"
#include "Mark.h"

using namespace sict;

int main(int argc, char *argv[]) {
    std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << '\n' << std::endl;

	Utilities::setDelimiter(',');
    std::ostream& os = std::cout;
    std::vector<Student> students;
    std::vector<Course> courses;
    std::vector<Test> tests;
    std::vector<Mark> marks;
    try {
		FileReader a(&argv[1], argc - 1);
        students = std::move(a.loadStudents(os));
        courses = std::move(a.loadCourses(os));
        tests = std::move(a.loadTests(os));
        marks = std::move(a.loadMarks(os));
        std::ofstream myFile ("output.txt");
        if (myFile.is_open()) {  
            // The following processes the data and writes to output.txt.
            for (size_t i = 0; i < students.size(); i++) {
                myFile << students[i];
                std::vector<double> grades;
                for (size_t j = 0; j < courses.size(); j++) {
                    double finalGrade {0};
                    for (size_t k = 0; k < tests.size(); k++) {
                        for (size_t l = 0; l < marks.size(); l++) {
                            if (students[i].getId() == marks[l].getStudentId() 
                            && courses[j].getId() == tests[k].getCourseId() 
                            && tests[k].getId() == marks[l].getTestId()) {
                                finalGrade += marks[l].getMark() * (tests[k].getTestWeight());
                            }
                        }
                    }
                    if (finalGrade > 0) {
                        grades.push_back(finalGrade);
                    }
                }
                double sumGrades = std::accumulate(grades.begin(), grades.end(), (double)0);
                myFile << "Total Average: " << std::fixed << std::setprecision(2) << sumGrades / grades.size() / 100 << "%" << std::endl;

                for (size_t x = 0; x < grades.size(); x++) {
                    myFile << std::endl << std::setw(10) << " " << courses[x];
                    myFile << std::setw(10) << " " << "Final Grade: " << grades[x] / 100 << "%" << std::endl;
                }
                myFile << std::endl;
            }

            // The following writes the raw data into the output.txt file.
            // for (size_t i = 0; i < students.size(); i++) {
            //     myFile << students[i];
            // }
            // for (size_t j = 0; j < courses.size(); j++) {
            //     myFile << courses[j];
            // }
            
            // for (size_t k = 0; k < tests.size(); k++) {
            //     myFile << tests[k];
            // }
            // for (size_t l = 0; l < marks.size(); l++) {
            //     myFile << marks[l];
            // }
            
            std::cout << std::endl << "Report has been created." << std::endl;
            myFile.close();
        }
	}
	catch (const std::string& str) {
		std::cerr << str << std::endl;
	}

    catch (...) {
        std::cerr << "Unexpected error occured." << std::endl;
    }

    return 0;
}