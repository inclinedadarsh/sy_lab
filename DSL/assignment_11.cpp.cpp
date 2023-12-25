/*
Sorting: Write a C++ menu driven program to store the percentage of
marks obtained by the students in an array. Write function for sorting array
of floating point numbers in ascending order using
1. Selection Sort
2. Bubble sort
3. Insertion sort
4. Shell Sort
5. Quick sort
6. Radix sort
7. Display top five scores
Implement 4 methods of sorting. Provide choice to user to take input from
user or using random numbers.
Use Standard Template Library (STL) sort function for above data.
*/

// Roll no.22
#include <iostream>
using namespace std;

class Sort
{
private:
	int a[50];
	int n;
	int min;
	int j, temp;
	int i;

public:
	void getdata()
	{
		cout << "Enter the size of array=";
		cin >> n;

		cout << "Enter the elements of array=";
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cout << "Unsorted Array={";
		for (i = 0; i < n; i++)
		{
			cout << a[i];
			if (i < (n - 1))
			{
				cout << ",";
			}
		}
		cout << "}" << endl;
	}

	void selectionsort()
	{
		for (i = 0; i < n; i++)
		{
			min = i;
			for (j = i + 1; j < n; j++)
			{
				if (a[min] > a[j])
					min = j;
			}

			if (min != i)
			{
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}
		cout << "Sorted Array Through Selection sort={";
		for (i = 0; i < n; i++)
		{
			cout << a[i];
			if (i < (n - 1))
			{
				cout << ",";
			}
		}
		cout << "}" << endl;
	}

	void bubblesort()
	{

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i; j < n - 1; j++)
			{
				if (a[i] > a[j + 1])
				{
					temp = a[i];
					a[i] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		cout << "Sorted Array Through BUBBLE Sort={";
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
			if (i < (n - 1))
			{
				cout << ",";
			}
		}
		cout << "}" << endl;
	}

	void insertionsort()
	{
		int t;
		for (int i = 1; i < n; i++)
		{
			t = a[i];
			j = i - 1;

			while (j >= 0 && a[j] > temp)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = t;
		}
		cout << "Sorted Array Through Insertion Sort={";
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
			if (i < (n - 1))
			{
				cout << ",";
			}
		}
		cout << "}" << endl;
	}

	void shellsort()
	{

		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i += 1)
			{
				int temp = a[i];
				int j;
				for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				{
					a[j] = a[j - gap];
				}
				a[j] = temp;
			}
		}
		cout << "Sorted Array Through Shell Sort={";
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
			if (i < (n - 1))
			{
				cout << ",";
			}
		}
		cout << "}" << endl;
	}
};

int main()
{
	Sort obj;
	obj.getdata();
	obj.selectionsort();
	obj.bubblesort();
	obj.insertionsort();
	obj.shellsort();
	return 0;
}
/*PS C:\Users\gaikw\C++\.vscode> cd 'c:\Users\gaikw\C++\.vscode\output'
PS C:\Users\gaikw\C++\.vscode\output> & .\'assignment11.exe'
Enter the size of array=6
Enter the elements of array=25
21
23
25
24
26
Unsorted Array={25,21,23,25,24,26}
Sorted Array Through Selection sort={21,23,24,25,25,26}
Sorted Array Through BUBBLE Sort={21,23,24,25,25,26}
Sorted Array Through Insertion Sort={21,23,24,25,25,26}
Sorted Array Through Shell Sort={21,23,24,25,25,26}
PS C:\Users\gaikw\C++\.vscode\output>*/
