#include<iostream>


using namespace std;
int read_positive_number(string massige);
int read_number(string massige);

void add_number_to_arry(int arr[], int& size);


void print_arr(int arr[], int size);
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int num = 0;

	int size = 0;

	add_number_to_arry(arr1, size);

	print_arr(arr1, size);
	cout << endl;

}

int read_positive_number(string massige)
{
	int number;
	cout << massige;
	cin >> number;
	while (number < 0)
	{
		cout << "Invalid number Enter again : ";
		cin >> number;
	}
	return number;
}
int read_number(string massige)
{
	int number;
	cout << massige;
	cin >> number;
	return number;
}

void add_array_elment(int num_to_add, int arr[], int& size)
{
	size++;
	arr[size - 1] = num_to_add;

}
void add_number_to_arry(int arr[], int& size)
{
	bool answer = true;
	do {
		add_array_elment(read_number("Enter number to add to array : "), arr, size);
		cout << "Do you like to add more number  [1] to Yes, [0] to No : ";
		cin >> answer;

	} while (answer);

}
void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}