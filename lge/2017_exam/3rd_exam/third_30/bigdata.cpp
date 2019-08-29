#include <iostream>
#include <cstring>

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;			//	모델명의 개수
char str[10010][21];	//	모델명 저장

typedef struct data_information
{
	int num;
	vector<int> vec;

}data_info_t;

map<string, data_info_t> mInfo;
vector<pair<data_info_t, string>> vec;

static bool _compare(
		const pair<data_info_t, string> &var_1, 
		const pair<data_info_t, string> &var_2)
{
	if (var_1.first.num == var_2.first.num)
		return var_1.first.vec[0] < var_2.first.vec[0]; 
	else
		return var_1.first.num > var_2.first.num;
}

void Solve(){
	//	코드를 작성하세요
	for (auto &i : mInfo)
		vec.push_back({i.second, i.first});

	sort(vec.begin(), vec.end(), _compare);

	bool flag = false;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first.num >= 2)
		{
			flag = true;
			cout << vec[i].second;
			for (unsigned int j = 0; j < mInfo[vec[i].second].vec.size(); j++)
				printf(" %d", mInfo[vec[i].second].vec[j]);
			printf("\n");

			if (vec[i].first.num << 1 >= N)
				break;
		}
	}

	if (flag == false)
		printf("unique\n");
}

void InputData(){
	int cnt;
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> str[i];

		cnt = mInfo.find(str[i])->second.num + 1;
		mInfo[str[i]].num = cnt;
		mInfo[str[i]].vec.push_back(i + 1);
	}
}

int main(){

	InputData();		//	입력 함수
	Solve();		//	문제 풀이

	return 0;
}

