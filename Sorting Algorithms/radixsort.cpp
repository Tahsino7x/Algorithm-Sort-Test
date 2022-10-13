#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <chrono> 
using namespace std;
using namespace std::chrono;

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];
  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {
 
  int max = getMax(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

    auto quick_start = high_resolution_clock::now();
    radixSort(arr, 0, size-1);
    auto quick_stop = high_resolution_clock::now();
    auto quick_duration = duration_cast<nanoseconds>(quick_stop - quick_start);
    cout << "Radix Sort: " << quick_duration.count() << " nanoseconds" << endl;
   return 0;
}