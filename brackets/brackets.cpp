#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int recorveryBracket(int num)
{
	int resultNum = 0;
	switch (num)
	{

	case ~1:
		resultNum = ')';
		break;
	case ~2:
		resultNum = '}';
		break;
	case ~3:
		resultNum = ']';
		break;
	default:
		break;
	}
	return resultNum;
}

int bracketsToNum(char bracket)
{
	int resultNum = 0;
	switch (bracket)
	{
	case '(':
		resultNum = 1;
		break;
	case '{':
		resultNum = 2;
		break;
	case '[':
		resultNum = 3;
		break;
	case ')':
		resultNum = ~1;
		break;
	case '}':
		resultNum = ~2;
		break;
	case ']':
		resultNum = ~3;
		break;
	default:
		break;
	}
	return resultNum;
}

bool bracketsCheck(char left, char right)
{
	if (!(bracketsToNum(left) & bracketsToNum(right)))
	{
		return true;
	}
	return false;
}

int brackets(string strBracket)
{
	int num = 0;
	int strLen = strBracket.length();
	stack<int> stackBracket;
	stack<int> stackBuf;

	for (int i = 0; i < strLen; i++)
	{
		stackBracket.push(strBracket.at(i));
	}
	//마지막 괄호가 오픈 이면 0
	if (bracketsToNum(stackBracket.top()) > 0)
	{
		return 0;
	}

	while (!stackBracket.empty())
	{
		char tmp = stackBracket.top();
		stackBracket.pop();
		//닫힌 괄호
		if (bracketsToNum(tmp) < 0)
		{
			if (stackBracket.empty())
			{
				return 0;
			}
			//닫히면서 이전 거와 짝을 이루는 경우
			if (bracketsCheck(stackBracket.top(), tmp))
			{
				stackBuf.push(bracketsToNum(stackBracket.top()));
				stackBracket.pop();
			}
			else
			{
				stackBuf.push(bracketsToNum(tmp));
			}
		}
		//열린 괄호
		else
		{
			int tmpBuf = 0;
			while (!stackBuf.empty())
			{
				//숫자가 아니면
				if (bracketsToNum(recorveryBracket(stackBuf.top())) != 0)
				{
					//짝이 맞는지 체크
					if (bracketsCheck(tmp, recorveryBracket(stackBuf.top())))
					{
						stackBuf.pop();
						tmpBuf = (tmpBuf * bracketsToNum(tmp)) % 100000000;
						stackBuf.push(tmpBuf);
						break;
					}
					else
					{
						return 0;
					}
				}
				//숫자
				else
				{
					tmpBuf = (tmpBuf + stackBuf.top()) % 100000000;
					stackBuf.pop();
				}
			}
		}
	}
	while (!stackBuf.empty())
	{
		if (bracketsToNum(recorveryBracket(stackBuf.top())) != 0)
		{
			return 0;
		}
		num += stackBuf.top();
		stackBuf.pop();
	}
	return num % 100000000 ;
}


int main()
{
	ifstream inf;
	string tmpStr;
	cin >> tmpStr;
	inf.open(tmpStr.c_str());
	int testNum = 0;
	getline(inf, tmpStr);
	testNum = atoi(tmpStr.c_str());

	for (int i = 0; i < testNum; i++)
	{
		getline(inf, tmpStr);
		cout << brackets(tmpStr) << endl;
	}
}