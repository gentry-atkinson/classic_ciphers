/*******************************
*Author: Gentry Atkinson
*Date: 17 May 2019
*Desc: enciphers a textfile according to the Vigenere enciphers
*******************************/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const char ALPHA_ARRAY[][26] = {
                {'A', 'B', 'C', 'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
                {'B', 'C', 'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A'},
                {'C', 'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B'},
                {'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'},
                {'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D'},
                {'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E'},
                {'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F'},
              };

int main (int argc, char** argv){
  char *filename;
  char *key;
  int keyLength;
  switch(argc){
    case 2:
      if (strcmp(argv[1], "--help") == 0){
        cout << "Usage is: " << endl;
        cout << "  vigenere filename key" << endl;
        cout << "  vigenere about" << endl;
        cout << "  vigenere --help" << endl;
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
    case 3:
      filename = argv[1];
      key = argv[2];
      keyLength = strlen(key);
      break;
    default:
      cout << "Usage is: " << endl;
      cout << "  vigenere filename key" << endl;
      cout << "  vigenere about" << endl;
      cout << "  vigenere --help" << endl;
      return 1;
      break;
  }
  ifstream inFile(filename);
  int keyPosition = 0;

}
