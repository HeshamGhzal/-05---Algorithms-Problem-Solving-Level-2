#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsstring.h"

using namespace std;

class clsword
{
private:
	string _word = "";
public:
	clsword()
	{
		_word = "";
	}
	clsword(string word)
	{
		_word = word;
	}
	void set_word(string word)
	{
		_word = word;
	}
	string get_word()
	{
		return _word;
	}
	__declspec(property(get = get_word, put = set_word)) string word;

	static bool Is_palindrome(string word)
	{
		string rev = clsstring::reverse_string(word);
		return (clsstring::to_lower_string(word) == clsstring::to_lower_string(rev));
	}
	bool Is_palindrome()
	{
		return Is_palindrome(_word);
	}
	static int count_vowels(string word)
	{
		int count = 0;
		string vowels = "aeiouAEIOU";
		for (char c : word)
		{
			if (vowels.find(c) != string::npos)
			{
				count++;
			}
		}
		return count;
	}
	int count_vowels()
	{
		return count_vowels(_word);
	}
	static int count_consonants(string word)
	{
		int count = 0;
		string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
		for (char c : word)
		{
			if (consonants.find(c) != string::npos)
			{
				count++;
			}
		}
		return count;
	}
	int count_consonants()
	{
		return count_consonants(_word);
	}

	static void inverted_letter_pattern(short num)
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
	static void letter_pattern(short num)
	{
		for (int i = 65; i < 65 + num; i++)
		{
			for (int j = 65; j <= i; j++)
			{
				cout << char(i) << " ";
			}
			cout << endl;
		}
	}

	static void all_words_from_AAA_to_ZZZ()
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
	static bool guss_3_letter_password_from_AAA_to_ZZZ(string guss)
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

	static void print_ascii_table()
	{
		for (int i = 0; i < 256; i++)
		{
			cout << i << " = " << char(i) << "\n";
		}
	}

	static string encrypt_string(string to_encrypt, short enc_key)
	{
		string encrypted = "";
		for (char c : to_encrypt)
			encrypted += c + enc_key;
		return  encrypted;
	}
	string encrypt_string(short enc_key)
	{
		return encrypt_string(_word, enc_key);
	}
	static string decrypt_string(string to_decrypt, short enc_key)
	{
		string encrypted = "";
		for (char c : to_decrypt)
			encrypted += c - enc_key;
		return  encrypted;
	}
	string decrypt_string(string to_decrypt, short enc_key)
	{
		string encrypted = "";
		for (char c : to_decrypt)
			encrypted += c - enc_key;
		return  encrypted;
	}

	static int random_number(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}
	enum enchar_type
	{
		smool_letter = 1, captal_letter = 2, special_character = 3, digit = 4
	};
	static char get_rondom_character(enchar_type char_type = captal_letter)
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
	static string genrate_rondom_word(int num_of_char = 4)
	{
		string word;
		for (short i = 0; i < num_of_char; i++)
		{
			word += char(get_rondom_character());
		}
		return word;
	}
	static string genrate_key(int num_of_word = 4)
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

};

