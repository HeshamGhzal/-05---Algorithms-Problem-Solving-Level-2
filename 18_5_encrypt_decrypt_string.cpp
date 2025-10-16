#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;
string encrypt_string(string to_encrypt, short inc = 2);
string decrypt_string(string to_decrypt, short inc = 2);

int main()
{
	cout << encrypt_string("Mohammed") << endl;

	cout << decrypt_string(encrypt_string("Mohammed"));
}


string encrypt_string(string to_encrypt, short enc_key)
{
	string encrypted = "";
	for (char c : to_encrypt)
		encrypted += c + enc_key;
	return  encrypted;
}

string decrypt_string(string to_decrypt, short enc_key)
{
	string encrypted = "";
	for (char c : to_decrypt)
		encrypted += c - enc_key;
	return  encrypted;
}
