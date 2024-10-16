//
//  test.cpp
//  Project 3
/* 
 
 Jack Vegter, Chris Lee
 jvegter, chrislp
 
 Project 3
 */
//
//  Created by Jack Vegter on 10/6/24.
//


#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void testShiftAlphaCharacter();
void testremoveNonAlphas();
void testcharToInt();
void testremoveDuplicate();
void testtoUpperCase();
void testcaesarCipher();
void testvigenereCipher();
void testfillGrid();
void testMixKey();
void testfindInGrid();

void startTests() {
    testShiftAlphaCharacter();
    testremoveNonAlphas();
    testcharToInt();
    testremoveDuplicate();
    testtoUpperCase();
    testcaesarCipher();
    testvigenereCipher();
    testfillGrid();
    testMixKey();
    testfindInGrid();

    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" <<
    endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" <<
    endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" <<
    endl;
    cout << "Expected: 'w', Actual: '" << shiftAlphaCharacter('y', 24) << "'" <<
    endl;
    cout << "Expected: 'w', Actual:'" << shiftAlphaCharacter('y', 48) << "'" <<
    endl;
    cout << shiftAlphaCharacter('a', 0) <<
    endl;
    cout << shiftAlphaCharacter('b', 2) <<
    endl;
    cout << shiftAlphaCharacter('X', 5) <<
    endl;
    cout << shiftAlphaCharacter('X', 50) <<
    endl;


    return;
}

void testremoveNonAlphas() {
    cout << "expected EE, actual: " << removeNonAlphas("EEcs") << endl;
    cout << "expected EE, actual: " << removeNonAlphas("EECS 193") << endl;
    cout << "expected EE, actual: " << removeNonAlphas("EEcs *#$&732") << endl;


}

void testcharToInt() {
    cout << "Expected 0, actual: " << charToInt('0') << endl;
    cout << "Expected 1, actual: " << charToInt('1') << endl;
    cout << "Expected 2, actual: " << charToInt('2') << endl;
    cout << "Expected 3, actual: " << charToInt('3') << endl;
    cout << "Expected 4, actual: " << charToInt('4') << endl;
    cout << "Expected 5, actual: " << charToInt('5') << endl;
    cout << "Expected 6, actual: " << charToInt('6') << endl;
    cout << "Expected 7, actual: " << charToInt('7') << endl;
    cout << "Expected 8, actual: " << charToInt('8') << endl;
    cout << "Expected 9, actual: " << charToInt('9') << endl;

}

void testremoveDuplicate() {
    cout << "Expected ABC, actual: " << removeDuplicate("AABBCC") << endl;
    cout << "Expected ABC, actual: " << removeDuplicate("AABBCC88899999933355544")<< endl;
    cout << "Expected ABC, actual: " << removeDuplicate("001122334455667788899999933355544") << endl;



}

void testtoUpperCase() {
    cout << "Expected ABC, actual: " << toUpperCase("abc") << endl;
}

void testcaesarCipher() {
    cout << "Expected        Cuuj cu qj jxu Tyqw qj 11 f.c.     , Actual " << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << caesarCipher("Wood wo kd dro Nskq kd 11 z.w.", 42, false) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 10, true) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", -10, true) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", -10, false) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", -65, false) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", -70, true) << endl;



}

void testvigenereCipher() {
    cout << "Expected:   Euyb dv ee lxy Lzrk ll 11 f.g.  , Actual " <<
    vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true);
    cout << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false);
    cout << endl;
}

void testfillGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << endl;
}

void testfindInGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << findInGrid('1', grid) << endl;
}

void testMixKey() {
    cout << mixKey("POLYBIUS") << endl;
}
