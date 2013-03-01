#include "queen.h"


queen::queen(void){
	row = 1;
	column = 1;
}

queen::queen(int x, int y){
	row = x;
	column = y;
}



queen::~queen(void){
}

double queen::slope(const queen &x){
	double slope;
	double rise = (this->row - x.row);
	double run = (this->column -x.column);
	slope = rise/(this->column - x.column);
	return slope;

}

bool queen::hasConflict(const queen &x){
	if(this->row == x.row && this->column == x.column){
		return false; // for self checks
	}
	else if(this->row == x.row){
		return true;
	}
	else if (this->column == x.column){
		return true;
	}
	else if (slope(x) == 1 || slope(x) == -1){
		return true;
	}
	else{
		return false;
	}
}
