// Affine cipher 소스 코드 작성 
#include <iostream>
#include <string>
using namespace std;

void Encryption(); // 암호화 
void Decryption(); // 복호화
int inverse(int); // 역원 구하기 

int main(void) {
	while(1) {
		cout << "---------------Affine Cipher---------------\n";
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
	
	cout << "Input Two Keys : ";
	int a, b;
	cin >> a >> b;
	
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='a' && s[i]<='z') {
			s[i] = s[i] - 'a';
			s[i] = (s[i] * a + b)%26;
			s[i]=s[i]+'a';
		}
		else if(s[i]>='A' && s[i]<='Z') {
			s[i] = s[i] - 'A';
			s[i] = (s[i] * a + b)%26;
			s[i]=s[i]+'A';
		}
	}
	
	cout << "\nCipher Text : " << s << "\n";
}

void Decryption(void) {
	cout << "\nInput Cipher Text : ";
	string s;
	cin.ignore();
	getline(cin, s);
	
	cout << "Input Two Keys : ";
	int a, b;
	cin >> a >> b;
	
	a = inverse(a);
	
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='a' && s[i]<='z') {
			s[i] = s[i] - 'a';
			s[i] = (a * (s[i]-b))%26;
			if(s[i]<0) s[i]+=26;
			s[i] = s[i] + 'a';
		}
		else if(s[i]>='A' && s[i]<='Z') {
			s[i] = s[i] - 'A';
			s[i] = (a * (s[i]-b))%26;
			if(s[i]<0) s[i]+=26;
			s[i] = s[i] + 'A';
		}
	}
	
	cout << "\nPlain Text : " << s << "\n";
}

int inverse(int num) {
	for(int i=1; i<26; i++) {
		if((num*i)%26==1) return i;
	}
} 
