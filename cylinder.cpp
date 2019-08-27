/*******************************
*Author: Gentry Atkinson
*Date: 17 May 2019
*Desc: enciphers a textfile according to a cylinder cipher which selects every
  nth character in the plaintext to fill the ciphertext.
*******************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){
    int key = 7;
    char *filename;
    switch(argc){
    case 2:
      if (strcmp(argv[1], "--help") == 0){
        cout << "Usage is: " << endl;
        cout << "  cylinder filename" << endl;
        cout << "  cylinder filename key" << endl;
        cout << "  cylinder about" << endl;
        cout << "  cylinder --help" << endl;
        return 0;
      }
      else if (strcmp(argv[1], "about") == 0){
        cout << "In cryptography, a scytale is a tool used to perform a "
        << "transposition cipher, consisting of a cylinder with a strip of "
        << "parchment wound around it on which is written a message. The "
        << "ancient Greeks, and the Spartans in particular, are said to have "
        << "used this cipher to communicate during military campaigns."
        << endl << "--https://en.wikipedia.org/wiki/Scytale" << endl;
        return 0;
      }
      else {
        cout << "Using default key value." << endl;
        filename = argv[1];
      }
      break;
    case 3:
      cout << "Key should be mutually prime with message length." << endl;
      filename = argv[1];
      key = atoi(argv[2]);
      break;
      default:
      cout << "Usage is: " << endl;
      cout << "  cylinder filename" << endl;
      cout << "  cylinder filename key" << endl;
      cout << "  cylinder about" << endl;
      cout << "  cylinder --help" << endl;
      return 1;
      break;
    }

    ifstream inFile(filename);
    string inText = " ";
    char c;
    int messageLen = 0;
    int curPos = 0;
    while (inFile.get(c)){
        inText += c;
        ++messageLen;
    }
    do{
        cout << inText.at(curPos);
        curPos = (curPos + key) % messageLen;
    }while(curPos != 0);
}
