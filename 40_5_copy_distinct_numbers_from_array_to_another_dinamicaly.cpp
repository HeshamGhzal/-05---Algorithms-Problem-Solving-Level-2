#include<iostream>


using namespace std;


void fill_array_with_random_number(int arr[], int& size);
void copy_distinct_numbers_from_array_to_another_dinamicaly(int arr1[], int arr2[], int size1, int& size2);


void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100] = { 1,1,1,55,55,1,2,2,7,8,7,8, };
	int arr2[100];
	int size = 12;
	int size2 = 0;
	int num = 0;


	//fill_array_with_random_number(arr1, size);
	copy_distinct_numbers_from_array_to_another_dinamicaly(arr1, arr2, size, size2);

	print_arr(arr1, size);
	cout << endl;
	print_arr(arr2, size2);

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
int find_number_position_in_arry(int arr[], int num, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return i;
	}
	return-1;
}
bool Is_number_in_array(int arr[], int num, int& size)
{
	return find_number_position_in_arry(arr, num, size) != -1;
}
void add_array_elment(int arr_elmint, int arr[], int& size)
{
	size++;
	arr[size - 1] = arr_elmint;

}
void copy_distinct_numbers_from_array_to_another_dinamicaly(int arr1[], int arr2[], int size1, int& size2)
{
	for (int i = 0; i < size1; i++)
	{
		if (!Is_number_in_array(arr2, arr1[i], size2))
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