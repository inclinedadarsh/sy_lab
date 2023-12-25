/*
Name: Advik Gahukar              SY B-Tech                  
Roll no.: 22                     Sem III
Branch: AI & DS                  Course: Data Structure Lab
Div: B

Assignment-4 : Sparse Matrix.
Problem statement : Write a menu Driven C++ program with class for Sparse Matrix. Write Functions to perform Sparse Matrix operations as listed below:
1. Read Sparse Matrix.
2. Display Sparse Matrix.
3. Add two Sparse Matrices.
4. Find transpose using Simple transpose algorithm.
5. find transpose using Fast transpose algorithm.
*/

#include <iostream>
using namespace std;

class sparce
{
public:
    int mat1[10][3];
    int row, column, count;

public:
    sparce()
    {
        count = 0;
    }

    void getdata()
    {
        cout << "\nEnter the number of rows and columns in the matrix: ";
        cin >> row >> column;
        cout << "\nEnter the NORMAL MATRIX ELEMENT:\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cin >> mat1[count][0];
                mat1[count][1] = i;
                mat1[count][2] = j;
                if (mat1[count][0] != 0)
                    count++;
            }
        }
    }

    void putdata()
    {
        cout << "\nTriplet form of sparse matrix:\n";
        cout << row << "\t" << column << "\t" << count << "\n";
        for (int i = 0; i < count; i++)
        {
            cout << mat1[i][1] << "\t" << mat1[i][2] << "\t" << mat1[i][0] << "\n";
        }
    }

    sparce add(const sparce &obj2)
    {
        sparce obj3;
        int i = 0, j = 0, k = 0;
        obj3.row = row;
        obj3.column = column;
        obj3.count = 0;

        while (i < count && j < obj2.count)
        {
            if (mat1[i][1] < obj2.mat1[j][1] || (mat1[i][1] == obj2.mat1[j][1] && mat1[i][2] < obj2.mat1[j][2]))
            {
                obj3.mat1[k][0] = mat1[i][0];
                obj3.mat1[k][1] = mat1[i][1];
                obj3.mat1[k][2] = mat1[i][2];
                i++;
            }
            else if (mat1[i][1] == obj2.mat1[j][1] && mat1[i][2] == obj2.mat1[j][2])
            {
                obj3.mat1[k][0] = mat1[i][0] + obj2.mat1[j][0];
                obj3.mat1[k][1] = mat1[i][1];
                obj3.mat1[k][2] = mat1[i][2];
                i++;
                j++;
            }
            else
            {
                obj3.mat1[k][0] = obj2.mat1[j][0];
                obj3.mat1[k][1] = obj2.mat1[j][1];
                obj3.mat1[k][2] = obj2.mat1[j][2];
                j++;
            }
            k++;
        }

        while (i < count)
        {
            obj3.mat1[k][0] = mat1[i][0];
            obj3.mat1[k][1] = mat1[i][1];
            obj3.mat1[k][2] = mat1[i][2];
            i++;
            k++;
        }

        while (j < obj2.count)
        {
            obj3.mat1[k][0] = obj2.mat1[j][0];
            obj3.mat1[k][1] = obj2.mat1[j][1];
            obj3.mat1[k][2] = obj2.mat1[j][2];
            j++;
            k++;
        }

        obj3.count = k;
        return obj3;
    }

    void simple_transpose()
    {
        sparce transposed;
        transposed.row = column;
        transposed.column = row;
        transposed.count = count;

        for (int i = 0; i < count; i++)
        {
            transposed.mat1[i][0] = mat1[i][0];
            transposed.mat1[i][1] = mat1[i][2];
            transposed.mat1[i][2] = mat1[i][1];
        }

        cout << "\nSimple Transpose of the sparse matrix (triplet form):\n";
        transposed.putdata();
    }

    void fast_transpose()
    {
        sparce transposed;
        transposed.row = column;
        transposed.column = row;
        transposed.count = count;

        // Create an array to store the number of non-zero elements in each column
        int numNonZeroInColumn[column] = {0};

        // Create an array to store the starting position for each column in the transposed matrix
        int startingPos[column] = {0};

        // Calculate the number of non-zero elements in each column
        for (int i = 0; i < count; i++) {
            int col = mat1[i][2];
            numNonZeroInColumn[col]++;
        }

        // Calculate the starting position for each column in the transposed matrix
        for (int i = 1; i < column; i++) {
            startingPos[i] = startingPos[i - 1] + numNonZeroInColumn[i - 1];
        }

        // Fill the transposed matrix
        for (int i = 0; i < count; i++) {
            int col = mat1[i][2];
            int pos = startingPos[col];
            transposed.mat1[pos][0] = mat1[i][0];
            transposed.mat1[pos][1] = mat1[i][2];
            transposed.mat1[pos][2] = mat1[i][1];
            startingPos[col]++;
        }

        cout << "\nFast Transpose of the sparse matrix (triplet form):\n";
        transposed.putdata();
    }
};

