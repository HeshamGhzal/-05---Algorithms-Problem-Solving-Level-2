#include<iostream>


using namespace std;

void fill_array_with_random_number(int arr[], int& size);
int count_negtive_number_in_array(int arr[], int size);

void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100] = { 1,2,55,55,2,1 };
	int arr2[100];
	int size = 10;
	fill_array_with_random_number(arr1, size);
	print_arr(arr1, size);
	cout << endl;
	cout << count_negtive_number_in_array(arr1, size);
	cout << endl;
	/*print_arr(arr1, size);
	cout << endl;
	print_arr(arr2, size);*/
}
int random_number(short from = -100, short to = 100)
{
	return rand() % (to - from + 1) + from;
}
bool Is_even_num(int n)
{
	return  (n % 2 == 0) ? true : false;
}

void fill_array_with_random_number(int arr[], int& size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = random_number();
	}
}
bool Is_odd_number(int num)
{
	return	num % 2 != 0;
}
bool Is_positive_number(int num)
{
	return	num >= 0;
}

int count_negtive_number_in_array(int arr[], int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (!Is_positive_number(arr[i]))
			counter++;
	}
	return counter;
}


void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
