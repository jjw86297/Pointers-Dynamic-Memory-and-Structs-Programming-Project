//This program simulates a grade book.

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int count1 = 0;
int count2 = 0;
int new_count1 = 0;
double average = 0;
int the_final_count = 0;

int read();
double averages();
int letter();
void report();

string names[50];
int scores[50][35];
double averages_array[50];

const int num_scores = read();

int main()
{
    int average_count = 0;

    while (average_count < count1)
    {
        averages_array[average_count] = averages();
        average_count++;
    }

    report();
    return 0;
}

int read()
{
    ifstream inputFile("C:\\Users\\jacob\\Downloads\\StudentGrades.txt");

    int amount_scores = 0;
    string yes_or_no = " ";

    cout << "Do all students have the same amount of scores? Answer 'yes' or 'no' in all lowercase: ";
    cin >> yes_or_no;

    while (amount_scores == 0)
    {
        if (yes_or_no == "yes")
        {
            cout << endl << "How many scores does each student have? ";
            cin >> amount_scores;
        }
        else if (yes_or_no == "no")
        {
            amount_scores = -1;
            cout << endl;
        }
        else
        {
            cout << endl << "You did not enter a correct response! " << endl << endl;
            cout << "Do all students have the same amount of scores? Answer 'yes' or 'no' in all lowercase: ";
            cin >> yes_or_no;
        }
    }

    while (count1 < 50 && inputFile >> names[count1])
    {
        count2 = 0;

        if (yes_or_no == "no")
        {
            cout << "How many test scores does student " << count1 + 1 << " have? ";
            cin >> amount_scores;
        }

        //Below is where it went wrong. Having amount_scores set to a number 
        //like 50 causes it to read every line in the file, put it in the 
        //scores array, and leave nothing for the names array. I tried using
        //methods such as getline, a different kind of loop, etc. but nothing
        //worked. amount_scores is currently set to a user inputted number.
        while (count2 < amount_scores && inputFile >> scores[count1][count2])
        {
            count2++;
        }

        count1++;
    }

    inputFile.close();

    return count1 * count2;
}

double averages()
{
    int new_count2 = 0;
    int holder = 0;
    double average = 0;

    while (new_count1 < count1)
    {
        while (new_count2 < count2)
        {
            holder = scores[new_count1][new_count2];
            average += holder;
            new_count2++;
        }

        average /= count2;
        new_count1++;
        return average;
    }
}

int letter()
{
    char grade = 0;

    if (averages_array[the_final_count] < 60)
        grade = 'F';
    else if (averages_array[the_final_count] < 70)
        grade = 'D';
    else if (averages_array[the_final_count] < 80)
        grade = 'C';
    else if (averages_array[the_final_count] < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

void report()
{
    cout << endl << "     " << "Name" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    while (the_final_count < count1)
    {
        letter_grade = letter();
        cout << setw(10) << names[the_final_count] << setw(15) << averages_array[the_final_count] << setw(19) << letter_grade << endl;
        the_final_count++;
    }

    exit(0);
}