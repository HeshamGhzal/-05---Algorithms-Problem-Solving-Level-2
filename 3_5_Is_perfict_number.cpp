#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;

bool Is_perfect_number(int num);


int main()
{

	cout << Is_perfect_number(28);



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