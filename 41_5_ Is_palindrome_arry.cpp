#include<iostream>


using namespace std;


bool Is_palindrome_arry(int arr1[], int size);

void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100] = { 1,2,55,55,2,1 };
	int arr2[100];
	int size = 6;

	cout << Is_palindrome_arry(arr1, size);
	cout << endl;
	print_arr(arr1, size);
	cout << endl;
	print_arr(arr2, size);
}

void reverse_number_in_array(int arr1[], int arr2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[(size - 1) - i];
	}
}
void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
bool Is_palindrome_arry(int arr1[], int size)
{
	int arr2[100];
	reverse_number_in_array(arr1, arr2, size);
	for (int i = 0; i < size / 2; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}