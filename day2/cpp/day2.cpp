#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream file("day2.txt");
    
    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    } else {
        cout << "file opened \n";
    }

    // Read the file line by line
    int rows = 0;
    int part1 = 0;
    int part2 = 0;
    char buffer[256];
    while (file.getline(buffer, 256)) {
        rows++;

        istringstream lineStream(buffer);
        int value;
        int prevVal = -1;
        int inc = -1;
        int safe = 1;
        // int safe2 = 1;
        int life = 2;

        // Part 1
        // while (lineStream >> value) {
        //     if (prevVal == -1) {
        //         prevVal = value; // Initialize prevVal
        //         continue;
        //     }
        //     int lostLife = 0;

        //     // Detect invalid sequences or trends
        //     bool isEqualOrTooClose = abs(prevVal - value) < 1; // Adjacent values must differ by at least 1
        //     bool isTooFarApart = abs(prevVal - value) > 3;     // Adjacent values must differ by at most 3
        //     bool isInvalidDecreasing = (prevVal <= value && inc == 0); // Invalid in decreasing trend
        //     bool isInvalidIncreasing = (prevVal >= value && inc == 1); // Invalid in increasing trend

        //     if (isEqualOrTooClose || isTooFarApart || isInvalidDecreasing || isInvalidIncreasing) {
        //         // Commented out for part 2
        //         // safe = -1;
        //         // break;
        //         life --;
        //         if (life == 0) {
        //             safe = -1;
        //             break;
        //         }
        //         lostLife = 1;
        //     }

   

        //     // Update trend if undecided
        //     if (inc == -1) {
        //         inc = (prevVal > value) ? 0 : 1;
        //     }
            
        //     if (lostLife == 0) {
        //         prevVal = value; // Update prevVal for the next iteration
        //     }
        // }

        // if (safe == 1) {
        //     part1 ++;
        // }

        // Gave up using cpp
        while (lineStream >> value) {
            // Handle the first value
            if (prevVal == -1) {
                prevVal = value; // Initialize prevVal with the first value
                continue; // Skip further checks for the first value
            }

            int lostLife = 0;

            // Detect invalid sequences or trends
            bool isEqualOrTooClose = abs(prevVal - value) < 1; // Adjacent values must differ by at least 1
            bool isTooFarApart = abs(prevVal - value) > 3;     // Adjacent values must differ by at most 3
            bool isInvalidDecreasing = (prevVal <= value && inc == 0); // Invalid in decreasing trend
            bool isInvalidIncreasing = (prevVal >= value && inc == 1); // Invalid in increasing trend

            // Handle illegal value
            if (isEqualOrTooClose || isTooFarApart || isInvalidDecreasing || isInvalidIncreasing) {
                life--; // Decrease life for an illegal value
                if (life == 0) {
                    safe = -1; // Mark sequence as unsafe
                    break;     // Exit the loop
                }
                lostLife = 1; // Indicate that a life was lost due to an illegal value
            }

            // Update trend if undecided
            if (inc == -1) {
                inc = (prevVal > value) ? 0 : 1;
            }

            // Only update prevVal if no life was lost
            if (lostLife == 0) {
                prevVal = value; // Update prevVal for the next iteration
            }
        }

        if (safe == 1) {
            part1++; // Increment part1 if the sequence is safe
        }

    }

    cout << part1 << "\n";
    // cout << rows;

}

