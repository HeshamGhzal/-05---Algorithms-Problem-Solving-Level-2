#include<iostream>


using namespace std;

float my_floor(float num);

int main()
{


	cout << floor(-10.7);
	cout << endl;
	cout << my_floor(-10.7);

}



float my_floor(float num)
{
	if (num > 0)
		return int(num);
	else
		return int(num) - 1;
}