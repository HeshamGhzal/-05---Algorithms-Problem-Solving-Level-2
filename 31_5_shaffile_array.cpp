#include<iostream>
//#include<string>
//#include<vector>
//#include<ctime>
//#include<iomanip>

using namespace std;
void orderd_array(int arr[], int& to);
void shaffile_array(int arr[], int to);


void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	//int arr3[100];
	int size = 0;
	cout << "pleas Enter End of array : ";
	cin >> size;
	cout << "\n";
	orderd_array(arr1, size);
	print_arr(arr1, size);
	cout << "\n";
	shaffile_array(arr1, size);
	print_arr(arr1, size);



}
int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}
bool Is_even_num(int n)
{
	return  (n % 2 == 0) ? true : false;
}

void orderd_array(int arr[], int& to)
{

	for (int i = 0; i < to; i++)
	{
		arr[i] = i + 1;
	}
}
void shaffile_array(int arr[], int to)
{
	for (int i = 0; i < to; i++)
	{
		swap(arr[random_number(1, to) - 1], arr[random_number(1, to) - 1]);
	}
}
void print_arr(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
