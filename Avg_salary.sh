#!/bin/bash

# Checking if input file is provided
if [ -z "$1" ]; then
  echo "Use the below format to run the program: 
        ./Avg_salary.sh <input-file>"
  exit 1
fi

INPUT_FILE=$1

# Compiling the C++ program (Manually downloaded library in same directory)
echo "Compiling Emp_Avg_Salary.cpp..."
g++ -std=c++11 Emp_Avg_Salary.cpp tinyxml2.cpp -o Emp_Avg_Salary

#Compiling  the C++ program if libraries are inlcuded 
#g++ -std=c++11 -o Emp_Avg_Salary Emp_Avg_Salary.cpp -lnlohmann_json -ltinyxml2

# Check if compilation was successful
if [ $? -ne 0 ]; then
  echo "Compilation failed. Exiting..."
  exit 1
fi

echo "Compilation successful."

# Run the compiled program with the input file
echo "Running the program..."
./Emp_Avg_Salary "$INPUT_FILE"
