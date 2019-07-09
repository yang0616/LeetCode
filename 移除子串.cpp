#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

/*
ÒÆ³ý×Ó´®
*/
class Function
{
	void analyzedata(string str, unordered_set<string> &dict)
	{
		int flag = 1;
		string tmp_str;
		for (unsigned int i = 0; flag > 0; i++)
		{
			if (i == str.size())
			{
				flag = 0;
			}

			if (str[i] == ' ' || i == str.size())
			{
				dict.insert(tmp_str);
				tmp_str.clear();
				continue;
			}

			tmp_str += str[i];
		}
	}

	int moveSubstr(string &s, unordered_set<string> &dict)
	{
		int size = s.size();
		if (size == 0)
		{
			return 0;
		}

		queue<string> q;
		unordered_set<string> hashSet;

		int minLen = size;
		q.push(s);
		hashSet.insert(s);

		while (!q.empty())
		{
			string s = q.front();
			q.pop();

			for (auto it = dict.begin(); it != dict.end(); it++)
			{
				string str = *it;
				int pos = s.find(str);
				while (pos != s.npos)
				{
					string new_s = s.substr(0, pos) + s.substr(pos + str.size());
					if (hashSet.find(new_s) == hashSet.end())
					{
						q.push(new_s);
						hashSet.insert(new_s);
						minLen = min(minLen, (int)new_s.size());
					}
					pos = s.find(str, pos + 1);
				}
			}
		}
		return minLen;
	}

};


int main()
{
 	string parent, child;
	unordered_set<string> dict;
	while (1)
	{
		cout << "input parent str: ";
		getline(cin, parent);

		cout << "input child str: ";
		getline(cin, child);

		analyzedata(child, dict);
		int length = moveSubstr(parent, dict);
	
		cout << "length: " << length << endl;
		dict.clear();
	}
	return 0;
}