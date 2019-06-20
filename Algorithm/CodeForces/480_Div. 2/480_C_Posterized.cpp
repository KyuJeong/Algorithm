#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n, k;
int arr[100001];
bool choose[256];
int grp[256];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(grp, -1, sizeof(grp));

	bool start = true;
	int _min, _max;

	for (int i = 0; i < n; i++)
	{
		int num = arr[i];
		if (grp[num] != -1)
		{
			cout << grp[num] << " ";
		}

		else
		{
			int _min = num;
			for (int j = 0; j < k; j++)	// k-1만큼 차이날때까지 검사
			{
				if (num - j < 0)	// num - j가 0보다 작아지면
					break;
				if (grp[num - j] != -1)	// num - j가 이미 그룹에 속해있으면
				{
					if (num - grp[num - j] < k)		// 그 그룹에 속할 수 있으면 그 그룹의 키값이 최솟값이다.
					{
						grp[num] = grp[num - j];
						_min = grp[num - j];
						break;
					}
					else        // 그 그룹에 속할 수 없다면 [그 전 숫자, num] 그룹 생성
					{
						grp[num] = num;		
						break;
					}
				}
				else // num - j가 그룹에 속해있지 않다면 최솟값으로 갱신한다.
				{
					_min = num - j;
				}
			}
			for (int j = _min; j <= num; j++)	// 최솟값을 키값으로 [최솟값, 현재값] 그룹 생성
				grp[j] = _min;
			cout << grp[num] << " ";
		}
	}

	return 0;
}