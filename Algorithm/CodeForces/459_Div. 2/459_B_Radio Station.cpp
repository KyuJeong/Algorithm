#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
map <string, string> m;
string name, ip;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> name >> ip;
		ip += ';';
		m[ip] = name;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name >> ip;
		string server;
	
		cout << name << " " << ip << " #" << m[ip] << "\n";
	}

	return 0;
}