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

void keys_genrator(int number_of_keys);


int main()
{
	srand((unsigned)time(NULL));
	keys_genrator(4);


}



int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

char get_rondom_character(enchar_type char_type = captal_letter)
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

string genrate_rondom_word(int num_of_char = 4)
{
	string word;
	for (short i = 0; i < num_of_char; i++)
	{
		word += char(get_rondom_character());
	}
	return word;
}

string genrate_key(int num_of_word = 4)
{

	string line = "";

	for (short i = 0; i < num_of_word; i++)
	{
		if (i < num_of_word - 1)
			line += genrate_rondom_word() + '-';
		else
			line += genrate_rondom_word();
	}
	return line;
}

void keys_genrator(int number_of_keys)
{
	for (short i = 0; i < number_of_keys; i++)
	{
		if (i < number_of_keys - 1)
			cout << "key[" << i + 1 << "] : " << genrate_key() << endl;
		else
			cout << "key[" << i + 1 << "] : " << genrate_key();

	}
}