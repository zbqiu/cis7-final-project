//  CIS7 FinalProject
//  Case 3: Vigenère Cipher
//  Zhongbin Qiu
//  Instructor: Professor Kasey Nguyen, PhD.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// function to encrypt plaintext to ciphertext with keyword by using Vigenère Cipher
void Encrypt(const string &plaintext, const string &keyWord, string *ciphertext)
{
    //keywords only accept alpahbet letters,filter userinput keyword.
    string keyStr;
    for (int i = 0; i < keyWord.length(); i++) {
        char ch = keyWord[i];
        if(isalpha(ch)){
            ch = toupper(ch);
            keyStr += ch;
        }
    }
    if(keyStr.length()<=0)
    {
        cout << "invalid key" << endl;
        ciphertext = NULL;
        return;
    }
    
    // traverse plaintext
    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];
        
        // apply transformation to each alphabet letter only.
        if(isalpha(ch)){
            
            //which key in keyword to be used by Modulo
            int idx = i % keyStr.length();
            char k = keyStr[idx];
            
            // Convert the char to uppercase before transformation
            ch = toupper(ch);
            
            // int(ch)-65: Converting [A-Z] to numbers [0-25]
            ch = ( (int(ch)-65) + (int(k)-65) ) % 26 + 65;
        }
        
        //save the resulting result
        *ciphertext += char(ch);
    }
}

// function to Decrypt ciphertext to plaintext with keyword by using Vigenère Cipher
void Decrypt(const string &ciphertext, const string &keyWord, string *plainText)
{
    
    //keywords only accept alpahbet letters,filter userinput keyword.
    string keyStr;
    for (int i = 0; i < keyWord.length(); i++) {
        char ch = keyWord[i];
        if(isalpha(ch)){
            ch = toupper(ch);
            keyStr += ch;
        }
    }
    if(keyStr.length()<=0)
    {
        cout << "invalid key" << endl;
        return;
    }
    
    // traverse plaintext
    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];
        
        // apply transformation to each alphabet letter only.
        if(isalpha(ch)){
            
            //which key in keyword to be used by Modulo
            int idx = i % keyStr.length();
            char k = keyStr[idx];
            
            // Convert the char to uppercase before transformation
            ch = toupper(ch);
            
            // int(ch)-65: Convert ASCII to alphabetical order number
            ch = (int(ch) - int(k) + 26) % 26 + 65;
        }
        *plainText += char(ch);
    }
}


int main() {
    
    string plainText, cipherText, keyWord;
    int mode = 0;
    while(mode != 1 && mode !=  2)
    {
        cout << "--- Welcome to use Vigenère Cipher ---\nSelect mode" << endl;
        cout << "1.Encryption Mode" << endl;
        cout << "2.Decryption Mode" << endl;
        cout << "\nPlease input 1 or 2: ";
        cin >> mode;
        cin.ignore();
    }
    
    // mode 1 for encryption
    if(mode == 1) {
        cout << endl << "Please input texts for encryption: ";
        getline(cin,plainText);
        cout << endl << "Please input keyword for encryption: ";
        getline(cin,keyWord);
        
        Encrypt(plainText, keyWord, &cipherText);
        
        cout << endl << "--------Encryption Result-------"<< endl;
        cout << "Plain: " << plainText << endl;
        cout << "Keyword: " << keyWord << endl << endl;
        cout << "Cipher: " << cipherText << endl;
    }
    // mode 2 for decryption
    else if (mode == 2) {
        cout << endl << "Please input ciphertexts for decryption: " << endl;
        getline(cin,cipherText);
        cout << endl << "Please input keyword for decryption: " << endl;
        getline(cin,keyWord);
        
        Decrypt(cipherText, keyWord, &plainText);
        
        cout << endl << "--------Decryption Result-------"<< endl;
        cout << "Cipher: " << cipherText << endl;
        cout << "Keyword: " << keyWord << endl << endl;
        cout << "Plain: " << plainText << endl;
    }

    return 0;
}
