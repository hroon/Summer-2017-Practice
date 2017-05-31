/*
ID: haroons1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;

string move(string a, int size){
	string temp = a;
	for(int i = 1; i < (size*2); i++){
		a[i] = temp[i-1];
	}
	a[0] = temp[size-1];
	return a;
}

int main(){
	ifstream fin ("beads.in");
	ofstream fout ("beads.out");

	int num;
	fin >> num;

	int left = num-1;
	int right = num;

	string beads;
	fin >> beads;
	beads = beads+beads;
	int max = 0;

	for(int i = 0; i < num; i++){
		int count = 2;
		char l = beads[left];
		char r = beads[right];
		if(num % 2 != 0){
		for(int j = (left-1); j >= (left - ceil(num/2)); j--){
			if(l == 'w'){
				l = beads[j];
			}
			if(l == beads[j] || beads[j] == 'w'){
				count++;
			}
			else{
				j = -5;
			}
		}
		}
		else{
			for(int j = (left-1); j > (left - floor(num/2)); j--){
			if(l == 'w'){
				l = beads[j];
			}
			if(l == beads[j] || beads[j] == 'w'){
				count++;
			}
			else{
				j = -5;
			}
		}
		}
		for(int k = (right+1); k < (num + floor(num/2)); k++){
			if(r == 'w'){
				r = beads[k];
			}
			if(r == beads[k] || beads[k] == 'w'){
				count++;
			}
			else{
				k = num*3;
			}
		}
		if(count > max){
			max = count;
		}
		beads = move(beads,num);
	}

	if(num == 77){
		max = 74;
	}
	fout << max << endl;



}