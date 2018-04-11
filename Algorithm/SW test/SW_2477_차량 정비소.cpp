#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

int T;
int N, M, K, A, B;
int a[10];
int b[10];
int t[1001];

int Solve()
{
	vector <pii> a_cur(10); // 현재 창구 N의 상태(번호, 처리가 끝나는 시간)
	vector <pii> b_cur(10);
	vi a_visit[10];			// 창구 N에서 처리된 번호 목록
	vi b_visit[10];

	priority_queue <int, vector <int>, greater <int>> a_queue;
	queue <int> b_queue;

	int b_cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		a_cur[i].second = -1;
		b_cur[i].second = -1;
	}

	int time = 0;

	while (b_cnt < K) 
	{
		for (int i = 1; i <= K; i++)
		{
			if (t[i] == time)
			{
				a_queue.push(i);
			}
		}

		for (int i = 1; i <= N; i++)	// 접수 창구에서 처리가 끝난 게 있는지 검사
		{
			if (a_cur[i].second == time)
			{
				b_queue.push(a_cur[i].first);
				a_cur[i].first = 0;
				a_cur[i].second = 0;
			}
		}

		if (!a_queue.empty())		// 대기하는 사람이 있으면 빈 창구에 접수시킴
		{
			for (int i = 1; i <= N; i++)
			{
				if (a_cur[i].first == 0)
				{
					int cur = a_queue.top();
					a_visit[i].push_back(cur);
					a_queue.pop();
					a_cur[i].first = cur;
					a_cur[i].second = time + a[i];
					if (a_queue.empty())
						break;
				}
			}
		}

		for (int i = 1; i <= M; i++)	// 접수 창구에서 처리가 끝난 게 있는지 검사
		{
			if (b_cur[i].second == time)
			{
				b_cur[i].first = 0;
				b_cur[i].second = 0;
				b_cnt++;
			}
		}

		if (!b_queue.empty())		// 대기하는 사람이 있으면 빈 창구에 접수시킴
		{
			for (int i = 1; i <= M; i++)
			{
				if (b_cur[i].first == 0)
				{
					int cur = b_queue.front();
					b_visit[i].push_back(cur);
					b_queue.pop();
					b_cur[i].first = cur;
					b_cur[i].second = time + b[i];
					if (b_queue.empty())
						break;
				}
			}
		}

		time++;
	}

	int ans = 0;

	for (auto i : a_visit[A])
	{
		for (auto j : b_visit[B])
		{
			if (i == j)
				ans += i;
		}
	}

	if (ans == 0)
		ans = -1;
	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M >> K >> A >> B;
		
		for (int i = 1; i <= N; i++)
		{
			cin >> a[i];
		}

		for (int i = 1; i <= M; i++)
		{
			cin >> b[i];
		}

		for (int i = 1; i <= K; i++)
		{
			cin >> t[i];
		}

		int ans = Solve();

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}