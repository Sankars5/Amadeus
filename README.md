
**Developer Test - Amadeus**

Employee Average salary:
(Emp_Avg_salary.cpp)
 C++ program for reading input, parsing employee data from XML and JSON files, calculating the average salary, identifying the highest paid employee, and sorting employees by ID.
(Avg_salary.sh)
 Bash script to compile and run the C++ program

Requeirements :
C++11 or higher standard version is needed, else few features may not be working.
Need nlohmann/json library for JSON parsing.
Need tinyxml2 library for XML parsing.


Compile and Run:
1. Clone the repository:
   ```bash
   git clone https://github.com/Sankars5/Amadeus.git
   cd Amadeus
2. compile and run the program
      ```bash
   ./Avg_Salary.sh
   ./Avg_Salary.sh Employees.txt
   ./Avg_salary.sh Employees.xml
   ./Avg_Salary.sh Employees.json
 
   

Note: json.hpp and tinyxml2.h library has to be downloaded and added in the same directory where the .cpp and .sh files are present.


