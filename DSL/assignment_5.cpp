/*
Polynomial operations: Write a menu driven C++ program with class for
single variable polynomial and write functions to perform following
polynomial operations using arrays
1. Read polynomial
2. Display polynomial
3. Add two polynomials
You can try above polynomial operation using Linked list
*/

#include <iostream>
using namespace std;

typedef struct
{
    float coef;
    int exp;
} polynomial_term;

const int max_size = 100;

class Polynomial
{
private:
    polynomial_term polynomial[max_size];
    int size;

public:
    Polynomial()
    {
        size = 0;
    }

    void read()
    {
        cout << "\nEnter the total number of the terms you want to enter: ";
        cin >> size;

        cout << "Start entering the polynomial: " << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "Term number " << i + 1 << ": " << endl;
            cout << "Coefficient: ";
            cin >> polynomial[i].coef;
            cout << "Exponent: ";
            cin >> polynomial[i].exp;
        }
    }

    void display()
    {
        cout << polynomial[0].coef << "x^" << polynomial[0].exp;
        for (int i = 1; i < size; i++)
        {
            cout << " + " << polynomial[i].coef << "x^" << polynomial[i].exp;
        }
        cout << endl;
    }

    Polynomial add(Polynomial p2)
    {
        int i = 0, j = 0, k = 0;

        Polynomial p3;

        while (i < size && j < p2.size)
        {
            if (polynomial[i].exp == p2.polynomial[j].exp)
            {
                p3.polynomial[k].coef = polynomial[i].coef + p2.polynomial[j].coef;
                p3.polynomial[k].exp = polynomial[i].exp;

                i++;
                j++;
                k++;
            }
            else if (polynomial[i].exp > p2.polynomial[j].exp)
            {
                p3.polynomial[k].coef = polynomial[i].coef;
                p3.polynomial[k].exp = polynomial[i].exp;

                i++;
                k++;
            }
            else
            {
                p3.polynomial[k].coef = p2.polynomial[j].coef;
                p3.polynomial[k].exp = p2.polynomial[j].exp;

                j++;
                k++;
            }
        }

        while (i < size)
        {
            p3.polynomial[k].coef = polynomial[i].coef;
            p3.polynomial[k].exp = polynomial[i].exp;

            i++;
            k++;
        }

        while (j < p2.size)
        {
            p3.polynomial[k].coef = p2.polynomial[j].coef;
            p3.polynomial[k].exp = p2.polynomial[j].exp;

            j++;
            k++;
        }

        p3.size = k;

        return p3;
    }

    Polynomial operator+(Polynomial p2)
    {
        Polynomial p3;
        p3 = add(p2);
        return p3;
    }
};

int main()
{
    Polynomial p1;
    p1.read();

    int ch;

    do
    {
        cout << "\nYou can perform the following operations: " << endl;
        cout << "1. Display the polynomial." << endl;
        cout << "2. Add two polynomials." << endl;
        cout << "3. Exit program." << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            p1.display();
            break;

        case 2:
        {
            cout << "Enter the second polynormail: " << endl;
            Polynomial p2;
            p2.read();
            Polynomial p3;
            p3 = p1 + p2;
            cout << "Addition of the two polynomials: ";
            p3.display();
            break;
        }

        case 3:
            break;

        default:
            cout << "Wrong choice! Please enter again." << endl;
            break;
        }
    } while (ch != 3);

    return 0;
}