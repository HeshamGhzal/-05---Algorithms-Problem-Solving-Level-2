#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void count_all_digits_in_number(int num);



int main()
{
	count_all_digits_in_number(100001);


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

void count_all_digits_in_number(int num)
{
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		counter = count_digit_friqncy(num, i);
		if (counter != 0)
			cout << i << "  " << counter << endl;
	}
}