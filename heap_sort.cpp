#include<iostream>
using namespace std;

const int N = 1e5+10;
int arr[N];

//this will build the make the array into heapified array
void heapify(int size, int index)
{
    int largest = index;
    int left = (2*index)+1;
    int right = (2*index)+2;

    //if element at left or right is bigger than largest, change the largest
    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;

    //now, swap them
    if(largest != index)
    { 
        //swapping and heapify it again
        int temp;
        temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;
        heapify(size, largest);
    }
}

//heapify array before starting heap sort
void build_heap(int size)
{
    for(int i = (size/2)-1; i>= 0; i--)
        heapify(size, i);
}

//sort the array elements and heapify everytime heap condition is broken
void heap_sort(int size)
{
    for(int i = size-1; i >= 0; i--)
    {
        //swap 1st and Ith elements
        int temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i]  = temp;
        heapify(i, 0); 
    }
}

//displays the array
void display(int size)
{
    cout << endl;
    for(int i = 0; i < size; i++)
        cout << " " << arr[i];
}

int main()
{
    //take the array input from the user 
    int size;
    cout << "\n Enter the size of the array: ";
    cin >> size;
    cout << "\n Enter the " << size << " elements of the array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "\n The array before sorting: ";
    display(size);
    
    //convert the array into the heap before sorting
    build_heap(size);
   
    //sort the array using heap sort
    heap_sort(size);
    cout << "\n The array after sorting: ";
    display(size);

    return 0; 
}