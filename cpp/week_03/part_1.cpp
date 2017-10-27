
	A ( int n = 0 ) {val = n;}
	int & GetObj ( ) {
		int &b = this -> val;
		return b;
	}