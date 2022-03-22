

#include <iostream>
#include <iomanip>
using namespace std;

//Encryption function
void cipherEncryption(){
    int key_i = 0;
    string msg;
    string key;
    string result;
    cout << "Please enter a text to encrypt it: " << endl;
    getline(cin, msg);
    cout << "Please enter a key: " << endl;
    getline(cin, key);

    cout << "Encrypted Text:";
    for (int i = 0; i < msg.length(); i++) {
        result = msg[i] ^ key[key_i];
        cout << result;
    }
//Hexadecimal
    string encrypHexa = "";
    stringstream res;
    for (int i = 0; i < msg.length(); i++) {
        int result = msg[i] ^ key[key_i];
        res << hex << setfill('0') << std::setw(2) << (int) result;
        key_i++;
        if (key_i >= key.length()) {
            key_i = 0;
        }
        cout << "";
    }
    cout << "\n";
    res >> encrypHexa;
    cout << "Hexa:" << encrypHexa << endl;

}


//Decryption function
void cipherDecryption() {
//input message
    string msg;
    cout << "Please enter a text to decrypt in hexadecimal:"<<endl;
    getline(cin, msg);
//input key
    string key;
    cout << "Please enter a key:"<<endl;
    cin >> key;
//convert from hex
    string hex_to = "";
    for (int i = 0; i < msg.length() - 1; i += 2) {
        string output = msg.substr(i, 2);
        int decimal = strtol(output.c_str(), NULL, 16);
        hex_to += (char) decimal;
    }
    string result = "";
    int key_i = 0;
    for (int i = 0; i < hex_to.length(); i++) {
        result +=  hex_to[i] ^ key[key_i];
    }
    cout << result << endl;;

}

int main() {
    cout << "Hallo User";
    int choose;
    while (choose != 3) {
        cout << endl << "1-Cipher a text.\n2-Decipher a text.\n3-Exit." << endl;
        cout << "Enter 1,2 or 3:" << endl;
        cin >> choose;
        cin.ignore();
//choose 1 Encryption
        if (choose == 1) {
            cipherEncryption();
        }
//choose 2 Decryption
        else if (choose == 2) {
            cipherDecryption();

        }
//choose 3 End
        else if (choose == 3) {
            exit(0);

        } else
            cout<<"Wrong input enter again";
    }
}