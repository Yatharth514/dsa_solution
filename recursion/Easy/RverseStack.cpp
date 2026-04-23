#include <bits/stdc++.h>
using namespace std;
void insertAtBack(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBack(s, x);
    s.push(temp);
}
void reverse_stack(stack<int> &s)
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    reverse_stack(s);
    insertAtBack(s, temp);
}
int main()
{
    int n;
    cout << "Enter the number of the elements you want to insert in the stack : ";
    cin >> n;
    int data;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data : ";
        cin >> data;
        s.push(data);
    }
    cout << "The Original Stack : ";
    stack<int> temp = s;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    reverse_stack(s);
    cout << "Reversed stack : ";
    while (!s.empty())
    {

        int x = s.top();
        s.pop();
        cout << x << " ";
    }
    return 0;
}