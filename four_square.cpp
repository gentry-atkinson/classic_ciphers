/*******************************
*Author: Gentry Atkinson
*Date: 23 May 2019
*Desc: enciphers a textfile according to the Four Square cipher. May add a
*  random char to the end of the file since this cipher requires an even number
*  of characters in the file.
*******************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getRow(char);
int getCol(char);
void array_swap(char[], int, int);

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
      else if (strcmp(argv[1], "gen") == 0){
        srand(time(NULL));
        char key1[] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',};
        char key2[] = {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',};
        for(int i = 0; i < 300; ++i){
            array_swap(key1, rand()%25, rand()%25);
            array_swap(key2, rand()%25, rand()%25);
        }
        ofstream keyFile("square.key");
        for(int i = 0; i < 25; ++i)
            keyFile << key1[i] << " ";
        keyFile << endl;
        for(int i = 0; i < 25; ++i)
            keyFile << key2[i] << " ";
        keyFile.close();
      }
      return 0;
      break;
    case 3:
        if (strcmp(argv[1], "enc") == 0){
            enc = true;
        }
        else if (strcmp(argv[1], "dec") == 0){
            enc = false;
        }
        filename = argv[2];
        break;
    default:
        cout << "Usage is: " << endl;
        cout << "four_square about" << endl;
        cout << "four_square --help" << endl;
        cout << "four_square gen" << endl;
        cout << "four_square enc filename" << endl;
        cout << "four_square dec filename" << endl;
        return 1;
        break;
  }

  ifstream inFile(filename);
  ofstream outFile("message.txt");
  ifstream keyFile("square.key");
  char key1[25], key2[25], first, second;

  for(int i = 0; i < 25; ++i){
    keyFile >> key1[i];
  }
  keyFile.get(first);
  for(int i = 0; i < 25; ++i){
    keyFile >> key2[i];
  }
  while(!inFile.eof()){
    inFile.get(first);
    second = ' ';
    inFile.get(second);
    if(enc){
        cout << key1[getRow(first)*5+getCol(second)] << " "
            << key2[getRow(second)*5+getCol(first)] << " ";
    }
    else{

    }
  }

  return 0;
}

int getRow(char c){
    int value = static_cast<int>(c) - static_cast<int>('A');
    if (value > 8) value--;
    return value/5;
}
int getCol(char c){
    int value = static_cast<int>(c) - static_cast<int>('A');
    if (value > 8) value--;
    return value%5;
}

void array_swap(char a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}
