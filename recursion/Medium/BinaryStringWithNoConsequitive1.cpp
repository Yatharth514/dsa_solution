#include <bits/stdc++.h>
using namespace std;
void maker(int n, string s, vector<string> &str)
{
    int num = s.length();
    if (num == n)
    {
        str.push_back(s);
        return;
    }
    if (num == 0 || (num > 0 && s[num - 1] == '0'))
    {
        maker(n, s + '0', str);
        maker(n, s + '1', str);
    }
    else
    {
        maker(n, s + '0', str);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the string : ";
    cin >> n;
    vector<string> str;
    string s = "";
    

    maker(n, s, str);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    return 0;
}