//This program simulates a grade book through the usage of dynamic allocation and stuctures.
//This program takes input from a text file with student names, ID numbers, and tests scores, as well as the number of students and test scores for each student present at the top of the file.
//Using the names and scores given, the program calculates the average between the scores and lists them for each respective student. It also gives a letter grade based on the average score.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct student
{
    string name = "";
    int idNum = 0;
    double* score = 0;
    double average = 0;
    char grade = 0;
};

student* read(ifstream &file, int& students_cpy, int& tests_cpy);
void averages(student students_arr[], int students_cpy, int tests_cpy);
char letter(double average);
void report(student students_arr[], int students_cpy);
void remove(student students_arr[], int students_cpy);

//The pre-conditons for this function are that certain header files are included, namespace std is being used, the student structure is created with its respective variables, and the appropiate functions are prototyped.
//The program should always end at this function by returning 0, and the rest of the functions should have already executed.
int main()
{
    ifstream inputFile("StudentGrades.txt");

    if (inputFile)
    {
        cout << "Opening file..." << endl;
    }
    else
    {
        cout << "Error opening the file." << endl;

        exit(0);
    }

    int students = 0;
    int tests = 0;

    student* students_arr = read(inputFile, students, tests);

    inputFile.close();

    averages(students_arr, students, tests);
    report(students_arr, students);
    remove(students_arr, students);

    return 0;
}

//This function has the text file statement and a reference to both the students and tests variables passed to it.
//The pre-conditions for this function are that the file has already been opened, the students and tests variable are initialized, and this function is set equal to a newly defined array of student structures.
//The function ends by having placed info from the top of the file inside of the referenced variables, having dynamically allocated 6 student structures into an array and an array of 5 test scores for each student into each structure in the array, and copying the name, ID, and score information into each structure in the array. 
student* read(ifstream& file, int& students_cpy, int& tests_cpy)
{
    file >> students_cpy >> tests_cpy;

    student* students_arr = new student[students_cpy];

    for (int count = 0; count < students_cpy; count++)
    {
        file >> students_arr[count].name >> students_arr[count].idNum;
        students_arr[count].score = new double[tests_cpy];

        for (int count2 = 0; count2 < tests_cpy; count2++)
        {
            file >> students_arr[count].score[count2];
        }
    }

    return students_arr;
}

//This function takes as input the array of structures and the variables for the amount of students and test scores for each student.
//The pre-conditions for this function are that the read function has already been executed and the file closed.
//This function ends by having calculated all of the average test scores and having put all of the average test scores inside each of the structures' average variables.
void averages(student students_arr[], int students_cpy, int tests_cpy)
{
    for (int count = 0; count < students_cpy; count++)
    {
        double total_score = 0;

        for (int count2 = 0; count2 < tests_cpy; count2++)
        {
            total_score += students_arr[count].score[count2];
        }

        students_arr[count].average = total_score / tests_cpy;
    }
}

//This function only takes as input the average score for each student so a respective letter grade can be calculated.
//The pre-condition for this function is that every other function has already been executed except the remove function.
//This function will execute for how many students there are, and it will end by returning a letter grade for each one.
char letter(double mean)
{
    char grade = 0;

    if (mean < 60)
        grade = 'F';
    else if (mean < 70)
        grade = 'D';
    else if (mean < 80)
        grade = 'C';
    else if (mean < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

//This function takes as input the array of structures as well as the variable for the number of students.
//The pre-condition for this function is that every other part of main has executed (except for the return statement and remove function).
//This function ends by having displayed the names of the students, their ID numbers, their averages, and their respective letter grade.
void report(student students_arr[], int students_cpy)
{
    cout << endl << "     " << "Name" << "     " << "ID Number" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    for (int count = 0; count < students_cpy; count++)
    {
        students_arr[count].grade = letter(students_arr[count].average);
        cout << setw(10) << students_arr[count].name << setw(10) << students_arr[count].idNum << setw(19) << students_arr[count].average << setw(18) << students_arr[count].grade << endl;
    }
}

//This function takes as input the array of structures as well as the variable for the number of students so that all the dynamically allocated data can be deleted before the program ends.
//The pre-condition for this function is that every other part of main has executed (except for the return statement).
//This function ends by having deleted the dynamically allocated data for all of the test scores and the array of structures.
void remove(student students_arr[], int students_cpy)
{
    for (int count = 0; count < students_cpy; count++)
    {
        delete[] students_arr[count].score;
    }
    delete[] students_arr;
}
