class Solution {
public:
    string addBinary(string a, string b) {
        int n =a.length();
        int m =b.length();
        char ch='0';
        string res="";
        int i=0;
        int j=0;
        while(i<n&&j<m)
        {
            char c1=a[n-1-i];
            char c2=b[m-1-j];
            if(c1=='1'&&c2=='1')
            {
                if(ch=='1')
                {
                    res="1"+res;
                }
                else
                {
                    res="0"+res;
                }
                ch='1';
            }
            else if((c1=='1'&&c2=='0')||(c1=='0'&&c2=='1'))
            {
                if(ch=='1')
                {
                    res="0"+res;
                    ch='1';
                }
                else
                {
                    res="1"+res;
                    ch='0';
                }
                
            }
            else
            {
                if(ch=='1')
                {
                    res="1"+res;
                }
                else
                {
                    res="0"+res;
                }
                ch='0';
            }
            i++;
            j++;

        }
        while(i<n)
        {
            char c1=a[n-1-i];
            if(c1=='1'&&ch=='1')
            {
                res="0"+res;
                ch='1';
            }
            else if(c1=='0'&&ch=='1')
            {
                res="1"+res;
                ch='0';
            }
            else if(ch=='0')
            {
                res=c1+res;
            }
            i++;
        }
        while(j<m)
        {
            char c2=b[m-1-j];
            if(c2=='1'&&ch=='1')
            {
                res="0"+res;
                ch='1';
            }
            else if(c2=='0'&&ch=='1')
            {
                res="1"+res;
                ch='0';
            }
            else if(ch=='0')
            {
                res=c2+res;
            }
            j++;
        }
        if(ch=='1')
        {
            res="1"+res;
        }
        return res;

        
    }
};