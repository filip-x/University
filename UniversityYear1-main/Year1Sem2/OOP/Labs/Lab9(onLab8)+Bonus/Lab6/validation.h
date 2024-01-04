#pragma once 
#include <string>
#include<ctime>
typedef tm Date;
class Validation
{
public:
	static int validation_int(std::string word_from_command);
	static int validation_date(Date input_date);

private:

};
