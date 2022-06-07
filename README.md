
# Vigenère Cipher Encryption and ecryption

Project Name: 	Vigenère Cipher Encryption and Decryption
Course Name: 	CIS-7 Discrete Structures
Author: Zhongbin Qiu
Public Date: 06/07/22

## Project Information

#### 1. Vigenère cipher introduction

> The Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers, based on the letters of a keyword. It employs a form of polyalphabetic substitution.

#### 2. Algorithm implementation

##### 2.1 Vigenère table analysis and Algorithm implementation

By analyzing the Vigenere Table, we can think of the first row as a plaintext alphabet and label them with numbers starting from 0 to 25. Treat the first column as the alphabet of the keyword, and also mark their index values with numbers from 0 to 25, which also represent the letter offset of the row in which it is located.
![enter image description here]([[https://s1.ax1x.com/2022/06/07/XDp15d.jpg](https://raw.githubusercontent.com/zbqiu/cis7-final-project/main/Vigene%CC%80re-table.jpeg)](https://raw.githubusercontent.com/zbqiu/cis7-final-project/main/Vigene%CC%80re-table.jpeg))
Therefore, we can use mathematical formulas to express the correspondence between plaintext, keyword, and ciphertext.

##### 2.2  Calculation description

Abbr.
P: PlainText
E: EncryptedText
K: Keyword
i: index

Encryption

```
Ei = (Pi + Ki) mod 26
```

Decryption

```
Di = (Ei - Ki + 26) mod 26
```

## How to use the project
This project is written in C++. simply run the .cpp code on any C++ IDE and compile it. Interacting Through the IDE terminal, input plaintext to encrypt, and keyword, will get encrypted text. And vice versa.
