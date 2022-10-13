#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <chrono>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arraysize;
    cout<<"Enter the input size: ";
    cin>>arraysize;
    int randArray[arraysize]; 
  
    for(int i=0; i<arraysize; i++)
      randArray[i]=rand()%1000;  

	auto start = chrono::steady_clock::now();
    insertionSort(randArray, arraysize);
	auto end = chrono::steady_clock::now();
    cout<<"Insertion sort takes: "<< chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<" nanoseconds"<<endl;
    return 0;
}