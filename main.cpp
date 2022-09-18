#include "BigInt.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>

std::string display_vector(std::vector<std::string> thing)
{
    std::string display = "{";
    std::string s;
    for(int i = 0; i < thing.size(); i++)
    {
        s = thing.at(i);
        if(i == 0)
        {
            display += s;
        }
        else
        {
            display += "," + s;
        }
    }
    display += "}";
    return display;
}

std::string reverse_string(std::string str)
{
    std::string new_string = "";
    for(int i = str.length()-1; i <= str.length()-1; i--)
    {
        new_string += str.at(i);
    }
    return new_string;
}

int main()
{
	std::string num_start = "0"; // 89650295750128200205698
	std::string initial = "0";
	BigInt num = num_start;
	BigInt num2 = initial;
	BigInt result = initial;
	std::string num_str = "";
	std::string reversed_num_str = "";
	
	BigInt subtraction = initial;
	bool valid_first_digit;
	int A_digit;
	int B_digit;
	int C_digit;
	int D_digit;
	int M_digit;
	int N_digit;
	int P_digit;
	int Q_digit;

	std::vector<std::string> found_numbers;

	while(true)
	{
		//Sleep(1000);

		num += 1;
		num_str = num.to_string();
		A_digit = (int)num_str[0]-48;
		valid_first_digit = A_digit % 2 == 0;

		if(valid_first_digit == false) // Skips if the first number is odd
		{
			//std::cout << "\nAdding: " << pow(10, num_str.size()-1);
			num += pow(10, num_str.size()-1);
			num_str = num.to_string();
			//std::cout << "\ncorrected to " << num << "\n";
		}
		//Q_digit = std::stoi((num % 10).to_string());
		
		// Implementing some properties with the first 4 and last 4 numbers
		if(num_str.size() >= 4)
		{
			A_digit = (int)num_str[0]-48;
			B_digit = (int)num_str[1]-48;
			P_digit = (int)num_str[num_str.size()-2]-48;
			Q_digit = std::stoi((num % 10).to_string());
			
			if(A_digit == 4)
			{
				if(Q_digit != 0)
				{
					continue;
				}
				if(abs(B_digit-P_digit) % 2 != 0)
				{
					continue;
				}
			}
			if(A_digit == 6)
			{
				if(Q_digit != 0 && Q_digit != 5)
				{
					continue;
				}
				if(abs(B_digit-P_digit) % 2 == 0)
				{
					continue;
				}
			}
			if(A_digit == 8)
			{
				if(Q_digit != 2 && Q_digit != 3 && Q_digit != 7 && Q_digit != 8)
				{
					continue;
				}
				if(Q_digit == 2)
				{
					if(B_digit + P_digit != 9)
					{
						continue;
					}
				}
				if(Q_digit == 3)
				{
					if(B_digit - P_digit != 7 && B_digit - P_digit != -3)
					{
						continue;
					}
				}
				if(Q_digit == 7)
				{
					if(B_digit > 1)
					{
						if(B_digit + P_digit != 11)
						{
							continue;
						}
					}
					if(B_digit < 1)
					{
						if(B_digit + P_digit != 1)
						{
							continue;
						}
					}
				}
				if(Q_digit == 8)
				{
					if(B_digit != Q_digit)
					{
						continue;
					}
				}
			}
		}
		
		// From here on it's logging and slow stuff that needs to be avoided.
		std::cout << "\n==========================================";
		std::cout << "\nnum = " << num << "\n";
		std::cout << "Found numbers: " << display_vector(found_numbers);
		std::cout << "\n==========================================";
		
		//std::cout << "num2 = " << num2 << "\n";
		//std::cout << "sum = " << num+num2 << "\n";
		//std::cout << "result = " << result << "\n";
		//std::cout << "==================================================================";

		reversed_num_str = reverse_string(num_str);
		num2 = reversed_num_str;
		
		result = sqrt(num+num2);
		if(result*result == num+num2 && num_str != reversed_num_str && num > num2)
		{
			if(num >= num2)
			{
				subtraction = num-num2;
			}
			else
			{
				subtraction = num2-num;
			}
			result = sqrt(subtraction);
			if(result*result == subtraction)
			{
				found_numbers.push_back(num.to_string());
			}
		}
	}
}
