/*******************************
*Author: Gentry Atkinson
*Date: 17 May 2019
*Desc: enciphers a textfile according to the Vigenere enciphers. Re-built to be
*  more efficient but loses some faithfullness to the hand implementation.
*******************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

int main (int argc, char** argv){
  char *filename;
  char *key;
  int keyLength;
  bool enc = false;
  switch(argc){
    case 2:
      if (strcmp(argv[1], "--help") == 0){
        cout << "Usage is: " << endl;
        cout << "  vigenere_fast enc filename key" << endl;
        cout << "  vigenere_fast dec filename key" << endl;
        cout << "  vigenere_fast about" << endl;
        cout << "  vigenere_fast --help" << endl;
      }
      else if (strcmp(argv[1], "about") == 0){
        cout << "First described by Giovan Battista Bellaso in 1553, the cipher "
          << "is easy to understand and implement, but it resisted all attempts "
          << "to break it until 1863, three centuries later. This earned it the "
          << "description le chiffre indéchiffrable (French for 'the "
          << "indecipherable cipher'). Many people have tried to implement "
          << "encryption schemes that are essentially Vigenère ciphers.[3] In "
          << "1863, Friedrich Kasiski was the first to publish a general method "
          << "of deciphering Vigenère ciphers. "
          << "--https://en.wikipedia.org/wiki/Vigenere_cipher"
          << endl;
      }
      return 0;
      break;
    case 4:
      if (strcmp(argv[1], "enc") == 0) enc = true;
      filename = argv[2];
      key = argv[3];
      keyLength = strlen(key);
      break;
    default:
    cout << "Usage is: " << endl;
    cout << "  vigenere_fast enc filename key" << endl;
    cout << "  vigenere_fast dec filename key" << endl;
    cout << "  vigenere_fast about" << endl;
    cout << "  vigenere_fast --help" << endl;
      return 1;
      break;
  }
  ifstream inFile(filename);
  int keyPosition = 0;
  char c;
  while (inFile.get(c)){
    if (isalpha(c)){
      int shift = 0;
      c = toupper(c);
      int c_int = c - 'A';
      if (enc)
        shift = int(key[keyPosition] - 'A');
      else
        shift = 26 - int(key[keyPosition] - 'A');
      cout << char(((c_int + shift) % 26) + 'A');
      keyPosition = (keyPosition + 1) % keyLength;
    }
    else{
      cout << c;
    }
  }

}
