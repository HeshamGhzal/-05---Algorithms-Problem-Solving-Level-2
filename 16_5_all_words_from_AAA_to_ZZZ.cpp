#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
void all_words_from_AAA_to_ZZZ();



int main()
{
	all_words_from_AAA_to_ZZZ();


}



void all_words_from_AAA_to_ZZZ()
{
	string word;
	for (int i = int('A'); i <= int('Z'); i++)
	{
		for (int j = int('A'); j <= int('Z'); j++)
		{
			for (int k = int('A'); k <= int('Z'); k++)
			{
				word += char(i);
				word += char(j);
				word += char(k);
				cout << word << "  ";
				word = "";
			}
		}
	}

}


