#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

//#define JSLEE_DEBUG
#define MAX_BUF		200
#define PI		3.1415926535

typedef struct coordinate_information
{
	int x;
	int y;
}coordi_t;

class vectorCompute
{
	public :
		int x;
		int y;

		double crossFunc(const vectorCompute &rVec) const {
			return (this->x * rVec.y) - (this->y * rVec.x);
		}
};

vectorCompute gVecCom[MAX_BUF + 1];
unsigned long minVal;

static double inline ccwFunc(vectorCompute &rVec1, vectorCompute &rVec2)
{
	return rVec1.crossFunc(rVec2);
}

#ifdef JSLEE_DEBUG
static inline void _showAllVectorMembers(vector<int> &rSt)
{
	vector<int>::iterator it;

	for (it = rSt.begin(); it != rSt.end(); it++)
		printf("%3d ", *it);
	printf("\n");
}
#endif

static inline void _computeExtetQuadrangle(vector<int> &rSt)
{
	int i = 0;
	vectorCompute coordi[4];
	vector<int>::iterator it;

	for (it = rSt.begin(); it != rSt.end(); i++, it++)
		coordi[i] = gVecCom[*it];

	int x1 = coordi[0].x - coordi[1].x;
	int y1 = coordi[0].y - coordi[1].y;
	int x2 = coordi[2].x - coordi[3].x;
	int y2 = coordi[2].y - coordi[3].y;





	
}

void doCombinationFunc(vector<int> &rSt, int *pArr, int n, int r, int idx)
{
	if (r == 0) {
#ifdef JSLEE_DEBUG
		_showAllVectorMembers(rSt);
#endif
		return;
	}
	else if (n == r) {
		int i;
		for (i = 0; i < n; i++)
			rSt.push_back(pArr[idx + i]);
#ifdef JSLEE_DEBUG
		_showAllVectorMembers(rSt);
#endif
		for (i = 0; i < n; i++)
			rSt.pop_back();
	}
	else {
		rSt.push_back(pArr[idx]);
		doCombinationFunc(rSt, pArr, n - 1, r - 1, idx + 1);

		rSt.pop_back();
		doCombinationFunc(rSt, pArr, n - 1, r, idx + 1);
	}
}

static double _getDegree(vectorCompute from, vectorCompute to)
{
	return atan2(from.y - to.y, to.x - from.x) * 180 / 3.1415926535;
}

static double _getDegreeCalcFunc(double lx1, double ly1, 
		double lx2, double ly2)
{
	double inner = (lx1 * lx2 + ly1 * ly2);
	double i1 = sqrt(lx1 * lx1 + ly1 * ly1);
	double i2 = sqrt(lx2 * lx2 + ly2 * ly2); 

	if (i1)
	{
		lx1 = (lx1 / i1);
		ly1 = (ly1 / i1);
	}

	if (i2)
	{
		lx2 = (lx2 / i2);
		ly2 = (ly2 / i2);
	}

	inner = (lx1 * lx2 + ly1 * ly2);
	return acos(inner) * 180.0 / PI;
}


int main(void)
{
	int tCase;
	int nCase;

	int arrIdx[MAX_BUF];
	vector<int> st;

	for (int i = 0; i < MAX_BUF; i++)
		arrIdx[i] = i;

	scanf("%d", &tCase);
	for (int i = 0; i < tCase; i++)
	{
		minVal = ~0UL;

		scanf("%d", &nCase);
		for (int j = 0; j < nCase; j++)
			scanf("%d %d", &gVecCom[j].x, &gVecCom[j].y);
#if 0
//#ifdef JSLEE_DEBUG
		for (int j = 0; j < nCase; j++)
			printf("%d %d\n", gVecCom[j].x, gVecCom[j].y);
#endif
//		doCombinationFunc(st, arrIdx, nCase, 4, 0);
	}
		
	return 0;
}


#if 0
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (j == k)
					continue;

				printf("%3d %3d ", j, k);
				double temp = ccwFunc(gVecCom[j], gVecCom[k]);
				printf("%2.0lf ", temp);
				printf("%5.1lf\t", 
						_getDegree(gVecCom[j], gVecCom[k]));

#if 0
				printf("%5.1lf\t", temp > 0 ?
						180.0 + _getDegree(gVecCom[j], gVecCom[k]) :
						_getDegree(gVecCom[j], gVecCom[k]));
#endif
			}
			printf("\n");
		}
#endif

#if 0
static double _getDegreeCalcFunc(double lx1, double ly1, 
		double lx2, double ly2)
{
	double inner = (lx1*lx2 + ly1*ly2);// 기본내적

	double i1=sqrt(lx1*lx1+ ly1*ly1); // 처음 직선의 노말라이즈 준비
	double i2=sqrt(lx2*lx2+ ly2*ly2); // 두번째 직선의 노말라이즈 준비

	lx1=(lx1/i1); // 각 요소를 단위 벡터로 변환한다.
	ly1=(ly1/i1);
	lx2=(lx2/i2);
	ly2=(ly2/i2);

	//위 과정을 거치면 결과적으로 계산된 두 직선의 크기는 1이면서 방향은 이전과 같은 단위벡터가 된다.
	inner =(lx1*lx2 + ly1*ly2); //다시 내적을 구한다.
	double result = acos(inner)*180/PI;
	// 아크 코사인을 통해 라디안을 구하고 그걸 각도로 변환하기 위해 180을 곱하고 파이로나눈다.
	// 사이각은 최대 0-180도 사이마 존재함으로 입력된 x값을 참조하여 360에 가까운 값으로 변환하는 과정을 거친다.
	//if(lx1 > lx2) result=360-result;//사이각을 구하기 위해서는 이 부분을 삭제.

	return result ; //완료
}
#endif
