#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n <= 2)
    {
        cout << "There is no third element " << endl;
        return 0;
    }
    int first = arr[0];
    int second = 0;
    int third = 0;
    bool ThirdFound = false;
    bool SecondFound = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > first)
        {
            int k = first;
            first=arr[i];
            int j = second;
            second = k;
            SecondFound = true;
            if (j != second)
            {
                third = j;
                ThirdFound = true;
            }
        }
        else if (arr[i] < first)
        {
            if (arr[i] > second || !SecondFound)
            {
                int k = second;
                second = arr[i];
                SecondFound = true;
                if (k != second)
                {
                    third = k;
                    ThirdFound = true;
                }
            }
            else if (arr[i] < second&&SecondFound)
            {
                if (!ThirdFound || arr[i] > third)
                {
                    ThirdFound = true;
                    third = arr[i];
                }
            }
        }
    }
    if(ThirdFound)
    {
        cout<<third;
        return 0;

    }
    cout<<-1;
    return 0;
}
int main(){
int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n <= 2)
    {
        cout << "There is no third element " << endl;
        return 0;
    }
    int maxm=arr[0];
    for(int i =0;i<n;i++)
    {
       maxm= max(maxm,arr[i]);
    }
    int maxm2=int_min;
    bool second=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxm2&&arr[i]<maxm)
        {
            maxm2=arr[i];
            second=true;
        }
    }
    int maxm3=arr[0];
    bool third= false;
    for(int i =0;i<n;i++)
    {
        if(arr[i]>maxm3&&arr[i]<maxm2)
        {
            maxm3=arr[i];
            third=true;
        }
    }
    if(third)
    {
        cout<<maxm3;
        return 0;
    }
    cout<<-1;

}