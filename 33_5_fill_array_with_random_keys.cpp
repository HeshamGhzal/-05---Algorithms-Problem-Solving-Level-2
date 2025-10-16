#include<iostream>


using namespace std;
enum enchar_type
{
	smool_letter = 1, captal_letter = 2, special_character = 3, digit = 4
};
void fill_array_with_random_keys(string arr[], int& size);

void print_string_arr(string arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	string  arr1[100];

	int size = 0;
	cout << "pleas Enter size of array : ";
	cin >> size;
	fill_array_with_random_keys(arr1, size);
	cout << "\n";
	print_string_arr(arr1, size);




}
int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}
bool Is_even_num(int n)
{
	return  (n % 2 == 0) ? true : false;
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

void fill_array_with_random_keys(string arr[], int& size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = genrate_key();
	}
}


void print_string_arr(string arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Array of [" << i << "] : " << arr[i] + "\n";
	}
}
