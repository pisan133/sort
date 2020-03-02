/**
 * Sort functions on integers
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[";
  if (!v.empty()) {
    os << v[0];
    for (int i = 1; i < v.size(); ++i) {
      os << "  " << v[i];
    }
  }
  os << "]";
  return os;
}

void fillRandom(vector<int>& items) {
  for (int i = 0; i < items.size(); ++i) {
    items[i] = rand() % 100;
  }
}

int linearSearch(const vector<int>& items, int key) {
  for (int i = 0; i < items.size(); ++i) {
    if (key == items[i]) {
      return i;
    }
  }
  return -1;
}

int binarySearch(const vector<int>& items, int key) {
  int low = 0;
  int high = items.size() - 1;
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

void insertionSort(vector<int>& items) {
  for (int next = 1; next < items.size(); ++next) {
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

void selectionSort(vector<int>& items) {
  // loop over size - 1 elements
  for (int i = 0; i < items.size() - 1; ++i) {
    int indexOfSmallest = i;

    // loop to find index of smallest element
    for (int index = i + 1; index < items.size(); ++index) {
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
void merge(vector<int>& items, int left, int middle1, int middle2, int right) {
  int leftIndex = left;
  int rightIndex = middle2;
  // index into temporary working array
  // [.... left ... middle1 middle2 ... right]
  // only care about left-right area
  int combinedIndex = left;
  int combinedSize = right + 1;
  vector<int> combined(combinedSize);

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

void mergeSort(vector<int>& items, int low, int high) {
  // test base case; size of array equals 1
  if ((high - low) >= 1) {
    int middle1 = (low + high) / 2;
    int middle2 = middle1 + 1;

    // split array in half; sort each half (recursive calls)
    mergeSort(items, low, middle1);   // first half of array
    mergeSort(items, middle2, high);  // second half of array

    // merge two sorted arrays after split calls return
    merge(items, low, middle1, middle2, high);
  }
}

void testSimple() {
  const int kArraySize = 20;
  vector<int> arr(kArraySize);

  cout << endl << "*** Start testSimple ***" << endl << endl;
  fillRandom(arr);
  cout << "Initial array is: " << arr << endl;
  int value = arr[rand() % kArraySize];
  cout << "Finding " << value << " using linear search" << endl;
  int vindex = linearSearch(arr, value);
  cout << "index for " << value << " is  " << vindex << endl;

  cout << endl << "sorting array using insertion sort" << endl;
  insertionSort(arr);
  cout << "Sorted array is: " << arr << endl;

  cout << endl << "Finding " << value << " using binary search" << endl;
  vindex = binarySearch(arr, value);
  cout << "index for " << value << " is  " << vindex << endl;
  cout << "Array is: " << arr << endl;

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr);
  cout << "Array is: " << arr << endl;
  cout << "sorting array using selection sort" << endl;
  selectionSort(arr);
  cout << "Sorted array is: " << arr << endl;

  cout << endl << "filling array with random numbers, array is:" << endl;
  fillRandom(arr);
  cout << "Array is: " << arr << endl;
  cout << "sorting array using merge sort" << endl;
  mergeSort(arr, 0, kArraySize - 1);
  cout << "Sorted array is:" << endl;
  cout << "Sorted array is: " << arr << endl;
}
