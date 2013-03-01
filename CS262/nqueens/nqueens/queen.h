#pragma once
class queen{
public:
	queen(void);
	~queen(void);
	queen(int x, int y);
	int row;
	int column;
	double slope(const queen &x); // used in the hasConflict function as well, just made it a seperate function for readablity. 
	bool hasConflict(const queen &x); // will return true if there is a conflict

};

