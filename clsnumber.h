#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"clsstring.h"

class clsnumber
{
private:
	int _number = 0;
public:
	clsnumber()
	{
		_number = 0;
	}
	clsnumber(int number)
	{
		_number = number;
	}
	void set_number(int number)
	{
		_number = number;
	}
	int get_number()
	{
		return _number;
	}
	__declspec(property(get = get_number, put = set_number)) int number;

	static int random_number(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}
	int random_number(int to)
	{
		return random_number(0, to);
	}
	int random_number()
	{
		return random_number(0, _number);
	}

	static bool Is_positive_number(int num)
	{
		return	num >= 0;
	}
	bool Is_positive_number()
	{
		return  Is_positive_number(_number);
	}
	static bool Is_even_num(int n)
	{
		return  (n % 2 == 0) ? true : false;
	}
	bool Is_even_num()
	{
		return  Is_even_num(_number);
	}

	static bool Is_odd_num(int n)
	{
		return  !Is_even_num(n);
	}
	bool Is_odd_num()
	{
		return  Is_odd_num(_number);
	}

	static bool Is_prime(int num)
	{
		if (num == 2)
			return true;

		if (num <= 1 || Is_even_num(num))
			return false;

		for (int i = 2; i <= (num / 2); i++)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
	bool Is_prime()
	{
		return  Is_prime(_number);
	}

	static bool Is_perfect_number(int num)
	{
		int devide_by = num / 2;
		int sum = 0;
		for (int i = 1; i <= devide_by; i++)
		{
			if (num % i == 0)
				sum += i;
		}
		return (num == sum);
	}
	bool Is_perfect_number()
	{
		return  Is_perfect_number(_number);
	}

	static void print_perfect_number_from_1_to_n(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (Is_perfect_number(i))
				cout << i << " ";
		}
	}
	void print_perfect_number_from_1_to_n()
	{
		print_perfect_number_from_1_to_n(_number);
	}

	static void print_number_reversed_order(int num)
	{
		while (num > 0)
		{
			cout << num % 10 << endl;
			num = num / 10;
		}
	}
	void print_number_reversed_order()
	{
		print_number_reversed_order(_number);
	}

	static int sum_of_digits(int num)
	{
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num = num / 10;
		}
		return sum;
	}
	int sum_of_digits()
	{
		return sum_of_digits(_number);
	}

	static int reverse_number(int num)
	{
		int sum = 0;
		while (num > 0)
		{
			sum *= 10;
			sum += (num % 10);
			num = num / 10;
		}
		return sum;
	}
	int reverse_number()
	{
		return reverse_number(_number);
	}

	static short count_digit_friqncy(int num, short digit)
	{
		short counter = 0;
		while (num > 0)
		{
			if (num % 10 == digit)
				counter++;
			num = num / 10;
		}
		return counter;
	}
	short count_digit_friqncy(short digit)
	{
		return count_digit_friqncy(_number, digit);
	}

	static void count_all_digits_in_number(int num)
	{
		int counter = 0;
		for (int i = 0; i < 10; i++)
		{
			counter = count_digit_friqncy(num, i);
			if (counter != 0)
				cout << i << "  " << counter << endl;
		}
	}
	void count_all_digits_in_number()
	{
		count_all_digits_in_number(_number);
	}

	static int Power(int base, int power)
	{
		int result = 1;
		for (int i = 0; i < power; i++)
		{
			result *= base;
		}
		return result;
	}
	int Power(int power)
	{
		return Power(_number, power);
	}

	static void print_number_from_left_to_right(int num)
	{
		num = reverse_number(num);
		print_number_reversed_order(num);

	}
	void print_number_from_left_to_right()
	{
		print_number_from_left_to_right(_number);
	}

	static int factorial(int num)
	{
		if (num < 0)
			return -1;
		if (num == 0 || num == 1)
			return 1;
		int result = 1;
		for (int i = 2; i <= num; i++)
		{
			result *= i;
		}
		return result;
	}
	int factorial()
	{
		return factorial(_number);
	}

	static bool Is_palindrom_number(int num)
	{
		return num == reverse_number(num);
	}
	bool Is_palindrom_number()
	{
		return Is_palindrom_number(_number);
	}

	static void inverted_number_pattern(short num)
	{
		for (int i = num; i >= 1; i--)
		{
			for (int j = i; j >= 1; j--)
			{
				cout << i << " ";
			}
			cout << endl;
		}
	}
	void inverted_number_pattern()
	{
		inverted_number_pattern(_number);
	}

	static void number_pattern(short num)
	{
		for (int i = 1; i <= num; i++)
		{
			for (int j = i; j >= 1; j--)
			{
				cout << i << " ";
			}
			cout << endl;
		}
	}
	void number_pattern()
	{
		number_pattern(_number);
	}

	static void multiplication_table(short num)
	{
		for (int i = 1; i <= 12; i++)
		{
			cout << setw(2) << num << " * " << setw(2) << i << " = " << setw(3) << num * i << endl;
		}
	}
	void multiplication_table()
	{
		multiplication_table(_number);
	}

	static float my_abs(float num)
	{
		return num > 0 ? num : num * -1;
	}
	float my_abs()
	{
		return my_abs((float)_number);
	}

	static float get_fraction_part(float num)
	{
		return num - (int)num;
	}
	float get_fraction_part()
	{
		return get_fraction_part((float)_number);
	}

	static float my_round(float num)
	{
		if (my_abs(get_fraction_part(num)) >= 0.5)
			if (num > 0)
				return int(++num);
			else
				return int(--num);
		else
			return int(num);
	}
	float my_round()
	{
		return my_round((float)_number);
	}

	static float my_floor(float num)
	{
		if (num > 0)
			return int(num);
		else
			return int(num) - 1;
	}
	float my_floor()
	{
		return my_floor((float)_number);
	}

	static float my_ceil(float num)
	{
		if (num > 0)
			return int(num) + 1;
		else
			return int(num);
	}
	float my_ceil()
	{
		return my_ceil((float)_number);
	}

	static float my_sqrt(float num)
	{
		return pow(num, 0.5);
	}
	float my_sqrt()
	{
		return my_sqrt((float)_number);
	}

	static int GCD(int num1, int num2)
	{
		while (num2 != 0)
		{
			int temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		return num1;
	}
	int GCD(int num2)
	{
		return GCD(_number, num2);
	}

	static int LCM(int num1, int num2)
	{
		return (num1 * num2) / GCD(num1, num2);
	}
	int LCM(int num2)
	{
		return LCM(_number, num2);
	}

};