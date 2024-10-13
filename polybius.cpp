/*
 * polybius.cpp
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

#include <iostream>
#include "polybius.h"
#include <string>
#include <algorithm>

using namespace std;


string mixKey(string key) {
    string result = key;             
    string remaining = ALNUM;        
    int length = key.length();
    for (int i = 0; i < length; i++) {
        char c = key[i];
        remaining.erase(remove(remaining.begin(), remaining.end(), c), remaining.end());
    }

    result += remaining;

    return result;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int b = 0;
    for (int rows = 0; rows < 6; rows++) {
        for (int cols = 0; cols < 6; cols++) {
            grid[rows][cols] = content.at(b);
            b += 1;
        }
        
    }

}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string coords = "";
    for (int rows = 0; rows < 6; rows++) {
        for (int cols = 0; cols < 6; cols++) {
            if (grid[rows][cols] == c) {
                coords += to_string(rows);
                coords += to_string(cols);
                
            }
        }
    }

    return coords;
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    string square_key = mixKey(key);
    string final_result = "";
    int length = original.length();

    fillGrid(grid, square_key);

    if (encrypt) {
        for (int x = 0; x < length; x++) {
            if (original[x] == ' ') {
                final_result += ' ';
            }
            else {
                final_result += findInGrid(original[x], grid);
            }
        }
    }
    else {
        int y = 0;
        while (y < length) {
            if (!(original[y] == ' ')) {
                int rows = charToInt(original[y]);
                int cols = charToInt(original[y + 1]);
                final_result += grid[rows][cols];
                y += 2;

            }
            else {
                final_result += ' ';
                y++;
            }

        }
        return final_result;
    }
}
