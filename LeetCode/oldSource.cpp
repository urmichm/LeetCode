#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int myAtoi(string str);
bool isNumber(string s);
bool canCross(vector<int>& stones);

int _main()
{
	//cout << isNumber("-2147483649") << "== true" << endl;
	//cout << isNumber("0") << "== true" << endl;
	//cout << isNumber("-0.1") << "== true" << endl;
	//cout << isNumber("e3") << "== false" << endl;
	//cout << isNumber(" 6e-1") << "== true" << endl;
	//cout << isNumber(" 99e2.5 ") << "== false" << endl;
	//cout << isNumber("95a54e53") << "== false" << endl;
	//cout << isNumber("--6") << "== false" << endl;
	//cout << isNumber("++4") << "== false" << endl;
	//cout << isNumber("55.6e34") << "== true" << endl;
	//cout << isNumber("1e") << "== false" << endl;
	//cout << isNumber("12  ") << "== true" << endl;
	//cout << isNumber("  .1  ") << "== true" << endl;


	// the iterator constructor can also be used to construct from arrays:
	//int myints[] = { 0,1,3,5,6,8,12,17 }; // tru
	//std::vector<int> stones(myints, myints + sizeof(myints) / sizeof(int));

	std::vector<int> stones;
	for (int i = 0; i < 500; i++)
		stones.push_back(i);

	cout << canCross(stones) << "  true" << endl;

	system("pause");
	return 0;
}


bool canCross(vector<int>& stones) 
{
	struct next {
		int stone;
		int jump;
	};
	vector<struct next> queue;
	int jumplen = 1;
	if (stones[1] > 1)
		return false;

	queue.push_back({ 1,1 });

	while (!queue.empty())
	{
		struct next cur = queue[0];
		queue.erase(queue.begin());
		if (cur.stone == stones.size() - 1)
			return true;
		for (int i = cur.stone + 1; i < stones.size(); i++)
		{
			int len = stones[i] - stones[cur.stone];
			if (len == cur.jump - 1 || len == cur.jump || len == cur.jump + 1)
			{
				queue.push_back({ i, len });
			}
			if (len > cur.jump + 1)
				break;
		}


		for (int p = 0; p < queue.size(); p++)
			cout << queue.at(p).stone << " ";
		cout << endl;

	}
	return false;
}


/**
Some examples:

" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
**/
bool isNumber(string s) {
	if (s.empty())
		return false;
	
	bool dotUsed = false;
	bool eUsed = false;

	// remove useless symbols
	while (s[0] == ' ')
	{
		s.erase(0, 1);
		if (s.empty())
			return false;
	}

	if (s[0] == '+' || s[0] == '-')
		s.erase(0, 1);

	if (s[0] == '.')
	{
		s.erase(0, 1);
		dotUsed = true;
	}

	if (s[0] < '0' || s[0] > '9')
		return false;

	while (!s.empty())
	{
		if (s[0] < '0' || s[0] > '9')
		{
			if (s[0] == '.' && dotUsed)
				return false;
			else if (s[0] == '.' && !dotUsed)
			{
				dotUsed = true;
				s.erase(0, 1);  // remove dot
			}
			else if (s[0] == 'e' && eUsed)
				return false;
			else if (s[0] == 'e' && !eUsed)
			{
				dotUsed = eUsed = true;
				s.erase(0, 1); // remove e
				if (s[0] == '+' || s[0] == '-')
					s.erase(0, 1);

				while (s[0] == ' ')
					s.erase(0, 1); 

				if (s.empty())
					return false;

			}
			else if (s[0] == ' ')
			{
				while (s[0] == ' ')
				{
					s.erase(0, 1);
					if (s.empty())
						return true;
				}
				return false;
			}
			else
				return false;			
		}
		else
			s.erase(0, 1);
	}

	// test passed
	return true;
}

int myAtoi(string str){
	int result = 0;
	int sign = 1;

	// empty string
	if (str == "")
		return result;
	// remove useless symbols
	while (!str.empty() && str[0] == ' ')
	{
		str.erase(0, 1);
	}

	// check sign
	if (str[0] == '-')
	{
		str.erase(0, 1);
		sign = -1;
	}
	else if (str[0] == '+')
	{
		str.erase(0, 1);
		sign = 1;
	}
	// go for digits
	while (!str.empty() && (str[0] >= '0' && str[0] <= '9'))
	{
		int digit = 0 + (str[0] - '0');
		// check overflow
		if (result > INT_MAX / 10)
			return INT_MAX;
		if (result == INT_MAX / 10 && digit > INT_MAX % 10)
			return INT_MAX;
		if (result < INT_MIN / 10)
			return INT_MIN;
		if (result == INT_MIN / 10 && -digit < INT_MIN % 10)
			return INT_MIN;
		// append digit
		result = sign == 1 ? 10 * result + digit : 10 * result - digit;
		str.erase(0, 1);
	}
	return result;
}