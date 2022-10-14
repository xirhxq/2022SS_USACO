#include<iostream>
using namespace std;

string read(){
    int T;
    char c;
    string s = "", str = "";
	while (cin >> c){
		if (c == '['){
			cin >> T;
			str = read();
			while (T--){
				s += str;
			}
		}
		else if (c == ']'){
			return s;
		}
		else{
			s += c;
		}
	}
}

int main(){
	cout << read();
	return 0;
}
