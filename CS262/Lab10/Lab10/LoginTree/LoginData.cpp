#include "LoginData.h"


LoginData::LoginData(void){ // default values are for debuging and checks only
	loginId = "foxy";
	password = "boxy";
}

LoginData::LoginData(std::string x, std::string y){
	loginId = x;
	password = y;
}

LoginData::~LoginData(void){
}

std::string LoginData::getLoginId() const{
	return loginId;
}

std::string LoginData::getPassword() const{
	return password;
}

bool LoginData::operator<(const LoginData& compare){
	if(loginId <= compare.getLoginId()){
		return true;
	}
	else{
		return false;
	}
}

bool operator ==(const LoginData & x, const LoginData& y){
	if(x.getLoginId() == y.getLoginId() && x.getPassword() == y.getPassword()){
		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator <<(std::ostream& output, const LoginData& x){
	output<< "(" << x.getLoginId() << ", " << x.getPassword() << ")";
	return output;
}
