#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll init(vector <ll> &arr, vector <ll> &tree, int node, int start, int end)
{

	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}


int main()
{
	std::ios::sync_with_stdio(false);

	return 0;
}