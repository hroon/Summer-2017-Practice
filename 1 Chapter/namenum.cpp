/*
ID: haroons1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;



bool compare(char a, char b){
	if(a == '2'){
		if(b == 'A' || b == 'B' || b == 'C'){
			return true;
		}
	}
	else if(a == '3'){
		if(b == 'D' || b == 'E' || b == 'F'){
			return true;
		}
	}
	else if(a == '4'){
		if(b == 'G' || b == 'H' || b == 'I'){
			return true;
		}
	}
	else if(a == '5'){
		if(b == 'J' || b == 'K' || b == 'L'){
			return true;
		}
	}
	else if(a == '6'){
		if(b == 'M' || b == 'N' || b == 'O'){
			return true;
		}
	}
	else if(a == '7'){
		if(b == 'P' || b == 'R' || b == 'S'){
			return true;
		}
	}
	else if(a == '8'){
		if(b == 'T' || b == 'U' || b == 'V'){
			return true;
		}
	}
	else if(a == '9'){
		if(b == 'W' || b == 'X' || b =='Y'){
			return true;
		}
	}
	return false;
}


int main(){

	ofstream fout ("namenum.out");
	ifstream fin ("namenum.in");
	ifstream din ("dict.txt");

	string serial;
	fin >> serial;

	unsigned int size = serial.length();
	list<string> myList;

	string arr[4617];
	bool word = false;

	for(int i = 0; i < 4617; i++){
		string temp;
		din >> temp;
		unsigned int count = 0;
		if(temp.length() == size){
			for(unsigned int j = 0; j < size; j++){
				if(compare(serial[j],temp[j])){
					count++;
				}
			}
			if(count == size){
				myList.push_back(temp);
				word = true;
			}
		}
	}

	if(word == false){
		fout << "NONE" << endl;
	}
	for(list<string>::const_iterator it = myList.begin(); it != myList.end(); ++it){
		fout << *it << endl;
	}
	return 0;
}