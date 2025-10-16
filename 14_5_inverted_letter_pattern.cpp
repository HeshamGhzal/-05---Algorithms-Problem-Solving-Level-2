#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void inverted_letter_pattern(short num);



int main()
{
	inverted_letter_pattern(5);


}



void inverted_letter_pattern(short num)
{
	for (int i = 64 + num; i > 64; i--)
    {
	   for (int j = 65; j <= i; j++)
	    {
		cout << char(i) << " ";
	     }
	 cout << endl;
    }
}