#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
	int *ptr, *ptrTemp, temp;
	bool flg;
	public:
		Array2 (int row, int col) {
			ptr = new int [sizeof (int) * row * col];
			flg = 0;
			ptrTemp = ptr;
		}
		Array2 () {
			flg = 0;
			ptrTemp = ptr = NULL;
		}
		Array2 & operator [] ( int i) {
			if ( !flg ) {
				temp =  i * 4;
				flg = 1;
				return *this;
			}
			else {
				flg = 0;
				temp = temp + i;
				ptrTemp = ptr + temp;
				return *this;
			}
			
		} 		
		friend ostream & operator << (ostream &os , Array2 &a);
		void operator = (int key) {
			*(ptrTemp )= key;
		}
		Array2 & operator () (int i, int j) {
			ptrTemp = ptr;
			ptrTemp += i * 4 + j; 
			return *this;
		}
		Array2 & operator = ( Array2 &a ) {
			ptrTemp = ptr = a.ptr;
			return *this;
		}
		void print() {
			for (int m = 0; m < 12; m++)
			cout << *(ptr + m) << endl;
		}
};

ostream & operator << (ostream &os , Array2 &a) {
	os << *a.ptrTemp;
	return os;
};
// ---------------------------------
int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;	
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}