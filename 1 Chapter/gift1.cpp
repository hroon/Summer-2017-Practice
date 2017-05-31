/*
ID: haroons1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){

	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");

	int num;		//number of people
	fin >> num;

	string current,temp;

	map<string,int> m; //maps the name to their money
	map<int,string> order; //maps the order to the name


	for(int i = 0; i < num; i++){
		fin >> temp;
		m[temp] = 0;
		order[i] = temp;
	}

	for(int i = 0; i < num; i++){
		fin >> current;
		int money, friends, spend, keep;
		fin >> money >> friends;
		//m[current] += money;
		if(friends == 0){
			friends = 0;
		}
		else{
			keep = money % friends;
			spend = (money - keep)/friends;
			m[current] -= (spend*friends);
			for(int j = 0; j < friends; j++){
				fin >> temp;
				m[temp] += spend;
			}
		}
		/*for(map<string,int>::const_iterator it = m.begin(); it != m.end(); ++it){
			fout << it->first << " " << it->second << "\n";
		}
		fout << "\n";*/
	}

	for(map<int,string>::const_iterator it = order.begin(); it != order.end(); ++it){
		fout << it->second << " " << m[it->second] << "\n";

	}





	return 0;
}