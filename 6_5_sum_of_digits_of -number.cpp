#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
int print_sum_of_digits(int num);



int main()
{
	cout << print_sum_of_digits(1256);


}

int print_sum_of_digits(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}