#include <iostream>
#include "sorting_algorithms.hpp"

int genRandInt(int low, int high);
void fillArrays(int arr1[], int arr2[],int arr3[]);

const int NUMBERS_SIZE = 500000;   // Size of the arrays

int main() {
    // Time at the start of the function call 
    chrono::_V2::system_clock::time_point start;
    // Time at the end of the function call 
    chrono::_V2::system_clock::time_point end;
    // Holds elapsed time for each sorting algorithm
    chrono::duration<double> elapsed_time;

    // Declare 3 arrays, one for each sort algorithm
    int *arr1 = new int[NUMBERS_SIZE]; // Used in Quicksort_midpoint
    int *arr2 = new int[NUMBERS_SIZE]; // Used in Quicksort_medianOfThree
    int *arr3 = new int[NUMBERS_SIZE]; // Used in InsertionSort

    // Populate the arrays
    fillArrays(arr1, arr2, arr3); 

    cout << "Size of the array to sort is " << NUMBERS_SIZE 
    << " elements." << endl << endl;
     
  { /* Timing Quicksort_midpoint algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort Midpoint avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
  
    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort Midpoint avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl << endl;
  }
  
  { /* Timing Quicksort_medianOfThree algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort medianOfThree avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort medianOfThree avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl << endl;
  }

  { /* Timing Insertion Sort algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    InsertionSort(arr3, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();  

    elapsed_time = end - start; 
    cout << "Insertion Sort avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    InsertionSort(arr3, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();

    elapsed_time = end - start; 
    cout << "Insertion Sort avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;
  }
  return 0; 
}

/* return random integers */
int genRandInt(int low, int high) {
  return low + rand() % (high - low + 1);
}

/* Generate 3 equal arrays*/
void fillArrays(int arr1[], int arr2[],int arr3[]){
  for(int i = 0; i < NUMBERS_SIZE; ++i){
    arr1[i] = genRandInt(0,NUMBERS_SIZE);
    arr2[i] = arr1[i];
    arr3[i] = arr1[i];
  }
}