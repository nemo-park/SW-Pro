#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int totAmountCnt;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)	return a.first > b.first;
	return a.second > b.second;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		v.clear();
		totAmountCnt = 0;

		int totCnt = 0;
		cin >> totCnt;

		for (int i = 1; i <= totCnt; i++) {
			int eachCnt = 0;
			cin >> eachCnt;
			totAmountCnt = totAmountCnt + eachCnt;

			for (int j = 1; j <= eachCnt; j++) {
				int amount = 0;
				cin >> amount;
				v.push_back(make_pair(i, amount));
			}
		}

		sort(v.begin(), v.end(), compare);

		int ans = 0;

		for (int i = totCnt; i > 0; i--) {
			for (int j = 0; j < totAmountCnt; j++) {
				if (v[j].first >= i && v[j].second > 0) {
					ans = ans + v[j].second;
					v[j].second = 0;
					break;
				}
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}