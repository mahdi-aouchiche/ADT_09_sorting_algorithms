# Abstact Data Types : Sorting Algorithms

Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/ADT_09_sorting_algorithms>)

* Implement different sorting algorithms and compare thier runtimes.
* Compare each algorithm on unsorted and sorted arrays to check the runtime of the best and average sorting cases.
* Output the elapsed runtime of each algorithm in seconds for comparison.

## Sort Algorithms time complexity

Algorithm           |   Best Case   |   Average Case    |   Worst Case  |
    ---             |       ---     |       ---         |       ---     |
`Quick-Sort`        |   n log n     |   n log n         |   n^2         |
`Insertion-Sort`    |   n           |   n^2             |   n^2         |
`Bubble-Sort`       |   n           |   n^2             |   n^2         |
`Selection-sort`    |   n^2         |   n^2             |   n^2         |

### To run the project nicely run the following commands

```c++
cmake -S . -B build
cmake --build build/ 
```

### 1 executable is created, use the following command to run an executable

```c++
// run the code
./build/sorting_runtimes
```
