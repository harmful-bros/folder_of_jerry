#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#define JERRY_CODES

using namespace std;

int getInput(vector<string>& words) {
	int count = 0;
	string line;
	string token;

	getline(cin, line);
	stringstream ssCount(line);
	ssCount >> token;
	count = atoi(token.c_str());

	getline(cin, line);
	stringstream ss(line);
	for (int i = 0 ; i < count ; i++) {
		ss >> token;
		words.push_back(token);
	}

	return count;
}

void solve() {
	int count = 0;
	int total_len = 0;
	vector<string> words;

	count = getInput(words);

	sort (words.begin(), words.end());

#ifdef JERRY_CODES
	string front = "";
	string end = words[0];

	unsigned int i = 1;
	for (; i < words.size(); i++)
	{
		if (i & 0x1)
			end += words[i];
		else
			front = words[i] + front;
	}
	front += end;
	cout << front[front.size() / 3] << endl;
#endif
}

int main() {
	solve();
	return 0;
}
