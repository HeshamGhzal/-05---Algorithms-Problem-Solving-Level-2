#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
short count_digit_friqncy(int num, short digit);



int main()
{
	cout << count_digit_friqncy(1231111261, 1);


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