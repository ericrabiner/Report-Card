# Report Cards

An application written in C++ that reads and processes data from .csv files and creates a new text file called output.txt. The default delimeter is ',' and can be set to any character.

## Prerequisites
Install the Minimalist GNU for Windows

## Running the Application

Compile the source and header files.
```
c++ main.cpp Utilities.cpp fileReader.cpp Student.cpp Course.cpp Test.cpp Mark.cpp -std=c++11 -o report.exe
```

Run the executable file.
```
./report.exe students.csv courses.csv tests.csv marks.csv
```

Note: the .csv files must be in this order.

Output
```
Student ID: 1, name: A
Total Average: 72.03%

          Course: Biology, Teacher: Mr. D
          Final Grade: 90.10%

          Course: History, Teacher:  Mrs. P
          Final Grade: 51.80%

          Course: Math, Teacher:  Mrs. C
          Final Grade: 74.20%

Student ID: 2, name: B
Total Average: 62.15%

          Course: Biology, Teacher: Mr. D
          Final Grade: 50.10%

          Course: History, Teacher:  Mrs. P
          Final Grade: 74.20%

Student ID: 3, name: C
Total Average: 72.03%

          Course: Biology, Teacher: Mr. D
          Final Grade: 90.10%

          Course: History, Teacher:  Mrs. P
          Final Grade: 51.80%

          Course: Math, Teacher:  Mrs. C
          Final Grade: 74.20%
```