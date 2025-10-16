#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;

void print_multiplication_table(short from, short to);


int main()
{

	print_multiplication_table(1, 12);

}


void print_multiplication_table(short from, short to)
{
	cout << "---multiplication table from [" << from << "] to [" << to << "]---\n";
	cout << string(((to - from + 1) * 4) + 4, '-');
	cout << "\n   ";
	for (short i = from; i <= to; i++)
	{
		cout << setw(4) << i;
	}
	cout << "\n" << string(((to - from + 1) * 4) + 4, '-');

	for (short j = from; j <= to; j++)
	{
		cout << "\n";
		cout << setw(2) << j << "|";
		for (short k = from; k <= to; k++)
		{
			cout << setw(4) << k * j;
		}
	}
	cout << "\n" << string(((to - from) * 4) + 8, '-') << endl;
}