/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Jack Vegter, Chris Lee
 * jvegter, chrislp
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * In this project, we use ciphers to dabble in the field of cryptography
 */

#include "caesar.h"
#include <iostream>


//************************************************************************
// Implement the functions below this line.
//************************************************************************

char shiftAlphaCharacter(char c, int n) {
    int inputChar = static_cast<int>(c);
    char shiftedChar;
    int num_letters_in_alphabet = 26;
    int upperCaseA = 65;
    int uppercaseZ = 90;
    int lowerA = 97;
    int lowerZ = 122;
    while (!(n >= 0 && n < num_letters_in_alphabet)) {
        if (n < 0) {
            n += num_letters_in_alphabet;
        }
        else {
            n -= num_letters_in_alphabet;
        }
    }
    
    if ((inputChar >= upperCaseA) && (inputChar <= uppercaseZ)) {
        if (c + n > 'Z') {
            n = c + n - 'Z' - 1;
            c = 'A';
        }
    }

    else if ((inputChar >= lowerA) && (inputChar <= lowerZ)) {
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

