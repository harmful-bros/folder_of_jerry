#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_ABS_DATA	4000

int data[500000];
double sum;
pair<int, int> mode[(MAX_ABS_DATA << 1) + 1];

static bool _compare(const pair<int, int> data_1, const pair<int, int> data_2)
{
	if (data_1.first == data_2.first)
		return data_1.second < data_2.second;
	else
		return data_1.first > data_2.first;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data[i]);
		sum += data[i];
		
		mode[data[i] + MAX_ABS_DATA].first++;
		mode[data[i] + MAX_ABS_DATA].second = data[i];
	}

	/* average val */
	printf("%lld\n", (long long)floor((sum / (double)num) + 0.5));

	/* center val */
	sort(data, data + num);
	printf("%d\n", data[num >> 1]);

	/* mode */
	sort(mode, mode + (MAX_ABS_DATA << 1) + 1, _compare);
	if (mode[0].first == mode[1].first)
		printf("%d\n", mode[1].second);
	else
		printf("%d\n", mode[0].second);

	/* range */
	printf("%d\n", data[num - 1] - data[0]);

	return 0;
}

#if 0
int main(void)
{
	string str;
	getline(cin, str, '\n');
	sort(&str[0], &str[str.size()], greater<char>());
	cout << str << endl;
	return 0;
}
#endif

#if 0
bool _compare(int num_1, int num_2)
{
	return num_1 < num_2;
}

int main(void)
{
	int num;
	cin >> num;
	vector<int> vec(num, 0);
	for (int i = 0; i < num; i++)
		cin >> vec[i];
	
	sort(vec.begin(), vec.end(), _compare);

	for (int i = 0; i < num; i++)
		cout << vec[i] << endl;

	return 0;
}
#endif
