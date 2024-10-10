#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testShiftAlphaCharacter();
void testremoveNonAlphas();
void testcharToInt();
void testremoveDuplicate();
void testtoUpperCase();
void testcaesarCipher();
void testvigenereCipher();

void startTests() {
    testShiftAlphaCharacter();
    testremoveNonAlphas();
    testcharToInt();
    testremoveDuplicate();
    testtoUpperCase();
    testcaesarCipher();
    testvigenereCipher();
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'w', Actual: '" << shiftAlphaCharacter('y', 24) << "'" << endl;


    return;
}

void testremoveNonAlphas() {
    cout << "expected EE, actual: " << removeNonAlphas("EEcs") << endl;
}

void testcharToInt() {
    cout << "Expected 1, actual: " << charToInt('1') << endl;
}

void testremoveDuplicate() {
    cout << "Expected ABC, actual: " << removeDuplicate("AABBCC") << endl;
}

void testtoUpperCase() {
    cout << "Expected ABC, actual: " << toUpperCase("abc") << endl;
}

void testcaesarCipher() {
    cout << "Expected        Cuuj cu qj jxu Tyqw qj 11 f.c.     , Actual " << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
}

void testvigenereCipher() {
    cout << "Expected:   Euyb dv ee lxy Lzrk ll 11 f.g.  , Actual " << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true);

}