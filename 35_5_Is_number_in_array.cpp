#include<iostream>


using namespace std;

void fill_array_with_random_number(int arr[], int& size);
int find_number_position_in_arry(int arr[], int num, int& size);
bool Is_number_in_array(int arr[], int num, int& size);

void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int num;
	int size = 0;
	cout << "pleas Enter size of array : ";
	cin >> size;

	fill_array_with_random_number(arr1, size);
	print_arr(arr1, size);
	cout << endl;
	cout << "pleas Enter number to find in array : ";
	cin >> num;
	cout << find_number_position_in_arry(arr1, num, size);
	cout << endl;
	cout << Is_number_in_array(arr1, num, size);




}


int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}
void fill_array_with_random_number(int arr[], int& size)
{

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