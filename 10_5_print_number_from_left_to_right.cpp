#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void print_number_from_left_to_right(int num);



int main()
{
	print_number_from_left_to_right(1234);


}

short count_digit_friqncy(int num, short digit)
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

int reverse_number(int num)
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

void print_number_reversed_order(int num)
{
	while (num > 0)
	{
		cout << num % 10 << endl;
		num = num / 10;
	}
}

void print_number_from_left_to_right(int num)
{
	num = reverse_number(num);
	print_number_reversed_order(num);

}