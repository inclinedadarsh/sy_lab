/*
Linked list operations: Create a linked list of names and birthdays of
students. Write a menu driven C++ program to perform following
operations
1. Insert name and birthday of new student
2. Delete a student entry
3. Display a happy birthday message for whom today (based on
system date) is birthday
4. Display list of students with their birthdays
*/

#include <iostream>
#include <ctime>
using namespace std;

class Student
{
public:
    string name;
    int date;
    int month;
    int year;

    Student()
    {
        name = "";
    }

    void get_data()
    {
        cout << "\nEnter name of the student: ";
        cin >> name;
        cout << "Enter date of birth: ";
        cin >> date;
        while (date > 31)
        {
            cout << "Enter a valid date (below 32): ";
            cin >> date;
        }

        cout << "Enter month of birth: ";
        cin >> month;
        while (month > 12)
        {
            cout << "ENter a valid month (below 13): ";
            cin >> month;
        }

        cout << "Enter year of birth: ";
        cin >> year;
    }

    void print()
    {
        cout << "---------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << date << "/" << month << "/" << year << endl;
        cout << "---------------------" << endl;
    }
};

class Node
{
public:
    Student data;
    Node *pointer;

    Node()
    {
        this->pointer = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    Node *createNode()
    {
        Node *newnode = new Node();
        Student data;
        data.get_data();
        newnode->data = data;
        return newnode;
    }

    void append(Node *newnode)
    {

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        Node *temp = head;
        while (temp->pointer != NULL)
        {
            temp = temp->pointer;
        }

        temp->pointer = newnode;
    }

    void insert(Node *newnode, int position)
    {
        if (position < 0)
        {
            cout << "Invalid position. Position should be a non-negative integer." << endl;
            return;
        }

        if (position == 0)
        {
            newnode->pointer = head;
            head = newnode;
            return;
        }

        Node *temp = head;
        int currentPosition = 0;

        while (temp != nullptr && currentPosition < position)
        {
            temp = temp->pointer;
            currentPosition++;
        }

        if (currentPosition - position == 1)
        {
            newnode->pointer = temp->pointer;
            temp->pointer = newnode;
        }
        else
        {
            cout << "Invalid position. Position exceeds the length of the list." << endl;
        }
    }

    void deleteNode(int position)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. Cannot delete a node.\n"
                 << endl;
            return;
        }

        if (position == 0)
        {
            Node *temp = head;
            head = head->pointer;
            delete temp;
            return;
        }

        Node *temp = head;
        int currentPosition = 0;
        Node *prevNode = nullptr;

        while (temp != nullptr && currentPosition < position)
        {
            prevNode = temp;
            temp = temp->pointer;
            currentPosition++;
        }

        if (temp == nullptr)
        {
            cout << "Invalid position. Position exceeds the length of the list." << endl;
            return;
        }

        prevNode->pointer = temp->pointer;
        delete temp;
    }

    void wish()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int wished = 0;

        int currentDay = now->tm_mday;
        int currentMonth = now->tm_mon + 1;

        Node *current = head;

        while (current != nullptr)
        {
            if (current->data.date == currentDay && current->data.month == currentMonth)
            {
                cout << "\nHappy Birthday, " << current->data.name << "!\n"
                     << endl;
                wished = 1;
            }

            current = current->pointer;
        }

        if (!wished)
            cout << "\nNo student has a birthday today. \n";
    }

    void display()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "\nList is empty!\n";
            return;
        }

        temp->data.print();
        temp = temp->pointer;

        while (temp != NULL)
        {
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "v" << endl;
            temp->data.print();
            temp = temp->pointer;
        }
    }
};

int main()
{
    LinkedList list;
    int ch;

    do
    {
        cout << "\nYou can perform the following operations: " << endl;
        cout << "1. Add a new student." << endl;
        cout << "2. Delete a student entry." << endl;
        cout << "3. Wish birthday to student whose birthday is today." << endl;
        cout << "4. Display list of students with their birth date." << endl;
        cout << "5. Exit the program." << endl;
        cout << "Please enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            Node *tempNode1 = list.createNode();
            list.append(tempNode1);
            cout << "Student entry added!" << endl;
            break;
        }

        case 2:
        {
            cout << "\nEnter the position of the student you want to delete: ";
            int delPos;
            cin >> delPos;
            list.deleteNode(delPos);
            cout << "Student entry deleted!" << endl;
            break;
        }

        case 3:
        {
            list.wish();
            break;
        }

        case 4:
        {
            list.display();
            break;
        }

        case 5:
        {
            break;
        }

        default:
        {
            cout << "Wrong choice! Please try again." << endl;
            break;
        }
        }
    } while (ch != 5);
    return 0;
}