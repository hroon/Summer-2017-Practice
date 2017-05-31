/*
ID: haroons1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>


using namespace std;

class dot {
public:
		int day,dotw,month,year;
		void set_values(int,int,int,int);
};

void dot::set_values(int x, int a, int y, int z){
	day = x;
	dotw = a;
	month = y;
	year = z;
}


dot new_day(dot a, int m[]){
	if(a.month == 1){
		if(a.day == m[1]){
			a.day = 1;
			a.month = 2;
		}
		else{
			a.day++;
		}
	}
	else if(a.month == 11){
		if(a.day == m[11]){
			a.day = 1;
			a.month = 0;
			a.year++;
		}
		else{
			a.day++;
		}
	}
	else{
		if(a.day == m[a.month]){
			a.day = 1;
			a.month++;
		}
		else{
			a.day++;
		}
	}
	if(a.dotw == 6){
		a.dotw = 0;
	}
	else{
		a.dotw++;
	}
	return a;

}

int main(){
	ifstream fin ("friday.in");
	ofstream fout ("friday.out");

	int num;
	fin >> num;

	int days[7] = {0,0,0,0,0,0,0};
	int months[12];

	months[0] = 31; //January
	months[1] = 28; //February
	months[2] = 31; //March
	months[3] = 30; //April
	months[4] = 31; //May
	months[5] = 30; //June
	months[6] = 31; //July
	months[7] = 31; //August
	months[8] = 30; //September
	months[9] = 31; //October
	months[10] = 30; //November
	months[11] = 31; //December


	dot date;
	date.set_values(1,2,0,1900);
	bool going = true;

	

	while(going){
		int c = date.year;
		if(c % 100 == 0){
			if(c % 400 == 0){
				months[1] = 29;
			}
		}
		else if(c % 4 == 0){
			months[1] = 29;
		}
		else{
			months[1] = 28;
		}
		if(date.day == 13){
			days[date.dotw]++;
		}
		date = new_day(date,months);
		//fout << date.day << " " <<  date.month << " " << date.year << endl;
		
		if(date.day == 31){
			if(date.month == 11){
				if(date.year == (1900+num-1)){
					going = false;
				}
			}
		}
	}

	for(int i = 0; i < 6; i++){
		fout << days[i] << " ";
	}
	fout << days[6] << "\n";

	return 0;
}