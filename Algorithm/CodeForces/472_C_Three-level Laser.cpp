#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
double S;
vector <double> v;
double tmp;
int lft, rgt;
double ans = -1;

int main()
{
	scanf("%d %lf", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &tmp);
		v.push_back(tmp);
	}

	rgt = 2;

	while (rgt < N)
	{
		double dif = v[rgt] - v[lft];
		
		if (dif <= S)
		{
			double E = (v[rgt] - v[lft + 1]) / dif;
			ans = max(ans, E);
			if (rgt < N - 1)
			{
				if (v[rgt + 1] - v[lft] <= S)
					rgt++;
				else
					lft++;
			}
			else
				lft++;
		}

		else
		{
			lft++;
		}

		if (rgt - lft < 2)
			rgt++;

	}

		printf("%.10lf", ans);

	return 0;
}