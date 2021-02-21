#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX_N 100001
using namespace std;

pair<int, int> s[MAX_N];

bool compare(pair<int, int> a, pair<int, int> b) {
	// first 기준 오름차순 정렬
	if (a.first == b.first)	return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		memset(s, 0, sizeof(s));

		int cnt = 0;
		cin >> cnt;
		int attack = 0;	int defense = 0;
		for (int i = 0; i < cnt; i++) {
			cin >> attack >> defense;
			s[i] = { attack, defense };
		}

		sort(s, s + cnt, compare);

		int ans = 1;
		int minDefense = s[0].second;
		for (int i = 1; i < cnt; i++) {

			if (s[i].second == 1) {
				ans++;
				break;
			}

			if (s[i].second < minDefense) {
				minDefense = s[i].second;
				ans++;
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}