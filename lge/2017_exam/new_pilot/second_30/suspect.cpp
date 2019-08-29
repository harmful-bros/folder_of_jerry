#include <iostream>

#define JERRY_CODES

#ifdef JERRY_CODES
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#endif

using namespace std;

#ifdef JERRY_CODES
#define JERRY_ERR(fmt, ...)						\
	do {								\
		printf("[ERR] %s, %s:%d\n", 				\
				fmt, ##__VA_ARGS__, __func__, __LINE__);\
	} while (0)

static int _kmp_algorithm(const string &all, const string &suspect, 
		unsigned long *ppi, vector<int> &res);
static int _get_pi(const string &str, unsigned long *ppi);

static int _kmp_algorithm(const string &all, const string &suspect, 
		unsigned long *ppi, vector<int> &res)
{
	unsigned long i = 0;
	unsigned long j = 0;
	for (; i < all.length(); i++)
	{
		//현재 j만큼 찾았는데 이번에 비교하는 문자가 다른 경우
		//문자열 B를 failure function 이후 부터 비교를 해줍니다.
		while (j > 0 && all[i] != suspect[j]) 
			j = ppi[j - 1];        

		//비교하는 문자가 같은 경우
		if (all[i] == suspect[j])
		{ 
			//문자열 B를 전부 탐색하였기 때문에 답에 위치를 넣어줍니다.
			if (j == suspect.length() - 1)
			{
				//다음 탐색을 위하여 이번에도 failure function 이후 부터 비교를 해줍니다.
				res.push_back(i - suspect.length() + 1);
				j = ppi[j];    
			}
			else
				j++;    //문자열 B의 다음 단어를 비교해줍니다.
		}
	}

	return 0;
}

static int _get_pi(const string &str, unsigned long *ppi)
{
	cout << str.length() << endl;

	unsigned long j = 0;
	for (unsigned long i = 1; i < str.length(); i++)
	{
		//불일치가 일어날 경우
		while (j > 0 && str[i] != str[j])
			j = ppi[j - 1];        

		//prefix가 같은 가중치만큼 pi를 정해줍니다.
		if (str[i] == str[j])
			ppi[i] = ++j;
	}

	for (unsigned int i = 0; i < str.length(); i++)
		printf("[%u] %lu\n", i, ppi[i]);

	return 0;
}


#endif

int main() {

#ifdef JERRY_CODES
	int idx;
	string all;

	cin >> all;
	scanf("%d", &idx);

	string suspect[idx];
	int i = 0;
//	for (int i = 0; i < idx; i++)
	{
		cin >> suspect[i];

		cout << suspect[i] << endl;

		unsigned long pi[suspect[i].length() + 1];
		memset(pi, 0x00, sizeof(pi));
		if (_get_pi(suspect[i], pi) < 0)
		{
			JERRY_ERR("Failed to call function,,");
			goto error;
		}
	}

#endif
	return 0;

error :
	return -1;
}


