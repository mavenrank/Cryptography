#include <iostream>
using namespace std;

typedef enum {
    a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8, j = 9, k = 10, l = 11, m = 12, n = 13, o = 14, p = 15, q = 16, r = 17, s = 18, t = 19, u = 20, v = 21, w = 22, x = 23, y = 24, z = 25 
} Alphabet;

void caeserEncypt(string plainText, int key)
{
    string cipherText;
    for (int i = 0; i < plainText.length(); i++){
        char ch = plainText[i];
        if ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')){
            char encrypedValue = (ch + key - 'a') % 26;
            char encryptedCh = 'a' + encrypedValue;
            cipherText += encryptedCh;
        }
        else{
            cout << "Invalid String Entered!" << endl;
            return;
        }
    }

    cout << "CipherText : " << cipherText;
}

void caeserDecrypt(string cipherText, int key)
{
    string plainText;
    for (int i = 0; i < cipherText.length(); i++){
        char ch = cipherText[i];
        if ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')){
            char decryptedValue = (ch - key - 'a') % 26;
            char decryptedCh = 'a' + decryptedValue;
            plainText += decryptedCh;
        }
        else{
            cout << "Invalid String Entered!" << endl;
            return;
        }

    }
    cout << "Plain Text : " << plainText;
}

int main()
{
    bool flag = true;
    cout << "Caeser's Algorithm" << endl;
    int choice;
    while (flag)
    {
        cout << "\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter your Choice : ";
        cin >> choice;
        string plainText;
        string cipherText;
        int key;
        switch (choice)
        {
        case 1:
            cout << "Enter your Text : ";
            cin >> plainText;
            cout << "Enter the Key for Caeser :";
            cin >> key;
            caeserEncypt(plainText, key);
            break;
        case 2:
            cout << "Enter Cipher/Encypted Text : ";
            cin >> cipherText;
            cout << "Enter the Key for Caeser :";
            cin >> key;
            caeserDecrypt(cipherText, key);
            break;
        case 3:
            cout << "Exiting ...";
            exit(1);
        }
    }
}