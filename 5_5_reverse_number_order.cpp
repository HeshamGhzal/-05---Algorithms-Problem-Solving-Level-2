#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void print_number_reversed_order(int num);



int main()
{
	print_number_reversed_order(700);


}

void print_number_reversed_order(int num)
{
	while (num > 0)
	{
		cout << num % 10 << endl;
		num = num / 10;
	}
}