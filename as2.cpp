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
    // Question 2
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
            if (found == false){
                cout << "Element " << a[i] << " Not found" << endl;
            }
        }
    }
    return 0;
}
