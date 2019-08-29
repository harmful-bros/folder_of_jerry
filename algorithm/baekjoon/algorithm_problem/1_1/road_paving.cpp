#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<pair<int, int>> vec[10001];

int dist[10001][21];
bool flag[10001][21];
const int MAX_VAL = 1000000;

int main(void)
{
	int n;
	int m;
	int k;

	int city;
	int road;
	int cost;

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &city, &road, &cost);
		vec[city].push_back({road, cost});
		vec[road].push_back({city, cost});
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			dist[i][j] = MAX_VAL;

	priority_queue<tuple<int, int, int>> pque;

	dist[1][0] = 0;
	pque.push({0, 1, 0});
	while (!pque.empty())
	{
		road = get<1>(pque.top());
		cost = get<2>(pque.top());
		pque.pop();

		if (flag[road][cost] == true)
			continue;

		flag[road][cost] = true;
		for (unsigned int i = 0; i < vec[road].size(); i++)
		{
			city = vec[road][i].first;

			if (cost + 1 <= k && 
			    dist[city][cost + 1] > dist[road][cost])
			{
				dist[city][cost + 1] = dist[road][cost];
				pque.push({-dist[city][cost + 1], city, cost + 1});
			}

			if (dist[city][cost] > 
					dist[road][cost] + vec[road][i].second)
				pque.push({-dist[city][cost], city, cost});
		}
	}

	int max = MAX_VAL;
	for (int i = 1; i <= k; i++)
	{
		if (flag[n][i] == true && max > dist[n][i])
			max = dist[n][i];
	}
	printf("%d\n", max);

	return 0;
}
