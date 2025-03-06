#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; 
    }
    return arr;
}

void measureSortingTime(const string& sortName, vector<int> arr, void (*sortFunction)(vector<int>&)) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;
    cout << sortName << " took " << elapsed.count() << " ms" << endl;
}

int main() {
    int size = 1000;
    vector<int> array1 = generateRandomArray(size);
    vector<int> array2 = array1;
    vector<int> array3 = array1;

    cout << "Sorting an array of size: " << size << endl;
    
    measureSortingTime("Bubble Sort", array1, bubbleSort);
    measureSortingTime("Selection Sort", array2, selectionSort);
    measureSortingTime("Insertion Sort", array3, insertionSort);
    
    return 0;
}
