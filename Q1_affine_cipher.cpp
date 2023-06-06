#include<iostream>
using namespace std;

const int a=17;
const int b=20;

int findInverse(){
    
    int flag = 0;
    for(int i=0; i<26; i++){
        flag = (a*i)%26;
        if(flag == 1) return i;
    }
    return 0;
}

string cipher(string plainText){
    string cipherText = "";

    for(int i=0; i<plainText.length(); i++){
        cipherText += (char) ((((a * (plainText[i] - 'A')) + b) % 26) + 'A');
    }    

    return cipherText;
}

string decipher(string cipherText){
    string plainText = "";
    int aInv=0;

    aInv = findInverse();

    for(int i=0; i<cipherText.length(); i++){
        plainText += (char) (((aInv * ((cipherText[i]+'A' - b)) % 26)) + 'A');
    }

    return plainText;
}

int main(){
    string plainText, cipherText;
    
    cout<<"Enter text to encrypt: ";
    cin>>plainText;

    cipherText = cipher(plainText);
    cout<<"Cipher Text: "<<cipherText<<endl;
    
    plainText = decipher(cipherText);
    cout<<"Plain text: "<<plainText;

    return 0;
}