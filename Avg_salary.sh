#!/bin/bash

# Check if input file is provided
if [ -z "$1" ]; then
  echo "Usage: ./Avg_salary.sh <input-file>"
  exit 1
fi

INPUT_FILE=$1

# Compile the C++ program
g++ -std=c++11 -o Employee_Avg_Salary Employee_Avg_Salary.cpp -lnlohmann_json -ltinyxml2

# Run the C++ program with the provided input file
./employee_util $INPUT_FILE
