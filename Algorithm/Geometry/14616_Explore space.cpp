#include <bits/stdc++.h>

using namespace std;

typedef pair <double, double> pdd;

double N, M;
vector <pdd> v;
vector <double> r;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	int cnt = N;

	double X1, Y1, X2, Y2;
	for (int i = 0; i < N; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		double grad1 = Y1 / X1;
		double grad2 = Y2 / X2;
		v[i].first = min(grad1, grad2);
		v[i].second = max(grad1, grad2);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> X1 >> Y1;
		r.push_back(Y1 / X1);
	}

	sort(r.begin(), r.end());

	int idx = 0;

	for (int i = 0; i < N; i++)
	{
		while (idx < M)
		{
			if (v[i].first <= r[idx])
			{
				if (v[i].second >= r[idx])	// 두 기울기 사이에 레이저가 존재하는지 검사
				{
					cnt--;
					break;
				}
				break;
			}
			idx++;
		}
		
	}

	cout << cnt;

	return 0;
}