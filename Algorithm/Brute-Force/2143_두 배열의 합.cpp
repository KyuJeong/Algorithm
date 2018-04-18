#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
int A[1001];
int B[1001];
int ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];

	return 0;
}