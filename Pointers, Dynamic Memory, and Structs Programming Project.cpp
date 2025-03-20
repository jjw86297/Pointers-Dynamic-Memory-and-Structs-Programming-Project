//This program simulates a grade book.
//This program takes input from a text file with student names and tests scores. The file must be in a specific format where the names and scores are on separate lines.
//Using the names and scores given, the program calculates the average between the scores and lists them for each respective student. It also gives a letter grade based on the average score.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int num_tests = 5;

int read(string[], int[][num_tests], ifstream&);
void averages(int[][num_tests], double[], int);
char letter(double);
void report(string[], double[], int);

//The only pre-conditons for this function are that certain header files are included, namespace std is being used, the constant int for the number of tests is 5, and the appropiate functions are prototyped.
//The program should always end at this function by returning 0, and the rest of the functions should have already executed.
int main()
{
    string names[50];
    int scores[50][num_tests];
    double averages_array[50];

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
    students = read(names, scores, inputFile);

    inputFile.close();

    averages(scores, averages_array, students);
    report(names, averages_array, students);

    return 0;
}

//This function has the text file statement and the name and score arrays passed to it so information can be read from the file and appropiately placed inside both the arrays.
//The pre-conditions for this function are that the file has already been opened and the arrays defined.
//The function ends by having placed info inside of the arrays and returning a count to main which is equal to the amount of students in the file.
int read(string names[], int scores[][num_tests], ifstream& file)
{
    string name = " ";
    int count = 0;

    while (getline(file, name) && count < 50)
    {
        names[count] = name;

        for (int count2 = 0; count2 < num_tests; count2++)
        {
            file >> scores[count][count2];
        }

        file.ignore();
        count++;
    }

    return count;
}

//This function takes as input the scores array and the amount of students so the scores for each student can be passed into the averages array (which is also taken as input).
//The pre-conditions for this function are that the read function has already been executed and the file closed.
//This function ends by having calculated all of the average test scores and having put all of the average test scores inside of the averages array.
void averages(int scores[][num_tests], double averages_array[], int students)
{
    for (int count = 0; count < students; count++)
    {
        double total_score = 0;

        for (int count2 = 0; count2 < num_tests; count2++)
        {
            total_score += scores[count][count2];
        }

        averages_array[count] = total_score / num_tests;
    }
}

//This function only takes as input the average for each student so a respective letter grade can be calculated.
//The pre-condition for this function is that every other function has already been executed.
//This function will execute for how many students there are, and it will end by returning a letter grade for each one.
char letter(double average)
{
    char grade = 0;

    if (average < 60)
        grade = 'F';
    else if (average < 70)
        grade = 'D';
    else if (average < 80)
        grade = 'C';
    else if (average < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

//This function takes as input the names and averages array as well as the amount of students so the information in the arrays can finally be displayed for each student.
//The pre-condition for this function is that every other part of main has executed (except for the return statement).
//This function ends by having displayed the names of the students, their averages, and their respective letter grade.
void report(string names[], double averages_array[], int students)
{
    cout << endl << "     " << "Name" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    for (int count = 0; count < students; count++)
    {
        letter_grade = letter(averages_array[count]);
        cout << setw(10) << names[count] << setw(15) << averages_array[count] << setw(19) << letter_grade << endl;
    }
}

