/**
 * Sort functions using STL array and templates
 * Based on Deitel
 **/


#include <iostream>
#include <array>

using namespace std;

template<typename T, size_t size>
void printArray(const array<T, size> &items) {
  for (int i = 0; i < size; ++i) {
    cout << items[i] << " ";
  }
  cout << endl;
}

template<typename T, size_t size>
void fillRandom(array<T, size> &items) {
  for (int i = 0; i < size; ++i) {
    items[i] = rand() % 100;
  }
}

template<typename T, size_t size>
int linearSearch(const array<T, size> &items, const T &key) {
  for (size_t i{0}; i < items.size(); ++i) {
    if (key == items[i]) {  // if found,
      return i;  // return location of key
    }
  }
  return -1;  // key not found
}

template<typename T, size_t size>
int binarySearch(const array<T, size> &items, const T &key) {
  int low{0};  // low index of elements to search
  int high{static_cast<int>(items.size()) - 1};  // high index
  int middle{(low + high + 1) / 2};  // middle element
  int location{-1};  // key's index; -1 if not found

  do {  // loop to search for element
    // if the element is found at the middle
    if (key == items[middle]) {
      location = middle;  // location is the current middle
    } else if (key < items[middle]) {  // middle is too high
      high = middle - 1;  // eliminate the higher half
    } else {  // middle element is too low
      low = middle + 1;  // eliminate the lower half
    }
    middle = (low + high + 1) / 2;  // recalculate the middle
  } while ((low <= high) && (location == -1));

  return location;  // return location of key
}

template<typename T, size_t size>
void insertionSort(array<T, size> &items) {
  // loop over the elements of the array
  for (size_t next{1}; next < items.size(); ++next) {
    T insert{items[next]};  // save value of next item to insert
    size_t moveIndex{next};  // initialize location to place element

    // search for the location in which to put the current element
    while ((moveIndex > 0) && (items[moveIndex - 1] > insert)) {
      // shift element one slot to the right
      items[moveIndex] = items[moveIndex - 1];
      --moveIndex;
    }

    items[moveIndex] = insert;  // place insert item back into array
  }
}

template<typename T, size_t size>
void selectionSort(array<T, size> &items) {
  // loop over size - 1 elements
  for (size_t i{0}; i < items.size() - 1; ++i) {
    size_t indexOfSmallest{i};  // will hold index of smallest element

    // loop to find index of smallest element
    for (size_t index{i + 1}; index < items.size(); ++index) {
      if (items[index] < items[indexOfSmallest]) {
        indexOfSmallest = index;
      }
    }

    // swap the elements at positions i and indexOfSmallest
    T hold{items[i]};
    items[i] = items[indexOfSmallest];
    items[indexOfSmallest] = hold;
  }
}


// merge two sorted subarrays into one sorted subarray
template<typename T, size_t size>
void merge(array<T, size> &items,
           size_t left, size_t middle1, size_t middle2, size_t right) {
  size_t leftIndex{left};  // index into left subarray
  size_t rightIndex{middle2};  // index into right subarray
  size_t combinedIndex{left};  // index into temporary working array
  array<T, size> combined;  // working array

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

  if (leftIndex == middle2) {  // if at end of left array
    while (rightIndex <= right) {  // copy in rest of right array
      combined[combinedIndex++] = items[rightIndex++];
    }
  } else {  // at end of right array
    while (leftIndex <= middle1) {  // copy in rest of left array
      combined[combinedIndex++] = items[leftIndex++];
    }
  }

  // copy values back into original array
  for (size_t i = left; i <= right; ++i) {
    items[i] = combined[i];
  }
}

template<typename T, size_t size>
void mergeSort(array<T, size> &items, size_t low, size_t high) {
  // test base case; size of array equals 1
  if ((high - low) >= 1) {  // if not base case
    size_t middle1{(low + high) / 2};  // calculate middle of array
    size_t middle2{middle1 + 1};  // calculate next element over

    // split array in half; sort each half (recursive calls)
    mergeSort(items, low, middle1);  // first half of array
    mergeSort(items, middle2, high);  // second half of array

    // merge two sorted arrays after split calls return
    merge(items, low, middle1, middle2, high);
  }
}

void testTemplate() {
  const int arraysize = 20;
  array<int, arraysize> arr;

  cout << endl << "*** Start testTemplate ***" << endl << endl;
  fillRandom(arr);
  cout << "Initial array is:" << endl;
  printArray(arr);
  int value = arr[rand() % arraysize];
  cout << "Finding " << value << " using linear search" << endl;
  int vindex = linearSearch(arr, value);
  cout << "index for " << value << " is  " << vindex << endl;

  cout << endl << "sorting array using insertion sort" << endl;
  insertionSort(arr);
  cout << "Sorted array is:" << endl;
  printArray(arr);

  cout << endl << "Finding " << value << " using binary search" << endl;
  vindex = binarySearch(arr, value);
  cout << "index for " << value << " is  " << vindex << endl;
  printArray(arr);

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr);
  printArray(arr);
  cout << "sorting array using selection sort" << endl;
  selectionSort(arr);
  cout << "Sorted array is:" << endl;
  printArray(arr);

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr);
  printArray(arr);
  cout << "sorting array using merge sort" << endl;
  mergeSort(arr, 0, arraysize - 1);
  cout << "Sorted array is:" << endl;
  printArray(arr);
}
