#include <iostream>
using namespace std;
int main()
{
    // Question 1
    {
        int a[5] = {1, 34, 53, 567, 5436};
        int low = 0, high = 4, input;
        for (int i = 0; i < 5; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "Enter element: ";
        cin >> input;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == input)
            {
                cout << "found at " << mid + 1 << endl;
                break;
            }
            else if (input > a[mid])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    // // Question 2
    {
        int a[7] = {64, 34, 25, 12, 22, 90, 11};
        int temp = 0;
        cout << "Unsorted: ";
        for (int i = 0; i < 7; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "Sorted: ";
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = temp;
                }
            }
        }
        for (int i = 0; i < 7; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    // Question 3
    {
        int a[5] = {1, 34, 53, 567, 5436};
        int b[5] = {1, 34, 53, 5436};

        for (int i = 0; i < 5; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 5; ++i)
        {
            int low = 0, high = 4;
            bool found = false;
            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (a[i] > b[mid])
                {
                    low = mid + 1;
                }
                else if (a[i] < b[mid])
                    high = mid - 1;
                else if (b[mid] == a[i])
                {

                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Element " << a[i] << " Not found" << endl;
            }
        }
    }
    // // Question 4
    {
        // a.)
        {
            string s1, s2;
            cout << "Enter the 2 strings: ";
            getline(cin, s1);
            getline(cin, s2);
            string s3 = s1 + s2;
            cout << s3;
        }
        // b.)
        {
            string s1 = "krrish";
            for (int i = s1.size() - 1; i >= 0; --i)
            {
                cout << s1[i];
            }
            cout << endl;
        }
        // c.)
        {
            string s1 = "krrish";
            string s2 = "";
            cout << s1;
            cout << endl;
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'o' && s1[i] != 'u' && s1[i] != 'i' && s1[i] != 'A' && s1[i] != 'E' && s1[i] != 'I' && s1[i] != 'O' && s1[i] != 'U')
                {
                    s2.push_back(s1[i]);
                }
            }
            cout << s2;
            cout << endl;
        }
        // d.)
        {
            string s1 = "krrish";
            cout << s1 << endl;
            for (int i = 0; i < s1.size() - 1; ++i)
            {
                char temp;
                for (int j = 0; j < s1.size() - 1; ++j)
                {
                    if (s1[j] > s1[j + 1])
                    {
                        temp = s1[j + 1];
                        s1[j + 1] = s1[j];
                        s1[j] = temp;
                    }
                }
            }
            cout << s1 << endl;
        }
        // e.)
        {
            string s1 = "krrish";
            cout << s1 << endl;
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s1[i] >= 'a' && s1[i] <= 'z')
                    s1[i] -= 32;
            }
            cout << s1 << endl;
        }
    }
    // Question 5
    {
        // a
        // {
        //     int arr[4][4] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};
        //     int size = 0;
        //     for (int i = 0; i < 4; ++i)
        //     {
        //         for (int j = 0; j < 4; ++j)
        //         {
        //             cout << arr[i][j] << " ";
        //         }
        //         cout << '\n';
        //     }
        //     for (int i = 0; i < 4; ++i) //TODO: delete
        //     {
        //         for (int j = 0; j < 4; ++j)
        //         {
        //             if (arr[i][j] != 0)
        //                 ++size;
        //         }
        //     }
        //     int new_arr[size], k = 0;
        //     for (int i = 0; i < 4; ++i)
        //     {
        //         for (int j = 0; j < 4; ++j)
        //         {
        //             if (arr[i][j] != 0)
        //             {
        //                 new_arr[0][k] = i; // TODO: delete this
        // We dont need column info for a diag. matrix as there is only one way to arrange them in a column
        //                 new_arr[k] = arr[i][j];
        //
        //                 ++k;
        //             }
        //         }
        //     }
        //     cout << endl;
        //     for (int i = 0; i < 2; ++i)
        //     {
        //         for (int j = 0; j < size; ++j)
        //         {
        //             cout << new_arr[i][j] << " ";
        //         }
        //         cout << '\n';
        //     }
        // }

        // b.)
        {
            int arr[5][5] = {{1, 2, 0, 0, 0}, {1, 2, 3, 0, 0}, {0, 1, 2, 3, 0}, {0, 0, 1, 2, 3}, {0, 0, 0, 1, 2}};
            int size = 0;
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    cout << arr[i][j] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
            int new_arr[4][5], k = 0;
            for (int i = 0; i < 5; ++i)
            {
                new_arr[0][k] = i;
                for (int j = 0; j < 5; ++j)
                {
                    if (arr[i][j] != 0)
                    {

                        if (i == 0)
                        {
                            new_arr[1][0] = arr[0][0];
                            new_arr[2][0] = arr[0][1];
                            new_arr[3][0] = arr[0][2];
                        }
                        else if (i == 4)
                        {
                            new_arr[1][4] = arr[4][2];
                            new_arr[2][4] = arr[4][3];
                            new_arr[3][4] = arr[4][4];
                        }
                        else
                        {
                            new_arr[1][i] = arr[i][j];
                            new_arr[2][i] = arr[i][j + 1];
                            new_arr[3][i] = arr[i][j + 2];
                            break;
                        }
                    }
                }
                ++k;

            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    cout << new_arr[i][j] << " ";
                }
                cout << '\n';
            }
        }
        // c.)
        {
                int mat[4][4] = {{1, 0, 0, 0}, {1, 2, 0, 0}, {1, 2, 3, 0}, {1, 2, 3, 4}};
                int size = 0;
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (mat[i][j] != 0)
                            ++size;
                    }
                }
                cout << size << endl;
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        cout << mat[i][j] << " ";
                    }
                    cout << '\n';
                }
                cout << '\n';
                int arr[size];
                int k = 0;
                for (int j = 0; j < 4; ++j)
                {

                    for (int i = 0; i < 4; ++i)
                    {
                        if (mat[i][j] != 0)
                        {
                            arr[k] = mat[i][j];
                            ++k;
                        }

            //             // if (mat[i][j] != 0) // DONT REMOVE THIS
            //             // {
            //             //     for (int sum = 0; sum < 4; ++sum)
            //             //     {
            //             //         if (i - j == sum)
            //             //             arr[j + ((j * (9 - j)) / 2)] = mat[i][j]; // this term j(9-j)/2 came from the nth term of the series {0,4,7,9...} where An=(1-n)*(n-10)/2 and n = j+1` }
            //             //     }
                    }
                }
                for (int i = 0; i < size; ++i)
                    cout << arr[i] << " ";
                cout << endl;
        }
    }
        {
            int mat[3][3] = {{1, 2, 3},
                             {2, 1, 3},
                             {3, 3, 3}};
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    cout << mat[i][j] << " ";
                }
                cout << '\n';
            }
            cout << "Storing it in a 1D array row wise" << endl;
            int arr[9], k = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[k] = mat[i][j];
                    ++k;
                }
            }
            for (int i = 0; i < 9; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    
    // Question 6
    {

        const int n = 4;
        int mat[n][n] = {
            {1, 0, 0, 0},
            {2, 0, 3, 0},
            {0, 0, 0, 4},
            {0, 0, 0, 0}};

        int row[16], col[16], val[16];
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != 0)
                {
                    row[num] = i;
                    col[num] = j;
                    val[num] = mat[i][j];
                    num++;
                }
            }
        }

        cout << "Original Matrix:\n";
        for (int i = 0, k = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k < num && row[k] == i && col[k] == j)
                    cout << val[k++] << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }

        int trow[16], tcol[16], tval[16];
        int tnum = num;
        int k = 0;
        for (int c = 0; c < n; c++)
        {
            for (int m = 0; m < num; m++)
            {
                if (col[m] == c)
                {
                    trow[k] = col[m];
                    tcol[k] = row[m];
                    tval[k] = val[m];
                    k++;
                }
            }
        }
        cout << "\nTranspose:\n";
        for (int i = 0, k2 = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k2 < tnum && trow[k2] == i && tcol[k2] == j)
                    cout << tval[k2++] << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }

        int arow[32], acol[32], aval[32];
        int anum = 0;
        int i = 0, j = 0;
        while (i < num && j < num)
        {
            if (row[i] < row[j] || (row[i] == row[j] && col[i] < col[j]))
            {
                arow[anum] = row[i];
                acol[anum] = col[i];
                aval[anum] = val[i];
                anum++;
                i++;
            }
            else if (row[j] < row[i] || (row[i] == row[j] && col[j] < col[i]))
            {
                arow[anum] = row[j];
                acol[anum] = col[j];
                aval[anum] = val[j];
                anum++;
                j++;
            }
            else
            {
                int sumv = val[i] + val[j];
                if (sumv != 0)
                {
                    arow[anum] = row[i];
                    acol[anum] = col[i];
                    aval[anum] = sumv;
                    anum++;
                }
                i++;
                j++;
            }
        }
        while (i < num)
        {
            arow[anum] = row[i];
            acol[anum] = col[i];
            aval[anum] = val[i];
            anum++;
            i++;
        }
        while (j < num)
        {
            arow[anum] = row[j];
            acol[anum] = col[j];
            aval[anum] = val[j];
            anum++;
            j++;
        }

        cout << "\nAddition (mat + mat):\n";
        for (int r = 0, k3 = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (k3 < anum && arow[k3] == r && acol[k3] == c)
                    cout << aval[k3++] << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }

        int mrow[16], mcol[16], mval[16];
        int mnum = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int sum = 0;
                for (int k1 = 0; k1 < num; k1++)
                {
                    if (row[k1] != r)
                        continue;
                    for (int k2 = 0; k2 < tnum; k2++)
                    {
                        if (trow[k2] != c)
                            continue;
                        if (col[k1] == tcol[k2])
                            sum += val[k1] * tval[k2];
                    }
                }
                if (sum != 0)
                {
                    mrow[mnum] = r;
                    mcol[mnum] = c;
                    mval[mnum] = sum;
                    mnum++;
                }
            }
        }

        cout << "\nMultiplication (mat * mat^T):\n";
        for (int r = 0, k4 = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (k4 < mnum && mrow[k4] == r && mcol[k4] == c)
                    cout << mval[k4++] << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }
    }

    // Question 7
    {
        int arr[9] = {1, 23, 243, 4, 46, 3, 2, 34, 245};
        int inversions = 0;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (i < j && arr[i] > arr[j])
                {
                    cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
                    ++inversions;
                }
            }
        }
        cout << "Inversions: " << inversions << endl;
    }

    // Question 8
    {

    }
    // // Additional Questions
    {
        // Q1
        {
            int arr[6] = {8, 16, 12, 16, 4, 0};
            int k = 4, sum = 0;
            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 6; ++j)
                {
                    if (arr[i] - arr[j] == k)
                        ++sum;
                }
            }

            cout << "Pairs: " << sum << endl;
        }
        // Q2
        {
            int t;
            cin >> t;
            while (t--)
            {
                string str;
                cin >> str;
                bool boolie = false;
                for (int i = 0; i < str.size(); ++i)
                {
                    int sum = 0;
                    for (int j = 0; j < str.size(); ++j)
                    {
                        if (str[i] == str[j])
                        {
                            ++sum;
                        }
                    }
                    if (sum >= 3)
                    {
                        cout << "YES" << endl;
                        boolie = true;
                        break;
                    }
                }
                if (!boolie)
                    cout << "NO" << endl;
            }
        }
        // Ques 3
        {
            int t;
            cin >> t;
            while (t--)
            {

                string str1, str2;
                cin >> str1 >> str2;
                for (int i = 0; i < str1.size() - 1; ++i)
                {
                    char temp;
                    for (int j = 0; j < str1.size() - 1; ++j)
                    {
                        if (str1[j] > str1[j + 1])
                        {
                            temp = str1[j + 1];
                            str1[j + 1] = str1[j];
                            str1[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < str2.size() - 1; ++i)
                {
                    char temp;
                    for (int j = 0; j < str2.size() - 1; ++j)
                    {
                        if (str2[j] > str2[j + 1])
                        {
                            temp = str2[j + 1];
                            str2[j + 1] = str2[j];
                            str2[j] = temp;
                        }
                    }
                }
                if (str1 == str2)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        return 0;
    }
}