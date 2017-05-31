/*
ID: haroons1
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>


using namespace std;

void print_arr(char** a, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

char** rotation(char** arr, int n){
	char** array2D = 0;
	array2D = new char*[n];
	for(int i = 0; i < n; i++){
		array2D[i] = new char[n];
		for(int j = 0; j < n; j++){
			array2D[i][j] = arr[n-1-j][i];
		}
	}
	return array2D;
}

char** reflection(char** arr, int n){
	char** array2D = 0;
	array2D = new char*[n];
	for(int i = 0; i < n; i++){
		array2D[i] = new char[n];
		for(int j = 0; j < n; j++){
			array2D[i][j] = arr[i][n-j-1];
		}
	}
	return array2D;
}

bool compare(char** a, char** b, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){

	ifstream fin("transform.in");
	ofstream fout("transform.out");

	

	int size;
	fin >> size;

	char** arr;
	char** af;
	arr = new char*[size];
	af = new char*[size];

	for(int i = 0; i < size; i++){
		arr[i] = new char[size];
		for(int j = 0; j < size; j++){
			char d;
			fin >> d;
			arr[i][j] = d;
		}
	}
	for(int i = 0; i < size; i++){
		af[i] = new char[size];
		for(int j = 0; j < size; j++){
			char d;
			fin >> d;
			af[i][j] = d;
		}
	}



	char** arr_r1 = rotation(arr,size);

	if(compare(af,arr_r1,size)){
		fout << 1 << endl;
		return 0;
	}

	char** arr_r2 = rotation(arr_r1,size);
	if(compare(af,arr_r2,size)){
		fout << 2 << endl;
		return 0;
	}

	char** arr_r3 = rotation(arr_r2, size);
	if(compare(af,arr_r3,size)){
		fout << 3 << endl;
		return 0;
	}

	char** arr_4 = reflection(arr,size);
	if(compare(af,arr_4,size)){
		fout << 4 << endl;
		return 0;
	}

	char** arr_51 = rotation(arr_4,size);
	char** arr_52 = rotation(arr_51,size);
	char** arr_53 = rotation(arr_52,size);
	if(compare(af,arr_51,size) || compare(af,arr_52,size) || compare(af,arr_53,size)){
		fout << 5 << endl;
		return 0;
	}

	if(compare(af,arr,size)){
		fout << 6 << endl;
		return 0;
	}
	fout << 7 << endl;
	






	return 0;
}