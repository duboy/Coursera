#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Time {
	string mins[5];
	string min;
	int hour, i;
public :
	Time () {
		mins[0] = "00"; mins[1] = "10"; mins[2] = "30"; mins[3] = "50"; mins[4] = "55";
		hour = 0;
		i = 0;
		min = mins[0];
	}
	Time & operator ++ (int k) {
		if ( i > 4 ) {
			i = 0;
			++hour;
			cout << endl;
		}
		min = mins[i++];
		return *this;
	}
	friend ostream & operator << ( ostream &os, Time & t );
};

ostream & operator << ( ostream &os, Time & t ) {
	os << setfill('0') << setw(3) << t.hour << ':' << t.min << endl;;
	return os;
}
int main () 
{
	Time time;
	for (int i = 0; i < 20; ++i) {
		cout << time++;	
	}
}