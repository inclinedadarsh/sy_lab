/*
String operations: A palindrome is a string of characters that's identical
when read in forward and backward direction. Typically, punctuation,
capitalization, and spaces are ignored. For example, “1.Poor Dan is in a
droop!!” is a palindrome, as can be seen by examining the characters
“poordanisinadroop” and observing that they are identical when read
forward and backward directions. One way to check for a palindrome is to
reverse the characters in the string and compare them with the original-in a
palindrome, the sequence will be identical.
Write C++ program with functions using Standard Template Library (STL)
stack1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not
*/

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Stack
{
    string str;
    stack<char> strStack;

public:
    Stack(string s)
    {
        str = s;
    }

    void printStringAndRevString()
    {
        for (char c : str)
        {
            if (isalnum(c))
            {
                strStack.push(tolower(c));
            }
        }

        cout << endl;
        cout << "         String: " << str << endl;
        cout << "Reversed String: ";

        while (!strStack.empty())
        {
            cout << strStack.top();
            strStack.pop();
        }

        cout << endl;
    }

    bool isPalindrome(string input)
    {
        string str1 = "";

        for (char c : input)
        {
            if (isalnum(c))
            {
                str1 += tolower(c);
                strStack.push(tolower(c));
            }
        }

        string revStr = "";
        while (!strStack.empty())
        {
            revStr += strStack.top();
            strStack.pop();
        }

        return str1 == revStr;
    }
};

int main()
{
    string input;

    cout << "Enter the string: ";
    getline(cin, input);

    Stack s(input);

    s.printStringAndRevString();

    if (s.isPalindrome(input))
    {
        cout << "\nEntered string is palindrome." << endl;
    }
    else
    {
        cout << "\nEntered string is not palindrome." << endl;
    }

    return 0;
}