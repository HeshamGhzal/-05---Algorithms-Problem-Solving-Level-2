#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;

void print_perfect_number_from_1_to_n(int n);


int main()
{

	print_perfect_number_from_1_to_n(10000);


}


bool Is_perfect_number(int num)
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

void print_perfect_number_from_1_to_n(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (Is_perfect_number(i))
			cout << i << " ";
	}
}