classic_ciphers: vigenere vigenere_fast

vigenere_fast: vigenere_fast.cpp
	g++ -o vigenere_fast vigenere_fast.cpp

vigenere: vigenere.cpp
	g++ -o vigenere vigenere.cpp
