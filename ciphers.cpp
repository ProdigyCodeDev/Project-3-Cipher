/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Jack Vegter and Chris Lee
 * jvegter chrislp
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * In this project, we use ciphers to dabble in the field of cryptography
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************


void ciphers() {
    string result;
    string userChoice;
    string codeaction;
    string codeinput;
    string codefinal;
    string inputmessage;
    string inputkey;

    cout << "Choose a cipher(Caesar, Vigenere, or Polybius):" << endl;
    getline(cin, userChoice);

    int choicelength = userChoice.length();

    for (int l = 0; l < choicelength; l++) {
        userChoice[l] = tolower(userChoice[l]);
    }




    string lowerinput = userChoice;
    if (!(lowerinput == "c" || lowerinput == "v" || lowerinput == "p" || lowerinput == "caesar" || lowerinput == "vigenere" || lowerinput == "polybius")) {
        cout << " Invalid cipher!";
        return;
    }

    if (lowerinput == "c" || lowerinput == "caesar") {
        int inputkey;
        cout << "Encrypt or decrypt:" << endl;
        getline(cin, codeaction);

        int delength = codeaction.length();

        for (int m = 0; m < delength; m++) {
            codeaction[m] = tolower(codeaction[m]);
        }

        if (!(codeaction == "e" || codeaction == "d" || codeaction == "encrypt" || codeaction == "decrypt")) {
            cout << "Invalid mode!";
            return;
        }
        else {
            cout << "Enter a message:" << endl;
            getline(cin, inputmessage);

            cout << "What is your key:" << endl;
            cin >> inputkey;

            if (codeaction == "e" || codeaction == "encrypt") {
                result = caesarCipher(inputmessage, inputkey, true);
                cout << "The encrypted message is: " << result << endl;
            }
            else if (codeaction == "d" || codeaction == "decrypt") {
                result = caesarCipher(inputmessage, inputkey, false);
                cout << "The decrypted message is: " << result << endl;
            }
        }

    }

    else if (lowerinput == "v" || lowerinput == "vigenere") {
        string inputkey;
        cout << "Encrypt or decrypt:" << endl;
        getline(cin, codeaction);


        int delength = codeaction.length();

        for (int m = 0; m < delength; m++) {
            codeaction[m] = tolower(codeaction[m]);
        }

        if (!(codeaction == "e" || codeaction == "d" || codeaction == "encrypt" || codeaction == "decrypt")) {
            cout << "Invalid mode!";
            return;
        }
        else {
            cout << "Enter a message:" << endl;
            getline(cin, inputmessage);

            cout << "What is your key:" << endl;
            getline(cin, inputkey);

            int inputkeylength = inputkey.length();
            bool run = false;
            for (int x = 0; x < inputkeylength; x++) {
                if (isalpha(inputkey[x])) {
                    run = true;
                }
            }

            if (run) {
                if (codeaction == "e" || codeaction == "encrypt") {
                    result = vigenereCipher(inputmessage, inputkey, true);
                    cout << "The encrypted message is: " << result << endl;
                }
                else if (codeaction == "d" || codeaction == "decrypt") {
                    result = vigenereCipher(inputmessage, inputkey, false);
                    cout << "The decrypted message is: " << result << endl;
                }

            }

        }

    }
    else if (userChoice == "p" || userChoice == "polybius") {
        cout << "Encrypt or decrypt:" << endl;
        getline(cin, codeaction);

        int delength = codeaction.length();
        for (int m = 0; m < delength; m++) {
            codeaction[m] = tolower(codeaction[m]);
        }

        if (!(codeaction == "e" || codeaction == "d" || codeaction == "encrypt" || codeaction == "decrypt")) {
            cout << "Invalid mode!" << endl;
            return;
        }

        cout << "Enter a message:" << endl;
        getline(cin, inputmessage);

        cout << "What is your key:" << endl;
        getline(cin, inputkey);

        inputkey = toUpperCase(removeNonAlphas(inputkey));
        inputkey = removeDuplicate(inputkey);

        bool hasAlpha = false;
        int inputkeyLength = inputkey.length();
        for (int i = 0; i < inputkeyLength; i++) {
            if (isalpha(inputkey[i])) {
                hasAlpha = true;
            }
        }

        if (!hasAlpha) {
            cout << "Invalid key!" << endl;
            return;
        }

        char grid[SIZE][SIZE];
        if (codeaction == "e" || codeaction == "encrypt") {
            result = polybiusSquare(grid, inputkey, inputmessage, true);
            cout << "The encrypted message is: " << result << endl;
        }
        else if (codeaction == "d" || codeaction == "decrypt") {
            result = polybiusSquare(grid, inputkey, inputmessage, false);
            cout << "The decrypted message is: " << result << endl;
        }
    }
}




string polybiusSquare(char grid[SIZE][SIZE], string key,
    string original, bool encrypt);
   

