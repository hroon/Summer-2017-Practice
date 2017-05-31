/*
ID: haroons1
LANG: C++
TASK: palsquare
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

string tobase(int num, int base){
	string ret;
	int div = base;
	while(div < num){
		div *= base;
	}
	for(div /= base;;){
		ret += to_char(num/div);
		num = num % div;
		if(div < 2){
			break;
		}
		div /= base;
	}
	return ret;
}

string reverse_str(string a){
	reverse(a.begin(), a.end());
	return a;
}

int main(){

	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");

	int in;
	fin >> in;

	for (int i = 1; i <= 300; i++){
		string n = tobase(i,in);
		string n2 = tobase(i*i,in);
		if(n2 == reverse_str(n2)){
			fout << n << " " << n2 << endl;
		}
	}


	return 0;
}