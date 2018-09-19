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

double calc(char op, double a, double b)
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	return a / b;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack <double> st;

	int n;
	cin >> n;

	string s;
	cin >> s;

	double arr[27];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	double ans = 0;

	for (auto i : s)
	{
		if (i >= 'A' && i <= 'Z')
			st.push(arr[i - 'A']);
		else
		{
			double x = st.top();
			st.pop();
			double y = st.top();
			st.pop();
			ans = calc(i, y, x);
			st.push(ans);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}