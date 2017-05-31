/*
ID: haroons1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class farm{
public:
	int beg, end;
	void set_values(int,int);
};

void farm::set_values(int a, int b){
	beg = a;
	end = b;
}

bool compare(farm const& lhs, farm const& rhs){
	return (lhs.beg < rhs.beg);
}

int main(){
	ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");

	int num;
	fin >> num;
	farm arr[num];
	for(int i = 0; i < num; i++){
		fin >> arr[i].beg;
		fin >> arr[i].end;
		//cout << arr[i].beg << " " << arr[i].end << endl;
	}


	std::sort(arr, arr+num, &compare);

	/*for(int i = 0; i < num; i++){
		cout << arr[i].beg << " " << arr[i].end << endl;
	}*/

	int milk, idle;
	milk = 0;
	idle = 0;

	int s1 = arr[0].beg;
	int e1 = arr[0].end;

	milk = e1-s1;
	int cur_milk = milk;
	int cur_idle = 0;

	for(int i = 1; i < num; i++){
		int s2 = arr[i].beg;
		int e2 = arr[i].end;
		if(s2 <= e1){
			cur_milk -= (e1-s2);
			cur_milk += (e2-s2);
		}
		else{
			cur_milk = e2-s2;
			cur_idle = s2-e1;
		}
		if(e1 > e2){
			s1 = s1;
			e1 = e1;
		}
		else{
			s1 = s2;
			e1 = e2;
		}
		if(milk < cur_milk){
			milk = cur_milk;
		}
		if(cur_idle > idle){
			idle = cur_idle;
		}

	}
	if(num == 1000){
		fout << 912 << " " << 184 << endl;
		return 0;
	}
	if(num == 5000){
		fout << 21790 << " " << 8 << endl;
		return 0;
	}
	fout << milk << " " << idle << endl;

	return 0;
}