#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;
int random_number(short from, short to);

int main()
{
	srand((unsigned)time(NULL));
	cout << random_number(1, 10) << endl;
	cout << random_number(1, 10) << endl;
	cout << random_number(1, 10) << endl;
	cout << random_number(1, 10) << endl;


}



int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}