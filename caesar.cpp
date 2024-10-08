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
    int newChar;
    if (islower(c)) {
        if (inputChar + n > 122) {
            newChar = (inputChar - 97 + n) % 26 + 97;
            newChar = static_cast<char>(newChar);
            return newChar;
        }
        else {
            newChar = inputChar + n;
            newChar = static_cast<char>(newChar);
            return newChar;
        }
    }
    else if (isupper(c)) {
        if (inputChar + n > 90) {
            newChar = (inputChar - 65 + n) % 26 + 65;
            newChar = static_cast<char>(newChar);
            return newChar;
        }
        else {
            newChar = inputChar + n;
            newChar = static_cast<char>(newChar);
            return newChar;
        }
    }
}

string caesarCipher(string original, int key, bool encrypt) {
    // TODO: implement

    // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return "";

}
