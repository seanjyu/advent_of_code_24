#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int* arrI, int* arrJ) {
    int temp = *arrI;
    *arrI = *arrJ;
    *arrJ = temp;
}

// Implementation of in-place quick sort on a vector of integers (From Geeks4Geeks)
int partitionQuickSort(vector<int>& arr, int low, int high) {
    // Choose pivot point - in this case use high
    int pivot = arr[high];
    
    // Create pointers
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i ++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotInd = partitionQuickSort(arr, low, high);
        quickSort(arr, low, pivotInd - 1);
        quickSort(arr, pivotInd + 1, high);
    }
}


void testQuickSort() {
    vector<int> arr = {1,45,332,34,22,1,0,5000};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    testQuickSort();
    return 0;
}