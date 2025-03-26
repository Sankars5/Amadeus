#!/bin/bash

# Checking if input file is available
if [ -z "$1" ]; then
  echo "Usage: ./Avg_salary.sh <input-file>"
  exit 1
fi

INPUT_FILE=$1

# Compiling the C++ program
g++ -std=c++11 -o Emp_Avg_Salary Emp_Avg_Salary.cpp -lnlohmann_json -ltinyxml2
if [ $? -ne 0 ]; then
  echo "Compilation failed. Please check the code."
  exit 1
fi

# Run the C++ program with the input file
./Emp_Avg_Salary "$INPUT_FILE"
