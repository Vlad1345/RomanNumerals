#include <iostream>
#include <map>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

map<string, int> m =
{
	{ "M", 1000 },
	{ "CM", 900 },
	{ "D", 500 },
	{ "CD", 400 },
	{ "C", 100 },
	{ "XC", 90 },
	{ "L", 50 },
	{ "XL", 40},
	{ "X", 10 },
	{ "IX", 9 },
	{ "V", 5 },
	{ "IV", 4 },
	{ "I", 1 }

};
string romanLetters[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

bool isRoman(const string &str)
{
	return !str.empty() && str.find_first_not_of("MDCLXVI") == std::string::npos;
}

bool isNumber(const string &str)
{
	return !str.empty() && str.find_first_not_of("0123456789") == string::npos;
}

string integerToRoman(int n)
{
	string result = "";

	for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
	{
		while (n - values[i] >= 0)
		{
			n -= values[i];
			result += romanLetters[i];

		}
	}

	return result;
}

int romanToInteger(string n)
{

	string s;
	int result = 0;

	for (int i = n.length() - 1; i >= 0; i -= 2)
	{
		if (i > 0)
		{

			if (m.find(n.substr(i - 1, 2)) != m.end())
			{
				result += m.at(n.substr(i - 1, 2));
			}
			else
			{
				result += m.at(n.substr(i, 1));
				result += m.at(n.substr(i - 1, 1));
			}
		}
		else
		{
			s = n.at(i);
			result += m.at(n.substr(i, 1));
		}
	}

	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 2) return -1;

	string input(argv[1]);

	if (isRoman(input))
	{
		cout << romanToInteger(input) << endl;
		return 0;
	}
	if (isNumber(input))
	{
		cout << integerToRoman(stoi(input)) << endl;
		return 0;
	}

	return -1;
}