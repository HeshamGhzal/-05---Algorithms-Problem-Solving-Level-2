#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void inverted_number_pattern(short num);



int main()
{
	inverted_number_pattern(10);


}

//void inverted_number_pattern(short num)
//{
//	while (num > 0)
//	{
//		for (int i = 1; i <= num; i++)
//		{
//			cout << num << " ";
//		}
//		num--;
//		cout << endl;
//	}
//}

void inverted_number_pattern(short num)
{
	for (int i = num; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}
