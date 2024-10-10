/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    string newstr = "";
    int str_size = original.length();
    int key_size = keyword.length();
    int keyIndex = 0;

    for (int x = 0; x < str_size; x++) {
        char currChar = original.at(x);
        if (currChar >= 'a' && currChar <= 'z' || currChar >= 'A' && currChar <= 'Z') {
            char keyChar = keyword.at(keyIndex % key_size);  // Loop over key
            int keyShift;

            // Check if the key character is lowercase or uppercase
            if (keyChar >= 'a' && keyChar <= 'z') {
                keyShift = keyChar - 'a';  // Calculate shift for lowercase
            }
            else {
                keyShift = keyChar - 'A';  // Calculate shift for uppercase
            }

            if (!encrypt) {
                keyShift = -keyShift;  // Reverse shift for decryption
            }

            newstr += shiftAlphaCharacter(currChar, keyShift);
            keyIndex++;
        }
        else {
            newstr += currChar;  // Non-alphabet characters remain the same
        }
    }
    return newstr;
}
