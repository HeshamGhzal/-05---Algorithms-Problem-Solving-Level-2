#include<iostream>


using namespace std;

float my_ceil(float num);

int main()
{


	cout << ceil(10.7);
	cout << endl;
	cout << my_ceil(10.7);

}


float my_ceil(float num)
{
	if (num > 0)
		return int(num) + 1;
	else
		return int(num);
}