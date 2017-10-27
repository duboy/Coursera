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

int main ( )
{
	int Case, d_h, n_h, i_h, l_h, w_h;
	bool flgR = 1, flgB = 1;
	int timeR = 0, timeB = 0, M;

	cin >> Case;
	cin >> M;
	cin >> d_h >> n_h >> i_h >> l_h >> w_h;
	int &M_r = M, M_b = M; 
	
	Warrior dragon("dragon", d_h), ninja("ninja", n_h), iceman("iceman", i_h), lion("lion", l_h), wolf("wolf", w_h);
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