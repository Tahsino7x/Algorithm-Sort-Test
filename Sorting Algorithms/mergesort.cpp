#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays to sort the array into two sorted sub arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays(sorted) back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m); 
    mergeSort(arr,m+1,r); 
    merge(arr,l,m,r); 
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

    auto merge_start = high_resolution_clock::now(); 
    mergeSort(arr, 0, size-1);
    auto merge_stop = high_resolution_clock::now();
    auto merge_duration = duration_cast<nanoseconds>(merge_stop - merge_start);
    cout << "Merge Sort: " << merge_duration.count() << " nanoseconds" << endl;
   return 0;
}