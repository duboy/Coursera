#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int redNum = 0;
int bluNum = 0;
string weaponList[3] = { "sword", "bomb", "arrow" };

class Warrior {
public:
	int num, hp;
	Warrior (int H) : num(0), hp(H) { }
	virtual void process ( int &Num, int &hp, string side ) { }
	
};
class Dragon : public Warrior {
public:
	int weapon;
	float morale;
	Dragon (int &H) : Warrior (H) { }
	virtual void process ( int &Num, int &Hp, string side ) { //Num 此时总数, hp 剩余生命元
		weapon = Num % 3;
		morale = float (int ( (float (Hp) / hp) * 100 + 0.5)) / 100;
		cout << side + " dragon " << Num << " born with strength " << hp << "," << ++num 
			<< " dragon in " << side << " headquarter" << endl;
		cout << "It has a " << weaponList[weapon] << ",and it's morale is " 
			<< setiosflags(ios::fixed) << setprecision(2) << morale << endl;
	}
};
class Ninja : public Warrior {
public :
	int weapon[2];
	Ninja (int &H) : Warrior (H) { }
	virtual void process ( int &Num, int &Hp, string side ) {
		weapon[0] = Num % 3;
		weapon[1] = (Num + 1) % 3;
		cout << side + " ninja " << Num << " born with strength " << hp << "," << ++num 
			<< " ninja in " << side << " headquarter" << endl;
		cout << "It has a " << weaponList[weapon[0]] << " and a " << weaponList[weapon[1]] << endl; 
	}
};
class Iceman : public Warrior { 
public :
	int weapon;
	Iceman (int &H) : Warrior (H) { }
	virtual void process ( int &Num, int &Hp, string side ) {
		weapon = Num % 3;
		cout << side + " iceman " << Num << " born with strength " << hp << "," << ++num 
			<< " iceman in " << side << " headquarter" << endl;
		cout << "It has a " << weaponList[weapon] << endl;
	}
};
class Lion : public Warrior {
public :
	int loyalty;
	Lion (int &H) : Warrior (H) { }
	virtual void process ( int &Num, int &Hp, string side ) {
		loyalty = Hp;
		cout << side + " lion " << Num << " born with strength " << hp << "," << ++num 
			<< " lion in " << side << " headquarter" << endl;
		cout << "It's loyalty is " << loyalty << endl;
	}
};
class Wolf : public Warrior {
public :
	Wolf (int &H) : Warrior (H) { }
	virtual void process ( int &Num, int &Hp, string side ) {
		cout << side + " wolf " << Num << " born with strength " << hp << "," << ++num 
			<< " wolf in " << side << " headquarter" << endl;
	}
};

void output (int M, vector<int>::iterator hp) { // M 初始生命元 hp 每个战士的生命，共五个。
	int redNum = 0;
	int bluNum = 0;
	bool flgR = 1, flgB = 1;
	int &M_r = M, M_b = M; 
	int timeR = 0, timeB = 0;
	Dragon RDragon(hp[0]); Ninja RNinja(hp[1]); Iceman RIceman(hp[2]); Lion RLion(hp[3]); Wolf RWolf(hp[4]);
	Dragon BDragon(hp[0]); Ninja BNinja(hp[1]); Iceman BIceman(hp[2]); Lion BLion(hp[3]); Wolf BWolf(hp[4]);
	vector<Warrior *> redW;
	vector<Warrior *> bluW;
	
	redW.push_back(&RIceman);
	redW.push_back(&RLion);
	redW.push_back(&RWolf);
	redW.push_back(&RNinja);
	redW.push_back(&RDragon);	

	bluW.push_back(&BLion);
	bluW.push_back(&BDragon);
	bluW.push_back(&BNinja);
	bluW.push_back(&BIceman);
	bluW.push_back(&BWolf);

	while ( flgR | flgB ) {
		while (flgR) {
			if ( M_r >= (*redW.begin())->hp ) {
				M_r -= (*redW.begin())->hp;
				cout << setfill('0') << setw(3) << timeR++ << " ";
				(*redW.begin()) -> process( ++redNum, M_r, "red" );			
				redW.push_back ( redW[0] );
				redW.erase( redW.begin() );
				break;
			}
			
			else if ( !redW.empty() ){
				redW.erase( redW.begin() );
			} 
			if ( redW.empty() ) {
				cout << setfill('0') << setw(3) << timeR++ << " ";
				cout << "red headquarter stops making warriors" << endl;
				flgR = 0;
			}
		}
		while (flgB) {
			if ( M_b >= (*bluW.begin())->hp ) {
				M_b -= (*bluW.begin())->hp;
				cout << setfill('0') << setw(3) << timeB++ << " ";
				(*bluW.begin()) -> process( ++bluNum, M_b, "blue" );
				bluW.push_back ( bluW[0] );
				bluW.erase( bluW.begin() );
				break;
			}
			else if ( !bluW.empty() )
				bluW.erase( bluW.begin() );
			if ( bluW.empty() ) {
				cout << setfill('0') << setw(3) << timeB++ << " ";
				cout << "blue headquarter stops making warriors" << endl;
				flgB = 0;
			}
		}
	}	
}

int main ()
{
	int Case, m;
	int hp;
	cin >> Case;
	vector<int> M;
	vector<int> Hp;

	while ( Case-- )
	{
		cin >> m;
		M.push_back(m);
		
		for (int i = 0; i < 5; i++) {
			cin >> hp;
			Hp.push_back(hp);
		}
		
	}
	
	vector<int>::iterator it_M = M.begin(); 
	for (vector<int>::iterator it_H = Hp.begin(); it_H != Hp.end(); it_H += 5) {
		cout << "Case:" << ++Case+1 << endl;
		output(*it_M++, it_H);
	}

}