// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: XOR_20210268.cpp
// Program Description: Ciphers & deciphers text by applying XOR with a secret letter to each letter
// Last Modification Date: xx/xx/xxxx
// Author and ID and Group: Omar Ezz El-Deen, 20210268, Group A
// Teaching Assistant: xxxxx xxxxx
// Purpose: Cipher and decipher text

#include <iostream>
#include <string>

int secretLetter()   // Function to take the secret letter from the user
{
	char letter = ':';
	std::string test;
	while (letter < 65 || letter > 122) {      // Loops until a letter is entered
		std::cout << "Enter the secret letter: ";
		std::getline(std::cin, test);
		if (test.length() == 1) {        // Makes sure one single letter is entered
			letter = test[0];
		}
	}
	return int(letter);        // Returns the ASCII value of the letter
}


int cipher()      // Function to cipher the message
{
	int secret = secretLetter();       // Stores the ASCII value of the secret letter to be used  
	std::string ciphered = "", message;
	std::cout << "Enter the message you want to cipher: ";
	std::getline(std::cin, message);        // Takes the message from the user
	
	for (int i = 0; i < message.length(); i++) {   // For each letter in the message
		ciphered += char((secret ^ int(message[i])) + 96);  // XOR the secret letter and the current letter of the message
	}													    // Store each ciphered character in the string variable
	std::cout << "Ciphered text: " << ciphered << "  (Hexa ";   // Print the ciphered message

	for (int i = 0; i < message.length(); i++) {    // For each letter in the message
		std::cout << std::hex << (secret ^ int(message[i])) + 96;   // Print the hex of the result of XOR
	}
	std::cout << ")\n\n";
	return 0;
}

int decipher_text()              // Function to decipher the ciphered text (input in the form of text)
{
	int secret = secretLetter();
	std::string deciphered = "", text;
	std::cout << "Enter the text you want to decipher: ";
	std::getline(std::cin, text);       // Take the ciphered text to be deciphered

	for (int i = 0; i < text.length(); i++) {
		deciphered += char( (int(text[i]) - 96) ^ secret );    // XOR the secret letter and the current letter of the text
	}														   // Store each deciphered character in the string variable
	std::cout << "Deciphered text: " << deciphered << std::endl << std::endl;  // Print the deciphered message
	return 0; 
}

int decipher_hex()				// Function to decipher the ciphered text (input in the form of hexadecimal)
{
	int secret = secretLetter(), hex;
	std::string deciphered = "", text, sub;
	std::cout << "Enter the hexadecimal you want to decipher: ";
	std::getline(std::cin, text);				// Take the hexadecimal input

	for (int i = 0; i < text.length(); i += 2) {
		sub = text.substr(i, 2);      // Take a substring of the input of length 2 (bec. the hex of a char is 2 numbers)
		hex = stoi(sub, 0, 16);       // Turn the hexadecimal string to a decimal integer
		deciphered += char( (hex - 96) ^ secret );  // XOR  the decimal value of the current character with the secret letter
	}
	std::cout << "Deciphered text: " << deciphered << std::endl << std::endl;  // Print the deciphered message
	return 0;
}


int main() 
{
	int process = 0;
	while (process != 3) {          // Loops until the user chooses (3- End)
		std::cout << "Please enter the number of what you want to do\n";
		std::cout << "1- Cipher a message\n";
		std::cout << "2- Decipher a message\n";
		std::cout << "3- End\n";
		std::cin >> process;     // Takes the choice of the user
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // necessary so that the next getline works
		
		if (std::cin.fail()) {       // If the user inputs an invalid 
			std::cin.clear();        // clear and ignore cin
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;                // Ask him to choose again
		}      
		
		
		switch (process) {
		case 1:                                  // If the user chose 1 
			cipher();                            // Call the cipher function 
			break;
		
		case 2:                     // If the user chose 2
			int x = 0;
			while (x < 1 || x > 2) {
				std::cout << "Enter the number of what you want to do\n";    // Ask what type of input to use
				std::cout << "1- Decipher text\n";
				std::cout << "2- Decipher hexa\n";
				std::cin >> x;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (std::cin.fail()) {             // If the user inputs an invalid
					std::cin.clear();              // clear and ignore cin
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			switch (x) {
			case 1:         // If the user chose 1 
				decipher_text();   // call the decipher function using text
				break;
			case 2:         // If the user chose 2 
				decipher_hex();    // call the decipher function using text 
				break;
			}
			
			break;
		}
	}
	std::cout << "\nThanks for using the application\n";
}