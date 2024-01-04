#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Encoder
{
public:
	Encoder();
	~Encoder();
	string encode(string);
private:

};

class Alien_encoder:public Encoder
{
public:
	Alien_encoder();
	~Alien_encoder();
	string encode(string);

private:
	string header;
};

class Morse_encoder:public Encoder
{
public:
	Morse_encoder();
	~Morse_encoder();
	string encode(string);

private:
};

class  Communication:public Encoder
{
public:
	 Communication();
	~ Communication();
	void addMessage(string);
	string communicate(string);

private:
	string message[];
};

class Mixer:public Encoder
{
public:
	Mixer();
	~Mixer();
	string encode(string);
private:
};

Mixer::Mixer()
{
}

Mixer::~Mixer()
{
}

string Mixer::encode(string code)
{	
	string header;
	Encoder ms = Morse_encoder();
	Encoder al = Alien_encoder();
	for (int i = 0; i < size(code); i++)
	{
		if (i % 2 == 0 )
		{
			
			ms.encode(code);
		}
		else if (i % 2 == 1)
		{

			al.encode(code);
		}
	}
	return code;
}

 Communication:: Communication()
{
}

 Communication::~ Communication()
{
}

 void Communication::addMessage(string)
 {
 }

 string Communication::communicate(string)
 {
	 return string();
 }

Morse_encoder::Morse_encoder()
{
}

Morse_encoder::~Morse_encoder()
{
}

string Morse_encoder::encode(string code)
{
	string temporarly_code;
	for (int i = 0; i < size(code); i++)
	{
		temporarly_code.push_back('.');
	}
}

Alien_encoder::Alien_encoder()
{
	
}

Alien_encoder::~Alien_encoder()
{
}

string Alien_encoder::encode(string code)
{
	for (int i = 0; i < size(this->header); i++)
	{
		code.push_back(this->header[i]);
	}
	return code;
}

Encoder::Encoder()
{
}

Encoder::~Encoder()
{
}

int main()
{

    std::cout << "Hello World!2\n";
    return 0;
}