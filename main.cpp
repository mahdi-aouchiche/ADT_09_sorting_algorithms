#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include "sorting_algorithms.hpp"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

int genRandInt(int low, int high);
void fillArrays(int arr1[], int arr2[],int arr3[], int arr4[], int arr5[]);

const int NUMBERS_SIZE = 100000;   // Size of the arrays

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
    int *arr4 = new int[NUMBERS_SIZE]; // Used in BubbleSort
    int *arr5 = new int[NUMBERS_SIZE]; // Used in SelectionSort

    // Populate the arrays
    fillArrays(arr1, arr2, arr3, arr4, arr5); 

    cout << "Size of the array to sort is " << NUMBERS_SIZE 
    << " elements." << endl << endl;
    sleep_for(seconds(1)); // pause a sec

  { /* Timing Quicksort_midpoint algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort Midpoint avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
    sleep_for(seconds(1)); // pause a sec
    
    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort Midpoint avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;
  }
  cout << endl;
  sleep_for(seconds(1)); // pause a sec

  { /* Timing Quicksort_medianOfThree algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();
  
    elapsed_time = end - start; 
    cout << "Quicksort medianOfThree avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
    sleep_for(seconds(1)); // pause a sec

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();

    elapsed_time = end - start; 
    cout << "Quicksort medianOfThree avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;
  }
  cout << endl;
  sleep_for(seconds(1)); // pause a sec

  { /* Timing Insertion Sort algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    InsertionSort(arr3, NUMBERS_SIZE);
    end = chrono::system_clock::now();  

    elapsed_time = end - start; 
    cout << "Insertion Sort avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
    sleep_for(seconds(1)); // pause a sec

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    InsertionSort(arr3, NUMBERS_SIZE);
    end = chrono::system_clock::now();

    elapsed_time = end - start; 
    cout << "Insertion Sort avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;  
  }
  cout << endl;
  sleep_for(seconds(1)); // pause a sec

  { /* Timing Bubble Sort algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    BubbleSort(arr4, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();  

    elapsed_time = end - start; 
    cout << "Bubble Sort avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
    sleep_for(seconds(1)); // pause a sec

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    BubbleSort(arr4, NUMBERS_SIZE-1);
    end = chrono::system_clock::now();

    elapsed_time = end - start; 
    cout << "Bubble Sort avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;
  }
  cout << endl;
  sleep_for(seconds(1)); // pause a sec

  { /* Timing Selection Sort algorithm */
    // Runtime on an unsorted array
    start = chrono::system_clock::now();
    SelectionSort(arr5, NUMBERS_SIZE);
    end = chrono::system_clock::now();  

    elapsed_time = end - start; 
    cout << "Selection Sort avg runtime on an unsorted array: "
    << elapsed_time.count()
    << " seconds."<< endl;
    sleep_for(seconds(1)); // pause a sec

    // Runtime on a sorted array 
    start = chrono::system_clock::now();
    SelectionSort(arr4, NUMBERS_SIZE);
    end = chrono::system_clock::now();

    elapsed_time = end - start; 
    cout << "Selection Sort avg runtime on a sorted array   : "
    << elapsed_time.count()
    << " seconds."<< endl;
  }
  
  return 0; 
}

/* return random integers */
int genRandInt(int low, int high) {
  return low + rand() % (high - low + 1);
}

/* Generate 4 equal arrays*/
void fillArrays(int arr1[], int arr2[],int arr3[], int arr4[], int arr5[]){
  srand((unsigned)time(0)); // re-seed the random generator
  for(int i = 0; i < NUMBERS_SIZE; ++i){
    arr1[i] = genRandInt(0,NUMBERS_SIZE);
    arr2[i] = arr1[i];
    arr3[i] = arr1[i];
    arr4[i] = arr1[i];
    arr5[i] = arr1[i];
  }
}