#include <iostream>
#include <string>

using namespace std;

#define MAX 10000

template <typename T>
class stack
{
private:
	T arr[MAX] = { 0 };
	int idx = 0;
public:
	void push(T data)
	{
		if (idx == MAX) return; // 꽉 차면 push 불가
		arr[idx++] = data;
	}

	void pop()
	{
		if (idx == 0) return; // 비어있으면 pop 불가
		idx--;
	}

	int size() { return idx; }

	bool empty()
	{
		if (idx == 0) return true;
		else return false;
	}

	T top()
	{
		if (idx == 0) return -1;
		return arr[idx - 1];
	}
};

int operationRank(char op)
{
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 3;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack <char> st;

	string s;
	cin >> s;
	for (auto i : s)
	{
		if (i >= 'A' && i <= 'Z')
			cout << i;
		else
		{
			int rank = operationRank(i);
			if (rank == 0)
				st.push(i);
			else if (rank == 1 || rank == 2)
			{
				while (!st.empty() && operationRank(st.top()) >= rank)
				{
					cout << st.top();
					st.pop();
				}
				st.push(i);
			}
			else
			{
				while (!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}

	while (!st.empty())
		cout << st.top(), st.pop();

	return 0;
}