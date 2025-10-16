#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
bool  guss_3_letter_password_from_AAA_to_ZZZ(string guss);



int main()
{
	guss_3_letter_password_from_AAA_to_ZZZ("AAM");


}



bool guss_3_letter_password_from_AAA_to_ZZZ(string guss)
{
	string word;
	int trial = 0;
	for (int i = int('A'); i <= int('Z'); i++)
	{
		for (int j = int('A'); j <= int('Z'); j++)
		{
			for (int k = int('A'); k <= int('Z'); k++)
			{
				word += char(i);
				word += char(j);
				word += char(k);
				trial++;
				cout << " [" << trial << "] " << word << " \n";

				if (word == guss)
				{
					cout << word << " after[" << trial << "] trial" << " \n";
					return true;
				}
				word = "";
			}
		}
	}
	return false;
}


