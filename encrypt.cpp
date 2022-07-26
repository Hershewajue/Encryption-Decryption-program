//Group project 2 - Encrypting & Decrypting program
#include <iostream>
#include <string>
using namespace std;

//declaring the functions
string encode(string, char[], char[], int);
string decode(string, char[], char[], int);

int main(){
    //definitions and initialization
	const int size = 53;
	char decryptionText[size] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	char encryptionText[size] = {'S','X','G','W','L','Z','P','D','O','K','F','I','V','U','H','J','Y','T','Q','B','N','M','A','C','E','R','s','x','g','w','l','z','p','d','o','k','f','i','v','u','h','j','y','t','q','b','n','m','a','c','e','r','%'};
	
	//string userInput = "I Love Programming";
	
	//get the input from the user
	cout << "Please enter the data to be encrypted:" << endl;
	string userInput;
	getline(cin, userInput);
	
	//displaying the message
	cout << endl;
	cout << "Original message is \n" << userInput << endl << endl;
	cout << "Encoded message is \n"<< encode(userInput, decryptionText, encryptionText, size) << endl << endl;
	string encodedText = encode(userInput, decryptionText, encryptionText, size);
	cout << "Decoded message is \n"<< decode(encodedText, decryptionText, encryptionText, size) << endl << endl;
}
//function to encode the message
string encode(string userInput, char decryptionText[], char encryptionText[], int size){
	string encodedText = userInput;
	int x = userInput.length();	                    //capture the length of the message
	for(int i = 0; i < x; i++){                     //loop through the message
		for(int j = 0; j < size; j++){              //loop through the decryption text
			if(userInput[i] == decryptionText[j]){
				encodedText[i] = encryptionText[j]; //stores the encypted text
			}
		}
	}
	return encodedText;
}
//function to decode the message
string decode(string encodedText, char decryptionText[], char encryptionText[], int size){
	string decodedText = encodedText;
	int x = encodedText.length();	                    //capture the length of the message
	for(int i = 0; i < x; i++){                         //loop through the message
		for(int j = 0; j < size; j++){                  //loop through the decryption text
			if(encodedText[i] == encryptionText[j]){
				decodedText[i] = decryptionText[j];     //stores the encypted text
			}
		}
	}
	return decodedText;
}

