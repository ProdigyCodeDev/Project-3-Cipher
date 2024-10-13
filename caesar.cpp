/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>


//************************************************************************
// Implement the functions below this line.
//************************************************************************
/*
 * Requires: c is an alphabetical character.
 * Modifies: Nothing.
 * Effects:  Returns c shifted by n characters.
 *           If c is lowercase, it will remain lowercase.
 *           If c is uppercase, it will remain uppercase.
 * Used in:  caesarCipher.
 */
char shiftAlphaCharacter(char c, int n) {
    int inputChar = static_cast<int>(c);
    char shiftedChar;
    while (!(n >= 0 && n < 26)) {
        if (n < 0) {
            n += 26;
        }
        else {
            n -= 26;
        }
    }
    
    if ((inputChar >= 65) && (inputChar <= 90)) {
        if (c + n > 'Z') {
            n = c + n - 'Z' - 1;
            c = 'A';
        }
    }

    else if ((inputChar >= 97) && (inputChar <= 122)) {
        if (c + n > 'z') {
            n = c + n - 'z' - 1;
            c = 'a';
        }
    }
    shiftedChar = c + n;
    return shiftedChar;
}




string caesarCipher(string original, int key, bool encrypt) {
    string newstr = "";
    int str_size = original.length();

    if (encrypt) {
        for (int x = 0; x < str_size; x++) {
            char currChar = original.at(x);
            if (currChar >= 'a' && currChar <= 'z' || currChar >= 'A' && currChar <= 'Z') {
                newstr += shiftAlphaCharacter(currChar, key);
            }
            else {
                newstr += currChar;
            }
        }
    }
    else if (!encrypt) {
        for (int x = 0; x < str_size; x++) {
            char currChar = original.at(x);
            if (currChar >= 'a' && currChar <= 'z' || currChar >= 'A' && currChar <= 'Z') {
                newstr += shiftAlphaCharacter(currChar, (-1 * key));
            }
            else {
                newstr += currChar;
            }
        }
    }
    return newstr;

}
