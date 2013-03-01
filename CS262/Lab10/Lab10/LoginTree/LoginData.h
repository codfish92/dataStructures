#pragma once
#include <string>

class LoginData
{
public:
	LoginData(void);
	~LoginData(void);
	LoginData(std::string x, std::string y);
	std::string getLoginId() const;
	std::string getPassword() const;
	bool operator < (const LoginData& compare);
	
	


private:
	std::string loginId;
	std::string password;
};

bool operator == (const LoginData& x, const LoginData &y);
std::ostream& operator <<(std::ostream& output, const LoginData& x);