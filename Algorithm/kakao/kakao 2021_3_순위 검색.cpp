#include <bits/stdc++.h>

using namespace std;

struct Info {
	int language;
	int task;
	int career;
	int food;
	int score;
};

vector<string> parseInfo(string str) {
	vector<string> ret;

	int pos = 0;
	string token;

	while ((pos = str.find(" ")) != string::npos) {
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + 1);
	}

	ret.push_back(str);

	return ret;
}

vector<string> parseQuery(string str) {
	vector<string> ret;

	int pos = 0;
	string token;

	while ((pos = str.find(" and ")) != string::npos) {
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + 5);
	}

	ret.push_back(str);

	return ret;
}

vector<Info> all_user;
vector<Info> user_list[1000];
bool check[1000];

bool operator < (const Info& a, const Info& b) {
	return a.score < b.score;
}

void setUserInfo(vector<string> info) {
	int sz = info.size();
	for (int i = 0; i < sz; i++) {
		vector<string> vec = parseInfo(info[i]);
		int num = 0;
		Info user;
		if (vec[0][0] == 'c') user.language = 1;
		else if (vec[0][0] == 'j') user.language = 2;
		else user.language = 3;
		num += (user.language);

		if (vec[1][0] == 'b') user.task = 1;
		else user.task = 2;
		num += (user.task * 5);

		if (vec[2][0] == 'j') user.career = 1;
		else user.career = 2;
		num += (user.career * 25);

		if (vec[3][0] == 'c') user.food = 1;
		else user.food = 2;
		num += (user.food * 125);

		// 1322

		user.score = stoi(vec[4]);

		all_user.push_back(user);

		user_list[num - user.language + 4].push_back(user);
		user_list[num - (user.task * 5) + 15].push_back(user);
		user_list[num - (user.career * 25) + 75].push_back(user);
		user_list[num - (user.food * 125) + 375].push_back(user);

		user_list[num - user.language - user.task * 5 + 19].push_back(user);
		user_list[num - user.language - user.career * 25 + 79].push_back(user);
		user_list[num - user.language - user.food * 125 + 379].push_back(user);
		user_list[num - user.task * 5 - user.career * 25 + 90].push_back(user);
		user_list[num - user.task * 5 - user.food * 125 + 390].push_back(user);
		user_list[num - user.career * 25 - user.food * 125 + 450].push_back(user);

		user_list[num - user.language - user.task * 5 - user.career * 25 + 94].push_back(user);
		user_list[num - user.language - user.task * 5 - user.food * 125 + 394].push_back(user);
		user_list[num - user.language - user.career * 25 - user.food * 125 + 454].push_back(user);
		user_list[num - user.task * 5 - user.career * 25 - user.food * 125 + 465].push_back(user);

		user_list[num - user.language - user.task * 5 - user.career * 25 - user.food * 125 + 469].push_back(user);

		user_list[num].push_back(user);
	}
}

int getAnswer(string query) {
	vector<string> vec = parseQuery(query);
	vector<string> e = parseInfo(vec[3]);
	vec[3] = e[0];
	vec.push_back(e[1]);

	int num = 0;
	Info user;
	if (vec[0][0] == 'c') user.language = 1;
	else if (vec[0][0] == 'j') user.language = 2;
	else if (vec[0][0] == 'p') user.language = 3;
	else user.language = 4;
	num += (user.language);

	if (vec[1][0] == 'b') user.task = 1;
	else if (vec[1][0] == 'f') user.task = 2;
	else user.task = 3;
	num += (user.task * 5);

	if (vec[2][0] == 'j') user.career = 1;
	else if (vec[2][0] == 's') user.career = 2;
	else user.career = 3;
	num += (user.career * 25);

	if (vec[3][0] == 'c') user.food = 1;
	else if (vec[3][0] == 'p') user.food = 2;
	else user.food = 3;
	num += (user.food * 125);
	int score = stoi(vec[4]);
	int ret = 0;
	if (!check[num]) {
		sort(user_list[num].begin(), user_list[num].end());
		check[num] = true;
	}
	int sz = user_list[num].size();
	for (int i = 0; i < sz; i++) {
		if (user_list[num][i].score >= score) {
			ret = sz - i;
			break;
		}
	}

	return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	setUserInfo(info);

	for (auto i : query)
		answer.push_back(getAnswer(i));

	return answer;
}