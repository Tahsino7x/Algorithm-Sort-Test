#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

void heapify(int arr[], int n, int i)
{
   int largest = i;
   int l = 2 * i + 1; 
   int r = 2 * i + 2; 


   if (l < n && arr[l] > arr[largest])
    {
       largest = l;
    }

   if (r < n && arr[r] > arr[largest])
    {  
       largest = r;
    }

   if (largest != i)
    {
       swap(arr[i], arr[largest]);
       heapify(arr, n, largest);
   }

}

void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
    {
       heapify(arr, n, i); 
    }

   for (int i = n - 1; i >= 0; i--)
    {
       swap(arr[0], arr[i]); 
       heapify(arr, i, 0);
   }
}

int main()
{
    int size,i;
    cout<<"Enter the input size : ";
    cin>>size;
    int *arr;
    arr = (int *)malloc(size*sizeof(int)); 
  
    srand(time(0)); 
    for(i = 0; i < size; i++)
    {
        int x = rand(); 
        arr[i] = x;    
    }

    auto heap_start = high_resolution_clock::now(); 
    heapSort(arr, size);
    auto heap_stop = high_resolution_clock::now();

    auto heap_duration = duration_cast<nanoseconds>(heap_stop - heap_start);
   
    cout << "Heap Sort takes: " << heap_duration.count() << " nanoseconds" << endl;
   return 0;
}