int main()
{
    sparce obj1, obj2, addition;
    int ch, menu;
    do
    {
        cout << "\nSelect the task that you have to perform:";
        cout << "\n1. Read the matrix\n2. Display sparse matrix\n3. Addition of sparse matrix\n4. Simple transpose\n5. Fast transpose \n6. Exit";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj1.getdata();
            obj2.getdata();
            break;

        case 2:
            obj1.putdata();
            obj2.putdata();
            break;

        case 3:
            addition = obj1.add(obj2);
            cout << "\nAddition of two sparse matrices (triplet form):\n";
            addition.putdata();
            break;

        case 4:
            obj1.simple_transpose();
            obj2.simple_transpose();
            break;

        case 5:
            obj1.fast_transpose();
            obj2.fast_transpose();
            break;

        case 6:
            cout << "\nThank you....!";
            exit(0);
            break;

        default:
            cout << "\nPlease enter the valid option: ";
            break;
        }
        cout << "\nDo you want to continue?\nYes = 1 or No = 0: ";
        cin >> menu;
    } while (menu != 0);
    return 0;
}

/*C:\Users\RUCHA\Pictures\Desktop\c++>g++ as_4.cpp

C:\Users\RUCHA\Pictures\Desktop\c++>a

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit1

Enter the number of rows and columns in the matrix: 6 5

Enter the NORMAL MATRIX ELEMENT:
0 0 0 8 0
2 0 0 0 0
0 0 0 0 0
4 0 5 0 0
0 0 0 0 7
0 6 0 0 0

Enter the number of rows and columns in the matrix: 6 5

Enter the NORMAL MATRIX ELEMENT:
0 0 0 2 0
0 0 3 0 0
0 1 0 0 0
2 0 4 0 0
0 0 0 0 0
0 2 0 0 4

Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit2

Triplet form of sparse matrix:
6       5       6
0       3       8
1       0       2
3       0       4
3       2       5
4       4       7
5       1       6

Triplet form of sparse matrix:
6       5       7
0       3       2
1       2       3
2       1       1
3       0       2
3       2       4
5       1       2
5       4       4

Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit3

Addition of two sparse matrices (triplet form):

Triplet form of sparse matrix:
6       5       9
0       3       10
1       0       2
1       2       3
2       1       1
3       0       6
3       2       9
4       4       7
5       1       8
5       4       4

Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit4

Simple Transpose of the sparse matrix (triplet form):

Triplet form of sparse matrix:
5       6       6
3       0       8
0       1       2
0       3       4
2       3       5
4       4       7
1       5       6

Simple Transpose of the sparse matrix (triplet form):

Triplet form of sparse matrix:
5       6       7
3       0       2
2       1       3
1       2       1
0       3       2
2       3       4
1       5       2
4       5       4

Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit5

Fast Transpose of the sparse matrix (triplet form):

Triplet form of sparse matrix:
5       6       6
0       1       2
0       3       4
1       5       6
2       3       5
3       0       8
4       4       7

Fast Transpose of the sparse matrix (triplet form):

Triplet form of sparse matrix:
5       6       7
0       3       2
1       2       1
1       5       2
2       1       3
2       3       4
3       0       2
4       5       4

Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit9

Please enter the valid option:
Do you want to continue?
Yes = 1 or No = 0: 1

Select the task that you have to perform:
1. Read the matrix
2. Display sparse matrix
3. Addition of sparse matrix
4. Simple transpose
5. Fast transpose
6. Exit6

Thank you....!
C:\Users\RUCHA\Pictures\Desktop\c++>*/
