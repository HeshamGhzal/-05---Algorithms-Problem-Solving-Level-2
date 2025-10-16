#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void number_pattern(short num);



int main()
{
	number_pattern(10);


}

//void number_pattern(short num)
//{
//	int temp = 1;
//	while (temp <= num)
//	{
//		for (int i = 1; i <= temp; i++)
//		{
//			cout << temp << " ";
//		}
//		temp++;
//		cout << endl;
//	}
//}

void number_pattern(short num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}
