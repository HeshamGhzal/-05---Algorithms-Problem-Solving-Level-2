#include<iostream>


using namespace std;

float my_round(float num);
float get_fraction_part(float num);

int main()
{


	cout << round(-10.5);
	cout << endl;
	cout << my_round(-10.5);

}


float my_abs(float num)
{
	return num > 0 ? num : num * -1;
}

float get_fraction_part(float num)
{
	return num - (int)num;
}

float my_round(float num)
{
	if (my_abs(get_fraction_part(num)) >= 0.5)
		if (num > 0)
			return int(++num);
		else
			return int(--num);
	else
		return int(num);
}