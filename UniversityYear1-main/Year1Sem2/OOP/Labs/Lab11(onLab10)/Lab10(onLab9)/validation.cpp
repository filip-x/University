#include "validation.h"

int Validation::validation_int(std::string word_from_command)
{
	int length = word_from_command.length();
	for (int i = 0; i < length; i++)
	{
		if (word_from_command[i] < '0' && word_from_command[i]>'9')
		{
			return 0;
		}
	}
	return 1;
}

int Validation::validation_date(Date input_date)
{
	if (input_date.tm_mon <= 0 || input_date.tm_mon > 12)
		return 0;
	int max_days[] = { 0, 31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31 };
	if (input_date.tm_year % 4 == 0)// an bisect
		max_days[2]++;
	if (input_date.tm_mday <= 0 || input_date.tm_mday > max_days[input_date.tm_mon])
		return 0;
	return 1;
}