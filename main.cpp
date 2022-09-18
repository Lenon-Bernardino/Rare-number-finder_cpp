#include "BigInt.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

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
	std::string initial = "0";
	BigInt num = initial;
	BigInt num2 = initial;
	BigInt result = initial;
	std::string num_str = "";
	std::string reversed_num_str = "";
	
	BigInt subtraction = initial;

	while(true)
	{
		//std::cout << "num = " << num << "\n";
		//std::cout << "num2 = " << num2 << "\n";
		//std::cout << "sum = " << num+num2 << "\n";
		//std::cout << "result = " << result << "\n";
		//std::cout << "==================================================================";

		num += 1;
		num_str = num.to_string();
		reversed_num_str = reverse_string(num_str);
		num2 = reversed_num_str;
		
		result = sqrt(num+num2);
		if(result*result == num+num2 && num_str != reversed_num_str)
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
				std::cout << num << "\n";
			}
		}
	}
}
