#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

vector<string> vote(vector<string> &vectorStr)
{
	map<string, int> mapVoteCount;
	vector<string>::iterator vectorItr;
	vector<string> vectorResult;
	int maxVote = 0;

	for (vectorItr = vectorStr.begin(); vectorItr != vectorStr.end(); vectorItr++)
	{
		if (mapVoteCount.insert(pair<string, int>(*vectorItr, 0)).second == false)
		{
			map<string, int>::iterator mapItr;
			mapItr = mapVoteCount.find(*vectorItr);
			mapItr->second++;
			if (maxVote < mapItr->second)
			{
				maxVote = mapItr->second;
			}
		}
	}

	map<string, int>::iterator mapItr;

	for (mapItr = mapVoteCount.begin(); mapItr != mapVoteCount.end(); mapItr++)
	{
		if (mapItr->second == maxVote)
		{
			vectorResult.push_back(mapItr->first);
		}
	}

	return vectorResult;
}

int main()
{
	vector<string> vectorStr;
	vector<string> vectorResult;
	char tmpStr[50] = {0};
	int i = 0;

	while ( (tmpStr[i++] = cin.get()) != EOF)
	{
		if (tmpStr[i-1] == '\n')
		{
			tmpStr[i-1] = 0;
			i = 0;
			vectorStr.push_back(tmpStr);
		}
	}

	vectorResult = vote(vectorStr);

	vector<string>::iterator vectorItr;
	for (vectorItr = vectorResult.begin(); vectorItr != vectorResult.end(); vectorItr++)
	{
		cout << *vectorItr << endl;
	}

}
