/*
ID: haroons1
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct gap{
	int start;
	int end;
	int size;
};

bool comparator(gap lhs, gap rhs){
	return lhs.size < rhs.size;
}

int main(){

	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int max_boards, num_stalls, num_cows;
	fin >> max_boards >> num_stalls >> num_cows;

	vector<int> myVec; 

	for(int i = 0; i < num_cows; i++){
		int occ;
		fin >> occ;
		myVec.push_back(occ);
	}

	sort(myVec.begin(), myVec.end());

	int num_boards = num_cows;
	int stalls_blocked = num_cows;

	//int current = myVec[0];
	int current = myVec[0];
	vector<gap> gaps;

	/*vector<int> Cow;
	for(int i = 0; i < num_stalls; i++){
		if(i )
	}*/

	for(int i = 0; i < num_cows; i++){
		int diff = myVec[i] - current;
		if(diff == 0){
			diff = 0;
		}
		else if(diff == 1){
			while(diff == 1 && i < num_cows-1){
				diff = myVec[i+1] - myVec[i];
				if(diff == 1){
					num_boards --;
					i++;
				}
				else{
					/*gap temp;
					temp.start = myVec[i];
					temp.end = myVec[i+1];
					temp.size = temp.end - temp.start - 1;
					gaps.push_back(temp);*/
					
				}

			}
		}
		else{
			gap temp;
			temp.start = current;
			temp.end = myVec[i];
			temp.size = temp.end - temp.start - 1;
			gaps.push_back(temp);
			cout << "gap" << endl;

		}
		current = myVec[i];
	}

	sort(gaps.begin(), gaps.end(), comparator);

	for(unsigned int i = 0; i < gaps.size(); i++){
		cout << gaps[i].start << " " << gaps[i].end << " " << 
		gaps[i].size << endl;
	}

	unsigned int i = 0;

	
	cout << "number of boards " << num_boards << endl;
	cout << "stalls blocked " << stalls_blocked << endl;
	while(num_boards > max_boards){
		stalls_blocked += (gaps[i].size);
		num_boards--;
		cout << "board added between: " << gaps[i].start << " " <<
		gaps[i].end << endl;
		i++;
		if (i == gaps.size()){
			break;
		}
		cout << num_boards << endl;
		//cout << stalls_blocked << endl;
	}

	fout << stalls_blocked << endl;



	return 0;
}