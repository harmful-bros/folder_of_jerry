#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// sort(x.begin(), x.end(), greater<int>())

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0			// sort, 1377, 버블 소트
pair<int, int> data[500000];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data[i].first);
		data[i].second = i;
	}

	sort(data, data + num);

	// 실제 버블 소트를 하지 않고 이동 규칙을 찾아서 바로 구한다.
	int max = data[0].second;
	for (int i = 0; i < num; i++)
	{
		if (max < data[i].second - i)
			max = data[i].second - i;
	}

	printf("%d\n", max + 1);

	return 0;
}
#endif

#if 0			// sort, 10825, 국영수
struct student_information
{
	string str;
	int kor;
	int eng;
	int math;
};

// 정렬 순서가 복잡할 경우 struct 및 cmp를 직접 만들어 줘야 한다.
bool _compare(const student_information &fir, const student_information &sec)
{
	if (fir.kor > sec.kor)
		return true;
	else if (fir.kor == sec.kor)
	{
		if (fir.eng < sec.eng)
			return true;
		else if (fir.eng == sec.eng)
		{
			if (fir.math > sec.math)
				return true;
			else if (fir.math == sec.math)
				return fir.str < sec.str;
		}
	}

	return false;
}

int main(void)
{
	int i;
	int num;

	scanf("%d", &num);

	vector<student_information> info(num);
	for (i = 0; i < num; i++)
		cin >> info[i].str >> info[i].kor >> info[i].eng >> info[i].math;

	sort(info.begin(), info.end(), _compare);

	for (i = 0; i < num; i++)
		cout << info[i].str << '\n';

	return 0;
}
#endif

#if 0			// sort, 10814, 나이순 정렬

// pair에 들어있는 순서대로 정렬 된다.
vector<pair<pair<int, int>, string>> data[100001];

int main(void)
{
	int num;

	int fir;
	string str;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d ", &fir);
		getline(cin, str);

		data[i].push_back({{fir, i}, str});
	}

	sort(data, data + num);

	for (int i = 0; i < num; i++)
		cout << data[i].data()->first.first << " " << data[i].data()->second << endl;

	return 0;
}
#endif
