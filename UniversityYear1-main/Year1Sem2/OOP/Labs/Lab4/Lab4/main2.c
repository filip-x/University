#include <stdio.h>

int fibonacci_sum_of_even_terms(int user_input)
{
	int sum_of_the_even_fibonacci_numbers = 0;

	int first_term_of_the_fibonacci_sequence = 0; 

	int second_term_of_the_fibonacci_sequence = 1;

	int next_fibonacci_term = first_term_of_the_fibonacci_sequence + second_term_of_the_fibonacci_sequence;

	while (first_term_of_the_fibonacci_sequence <= user_input)
	{
		if (first_term_of_the_fibonacci_sequence % 2 == 0)
		{
			sum_of_the_even_fibonacci_numbers = sum_of_the_even_fibonacci_numbers + first_term_of_the_fibonacci_sequence;
		}
		first_term_of_the_fibonacci_sequence = second_term_of_the_fibonacci_sequence;

		second_term_of_the_fibonacci_sequence = next_fibonacci_term;

		next_fibonacci_term = first_term_of_the_fibonacci_sequence + second_term_of_the_fibonacci_sequence;
	}
	return sum_of_the_even_fibonacci_numbers;
}



int main()
{
	int input_from_the_user;

	scanf("%d",&input_from_the_user);

	printf("%d",fibonacci_sum_of_even_terms(input_from_the_user));

}