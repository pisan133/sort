/**
 * Testing of simple and template based search and sort
 */

/**
 * output (will change because of rand()
 * expected moutput is:
 *
 * *** Start testSimple ***
 *
 * Initial array is:
 * 7 49 73 58 30 72 44 78 23 9 40 65 92 42 87 3 27 29 40 12
 * Finding 58 using linear search
 * index for 58 is  3
 *
 * sorting array using insertion sort
 * Sorted array is:
 * 3 7 9 12 23 27 29 30 40 40 42 44 49 58 65 72 73 78 87 92
 *
 * Finding 58 using binary search
 * index for 58 is  13
 * 3 7 9 12 23 27 29 30 40 40 42 44 49 58 65 72 73 78 87 92
 *
 * filling array with random numbers, array is:
 * 69 9 57 60 33 99 78 16 35 97 26 12 67 10 33 79 49 79 21 67
 * sorting array using selection sort
 * Sorted array is:
 * 9 10 12 16 21 26 33 33 35 49 57 60 67 67 69 78 79 79 97 99
 *
 * filling array with random numbers, array is:
 * 72 93 36 85 45 28 91 94 57 1 53 8 44 68 90 24 96 30 3 22
 * sorting array using merge sort
 * Sorted array is:
 * 1 3 8 22 24 28 30 36 44 45 53 57 68 72 85 90 91 93 94 96
 *
 * *** Start testTemplate ***
 *
 * Initial array is:
 * 66 49 24 1 53 77 8 28 33 98 81 35 13 65 14 63 36 25 69 15
 * Finding 14 using linear search
 * index for 14 is  14
 *
 * sorting array using insertion sort
 * Sorted array is:
 * 1 8 13 14 15 24 25 28 33 35 36 49 53 63 65 66 69 77 81 98
 *
 * Finding 14 using binary search
 * index for 14 is  3
 * 1 8 13 14 15 24 25 28 33 35 36 49 53 63 65 66 69 77 81 98
 *
 * filling array with random numbers, array is:
 * 29 1 17 95 5 4 51 98 88 23 5 82 52 66 16 37 38 44 1 97
 * sorting array using selection sort
 * Sorted array is:
 * 1 1 4 5 5 16 17 23 29 37 38 44 51 52 66 82 88 95 97 98
 *
 * filling array with random numbers, array is:
 * 71 28 37 58 77 97 94 4 9 31 45 75 35 98 42 99 68 12 60 57
 * sorting array using merge sort
 * Sorted array is:
 * 4 9 12 28 31 35 37 42 45 57 58 60 68 71 75 77 94 97 98 99
 * Done!
 *
 * Process finished with exit code 0
 *
 **/

#include <iostream>

using namespace std;

// forward declarations
void testSimple();
void testTemplate();

void testAll() {
  testSimple();
  testTemplate();
}

int main() {
  testAll();
  cout << "Done!" << endl;
  return 0;
}
