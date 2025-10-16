#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;


int count_number_frqunt_in_array(int arr[], int size, int num);
void print_arr(int arr[], int size);
void fill_array(int arr[], int& size);

int main()
{

	int arr[100];

	int size = 0;
	int num = 2;
	fill_array(arr, size);
	cout << count_number_frqunt_in_array(arr, size, num);
	cout << "\n";
	print_arr(arr, size);
}

void fill_array(int arr[], int& size)
{
	cout << "pleas Enter size of array : ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "pleas enter the number of array index : [" << i + 1 << "] : ";
		cin >> arr[i];
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