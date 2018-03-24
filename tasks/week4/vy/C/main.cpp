#include <iostream>
#include <set>

using namespace std;

const int ABC = 26;
const int INF = 1e9;

struct Node {
	int cnt;
	Node *next[ABC];
	Node(int cnt): cnt(cnt) {
		for (int i = 0; i < ABC; ++i)
			next[i] = nullptr;
	}
};

Node *root = new Node(INF);
set <string> dict;

int countPath(string & s) {
	Node *cur = root;
	for (int i = 0; i < s.length(); ++i) {
		cur = cur->next[s[i] - 'a'];
		if (cur->cnt == 1)
			return i + 1;
	}
	return s.length();
}

void makePath(string & s) {
	Node *cur = root;
	for (int i = 0; i < s.length(); ++i) {
		int ind = s[i] - 'a';
		if (cur->next[ind] == nullptr)
			cur->next[ind] = new Node(0);
		cur = cur->next[ind];
		++cur->cnt;
	}
}

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (dict.count(s))
			ans += countPath(s);
		else {
			ans += s.length();
			makePath(s);
			dict.insert(s);
		}
	}
	cout << ans << endl;
	cin >> n;
	return 0;
}