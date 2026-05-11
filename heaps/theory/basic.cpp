#include<bits/stdc++.h>
using namespace std;
class heap
{
    public:
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
        int i=size;
        arr[i]=val; //we have inserted at the back of the array 

        while(i>1)
        {
            int parent=i/2;
            if(arr[parent]<arr[i])
            {
                swap(arr[i],arr[parent]);
                i=parent;
            }
            else
            {
                return ;
            }
            
        }

    }
    void delete_heap()
    {   if(size==0)
        {
            cout<<"Nothing to delete."<<endl;
            return ;
        }
        else if(size==1)
        {
            size--;
            return ;
        }
        int i =1;
        arr[i]=arr[size];
        size--;
        while(i<=size)
        {
            int child1=2*i;
            int child2=2*i+1;
            int largest=i;
            if(child1<=size&&arr[largest]<arr[child1])
            {
                largest=i;
            }
            if(child2<=size&&arr[largest]<arr[child2])
            {
                largest=i;
            }
            if(largest!=i)
            {
                swap(arr[largest],arr[i]);
                i=largest;
            }
            else
            {
                return ;
            }
        }
    }

    void print()
    {
        for(int i =1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};
int main()
{
    heap h;
    h.insert(56);
    h.insert(68);
    h.insert(45);
    h.insert(96);
    h.insert(54);

    h.print();
    h.delete_heap();
    h.print();
    return 0;


}