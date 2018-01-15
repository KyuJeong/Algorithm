#include <iostream>
#include <math.h>
using namespace std;

int A, P;
int D[10000];

int main()
{
	std::ios::sync_with_stdio(false);
	int idx = 2;
	int overlap_index = 0;
	cin >> A >> P;

	D[1] = A;

	while (overlap_index == 0)	// 싸이클 발생 전까지 반복
	{
		for (int quo = D[idx - 1]; quo > 0; quo /= 10)	// D[n]을 하나씩 채워나감
		{
			D[idx] += pow(quo % 10, P);
		}

		for (int i = 1; i < idx; i++)	// 싸이클 발생 여부 탐색
		{
			if (D[idx] == D[i])
			{
				overlap_index = i;	// 싸이클 발생 지점 저장
				break;
			}
		}
		idx++;
	}

	cout << overlap_index - 1;


	return 0;
}