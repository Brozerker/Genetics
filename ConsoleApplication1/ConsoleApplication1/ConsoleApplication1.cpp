// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string S = "dir1		dir11		dir12		picture.jpeg		dir121		file1.txt		dir2		file2.gif";
	
	int totalCount = 0;
	int highest = totalCount;
	int currentWord = 0;
	for (int i = 0; i < S.size(); ++i) {
		totalCount++;
		currentWord++;
		if (S[i] == '.') {
			if (S[i + 1] == 'j' || S[i + 1] == 'p' || S[i + 1] == 'g') {
				if (S[i + 2] == 'p' || S[i + 2] == 'n' || S[i + 2] == 'i') {
					if (S[i + 3] == 'e' || S[i + 3] == 'g' || S[i + 3] == 'f') {
						if (S[i + 4] == 'g') {
							if (highest < totalCount + 4)
								highest = totalCount + 4;
							totalCount -= currentWord;
							continue;
						}
						else {
							if (highest < totalCount + 3)
								highest = totalCount + 3;
							totalCount -= currentWord;
							continue;
						}
					}
				}
			}
		}
		if (S[i] == '\t') {
			currentWord = 0;
			totalCount --;
		}
	}
	cout << highest;
	return 0;
}

