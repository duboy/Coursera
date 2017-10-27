
	Big ( int n ) : b(n) {
		v = n;
	}
	Big ( Big & temp ) : b(temp.v) {
		v = temp.v;
	}
