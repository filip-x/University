#pragma once
#include <string>

class Astronomer
{
public:
	Astronomer(std::string, std::string);
	Astronomer();
	~Astronomer();
	std::string get_name();
	std::string get_constelation();
	void set_name(std:: string);
	void set_constelation(std::string);
	friend std::ostream& operator<<(std::ostream& output_stream, Astronomer& element);
	friend std::istream& operator>>(std::istream& input_stream, Astronomer& element);
	bool operator==(const Astronomer&) const;
private:
	std::string  name;
	std::string constelation;
	
};

