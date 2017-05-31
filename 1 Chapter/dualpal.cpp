/*
ID: haroons1
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

inline char to_char(int c){
	if(c >=10){
		return c - 10 + 'A';
	}
	return c + '0';
}

string conv(int a, int base){
	//int remainder = 0;
	string palin;
	while(a >= 1){
		int remainder = a % base;
		//cout << remainder << endl;
		char c = to_char(remainder);
		palin += c;
		if(a == 1){
			break;
		}
		a /= base;
	}
	return palin;
}

string reverse_str(string a){
	reverse(a.begin(), a.end());
	return a;
}

int main(){

	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");

	int num, min;
	fin >> num >> min;
	int current = min+1;


	while(num > 0){
		bool p = false;
		int count = 0;
		for(int i = 2; i <= 10; i++){
			string temp = conv(current,i);
			string reverse = reverse_str(temp);
			if (temp == reverse){
				count++;
			}
			if (count == 2){
				p = true;
				break;
			}
		}
		if(p){
			fout << current << endl;
			num--;
		}
		current++;
	}


	return 0;
}