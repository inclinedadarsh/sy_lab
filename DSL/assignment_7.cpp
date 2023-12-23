/*
Appointment Management: Write a menu driven C++ program for storing
appointment schedules for the day.
Appointments are booked randomly using linked lists. Set start and end
time for visit slots. Write functions for
1. Display free slots
2. Book appointment
3. Cancel appointment ( check validity, time bounds, availability etc)
4. Sort list based on time
5. Sort list based on time using pointer manipulation
*/

#include <iostream>
using namespace std;

int size;

class Slot
{
public:
    int start;
    int end;
    int min;
    int max;
    int flag;
    Slot *next;
};

class Schedule
{
public:
    int size;
    Slot *head;

    void create_schedule()
    {
        int i;
        Slot *temp, *last;

        head = NULL;

        cout << "Enter number of appointment slots: ";
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            temp = new Slot;

            cout << "Slot No. " << i + 1 << ": " << endl;
            cout << "Enter start time: ";
            cin >> temp->start;
            cout << "Enter end time: ";
            cin >> temp->end;
            cout << "Enter maximum duration: ";
            cin >> temp->max;
            cout << "Enter minimum duration: ";
            cin >> temp->min;

            temp->flag = 0;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
                last = head;
            }
            else
            {

                last->next = temp;
                last = last->next;
            }
        }
    }

    void book_slot()
    {
        Slot *temp = head;

        cout << "\nWelcome! We'll start booking our appointment!" << endl;

        int start;
        cout << "Please enter start time: ";
        cin >> start;

        while (temp != NULL)
        {
            if (start == temp->start)
            {
                if (!(temp->flag))
                {
                    cout << "Your slot is booked successfully! Thank you!" << endl;
                    temp->flag = 1;
                }
                else
                {
                    cout << "Slot is not available! Please try booking another slot!" << endl;
                }
            }

            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "No solt with the given timing found!\n"
                 << endl;
        }
    }

    void cancel_solt()
    {
        int start;
        Slot *temp;

        cout << "\nEnter the start time of the appointment you want to cancel: ";
        cin >> start;

        temp = head;

        while (temp != NULL)
        {
            if (start == temp->start)
            {
                if (temp->flag)
                {
                    cout << "Your appointment was canceled!" << endl;
                    temp->flag = 0;
                }
                else
                {
                    cout << "Your slot was never booked :(" << endl;
                }
            }

            temp = temp->next;
        }
    }

    void sort()
    {
        int i, tempVar;
        Slot *temp;

        for (int i = 0; i < size - 1; i++)
        {
            temp = head;

            while (temp->next != NULL)
            {
                if (temp->start > (temp->next)->start)
                {
                    tempVar = temp->start;
                    temp->start = (temp->next)->start;
                    (temp->next)->start = tempVar;

                    tempVar = temp->end;
                    temp->end = (temp->next)->end;
                    (temp->next)->end = tempVar;

                    tempVar = temp->min;
                    temp->min = (temp->next)->min;
                    (temp->next)->min = tempVar;

                    tempVar = temp->max;
                    temp->max = (temp->next)->max;
                    (temp->next)->max = tempVar;

                    tempVar = temp->flag;
                    temp->flag = (temp->next)->flag;
                    (temp->next)->flag = tempVar;
                }

                temp = temp->next;
            }
        }

        cout << "Appointments are now sorted!\n"
             << endl;
    }

    void display_schedule()
    {
        int count = 1;
        Slot *temp = head;

        cout << "-------Appointment Schedule-------" << endl;
        while (temp != NULL)
        {
            cout << "Appointment No. " << count << " : " << endl;
            cout << "\t  Start : " << temp->start << endl;
            cout << "\t    End : " << temp->end << endl;
            cout << "\t    Max : " << temp->max << endl;
            cout << "\t    Min : " << temp->min << endl;
            cout << "\t Status : ";

            if (temp->flag)
                cout << "Booked" << endl
                     << endl;
            else
                cout << "Free" << endl
                     << endl;

            temp = temp->next;
            count++;
        }
    }
};

int main()
{
    Schedule obj;

    int choice;
    char ans;

    do
    {
        cout << "\nWelcome to Appointment Booking Application!" << endl;
        cout << "You can perform the following operations: " << endl;
        cout << "1. Create an appointment schedule" << endl;
        cout << "2. Book a slot" << endl;
        cout << "3. Cancel a booked slot" << endl;
        cout << "4. Display the appointment" << endl;
        cout << "5. Sort the appointments" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.create_schedule();
            break;

        case 2:
            obj.book_slot();
            break;

        case 3:
            obj.cancel_solt();
            break;

        case 4:
            obj.display_schedule();
            break;

        case 5:
            obj.sort();
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}