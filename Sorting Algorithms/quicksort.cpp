#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <chrono> 
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

int partition (int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low); 
    swap(arr[random], arr[low]);

    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    auto quick_start = high_resolution_clock::now();
    quickSort(arr, 0, size-1);
    auto quick_stop = high_resolution_clock::now();
    auto quick_duration = duration_cast<nanoseconds>(quick_stop - quick_start);
    cout << "Quick Sort: " << quick_duration.count() << " nanoseconds" << endl;
   return 0;
}