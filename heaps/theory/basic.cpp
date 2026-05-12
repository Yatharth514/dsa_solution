#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int i = size;
        arr[i] = val; // we have inserted at the back of the array

        while (i > 1)
        {
            int parent = i / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void delete_heap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete." << endl;
            return;
        }
        else if (size == 1)
        {
            size--;
            return;
        }
        int i = 1;
        arr[i] = arr[size];
        size--;
        while (i <= size)
        {
            int child1 = 2 * i;
            int child2 = 2 * i + 1;
            int largest = i;
            if (child1 <= size && arr[largest] < arr[child1])
            {
                largest = i;
            }
            if (child2 <= size && arr[largest] < arr[child2])
            {
                largest = i;
            }
            if (largest != i)
            {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if (leftChild <= n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild <= n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        i = largest;
        heapify(arr, i, n);
    }
    return;
}
void heap_sort(int arr[], int n)
{
    if (n == 0)
    {
        cout << "No element to sort ." << endl;
        return;
    }
    if (n == 1)
    {
        cout << "Already sorted as only one element exists." << endl;
        return;
    }
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, 1, n);
    }
}

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

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }
    cout << "The max heap :" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heap_sort(arr, n);
    cout << "The sorted array using heap sort : ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
// parent index of the particular node will be i/2th index and the left and right child 's indexes will be 2*i and 2*i+1 respectively
// the indexes of the leaf nodes starts from the (n/2+1)th to nth index
// this code is the basic implementation of the max heap