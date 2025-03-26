# Amadeus
Developer Test

Employee Average salary:
This is a C++ program for reading, parsing employee data from XML and JSON files, calculating the average salary, identifying the highest paid employee, and sorting employees by ID.

Requeirements :
C++11 or higher standard version is needed, else few features may not be working.
nlohmann/json library for JSON parsing
tinyxml2 library for XML parsing


Compile and Run:
1. Clone the repository:
   ```bash
   git clone https://github.com/Sankars5/Amadeus.git
   cd Amadeus
2. compile the program 
   g++ -std=c++11 -o Emp_Avg_Salary Emp_Avg_Salary.cpp -lnlohmann_json -ltinyxml2
3. Run the program
   ./.sh tests/Employees.xml
   ./.sh tests/Employees.json
