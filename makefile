classic_ciphers: vigenere vigenere_fast cylinder four_square

vigenere_fast: vigenere_fast.cpp
	g++ -o vigenere_fast vigenere_fast.cpp

vigenere: vigenere.cpp
	g++ -o vigenere vigenere.cpp
	
cylinder: cylinder.cpp
	g++ -o cylinder cylinder.cpp
	
four_square: four_square.cpp
	g++ -o four_square four_square.cpp
