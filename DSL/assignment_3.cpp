/*
String Operations: Write a menu driven C++ program with a class for
String. Write functions
1. To determine the frequency of occurrence of a particular character
in the string.
2. Extract a new string from original string by accepting starting
position and length
3. To accept any character and return the string with by removing all
occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the
string x. Note that w may not be of same size that of x
5. To check whether given string is palindrome or not
*/

#include <iostream>
using namespace std;

class StringFunc
{
private:
    string str;
    int len = 0;

public:
    StringFunc()
    {
        cout << "\nPlease enter a string: ";
        cin >> str;

        len = getLength(str);
    }

    int getLength(string outStr)
    {
        int l = 0;
        for (int i = 0; outStr[i] != '\0'; i++)
        {
            l++;
        }

        return l;
    }

    void findOccurence()
    {
        char ch;
        cout << "\nEnter the character you want to find the occurence of: ";
        cin >> ch;

        int occ = 0;

        for (int i = 0; i < len; i++)
        {
            if (str[i] == ch)
            {
                occ++;
            }
        }

        cout << "The occurence of '" << ch << "' is " << occ << endl;
    }

    void extractString()
    {
        string ext = "";
        int l = 0, s = 0;
        int sIndex = 0;

        cout << "\nEnter the starting point of the string you want to extract (starts from 0): ";
        cin >> s;

        cout << "Enter the length of the string you want to extract: ";
        cin >> l;

        for (int i = s; i <= l; i++)
        {
            ext += str[i];
            sIndex++;
        }

        cout << "The extracted string is: " << ext << endl;
    }

    void removeOccurence()
    {
        string ext = str;
        char ch;

        cout << "\nEnter the character you want to remove: ";
        cin >> ch;

        for (int i = 0; i <= len; i++)
        {
            if (ext[i] == ch)
            {
                for (int j = i; j < len; j++)
                {
                    ext[j] = ext[j + 1];
                }
                i--;
            }
        }

        cout << "The new string is: " << ext << endl;
    }

    void replaceString()
    {
        string oldStr;
        string newStr;
        string ext;

        cout << "\nEnter string you want to remove and replace: ";
        cin >> oldStr;

        cout << "Enter new string you want to put in: ";
        cin >> newStr;

        int oldL = getLength(oldStr);
        int newL = getLength(newStr);

        int oldExists = 1;

        for (int i = 0; i < len - oldL; i++)
        {
            if (str[i] == oldStr[0])
            {
                int oldCount = 1;
                for (int j = i; j <= oldL; j++)
                {
                    if (str[j] != oldStr[oldCount])
                    {
                        break;
                    }
                    else
                    {
                        oldCount++;
                    }
                }
            }
        }
    }

    void isPalindrome()
    {
        string ext = "";

        for (int i = len - 1; i >= 0; i--)
        {
            ext += str[i];
        }

        if (str == ext)
        {
            cout << "The string is PALINDROME" << endl;
        }
        else
        {
            cout << "The string is NOT PALINDROME" << endl;
        }
    }
};

int main()
{
    StringFunc str;
    int ch;

    do
    {
        cout << "\nYou can perform the following operations: " << endl;
        cout << "1. Find occurence of a character in the string." << endl;
        cout << "2. Extract a sub string from the original string." << endl;
        cout << "3. Remove all occurences of a character in the string." << endl;
        cout << "4. Check if the string is palindrome." << endl;
        cout << "5. Exit the program." << endl;
        cout << "Please enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            str.findOccurence();
            break;
        case 2:
            str.extractString();
            break;
        case 3:
            str.removeOccurence();
            break;
        case 4:
            str.isPalindrome();
            break;
        case 5:
            break;
        default:
            cout << "Wrong choice! Please try again.";
            break;
        }
    } while (ch != 5);

    return 0;
}
