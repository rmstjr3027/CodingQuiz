#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

const int MaxSum = 100000000;

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

bool bracketsCheck(char openBracket, char closeBracket)
{
	if (!(bracketsToNum(openBracket) & bracketsToNum(closeBracket)))
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
						tmpBuf = (tmpBuf * bracketsToNum(tmp)) % MaxSum;
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
					tmpBuf = (tmpBuf + stackBuf.top()) % MaxSum;
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
		num = (num + stackBuf.top()) % MaxSum;
		stackBuf.pop();
	}
	return num % MaxSum;
}


int main()
{
	ifstream inf;
	string tmpStr;
	int testNum = 0;
	cin >> testNum;
	setvbuf (stdin, NULL, _IOFBF, 16384);

	for (int i = 0; i < testNum; i++)
	{
		cin >> tmpStr;
		cout << brackets(tmpStr) << endl;
	}
}
