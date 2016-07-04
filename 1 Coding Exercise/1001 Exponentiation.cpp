#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
using namespace std;

struct bignum
{
	char* digits;
	int decimal_point;
	int length;
};

struct bignum* bignum_new(const char* num)
{
	int i, n = strlen(num);
	bool copy, decimal_found;
	struct bignum* result;

	result = (struct bignum*) malloc(sizeof(struct bignum));
	result->digits = (char*) malloc(sizeof(char) * n);
	strcpy(result->digits, num);

	copy = false;
	result->decimal_point = 0;
	decimal_found = false;

	for (i=0; i<n; i++)
	{
		if (copy)
		{
			result->digits[i] = result->digits[i+1];
		}

		else if (result->digits[i+1] == '.')
		{
			result->decimal_point = n - (i + 1) - 1;
			copy = true;
			decimal_found = true;
		}
	}

	result->length = n-1;

	if (!decimal_found)
	{
		result->length++;
		result->digits[i] = '\0';
	}

	return result;
}

void bignum_print(struct bignum* num)
{
	int n = num->length;
	bool print = false;
	int last;

	last = n;
	while (num->digits[last-1] == '0' && last > 1 && last > n - num->decimal_point)
		last--;

	if (last == 1)
	{
		cout << num->digits[0] << endl;
		return;
	}

	for (int i=n; i>n-last; i--)
	{
		if (num->digits[n-i] != '0')
			print = true;

		if (num->decimal_point == i)
		{
			cout << ".";
			print = true;
		}

		if (print)
			cout << num->digits[n-i];
	}

	cout << endl;
}

struct bignum* multiply(struct bignum* a, struct bignum* b)
{
	int carry = 0, sum;
	struct bignum* result = (struct bignum*) malloc(sizeof(struct bignum));
	result->length = a->length + b->length;
	result->digits = (char*) malloc(sizeof(char) * (result->length + 1));

	for (int i=0; i < result->length; i++)
		result->digits[i] = '0';

	for (int i=0; i < b->length; i++)
	{
		for (int j=0; j < a->length + 1; j++)
		{
			if (j < a->length)
			{
				sum = (((result->digits[result->length-j-i-1] - '0') + (b->digits[b->length-i-1] - '0') * (a->digits[a->length-j-1] - '0') + carry) % 10);
				carry = (((result->digits[result->length-j-i-1] - '0') + (b->digits[b->length-i-1] - '0') * (a->digits[a->length-j-1] - '0') + carry) / 10);
			}
			else
			{
				sum = carry;
				carry = 0;
			}

			result->digits[result->length-j-i-1] = '0' + sum;
		}
	}

	result->decimal_point = a->decimal_point + b->decimal_point;

	return result;
}

void bignum_free(struct bignum* num)
{
	free(num->digits);
	free(num);
}

struct bignum* raise(struct bignum* r, int n)
{
	struct bignum* intermediate, * result;

	if (n == 0)
		return bignum_new("1");
	else if (n == 1)
		return r;
	else
	{
		intermediate = raise(r, n/2);

		if (n % 2 == 0)
			result = multiply(intermediate, intermediate);
		else
			result = multiply(r, multiply(intermediate, intermediate));
	}

	if (intermediate != r)
		bignum_free(intermediate);

	return result;
}

int main()
{
	char r[7];
	int n;

	struct bignum* input, * result;

	while (cin >> r >> n)
	{
		input = bignum_new(r);
		result = raise(input, n);
		bignum_print(result);
		
		bignum_free(input);

		if (result != input)
			bignum_free(result);
	}

	return 0;
}
