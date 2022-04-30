// Gronsfeld cipher 소스 코드 작성 
#include <iostream>
#include <string>
using namespace std;

void Encryption(); // 암호화 
void Decryption(); // 복호화

int main(void) {
	while(1) {
		cout << "---------------Gronsfeld Cipher---------------\n";
		cout << "1. Encryption\t2. Decryption\t3. Quit\n";
		cout << "Enter the number : ";
		int N;
		cin >> N;
		
		switch(N) {
			case 1:
				Encryption();
				break;
			case 2:
				Decryption();
				break;
			case 3:
				return 0;
			default:
				cout << "Wrong Input\n";
				break;
		}
	}
	
	return 0;
}

void Encryption(void) {
	cout << "\nInput Plain Text : ";
	string s;
	cin.ignore();
	getline(cin, s);
	
	cout << "Input Keys : ";
	string key;
	getline(cin, key);
	
	for(int i=0; i<s.size(); i++) {
		s[i] = s[i] + key[i] - '0';
	}
	
	cout << "\nCipher Text : " << s << "\n";
}

void Decryption(void) {
	cout << "\nInput Cipher Text : ";
	string s;
	cin.ignore();
	getline(cin, s);
	
	cout << "Input Keys : ";
	string key;
	getline(cin, key);
	
	for(int i=0; i<s.size(); i++) {
		s[i] = s[i] - key[i] + '0';
	}
	
	cout << "\nPlain Text : " << s << "\n";
}
