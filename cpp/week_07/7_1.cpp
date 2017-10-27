#include <iostream>
using namespace std;
// 在此处补充你的代码

template < class T >
class CArray3D {
	T *ptr, *ptrtemp;
	int temp, flag;
	int i, j, k, temp_i, temp_j, temp_k;
public:
	CArray3D (int x, int y, int z) {
		i = x; j = y; k = z;
		ptr = new T[i*j*k];
		ptrtemp = ptr;
		flag = 0;
	}
	CArray3D<T> & operator [] ( int indx ) {
		if ( flag == 0 ) {
			ptr = ptrtemp;
			temp_i = indx;
			flag++;
			return *this;
		}
		if ( flag == 1 ) {
			temp_j = indx;
			flag++;
			return *this;
		}
		else {
			temp_k = indx;
			flag = 0;
			ptr += temp_i * j * k + temp_j * k + temp_k;
			return *this;
		}
	}
	void operator = ( int key ) {
		*ptr = key;		
	}
	template < class T >
	friend ostream & operator << ( ostream &os , CArray3D<T> &a );
};
template < class T >
ostream & operator << ( ostream &os , CArray3D<T> &a ) {
	os << *a.ptr;
	return os;
}
//////////////////////////////////
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
			
   for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
			
return 0;
}