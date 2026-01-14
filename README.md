# Student Result Processing System

A C-based application designed for the **Processing Student Results**. The system processes student academic records from an input file, performs data validation, and generates a performance report with statistical analysis.

## 📊 Performance Standards
The system evaluates students based on the following criteria:
* **Subject Composition**: Each of the 5 subjects consists of a Minor (40 Marks) and a Major (60 Marks) component.
* **Passing Requirement**: The minimum passing mark in each subject is 50%.
* **Grading Scale**:
    * **O**: $\ge 90$ 
    * **A+**: 85 - 90 
    * **A**: 75 - 85 
    * **B+**: 65 - 75 
    * **B**: 60 - 65 
    * **C**: 55 - 60 
    * **D**: 50 - 55 
    * **F**: $< 50$ 

## 🛠️ Project Architecture
The project is implemented using **modular programming** with the following components:

* `main.c`: Orchestrates the program flow.
* `student.c/h`: Core logic for total/grade calculations and student structures.
* `file_io.c/h`: Handles reading and writing student records using Files.
* `validation.c/h`: Verification logic for IDs, names, and marks.
* `statistics.c/h`: Calculations for class averages and grade distributions.
* `display.c/h`: Handles formatted tabular output.
* `constants.h`: Centralized definitions for boundaries and limits.

## 📝 Input Format
The system reads data from a file where each record is on a single line. **Names containing spaces must be enclosed in double quotes.**

**Format:**
`<Student_ID> "<Name>" <Min1> <Maj1> <Min2> <Maj2> <Min3> <Maj3> <Min4> <Maj4> <Min5> <Maj5>`

**Example:**
`ABC001 "Alice Smith" 35 55 38 52 40 60 39 51 37 53`

### Validation Rules
* **IDs**: Must be unique and alphanumeric; special characters are rejected.
* **Names**: Must contain only alphabets; digits or symbols are rejected.
* **Marks**: Must be within the range [0, 100].

## 🚀 Execution
1. **Compile**: Use the `Makefile` to build the project:
   ```bash
   make

1. **Run**: Save the input file as `students_input.txt` then run
    ```bash
    make run
