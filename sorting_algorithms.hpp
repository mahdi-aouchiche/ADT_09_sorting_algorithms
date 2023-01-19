#ifndef __SORTING_ALGORITHMS_HPP__
#define __SORTING_ALGORITHMS_HPP__

#include <ctime>
#include <algorithm>
#include <chrono>
using namespace std;

/* 
  Partitions the given array to low 
  and high partitions from the pivot. 
*/
int midpointPartition(int numbers[], int i, int k) {

  // Pick middle element value as a pivot 
  int pivot = numbers[(i+k)/2]; 
  
  // initiate variables for low and high partitions 
  int low  = i;    // low partition 
  int high = k;    // high partition 

  bool done = false; 
  while (!done) {
    // Increment low while numbers[low] < pivot
    while (numbers[low] < pivot) { ++low; }

    // Decrement high while pivot < numbers[high]
    while (pivot < numbers[high]) { --high; }

    if (low >= high) {
      done = true;
    } else {
      
      // Swap numbers[low] and numbers[high], update low and high
      int temp   = numbers[low];
      numbers[low] = numbers[high];
      numbers[high] = temp;

      ++low;
      --high;
    }
  }
  
  return high; 
}

/* 
  This function sorts the given array in 
  the range from i to k using quicksort method.
  In this function, pivot is the midpoint
  element (numbers[(i+k)/2]).
*/
void Quicksort_midpoint(int numbers[], int i, int k) {

  //base case: partition is sorted if it has 0 or 1 elements to sort  
  if( i >= k) {
    return;
  } 

  // Get the last element of low partition from the array
  int j = midpointPartition(numbers, i, k);

  // Recursively sort low and high partitions 
  Quicksort_midpoint(numbers, i, j);      // sort lower partition 
  Quicksort_midpoint(numbers, j + 1, k);  // sort high partition
}

/* 
  Partitions the given array to low and
  high partitions from the pivot 
  using median-of-three technique. 
*/
int medianOfThreePartition(int numbers[], int i, int k) {
  
  int c = (i + k) / 2;   // center element 

  // i <= c <= k
  if (numbers[c] < numbers[i]) {
    swap(numbers[i], numbers[c]); 
  } 
  if (numbers[k] < numbers[i]) {
    swap(numbers[i], numbers[k]); 
  } 
  if (numbers[k] < numbers[c]) {
    swap(numbers[k], numbers[c]); 
  } 

  // get the pivot as the center of the three 
  int pivot = numbers[c];  

  // swap pivot and numbers[k-1]
  swap(numbers[c], numbers[k-1]);

  // set left and right variables 
  int left = i+1;
  int right = k-2 ;

  // when left < right 
  while (left < right) {

    while(numbers[left] < pivot) {
      ++left; 
    }
    while(numbers[right] > pivot) {
      --right;
    }

    // swap left and right elements' values  
    swap(numbers[left], numbers[right]); 

    // update left and right 
    ++left;
    --right;
  }

  // when left and right have crossed 
  swap(numbers[left], numbers[k-1]); 

  return  right;
} 

/* 
  This function utilizes different pivot selection
  technique in quicksort algorithm.
  The pivot is the median of the following three values:
    - leftmost (numbers[i])
    - midpoint (numbers[(i+k)/2])
    - rightmost (numbers[k])
*/ 
void Quicksort_medianOfThree(int numbers[], int i, int k) {
  // partition is sorted if it has 0 or 1 elements to sort  
  if( i >= k) {
    return;
  } 

  // Get the last element of low partition from the array
  int j = medianOfThreePartition(numbers, i, k);
  
  Quicksort_midpoint(numbers, i, j );    // sort lower partition 
  Quicksort_midpoint(numbers, j + 1, k); // sort high partition
}

/* 
  This function sorts the given array using InsertionSort method.
*/ 
void InsertionSort(int numbers[], int numbersSize) {
  int i = 0;
  int j = 0;

  int temp = 0; // temp variable for swap 

  for (i = 1; i < numbersSize; ++i) {
    j = i ;

    while ((j > 0) && (numbers[j] < numbers[j -1])) {
      // swap numbers[j] and numbers[j -1]
      temp = numbers[j];
      numbers[j] = numbers[j-1];
      numbers[j-1] = temp;
      --j; 
    }
  } 
}

#endif  // __SORTING_ALGORITHMS_HPP__