#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;
void fill_array_with_random_number(int arr[], int& size);
void reverse_number_in_array(int arr1[], int arr2[], int size);

void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	//int arr3[100];
	int size = 0;
	cout << "pleas Enter size of array : ";
	cin >> size;
	cout << "\n";
	fill_array_with_random_number(arr1, size);
	print_arr(arr1, size);
	cout << "\n";
	reverse_number_in_array(arr1, arr2, size);
	print_arr(arr2, size);



}
int random_number(short from, short to)
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
		arr[i] = random_number(1, 100);
	}
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
