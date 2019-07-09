#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>
using namespace std;

/*
×Ö·û´®Ä£Ê½Æ¥Åä
*/
class Function
{
private:
	bool deal(char ch, string str, map<char, string> &ma)
	{
		auto it = ma.find(ch);
		if (it == ma.end())
		{
			ma.insert(make_pair(ch, str));
			return true;
		}
		else if (it->second > str == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool detection(vector<string> &ve, string parent_str, int length)
	{
		string child_str;
		int new_pos = 0, old_pos = 0, flag = 1;

		while (flag)
		{
			if (length < 0)
			{
				return false;
			}

			if ((new_pos = parent_str.find(" ", old_pos)) == parent_str.npos)
			{
				flag--;
				new_pos = parent_str.size();
			}

			child_str = parent_str.substr(old_pos, new_pos - old_pos);
			ve.push_back(child_str);
			child_str.clear();
			old_pos = new_pos + 1;
			length--;
		}
		if (length == -1)
		{
			return true;
		}
		return false;
	}

public:
	bool worldMatch(string pattern, string str)
	{
		vector<string> ve;

		if (!detection(ve, str, pattern.size() - 1))
		{
			return false;
		}

		map<char, string> ma;
		for (unsigned int i = 0; i < pattern.size(); i++)
		{
			if (!deal(pattern[i], ve[i], ma))
				return false;
		}
		return true;
	}
};



int main()
{
	/*string  pattern, str;
	Function fun;

	while (1)
	{
		cout << "input pattern: ";
		getline(cin, pattern);

		cout << "input str: ";
		getline(cin, str);

		if (fun.worldMatch(pattern, str))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}		
	}	*/
	return 0;
}