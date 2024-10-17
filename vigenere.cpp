/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Jack Vegter, Chris Lee
 * jvegter, chrislp
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * In this project, we use ciphers to dabble in cryptography.
 */



//************************************************************************
// Implement the functions below this line.
//************************************************************************



 
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>



string vigenereCipher(string original, string keyword, bool encrypt) {

    string finalWord = "";

    keyword = toUpperCase(removeNonAlphas(keyword));

    int keyCount = 0;
    int inputLength = original.length();
    int keyLength = keyword.length();

    for (int i = 0; i < inputLength; i++) {

        if (keyCount % keyLength == 0) {
            keyCount = 0;
        }


        if ((original[i] >= 'a' && original[i] <= 'z') || (original[i] >= 'A' && original[i] <= 'Z')) {

            if (encrypt) {
                int shiftBy = static_cast<int>(keyword[keyCount] - 'A');
                finalWord += shiftAlphaCharacter(original[i],shiftBy);

            }

            else {
                int shiftBys = static_cast<int>((keyword[keyCount] - 'A') * -1);
                finalWord += shiftAlphaCharacter(original[i],shiftBys);
            }
            keyCount +=1 ;
        }
        else {
            finalWord  += original[i];
        }
    }
    return finalWord;
}


