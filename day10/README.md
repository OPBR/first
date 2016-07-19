This code shows is two-way chain table insert
operation sequence.But it is incomplete.


struct :
	typedef struct NODE{
		struct NODE *fwd;
		struct NODE *bwd;

		int value;
	}Node;
