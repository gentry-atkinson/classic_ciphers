/*******************************
*Author: Gentry Atkinson
*Date: 13 May 2020
*Desc: this command line tool will enchipher or decipher a text document using
*  a user-input keyword.
*Example:
*  Plain:     THIS IS MY PLAINTEXT
*  Key:       RAT
*  Key Text:  RATR AT RA TRATRATRA
*******************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main (int argc, char** argv){
  char *filename;
  bool enc = false;
  switch(argc){
    case 2:
      if (strcmp(argv[1], "--help") == 0){
        cout << "Usage is: " << endl;
        cout << "four_square about" << endl;
        cout << "four_square --help" << endl;
        cout << "four_square gen" << endl;
        cout << "four_square enc filename" << endl;
        cout << "four_square dec filename" << endl;
      }
      else if (strcmp(argv[1], "about") == 0){
        cout << "The four-square cipher is a manual symmetric encryption "
            << "technique. It was invented by the French cryptographer Felix "
            << "Delastelle. The technique encrypts pairs of letters (digraphs), "
            << "and thus falls into a category of ciphers known as polygraphic "
            << "substitution ciphers. This adds significant strength to the "
            << "encryption when compared with monographic substitution ciphers "
            << "which operate on single characters. The use of digraphs makes "
            << "the four-square technique less susceptible to frequency "
            << "analysis attacks, as the analysis must be done on 676 possible "
            << "digraphs rather than just 26 for monographic substitution. The "
            << "frequency analysis of digraphs is possible, but considerably "
            << "more difficult - and it generally requires a much larger "
            << "ciphertext in order to be useful. "
            << "--en.wikipedia.org/wiki/Four-square_cipher"
          << endl;
      }
