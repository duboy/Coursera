#include <iostream>
#include <string>
using namespace std;

class Student{
	string name, id;
	unsigned short age, avg1, avg2, avg3, avg4;
	
	public:
	void process () {
		cout << name + ',' << age << ',' << id + ',' << (avg1 + avg2 + avg3 + avg4)/4;
	}
	
	Student ( string &n, unsigned short &a, string &i, unsigned short &g1, unsigned short &g2, unsigned short &g3, unsigned short &g4){
		name = n;
		age = a;
		id = i;
		avg1 = g1;
		avg2 = g2;
		avg3 = g3;
		avg4 = g4;				
	}
};

int main ()
{
	string name, id;
	unsigned short age, avg1, avg2, avg3, avg4;
	char temp;
	
	getline (cin, name, ',');
	cin >> age >> temp;
	getline (cin, id, ',');
	cin >> avg1 >> temp >> avg2 >> temp >> avg3 >> temp >> avg4;

	Student S1 ( name, age, id, avg1, avg2, avg3, avg4);
	S1.process();
	
}