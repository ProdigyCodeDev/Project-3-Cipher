/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string toUpperCase(string original) {
    // TODO: implement

    // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return "";
}

string removeNonAlphas(string original) {
    string newString = "";
    int length = original.length();
    for (int i = 0; i < length; i++) {
        char numChar;
        int charNum = static_cast<int>(original.at(i));
        if ((charNum >= 65) && (charNum <= 90)) {
            numChar = static_cast<char>(charNum);
            newString += numChar;
        }
        else {
            newString += "";
        }
    }
    return newString;
}

int charToInt(char original) {
    char mod = original;
    int final = mod - 48;
    return final;

}

string removeDuplicate(string original) {
    string result = "";

    // Iterate through the string
    for (int i = 0; i < original.length(); i++) {
        bool isDuplicate = false;


        for (int j = 0; j < result.length(); j++) {
            if (original[i] == result[j]) {
                isDuplicate = true;
                // break;
            }
        }


        if (!isDuplicate) {
            result = result + original[i];
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
