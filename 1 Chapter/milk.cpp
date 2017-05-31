/*
ID: haroons1
LANG: C++
TASK: milk
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct farmer{
	int cost;
	int unit;
};

bool comparator(farmer lhs, farmer rhs){
	return (lhs.cost < rhs.cost);
}


int main(){

	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int num_units, num_farmers;
	fin >> num_units >> num_farmers;
	int money = 0;

	vector<farmer> farm;

	for(int i = 0; i < num_farmers; i++){
		int temp1, temp2;
		fin >> temp1 >> temp2;
		farmer temp;
		temp.cost = temp1;
		temp.unit = temp2;
		farm.push_back(temp);
		//cout << farm[i].cost << " " << farm[i].unit << endl;
	}
	//cout << endl;
	sort(farm.begin(),farm.end(), comparator);
	/*for(int i = 0; i < num_farmers; i++){
		cout << farm[i].cost << " " << farm[i].unit << endl;
	}*/

	for(int i = 0; i < num_farmers; i++){
		//farmer current = farm[i];
		while(num_units > 0 and farm[i].unit > 0){
			money += farm[i].cost;
			farm[i].unit--;
			num_units--;
		}
	}

	fout << money << endl;

	return 0;
}