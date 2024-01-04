#pragma once
#include <string>


class Stars
{
public:
	Stars(std::string ,std::string ,int ,int,int);
	Stars();
	~Stars();
	std::string get_name();
	std::string get_constelation();
	int get_ra();
	int get_dec();
	int get_diameter();
	void set_name(std::string);
	void set_constelation(std::string);
	void set_ra(int);
	void set_dec(int);
	void set_diameter(int);
	friend std::ostream& operator<<(std::ostream& output_stream, Stars& element);
	friend std::istream& operator>>(std::istream& input_stream, Stars& element);
	bool operator==(const Stars&) const;

private:
	std::string name;
	std::string constelation;
	int ra;
	int dec;
	int diameter;

};

