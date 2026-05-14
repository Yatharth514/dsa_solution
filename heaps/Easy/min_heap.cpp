#include<bits/stdc++.h>
using namespace std;
class heap 
{
    public :
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val)
    {
        size++;
        int i =size;
        arr[i]=val;

        while(i>1)
        {
            int parent=i/2;
            if(arr[parent]>arr[i])
            {
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else
            {
                return ;
            }
        }
    }
    void delete_from_heap()
    {
        if(size==0)
        {
            cout<<"No element to delete."<<endl;
            return ;
        }
        if(size==1)
        {
            size--;
            return ;
        }
        int i=1;
        arr[1]=arr[size];
        size--;
        while(i<=size)
        {
            int smallest=i;
            int leftChild=2*i;
            int rightChild=2*i+1;

            if(leftChild<=size&&arr[smallest]>arr[leftChild])
            smallest=leftChild;
            if(rightChild<=size&&arr[smallest]>arr[rightChild])
            smallest=rightChild;
            if(smallest!=i)
            {
                swap(arr[smallest],arr[i]);
                i=smallest;
            }
            else
            {
                return ;
            }
        }

    }
};
int main()
{
    heap h;
    priority_queue<int, vector<int>, greater<int>>pq;

}