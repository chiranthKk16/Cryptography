#include <bits/stdc++.h>
using namespace std;

int generate_symmetric_key(int g, int p, int x, int y) {
    
    int A = fmod(pow(g, x), p);
    int B = fmod(pow(g, y), p);

    // Calculate symmetric key
    int keyA = fmod(pow(B, x), p);
    int keyB = fmod(pow(A, y), p);

  
    if (keyA == keyB) {       
        return keyA;
    } else {
        return -1;
    }
}

int main() {
    int p = 23;
    int g = 9;  
    int x = 4;  //xPrivate key for Alice
    int y = 3;  //yPrivate key for bob
    
    cout<<"Given,\ng=9, p=23, x=4, y=3"<<endl;
  
    int SymmetricKey = generate_symmetric_key(g, p, x, y);

    if (SymmetricKey != -1) {
        cout<<"Symmetric Key generated: "<<SymmetricKey;
    } else {
        cout<<"Symmetric key could not be generated";
    }

    return 0;
}
