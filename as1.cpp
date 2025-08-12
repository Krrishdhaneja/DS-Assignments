#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    // Question 1
    // doubt: segmentation fault, bus error, -fsanitize=address
    {
        while (1)
        {
            int input, num_ele;
            char cont;
            int arr[num_ele];
            cout << "---MENU---" << '\n';
            cout << "1.CREATE" << '\n';
            cout << "2.DISPLAY" << '\n';
            cout << "3.INSERT" << '\n';
            cout << "4.DELETE" << '\n';
            cout << "5.LIN. SEARCH" << '\n';
            cout << "6.EXIT" << '\n';
            cin >> input;
            if (input == 1)
            {

                cout << '\n'
                     << "How many elements? ";
                cin >> num_ele;
                cout << "\n"
                     << "Enter the elements in order with space: ";
                for (int i = 0; i < num_ele; ++i)
                {
                    cin >> arr[i];
                }
                cout << endl;
            }
            else if (input == 2)
            {
                cout << "Elements: ";
                for (int i = 0; i < num_ele; ++i)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else if (input == 3)
            {
                int n, total;
                cout << "How many elements u wanna insert? ";
                cin >> n;
                total = num_ele + n;
                int arr2[total];
                for (int i = 0; i < num_ele; ++i)
                {
                    arr2[i] = arr[i];
                }
                for (int i = 0; i < n; ++i)
                {
                    int ele, pos;
                    cout << "Enter the " << i + 1 << "th element and its pos: ";
                    cin >> ele >> pos;
                    for (int j = num_ele + i; j > pos; --j)
                    {
                        arr2[j] = arr2[j - 1];
                    }
                    arr2[pos] = ele;
                }
                for (int i = 0; i < total; ++i)
                {
                    cout << arr2[i] << " ";
                }
                cout << endl;
            }
            else if (input == 4)
            {
                int n, pos;
                cout << "Enter the the num of ele u wanna dlt: ";
                cin >> n;
                int arr3[num_ele - n];
                for (int i = 0; i < n; ++i)
                {
                    cout << "Enter the pos of the " << i + 1 << "th element u wanna dlt: ";
                    cin >> pos;
                    for (int j = pos; j < num_ele - 1; ++j)
                    {
                        arr[j] = arr[j + 1];
                    }
                }
                for (int i = 0; i < num_ele - n; ++i)
                {
                    arr3[i] = arr[i];
                }
                for (int i = 0; i < num_ele - n; ++i)
                {
                    cout << arr3[i] << " ";
                }
                cout << endl;
            }
            else if (input == 5)
            {
                int search;
                cout << "Which element u wanna search? ";
                cin >> search;
                for (int i = 0; i < num_ele; ++i)
                {
                    if (arr[i] == search)
                    {
                        cout << "Found at position " << i << endl;
                        break;
                    }
                }
                cout << endl;
            }
            else if (input == 6)
            {
                break;
            }
        }
    }

    // Question 2
    {
        int a[6] = {0, 1, 1, 3, 4, 6};
        int b[6] = {0, 1, 1, 3, 4, 6};
        int b_size = 6;
        for (int i = 0; i < 6; ++i)
        {
            int sum = 0;
            for (int j = 0; j < b_size; ++j)
            {

                if (a[i] == b[j])
                {
                    ++sum;
                    if (sum > 1)
                    {
                        for (int z = j; z < b_size - 1; ++z)
                        {
                            b[z] = b[z + 1];
                        }
                        --b_size;
                        --j;
                    }
                }
            }
        }
        for (int i = 0; i < b_size; ++i)
        {
            cout << b[i] << " ";
        }
    }

    // Question 3
    {
        // It will print 1 firstly, and then 4 zero values as the default designation is 0
        int i;
        int arr[5] = {1};
        for (i = 0; i < 5; i++)
            printf("%d ", arr[i]);
    }

    // Question 4
    {
        // a.)
        int a[5] = {1, 2, 3, 4, 5};
        for (int i = 4; i >= 0; --i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        // c.)
        int b[2][3] = {{1,23,34,}, {55, 95, 84}};
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        int b_new[3][2];
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                b_new[j][i] = b[i][j];
            }
        }
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 2; ++i)
            {
                cout << b_new[j][i] << " ";
            }
            cout << endl;
        }
        // b.)
        int b_prod[2][3];
        int k = 0;
        for (int i = 0; i < 2; ++i)
        {

            for (int j = 0; j < 2; ++j)
            {
                int product = 0, sum = 0;
                for (int k = 0; k < 3; ++k)
                {
                    b_prod[i][j] += b[i][k] * b_new[k][j];
                }
            }
        }
        for (int k = 0; k < 2; ++k)
        {
            for (int m = 0; m < 2; ++m)
            {
                cout << b_prod[k][m] << " ";
            }
            cout << endl;
        }
    }
    // Question 5
    {
        int a[2][3] = {{1,23,34,}, {55, 95, 84}};
        cout << "sum of all rows is: ";
        for (int i = 0; i < 2; ++i)
        {
            int sum = 0;
            for (int j = 0; j < 3; ++j)
            {
                sum += a[i][j];
            }
            cout << sum << " ";
        }
        cout << endl;
        cout << "sum of all columns is: ";
        for (int j = 0; j < 3; ++j)
        {
            int sum = 0;
            for (int i = 0; i < 2; ++i)
            {
                sum += a[i][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
