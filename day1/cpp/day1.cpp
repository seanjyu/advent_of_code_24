#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

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
    ifstream file("day1.txt");
    
    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    } else {
        cout << "file opened \n";
    }

    // Read the file line by line
    int rows = 0;
    char buffer[256];
    while (file.getline(buffer, 256)) {
        rows++;

        // Consume the newline character at the end of each line
        file.get();
    }

    // Rewind to the start of the file
    file.clear();
    file.seekg(0);

    // Create vectors to store the column values
    vector<int> col1;
    vector<int> col2;


    // Read the column values from the file
    for (int i = 0; i < rows; ++i) {
        int value1, value2;

        // Read two integers from each line
        if (!(file >> value1)) break;
        file.get();  // Consume the space between values
        if (!(file >> value2)) break;

        // Add the column values to their respective vectors
        col1.push_back(value1);
        col2.push_back(value2);
    }


    // sort col1 and col2
    quickSort(col1, 0, rows - 1);
    quickSort(col2, 0, rows - 1);

    // Print the populated vectors
    // cout << "Col1: ";
    // for (int value : col1) {
    //     cout << value << " ";
    // }
    // cout << "\n";

    // cout << "Col2: ";
    // for (int value : col2) {
    //     cout << value << " ";
    // }
    // cout << "\n";


    // Part 1
    int sol = 0; 
    for (int i = 0; i < rows; ++i) {
        sol += abs(col1[i] - col2[i]);
    }
    cout << "part 1:" << sol << "\n";

    // Part 2
    // create frequency map of second column
    unordered_map<int, int> um;

    for (auto i : col2) {
        um[i] ++;
    } 

    int sol2 = 0;

    for (auto i : col1) {
        sol2 += um[i] * i;
    }

    cout << "part 2:" << sol2 << "\n";

    
    // Close the file
    file.close();

    return 0;
}