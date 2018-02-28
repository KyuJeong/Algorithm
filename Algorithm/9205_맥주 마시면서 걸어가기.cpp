#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int T;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		pii H, R;
		pii C[101];

		cin >> H.first >> H.second;
		for (int i = 0; i < N; i++)
			cin >> C[i].first >> C[i].second;
		cin >> R.first >> R.second;
		
	}

	return 0;
}