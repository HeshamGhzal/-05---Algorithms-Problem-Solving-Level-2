#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;


void fill_array_with_random_number(int arr[], int& size);
void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int size = 0;
	fill_array_with_random_number(arr, size);

	cout << "\n";
	print_arr(arr, size);
}
int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
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
int count_number_frqunt_in_array(int arr[], int size, int num)
{
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (num == arr[i])
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