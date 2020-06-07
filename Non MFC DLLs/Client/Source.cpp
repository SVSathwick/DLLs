// MathClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MathLibrary.h"
#include "CustomeString.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
        " Fibonacci sequence values fit in an " <<
        "unsigned 64-bit integer." << std::endl;

    char str[10] = "Sathwick ";
    CustomString firstName(str);
    char str2[8] = "Sivvala";
    CustomString lastName(str2);
    CustomString fullName = firstName + lastName;
    cout << fullName << endl;

    cout << "Addition of 3 and 4: " << add(3, 4) << endl;
    //cout << "Square of 3 " << square(3) << endl;
    cout << "Addition of 3, 4 and their square: " << addAndSquare(3, 4) << endl;

    cout << "END" << endl;
  
    return 0;
}