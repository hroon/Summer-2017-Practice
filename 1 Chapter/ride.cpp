/*
ID: haroons1
LANG: C++
TASK: ride
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int str_to_num(string a){
	int x = 1;
	for (unsigned int i = 0; i < a.length(); i++){
		char c = a[i];
		int temp = (int)c % 32;
		x = x*temp;
	}
	return x;
}


int main(){

	ifstream fin ("ride.in");
	ofstream fout ("ride.out");

	string a, b;
	fin >> a >> b;	

	int c = str_to_num(a);
	int d = str_to_num(b);

	if( (c % 47) == (d % 47)){
		fout << "GO\n";
	}
	else{
		fout << "STAY\n";
	}


	return 0;
}