/**
 * Sort functions on integers
 *
 **/

#include <iostream>
#include <array>

using namespace std;

void printArray(const int items[], int asize) {
  for (int i = 0; i < asize; ++i) {
    cout << items[i] << " ";
  }
  cout << endl;
}

void fillRandom(int items[], int asize) {
  for (int i = 0; i < asize; ++i) {
    items[i] = rand() % 100;
  }
}

int linearSearch(const int items[], int asize, int key) {
  for (int i = 0; i < asize; ++i) {
    if (key == items[i]) {
      return i;
    }
  }
  return -1;
}

int binarySearch(const int items[], int asize, int &key) {
  int low = 0;
  int high = asize - 1;
  int middle{(low + high + 1) / 2};

  while (low <= high) {
    // if the element is found at the middle
    if (key == items[middle]) {
      return middle;
    } else if (key < items[middle]) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
    middle = (low + high + 1) / 2;
  }
  return -1;
}

void insertionSort(int items[], int asize) {
  for (int next = 1; next < asize; ++next) {
    int insert = items[next];
    int moveIndex = next;

    // search for the location in which to put the current element
    while ((moveIndex > 0) && (items[moveIndex - 1] > insert)) {
      // shift element one slot to the right
      items[moveIndex] = items[moveIndex - 1];
      --moveIndex;
    }

    items[moveIndex] = insert;  // place insert item back into array
  }
}

void selectionSort(int items[], int asize) {
  // loop over size - 1 elements
  for (int i = 0; i < asize - 1; ++i) {
    int indexOfSmallest = i;

    // loop to find index of smallest element
    for (int index = i + 1; index < asize; ++index) {
      if (items[index] < items[indexOfSmallest]) {
        indexOfSmallest = index;
      }
    }

    // swap the elements at positions i and indexOfSmallest
    int hold = items[i];
    items[i] = items[indexOfSmallest];
    items[indexOfSmallest] = hold;
  }
}

// merge two sorted subarrays into one sorted subarray
void merge(int items[], int left, int middle1, int middle2, int right) {
  int leftIndex = left;
  int rightIndex = middle2;
  // index into temporary working array
  // [.... left ... middle1 middle2 ... right]
  // only care about left-right area
  int combinedIndex = left;
  int combinedSize = right + 1;
  int combined[combinedSize];  // NOLINT

  // merge arrays until reaching end of either
  while (leftIndex <= middle1 && rightIndex <= right) {
    // place smaller of two current elements into result
    // and move to next space in array
    if (items[leftIndex] <= items[rightIndex]) {
      combined[combinedIndex++] = items[leftIndex++];
    } else {
      combined[combinedIndex++] = items[rightIndex++];
    }
  }

  if (leftIndex == middle2) {
    // if at end of left array copy rest
    while (rightIndex <= right) {
      combined[combinedIndex++] = items[rightIndex++];
    }
  } else {
    // if at end of right array copy rest
    while (leftIndex <= middle1) {
      combined[combinedIndex++] = items[leftIndex++];
    }
  }

  // copy values back into original array
  for (int i = left; i <= right; ++i) {
    items[i] = combined[i];
  }
}

void mergeSort(int items[], int low, int high) {
  // test base case; size of array equals 1
  if ((high - low) >= 1) {
    int middle1 = (low + high) / 2;
    int middle2 = middle1 + 1;

    // split array in half; sort each half (recursive calls)
    mergeSort(items, low, middle1);  // first half of array
    mergeSort(items, middle2, high);  // second half of array

    // merge two sorted arrays after split calls return
    merge(items, low, middle1, middle2, high);
  }
}

void testSimple() {
  const int kArraySize = 20;
  int arr[kArraySize];

  cout << endl << "*** Start testSimple ***" << endl << endl;
  fillRandom(arr, kArraySize);
  cout << "Initial array is:" << endl;
  printArray(arr, kArraySize);
  int value = arr[rand() % kArraySize];
  cout << "Finding " << value << " using linear search" << endl;
  int vindex = linearSearch(arr, kArraySize, value);
  cout << "index for " << value << " is  " << vindex << endl;

  cout << endl << "sorting array using insertion sort" << endl;
  insertionSort(arr, kArraySize);
  cout << "Sorted array is:" << endl;
  printArray(arr, kArraySize);

  cout << endl << "Finding " << value << " using binary search" << endl;
  vindex = binarySearch(arr, kArraySize, value);
  cout << "index for " << value << " is  " << vindex << endl;
  printArray(arr, kArraySize);

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr, kArraySize);
  printArray(arr, kArraySize);
  cout << "sorting array using selection sort" << endl;
  selectionSort(arr, kArraySize);
  cout << "Sorted array is:" << endl;
  printArray(arr, kArraySize);

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr, kArraySize);
  printArray(arr, kArraySize);
  cout << "sorting array using merge sort" << endl;
  mergeSort(arr, 0, kArraySize - 1);
  cout << "Sorted array is:" << endl;
  printArray(arr, kArraySize);
}
