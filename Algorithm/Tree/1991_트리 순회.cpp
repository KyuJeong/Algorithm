#include <bits/stdc++.h>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

void preOrder(Node* cur)
{
	cout << cur->data;
	if(cur->left != nullptr)
		preOrder(cur->left);
	if(cur->right != nullptr)
		preOrder(cur->right);
}

void inOrder(Node* cur)
{
	if (cur->left != nullptr)
		inOrder(cur->left);
	cout << cur->data;
	if (cur->right != nullptr)
		inOrder(cur->right);
}

void postOrder(Node* cur)
{
	if (cur->left != nullptr)
		postOrder(cur->left);
	if (cur->right != nullptr)
		postOrder(cur->right);
	cout << cur->data;
}

Node node[26];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	char d, l, r;
	for (int i = 0; i < N; i++)
	{
		cin >> d >> l >> r;
		Node* n = &node[d - 'A'];
		n->data = d;
		if (l == '.')
			n->left = nullptr;
		else 
			n->left = &node[l - 'A'];
		if (r == '.')
			n->right = nullptr;
		else
			n->right = &node[r - 'A'];
	}

	preOrder(&node[0]);
	cout << "\n";
	inOrder(&node[0]);
	cout << "\n";
	postOrder(&node[0]);
	cout << "\n";

	return 0;
}