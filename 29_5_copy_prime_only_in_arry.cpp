#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;


void fill_array_with_random_number(int arr[], int& size);
void  copy_prime_only_in_arry(int arr1[], int arr2[], int& size, int& size2);
void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	int size = 0;
	int size2 = 0;
	fill_array_with_random_number(arr1, size);
	copy_prime_only_in_arry(arr1, arr2, size, size2);
	cout << "\n";
	print_arr(arr1, size);
	cout << "\n";
	print_arr(arr2, size2);

}
int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}
bool Is_even_num(int n)
{
	return  (n % 2 == 0) ? true : false;
}

bool Is_prime(int num)
{
	if (num == 2)
		return true;

	if (num <= 1 || Is_even_num(num))
		return false;

	for (int i = 2; i <= (num / 2); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void fill_array_with_random_number(int arr[], int& size)
{
	cout << "pleas Enter size of array : ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		arr[i] = random_number(1, 100);
	}
}
void copy_prime_only_in_arry(int arr1[], int arr2[], int& size, int& size2)
{
	size2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (Is_prime(arr1[i]))
		{
			arr2[size2++] = arr1[i];
		}
	}
}
void print_arr(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
