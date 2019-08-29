#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
int main(void)
{
	char str[128] = {0, };

	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';

	printf("%c", str[0]);

	char *pstart;
	char *parr = str;
	while ((pstart = strstr(parr, "-")))
	{
		parr = pstart + 1;
		printf("%c", parr[0]);
	}
	printf("\n");

	return 0;
}
#endif

#if 0
string input;
string str[1001];

int main(void)
{
	getline(cin, input);

	for (unsigned int i = 0; i < input.size(); i++)
		str[i] = input.substr(i, input.size());

	sort(str, str + input.size());

	for (unsigned int i = 0; i < input.size(); i++)
		cout << str[i] << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int num_1;
	int num_2;
	int num_3;
	int num_4;

	scanf("%d %d %d %d", &num_1, &num_2, &num_3, &num_4);

	string str_1 = to_string(num_1) + to_string(num_2);
	string str_2 = to_string(num_3) + to_string(num_4);
	cout << stol(str_1) + stol(str_2) << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	char lower[] = "nopqrstuvwxyzabcdefghijklm";
	char upper[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	getline(cin, str);

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (isupper(str[i]))
			printf("%c", upper[str[i] - 'A']);
		else if (islower(str[i]))
			printf("%c", lower[str[i] - 'a']);
		else 
			printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
#endif

#if 0
int main(void)
{
	while (getline(cin, str))
	{
		int idx = 0;
		int data[4] = {0, };

		for (unsigned int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				idx = 0;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				idx = 1;
			else if (str[i] >= '0' && str[i] <= '9')
				idx = 2;
			else if (str[i] == ' ')
				idx = 3;

			data[idx]++;
		}

		for (int i = 0; i < 4; i++)
			printf("%d ", data[i]);
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int alpha[26] = {0, };
	getline(cin, str);

	for (unsigned int i = 0; i < str.size(); i++)
		alpha[str[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	printf("\n");

	return 0;
}
#endif

#if 0
string str;

int main(void)
{
	getline(cin, str);
	printf("%ld\n", str.size());

	return 0;
}
#endif
