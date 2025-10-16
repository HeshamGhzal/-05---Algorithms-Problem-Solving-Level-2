#include<iostream>


using namespace std;

float my_abs(float num);

int main()
{
	cout << abs(10);
	cout << endl;
	cout << my_abs(10);

}

float my_abs(float num)
{
	return num > 0 ? num : num * -1;
}