#include <iostream>
#include <cstdio>
#include <set>
#include <string>
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
	int n_lis;
	int n_see;

	scanf("%d %d", &n_lis, &n_see);

	string input;
	set<string> l_info;
	for (int i = 0; i < n_lis; i++)
	{
		cin >> input;
		l_info.insert(input);
	}

	set<string> s_info;
	for (int i = 0; i < n_see; i++)
	{
		cin >> input;
		if (l_info.count(input) == true)
			s_info.insert(input);
	}

	cout << s_info.size() << endl;
	for (auto &name : s_info)
		cout << name << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	string name;
	string check;
	set<string, greater<string>> info;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> check;
		if (check == "enter")
			info.insert(name);
		else
			info.erase(info.find(name));
	}

	for (auto p : info)
		cout << p << endl;

	return 0;
}
#endif
