#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
	Big ( int n ) : b(n) {
		v = n;
	}
	Big ( Big & temp ) : b(temp.v) {
		v = temp.v;
	}
};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}