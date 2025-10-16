#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void letter_pattern(short num);



int main()
{
	letter_pattern(5);


}



void letter_pattern(short num)
{
	for (int i = 65; i < 65 + num; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(i) << " ";
		}
		cout << endl;
	}
}

