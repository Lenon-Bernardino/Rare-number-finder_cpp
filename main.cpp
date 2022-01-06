#include <iostream>
#include <cmath>
#include <string.h>
#include <Windows.h>
#include <fstream>

using namespace std;

long long int get_reversed_number(long long int number)
{
    long long int reversed_number = 0;
    while (number > 0)
    {
        reversed_number = reversed_number * 10 + number % 10;
        number = number / 10;
    }
    return reversed_number;
}

long long int first_digit(long long int n)
{
    // Find total number of digits - 1
    long long int digits = (long long int)log10(n);

    // Find first digit
    n = (long long int)(n / pow(10, digits));

    // Return first digit
    return n;
}

int main() 
{
    long long int i = 281089082;
    while(true) 
    {
        long long int reversed_number = get_reversed_number(i);
        if(reversed_number != i)
        {
            double root = sqrt(reversed_number + i);
            bool perfect_square_addition = ((floor(root)-root) == 0);
            bool odd_digits = ((to_string(i).length() % 2) != 0);
            bool perfect_square_subtraction = (floor(sqrt(abs(i - reversed_number))) - sqrt(abs(i - reversed_number))) == 0;
            if(perfect_square_addition && perfect_square_subtraction)
            {
                cout << i << "\n";
                std::ofstream outfile;
                outfile.open("rare_numbers.txt", std::ios_base::app);
                outfile << i << "\n";
            }
        }
        i += 1;
        if((first_digit(i) % 2) != 0)
        {
            long long int digits = to_string(i).length()-1;
            i += pow(10, digits);
        }
    }
}
