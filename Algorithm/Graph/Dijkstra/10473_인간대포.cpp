#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <functional>

#define INF 2147483647

struct Pt
{
	double x;
	double y;
	Pt()
	{}
	Pt(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};


double calDistance(Pt pt1, Pt pt2)
{
	double distance = sqrt(pow(pt2.y - pt1.y, 2) + pow(pt2.x - pt1.x, 2));

	return distance;
}

double calCost(Pt pt1, Pt pt2)
{
	double distance = calDistance(pt1, pt2);

	double cost = 2.0 + abs((distance - 50.0) / 5.0);

	return cost;
}


using namespace std;

int n;
vector <double> dist(102, -1.0);
bool visit[102];
vector <Pt> point(102);
vector <vector <pair <double, int>>> v(102);

int main()
{
	cin >> point[0].x >> point[0].y;
	cin >> point[1].x >> point[1].y;

	cin >> n;

	for (int i = 2; i <= n + 1; i++)
	{
		cin >> point[i].x >> point[i].y;
	}

	v[0].push_back(make_pair(calDistance(point[0], point[1]) / 5.0, 1));

	for (int i = 2; i <= n + 1; i++)
	{
		v[0].push_back(make_pair(calDistance(point[0], point[i]) / 5.0, i));
		v[i].push_back(make_pair(calCost(point[1], point[i]), 1));
		for (int j = i + 1; j <= n + 1; j++)
		{
			if (i != j)
			{
				double tmp = calCost(point[i], point[j]);
				v[i].push_back(make_pair(tmp, j));
				v[j].push_back(make_pair(tmp, i));
			}
		}
	}

	dist[0] = 0.0;

	priority_queue <pair <double, int>, vector <pair <double, int>>, greater<pair <double, int>>> pq;
	pq.push(make_pair(0.0, 0));

	while (!pq.empty())
	{
		double cur_cost = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (visit[cur])
			continue;
		visit[cur] = true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			double nxt_cost = v[cur][i].first + cur_cost;
			int nxt = v[cur][i].second;
			if (dist[nxt] == -1.0 || dist[nxt] > nxt_cost)
			{
				dist[nxt] = nxt_cost;
				pq.push(make_pair(nxt_cost, nxt));
			}
		}
	}

	printf("%.6lf\n", dist[1]);

	return 0;
}