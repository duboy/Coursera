#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int M;


class Warrior {
	int selfID = 0, hp;
	//static int redID = 0, blueID = 0, 
	
	string name;
	
	public:
		int passFlg = 0;
		Warrior (string na, int h) {
			name = na;
			hp = h;
		}
		void test(){
			cout << "test" << endl;
		}
		
		void process (){
			if (M = M - hp > hp){
				selfID++;
				cout << name << selfID++;
			}
		}
		
		void pass (){
			passFlg = 1;
			
		}
};
class List {
	struct Node {
		Warrior *w;
		Node *next;
		
		Node( Warrior &war) : w( &war ), next( NULL ) {}
		
	};
	
	Node *head;
	
	public:
		List ( ) {
			head = new Node;
		}
		
		void add ( Warrior &w ) {
			Node *p = new Node(w);
			p -> next = head -> next;
			head -> next = p;
		}
		
		void erase () {
			
		}
	
};
int main ()
{
	int Case, d_h, n_h, i_h, l_h, w_h;
	int time = 0;
	cin >> Case;
	cin >> M;
	cin >> d_h >> n_h >> i_h >> l_h >> w_h;
	
	cout << setfill('0')<<setw(3)<<time++<<endl;
	
	Warrior iceman("iceman", i_h);
	
	List listRed;
	listRed.add(iceman);
	
	/*
	//Warrior dragon(d_h), ninja(n_h), iceman(i_h), lion(l_h), wolf(w_h);
	Warrior red[5] = { Warrior("iceman", i_h), Warrior("lion", l_h), 
						Warrior("wolf", w_h), Warrior("ninja", n_h), Warrior("dragon", d_h) };
	Warrior blu[5] = { Warrior("lion", l_h), Warrior("dragon", d_h), 
						Warrior("ninja", n_h), Warrior("iceman", i_h), Warrior("wolf", w_h) };
	
	for (i = 0, int flagR = flagB = 0; flagR < 5 && flagB < 5; i++){
		
	}
	*/
	
}