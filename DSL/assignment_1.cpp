/*
Name: Advik Gahukar              SY B-Tech
Roll no.: 22                     Sem III
Branch: AI & DS                  Course: Data Structure Lab
Div: B

Assignment-1 : Set Operations.
Problem statement : Write a menu Driven C++ program to store sets for students names participating in different events in Equinox such as Coding contest, Project competition and Mastermind etc.
1. Find out participants who have participated in Coding and Project both.
2. Find out participants who have participated in Coding or Project or both or Mastermind.
3. Find out participants who have participated in Coding but not in MasterMind.
4. Find out participants who have participated in all Events.
5. Find out participants who have participated only in Coding, Project and Mastermind.
*/

#include <iostream>
using namespace std;

class Set
{
	int n1, n2, n3, i, j, k, k1, k2, l = 0, l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, flag;
	string c[100], p[100], m[100], u1[100], u3[100], u4[100], ud2[100];

public:
	void data()
	{
		cout << "Enter Number of students participated in Coding: ";
		cin >> n1;
		cout << "Enter Names of students participated in Coding: ";
		for (i = 0; i < n1; i++)
		{
			cin >> c[i];
		}

		cout << "Enter Number of students participated in Project: ";
		cin >> n2;
		cout << "Enter Names of students participated in Project: ";
		for (i = 0; i < n2; i++)
		{
			cin >> p[i];
		}

		cout << "Enter Number of students participated in Mastermind: ";
		cin >> n3;

		cout << "Enter Names of students participated in Mastermind: ";
		for (i = 0; i < n3; i++)
		{
			cin >> m[i];
		}
	}

	void d1()
	{
		cout << "\nStudents participated in Coding and Project both: ";

		for (i = 0; i < n1; i++)
		{

			for (j = 0; j < n2; j++)
			{
				if (c[i] == p[j])
				{

					cout << c[i] << " ";
				}
			}
		}
	}

	void d2()
	{
		cout << "\nStudents participated only in Coding, Project and Mastermind :";

		for (i = 0; i < n1; i++)
		{
			flag = 0;
			for (j = 0; j < n2; j++)
			{
				if (c[i] == p[j])
				{
					flag = 1;
					break;
				}
			}

			for (k = 0; k < n3; k++)
			{
				if (c[i] == m[k])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				ud2[l2] = c[i];
				l2++;
			}
		}

		for (i = 0; i < n2; i++)
		{
			flag = 0;
			for (j = 0; j < n2; j++)
			{
				if (p[i] == c[j])
				{
					flag = 1;
					break;
				}
			}

			for (k = 0; k < n3; k++)
			{
				if (p[i] == m[k])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				ud2[l2] = p[i];
				l2++;
			}
		}

		for (i = 0; i < n3; i++)
		{
			flag = 0;
			for (j = 0; j < n1; j++)
			{
				if (m[i] == c[j])
				{
					flag = 1;
					break;
				}
			}

			for (k = 0; k < n3; k++)
			{
				if (m[i] == p[k])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				ud2[l2] = m[i];
				l2++;
			}
		}

		for (i = 0; i < l2; i++)
		{
			cout << ud2[i] << " ";
		}
	}

	void d3()
	{
		cout << "\nStudents participated in Coding but not in Mastermind: ";
		k2 = n1;

		for (i = 0; i < k2; i++)
		{
			flag = 0;
			for (j = 0; j < n3; j++)
			{
				if (c[i] == m[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				u3[l] = c[i];
				l++;
			}
		}

		for (i = 0; i < k2; i++)
		{
			cout << u3[i] << " ";
		}
	}

	void d4()
	{
		cout << "\nStudents participated in Coding or Project or Mastermind: " << endl;

		for (i = 0; i < n1; i++)
		{
			u1[i] = c[i];
		}
		k1 = n1;
		for (j = 0; j < n2; j++)
		{
			flag = 0;

			for (i = 0; i < k1; i++)
			{
				if (c[i] == p[j])
				{

					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				u1[k1] = p[j];
				k1++;
			}
		}

		for (j = 0; j < n3; j++)
		{
			flag = 0;
			for (i = 0; i < k1; i++)
			{
				if (u1[i] == m[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				u1[k1] = m[j];
				k1++;
			}
		}

		for (i = 0; i < k1; i++)
		{
			cout << u1[i] << " ";
		}
	}

	void d5()
	{
		cout << "\nStudents participated in All events: ";

		for (i = 0; i < n1; i++)
		{
			for (j = 0; j < n2; j++)
			{
				for (k = 0; k < n3; k++)
				{
					if (c[i] == p[j] && c[i] == m[k])
					{
						u4[l1] = c[i];
						l1++;
					}
				}
			}
		}

		for (i = 0; i < l1; i++)
		{
			cout << u4[i] << " ";
		}
	}
};

int main()
{
	int choice;
	string a;
	bool flag1;
	Set obj;
	obj.data();

	do
	{
		cout << "1. Students participated in Coding and Project both" << endl;
		cout << "2. Students participated only in coding, project or mastermind" << endl;
		cout << "3. Students participated in Coding but not in Mastermind" << endl;
		cout << "4. Students participated in Coding or Project or Mastermind" << endl;
		cout << "5. Students participated in All events" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			obj.d1();
			break;
		case 2:
			obj.d2();
			break;
		case 3:
			obj.d3();
			break;
		case 4:
			obj.d4();
			break;
		case 5:
			obj.d5();
			break;
		default:
			cout << "Wrong Choice!! Try Again!!" << endl;
		}

		cout << "\n\nWant to Check Again! Type 'yes', else Type 'no': ";
		cin >> a;

		if (a == "yes")
		{
			flag1 = true;
		}
		else
		{
			flag1 = false;
		}

	} while (flag1);

	return 0;
}
