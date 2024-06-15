#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
int M;

ll Init(vector <ll> &arr, vector <ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(Init(arr, tree, node * 2, start, mid), Init(arr, tree, node * 2 + 1, mid + 1, end));
}

ll Update(vector <ll> &tree, int node, int start, int end, int index, ll val)
{
	if (index < start || index > end)
		return tree[node];

	int mid = (start + end) / 2;

	if (start == end)
		return tree[node] = val;
	else
		return tree[node] = min(Update(tree, node * 2, start, mid, index, val), Update(tree, node * 2 + 1, mid + 1, end, index, val));
}

ll Min(vector <ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)	// [left, right]와 [start, end]가 겹치지 않는 경우
		return 1e9;

	if (left <= start && end <= right)	// [left, right]가 [start, end]를 완전히 포함하는 경우
		return tree[node];

	int mid = (start + end) / 2;

	return min(Min(tree, node * 2, start, mid, left, right), Min(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{

	scanf("%d", &N);

	vector <ll> A(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
	}
	scanf("%d", &M);

	int h = (int)ceil(log2(N));
	int size = (1 << (h + 1));

	vector <ll> v(size);
	Init(A, v, 1, 0, N - 1);

	while (M--)
	{
		int q, idx, b;
		scanf("%d %d %d", &q, &idx, &b);
		if (q == 1)
		{
			Update(v, 1, 0, N - 1, idx - 1, b);
		}
		else
		{
			printf("%lld\n", Min(v, 1, 0, N - 1, idx - 1, b - 1));
		}
	}

	return 0;
}