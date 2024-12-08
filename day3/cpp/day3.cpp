#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main() {
    ifstream file("day3.txt");
    
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
    char buffer[4096];
    string line;
    
    int doOrDont = 1;
    while (file.getline(buffer, sizeof(buffer))) {
        rows++;

        istringstream lineStream(buffer);
        char value;
        int foundMul = 0;
        string matStrVal1 = "";
        string matStrVal2 = "";
        int matVal1 = 0;
        int matVal2 = 0;
        int matVal = 0;
        int foundDo = 0;
        int foundDont = 0;
        while (lineStream >> value) {
            // cout << value << "\n";
            // use if statements to check if char makes do or dont
            // use counter value to check how far along do/dont
            if ('d' == value) {
                foundDo = 1;
            } else if ('o' == value && foundDo == 1) {
                foundDo = 2;
            } else if ('n' == value && foundDo == 2) {
                foundDont = 1;
                foundDo = 0;
            } else if ('(' == value && foundDo == 2) {
                foundDo = 3;
            } else if (')' == value && foundDo == 3) {
                doOrDont = 1;
                foundDo = 0;
            } else if ('\'' == value && foundDont == 1) {
                foundDont = 2;
            } else if ('t' == value && foundDont == 2) {
                foundDont = 3;
            } else if ('(' == value && foundDont == 3) {
                foundDont = 4;
            } else if (')' == value && foundDont == 4) {
                doOrDont = 0;
                foundDont = 0;
            } else {
                foundDo = 0;
                foundDont = 0;
            }


            // check for do or dont for part 2
            if (doOrDont == 1) {
                // use if statements to check if char makes mul()
                // use counters to keep track how far along mul the string is
                // also use string to keep track of the number
                if ('m' == value) {
                    foundMul = 1;
                    // cout << "m found" << "\n";
                } else if ('u' == value && foundMul == 1) {
                    foundMul = 2;
                } else if ('l' == value && foundMul == 2) {
                    foundMul = 3;
                } else if ('(' == value && foundMul == 3) {
                    foundMul = 4;
                } else if (',' == value && foundMul == 4) {
                    foundMul = 5;
                } else if (foundMul == 4 && isdigit(value)) {
                    matStrVal1 += value;
                } else if (')' == value && foundMul == 5) {
                    matVal = stoi(matStrVal1) * stoi(matStrVal2);
                    part1 += matVal;
                    // cout << matStrVal1 << "\n";
                    // cout << matStrVal2 << "\n";
                    matStrVal1 = "";
                    matStrVal2 = "";
                    foundMul = 0;
                    matVal1 = 0;
                    matVal2 = 0;
                } else if (foundMul == 5 && isdigit(value)) {   
                    matStrVal2 += value;
                } else {
                    matStrVal1 = "";
                    matStrVal2 = "";
                    foundMul = 0;
                    matVal1 = 0;
                    matVal2 = 0;
                }
            }
        }
        
    }
    cout << part1;

    // Close the file
    file.close();
}