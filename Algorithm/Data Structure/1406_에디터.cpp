#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	stack <char> front;
	stack <char> back;

	string sntc;
	int num;
	char order;
	char word;

	cin >> sntc;
	cin >> num;

	for (int i = 0; i < sntc.size(); i++)
	{
		front.push(sntc[i]);
	}

	for (int i = 0; i < num; i++)
	{
		cin >> order;
		switch (order)
		{
		case 'L':
			if (!front.empty())
			{
				back.push(front.top());
				front.pop();
			}
			break;
		case 'D':
			if (!back.empty())
			{
				front.push(back.top());
				back.pop();
			}
			break;
		case 'B':
			if (!front.empty())
			{
				front.pop();
			}
			break;
		case 'P':
			cin >> word;
			front.push(word);
			break;
		}
	}

	int size = front.size();
	for (int i = 0; i < size; i++)
	{
		back.push(front.top());
		front.pop();
	}

	size = back.size();
	for (int i = 0; i < size; i++)
	{
		cout << back.top();
		back.pop();
	}


	return 0;
}