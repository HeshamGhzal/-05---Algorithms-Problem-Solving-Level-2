#include<iostream>


using namespace std;


void fill_array_with_random_number(int arr[], int& size);
void copy_array_dinamicaly(int arr1[], int arr2[], int size1, int size2);


void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	int size = 0;
	int size2 = 0;
	int num = 0;


	fill_array_with_random_number(arr1, size);
	copy_array_dinamicaly(arr1, arr2, size, size2);

	print_arr(arr1, size);
	cout << endl;
	print_arr(arr2, size);

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

void add_array_elment(int arr_elmint, int arr[], int& size)
{
	size++;
	arr[size - 1] = arr_elmint;

}
void copy_array_dinamicaly(int arr1[], int arr2[], int size1, int size2)
{

	for (int i = 0; i < size1; i++)
	{
		add_array_elment(arr1[i], arr2, size2);
	}
}
void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}