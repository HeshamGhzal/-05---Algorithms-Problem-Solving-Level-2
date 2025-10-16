#pragma once
#include<iostream>
#include<string>
#include"number.h"
#include"clsword.h"
using namespace std;

class clsaeeay
{
private:
	int _arr[100];
	string _arrs[100];
public:
	clsaeeay() {};
	static void fill_array(int arr[], int& size)
	{
		cout << "pleas Enter size of array : ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cout << "pleas enter the number of array index : [" << i + 1 << "] : ";
			cin >> arr[i];
		}
	}

	static int count_number_frqunt_in_array(int arr[], int size, int num)
	{
		int counter = 0;

		for (int i = 0; i < size; i++)
		{
			if (num == arr[i])
				counter++;
		}
		return counter;
	}

	static void print_array(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	static int random_number(short from, short to)
	{
		return rand() % (to - from + 1) + from;
	}
	static void fill_array_with_random_number(int arr[], int& size)
	{
		cout << "pleas Enter size of array : ";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = random_number(1, 100);
		}
	}
	void fill_array_with_random_number(int& size)
	{
		fill_array_with_random_number(_arr, size);
	}
	static int maxmum_number_in_array(int arr[], int size)
	{
		int max = 0;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}
	int maxmum_number_in_array(int& size)
	{
		return maxmum_number_in_array(_arr, size);
	}
	static int minmum_number_in_array(int arr[], int size)
	{
		int min = arr[0];

		for (int i = 0; i < size; i++)
		{
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}
	int minmum_number_in_array(int& size)
	{
		return minmum_number_in_array(_arr, size);
	}
	static double average_of_array(int arr[], int size)
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum / size;
	}
	double average_of_array(int& size)
	{
		return average_of_array(_arr, size);
	}
	static int sum_number_in_array(int arr[], int size)
	{
		int sum = 0;

		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
	int sum_number_in_array(int& size)
	{
		return sum_number_in_array(_arr, size);
	}
	static void copy_arry(int arr1[], int arr2[], int& size)
	{
		for (int i = 0; i < size; i++)
		{
			arr2[i] = arr1[i];
		}
	}
	void copy_arry(int arr2[], int& size)
	{
		return copy_arry(_arr, arr2, size);
	}
	static void copy_prime_only_in_arry(int arr1[], int arr2[], int& size, int& size2)
	{
		size2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (clsnumber::Is_prime(arr1[i]))
			{
				arr2[size2++] = arr1[i];
			}
		}
	}
	void copy_prime_only_in_arry(int arr2[], int& size, int& size2)
	{
		copy_prime_only_in_arry(_arr, arr2, size, size2);
	}
	static void som_of_two_arry_to_therd_one(int arr1[], int arr2[], int arr3[], int& size)
	{
		fill_array_with_random_number(arr1, size);
		fill_array_with_random_number(arr2, size);
		for (int i = 0; i < size; i++)
		{
			arr3[i] = arr1[i] + arr2[i];
		}

	}
	void som_of_two_arry_to_therd_one(int arr2[], int arr3[], int& size)
	{
		fill_array_with_random_number(size);
		fill_array_with_random_number(arr2, size);
		for (int i = 0; i < size; i++)
		{
			arr3[i] = _arr[i] + arr2[i];
		}
	}
	static void shaffile_array(int arr[], int to)
	{
		for (int i = 0; i < to; i++)
		{
			swap(arr[random_number(1, to) - 1], arr[random_number(1, to) - 1]);
		}
	}
	void shaffile_array(int to)
	{
		for (int i = 0; i < to; i++)
		{
			swap(_arr[random_number(1, to) - 1], _arr[random_number(1, to) - 1]);
		}
	}
	static void reverse_number_in_array(int arr1[], int arr2[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr2[i] = arr1[(size - 1) - i];
		}
	}
	void reverse_number_in_array(int arr2[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr2[i] = _arr[(size - 1) - i];
		}
	}
	static bool is_array_sorted(int arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}
	bool is_array_sorted(int& size)
	{
		return is_array_sorted(_arr, size);
	}
	static void sort_array(int arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
		}
	}
	void sort_array(int& size)
	{
		sort_array(_arr, size);
	}
	static void fill_array_with_random_keys(string arr[], int& size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = clsword::genrate_key();
		}
	}
	void fill_array_with_random_keys(int& size)
	{
		fill_array_with_random_keys(_arrs, size);
	}
	static int find_number_position_in_arry(int arr[], int num, int& size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == num)
				return i;
		}

		return-1;
	}
	int find_number_position_in_arry(int num, int& size)
	{
		return find_number_position_in_arry(_arr, num, size);
	}
	static bool Is_number_in_array(int arr[], int num, int& size)
	{
		return find_number_position_in_arry(arr, num, size) != -1;
	}
	bool Is_number_in_array(int num, int& size)
	{
		return Is_number_in_array(_arr, num, size);
	}
	static void remove_number_from_array(int arr[], int num, int& size)
	{
		int pos = find_number_position_in_arry(arr, num, size);
		if (pos != -1)
		{
			for (int i = pos; i < size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			size--;
		}
	}
	void remove_number_from_array(int num, int& size)
	{
		remove_number_from_array(_arr, num, size);
	}
	static int read_number(string massige)
	{
		int number;
		cout << massige;
		cin >> number;
		return number;
	}
	static void add_array_elment(int num_to_add, int arr[], int& size)
	{
		size++;
		arr[size - 1] = num_to_add;

	}
	void add_array_elment(int num_to_add, int& size)
	{
		add_array_elment(num_to_add, _arr, size);
	}
	static void add_number_to_arry(int arr[], int& size)
	{
		bool answer = true;
		do {
			add_array_elment(read_number("Enter number to add to array : "), arr, size);
			cout << "Do you like to add more number  [1] to Yes, [0] to No : ";
			cin >> answer;

		} while (answer);
	}
	void add_number_to_arry(int& size)
	{
		add_number_to_arry(_arr, size);
	}
	static void copy_array_dinamicaly(int arr1[], int arr2[], int size1, int size2)
	{

		for (int i = 0; i < size1; i++)
		{
			add_array_elment(arr1[i], arr2, size2);
		}
	}
	void copy_array_dinamicaly(int arr2[], int size1, int& size2)
	{
		copy_array_dinamicaly(_arr, arr2, size1, size2);
	}
	static void copy_odd_numbers_from_array_to_another_dinamicaly(int arr1[], int arr2[], int size1, int& size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (arr1[i] % 2 != 0)
				add_array_elment(arr1[i], arr2, size2);
		}
	}
	void copy_odd_numbers_from_array_to_another_dinamicaly(int arr2[], int size1, int& size2)
	{
		copy_odd_numbers_from_array_to_another_dinamicaly(_arr, arr2, size1, size2);
	}
	static void copy_prime_numbers_from_array_to_another_dinamicaly(int arr1[], int arr2[], int size1, int& size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (clsnumber::Is_prime(arr1[i]))
				add_array_elment(arr1[i], arr2, size2);
		}
	}
	void copy_prime_numbers_from_array_to_another_dinamicaly(int arr2[], int size1, int& size2)
	{
		copy_prime_numbers_from_array_to_another_dinamicaly(_arr, arr2, size1, size2);
	}
	static void copy_distinct_numbers_from_array_to_another_dinamicaly(int arr1[], int arr2[], int size1, int& size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (!Is_number_in_array(arr2, arr1[i], size2))
				add_array_elment(arr1[i], arr2, size2);
		}
	}
	void copy_distinct_numbers_from_array_to_another_dinamicaly(int arr2[], int size1, int& size2)
	{
		copy_distinct_numbers_from_array_to_another_dinamicaly(_arr, arr2, size1, size2);
	}
	static bool Is_palindrome_arry(int arr1[], int size)
	{
		int arr2[100];
		reverse_number_in_array(arr1, arr2, size);
		for (int i = 0; i < size / 2; i++)
		{
			if (arr1[i] != arr2[i])
				return false;
		}
		return true;
	}
	bool Is_palindrome_arry(int& size)
	{
		return Is_palindrome_arry(_arr, size);
	}
	static int count_odd_number_in_array(int arr[], int size)
	{
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (clsnumber::Is_odd_num(arr[i]))
				counter++;
		}
		return counter;
	}
	int count_odd_number_in_array(int& size)
	{
		return count_odd_number_in_array(_arr, size);
	}
	static int count_even_number_in_array(int arr[], int size)
	{
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (!clsnumber::Is_odd_num(arr[i]))
				counter++;
		}
		return counter;
	}
	int count_even_number_in_array(int& size)
	{
		return count_even_number_in_array(_arr, size);
	}
	static int count_positive_number_in_array(int arr[], int size)
	{
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (clsnumber::Is_positive_number(arr[i]))
				counter++;
		}
		return counter;
	}
	int count_positive_number_in_array(int& size)
	{
		return count_positive_number_in_array(_arr, size);
	}
	static int count_negtive_number_in_array(int arr[], int size)
	{
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (!clsnumber::Is_positive_number(arr[i]))
				counter++;
		}
		return counter;
	}
	int count_negtive_number_in_array(int& size)
	{
		return count_negtive_number_in_array(_arr, size);
	}


	~clsaeeay() {};
};

