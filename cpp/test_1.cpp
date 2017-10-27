#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class MyString : public string {
	public :
		string s;
		MyString (string s_) {
			cout << "Initialized called" << endl;
			s = s_;
			cout << s << endl;
		}
		// MyString ( MyString &s_) {
			// s = s_.s;
		// }

		MyString () {};
		friend ostream & operator << ( ostream &os, MyString &s_);
		MyString & operator = ( MyString s_ ) {
			s = s_.s;
			cout << "= called s = " << s << endl;
			return *this;
		}
		MyString operator + ( MyString &s_ ) {
			s_.s = s_.s + s;
			return MyString ("sss");
		}
};
ostream & operator << ( ostream &os, MyString &s_) {
	os << s_.s;
	return os;
}
// MyString operator + ( MyString &s_1, MyString &s_2 ) {
	// cout << s_1.s + s_2.s << endl;
	// return MyString("sssss");
// }

int main() {
    MyString s1("abcd-"),s2("efgh-"),s4(s1);
	s4 = s1 + s2;
	cout << "s4: " << s4 << endl;
}