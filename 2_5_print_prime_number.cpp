#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;


void print_prime_number_from_1_to_n(int n);
bool Is_even_num(int n);
bool Is_odd_num(int n);

int main()
{



	print_prime_number_from_1_to_n(100);

}

bool Is_even_num(int n)
{
	return  (n % 2 == 0) ? true : false;
}

bool Is_odd_num(int n)
{
	return  !Is_even_num(n);
}

bool Is_prime(int num)
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

void print_prime_number_from_1_to_n(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (Is_prime(i))
			cout << i << " ";
	}
}