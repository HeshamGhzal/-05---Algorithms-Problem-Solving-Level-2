#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
int reverse_number(int num);



int main()
{
	cout << reverse_number(123236);


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