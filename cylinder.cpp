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
#include <math.h>

using namespace std;

int main(int argc, char** argv){
    int key = 1;
    char *filename;
    switch(argc){
    case 2:
      if (strcmp(argv[1], "--help") == 0){
        cout << "Usage is: " << endl;
        cout << "  cylinder filename" << endl;
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
        filename = argv[1];
      }
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
    string inText = "";
    char c;
    int messageLen = 0;
    while (inFile.get(c)){
        inText += c;
        ++messageLen;
    }

    key = ceil(sqrt(messageLen));
    int diff = (key*key) - messageLen;
    while (diff > 0){
        inText+=" ";
        diff--;
    }
    int startPos = 0;
    int curPos = 0;
    //cout << "Message Length: " << messageLen << endl;
    //cout << "Key: " << key << endl << endl;
    //cout << inText << endl;
    while(startPos < key){
        cout << inText.at(curPos);
        //cout << " " << startPos << " " << curPos << endl;
        curPos += key;
        if (curPos >= key*key){
            startPos++;
            curPos = startPos;
        }
    }
}
