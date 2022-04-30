// Rail Fence cipher 소스 코드 작성 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Encryption(); // 암호화 
void Decryption(); // 복호화

int main(void) {
	while(1) {
		cout << "-------------Rail Fence Cipher-------------\n";
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
	
	cout << "Input the number of rail : ";
	int a;
	cin >> a;
	
	vector<string> v(a);
	int flag = 1, in = 0;
	int i=0;
	
	while(s[i]!=0) {
		v[in].push_back(s[i]);
		
		if(flag) {
			in++;
			
			if(in==a-1) flag = 0;
		}
		else {
			in--;
			
			if(in==0) flag = 1;
		}
		
		i++;
	}
	
	string text = "";
	for(int i =0; i<a; i++) {
		text += v[i];
	}	
	
	cout << "\nCipher Text : " << text << "\n";
}

void Decryption(void) {
	cout << "\nInput Cipher Text : ";
	string s;
	cin.ignore();
	getline(cin, s);
	
	cout << "Input the number of rail : ";
	int a;
	cin >> a;
	
	vector<string> v(a);
	int index = 0;
	string text(s.size());
	
	for(int i=0; i<a; i++) {
		int temp = i;
		
		while(temp < s.size()) {
			
		}
	}
	
	cout << "\nPlain Text : " << s << "\n";
}

