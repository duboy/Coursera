#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int redNum = 0;
int bluNum = 0;

class Warrior {
	string name;
	int num;
	
	public:
		int hp;
		Warrior( string na, int &h ) {
			name = na;
			hp = h;
			num = 0;
		}
		void process (string side, int &cNum) {
			cout << ' ' + side;
			cout << ' ' + name + ' ' << ++cNum << " born with strength " << hp << "," << ++num << " " + name + " in ";
			cout << side + " headquarter" << endl;
		}
};

void output (int M, vector<int>::iterator hp)
{	
	int redNum = 0;
	int bluNum = 0;
	bool flgR = 1, flgB = 1;
	int &M_r = M, M_b = M; 
	int timeR = 0, timeB = 0;
	
	Warrior dragon("dragon", hp[0]), ninja("ninja", hp[1]), iceman("iceman", hp[2]), lion("lion", hp[3]), wolf("wolf", hp[4]);
	vector<Warrior> redW;
	vector<Warrior> bluW;
	
	redW.push_back(iceman);
	redW.push_back(lion);
	redW.push_back(wolf);
	redW.push_back(ninja);
	redW.push_back(dragon);	
	
	bluW.push_back(lion);
	bluW.push_back(dragon);
	bluW.push_back(ninja);
	bluW.push_back(iceman);
	bluW.push_back(wolf);
	
	while ( flgR | flgB ) {
		while (flgR) {
			if ( M_r >= redW.begin()->hp ) {
				M_r -= redW.begin()->hp;
				cout << setfill('0') << setw(3) << timeR++;
				redW.begin() -> process( "red", redNum );			
				redW.push_back ( *redW.begin() );
				redW.erase( redW.begin() );
				break;
			}
			
			else if ( !redW.empty() ){
				redW.erase( redW.begin() );
			} 
			if ( redW.empty() ) {
				cout << setfill('0') << setw(3) << timeR++;
				cout << " red headquarter stops making warriors" << endl;
				flgR = 0;
			}
		}
		while (flgB) {
			if ( M_b >= bluW.begin()->hp ) {
				M_b -= bluW.begin()->hp;
				cout << setfill('0') << setw(3) << timeB++;
				bluW.begin() -> process( "blue", bluNum );
				bluW.push_back ( *bluW.begin() );
				bluW.erase( bluW.begin() );
				break;
			}
			else if ( !bluW.empty() )
				bluW.erase( bluW.begin() );
			if ( bluW.empty() ) {
				cout << setfill('0') << setw(3) << timeB++;
				cout << " blue headquarter stops making warriors" << endl;
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