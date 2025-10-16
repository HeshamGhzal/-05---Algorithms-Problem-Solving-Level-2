#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;
enum enchar_type
{
	smool_letter = 1, captal_letter = 2, special_character = 3, digit = 4
};

char get_rondom_character(enchar_type char_type);

int main()
{
	srand((unsigned)time(NULL));
	cout << get_rondom_character(smool_letter) << endl;
	cout << get_rondom_character(captal_letter) << endl;
	cout << get_rondom_character(special_character) << endl;
	cout << get_rondom_character(digit) << endl;


}



int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

char get_rondom_character(enchar_type char_type)
{
	switch (char_type)
	{
	case smool_letter:
	{
		return char(random_number(97, 122));
		break;
	}
	case captal_letter:
	{
		return char(random_number(65, 90));
		break;
	}
	case special_character:
	{
		return char(random_number(33, 47));
		break;
	}
	case digit:
	{
		return char(random_number(48, 57));
		break;
	}
	return '\o';
	}

}