#include<iostream>


using namespace std;

float my_sqrt(float num);

int main()
{


	cout << sqrt(9);
	cout << endl;
	cout << my_sqrt(9);

}


float my_sqrt(float num)
{
	return pow(num, 0.5);
}