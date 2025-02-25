//This program displays an array of ten values and then works to reverse the list of values and sticks them in a new array to display.

#include <iostream>
using namespace std;

int* ReverseArray(int const arr[], int size);
void print(int const arr[], int size);

int main()
{
    cout << "Original array:" << endl;

    const int asize = 10;
    int original[asize];

    for (int count = 0; count < asize; count++)
    {
        original[count] = count + 1;

        cout << original[count] << " ";
    }

    int* new_array = nullptr;

    new_array = ReverseArray(original, 10);

    print(new_array, 10);

    return 0;
}

//The full original array needed to be defined first as it is passed to this function.
//The number 10 is also passed to the function for the array's size.
//This function takes the original array to be reversed, and it returns the reversed array back to main.
int* ReverseArray(int const arr[], int size)
{
    int* backwards = nullptr;
    backwards = new int[size];

    int other_count = 9;

    for (int count = 0; count < size; count++)
    {
        backwards[other_count] = arr[count];

        other_count--;
    }

    return backwards;
}

//Every other part of the function must have executed before this final function does.
//It takes the reversed array as input as well as its size of 10.
//This function must delete and nullify the dynamically allocated array before it ends the program with an exit command.
void print(int const arr[], int size)
{
    cout << endl << endl << "Reversed array: " << endl;

    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";

    cout << endl;

    delete [] arr;
    arr = nullptr;

    exit(0);
}
