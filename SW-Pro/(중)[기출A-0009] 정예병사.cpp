#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int ans, minVal;
vector<pair<int, int>> soldiers;

bool compare(pair<int, int> a, pair<int, int> b) {
	// first 기준 오름차순 정렬   
	if (a.first == b.first)	return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		soldiers.clear();

		int cnt = 0; int att = 0; int def = 0;
		cin >> cnt;



		for (int j = 1; j <= cnt; j++) {
			cin >> att >> def;
			soldiers.push_back(make_pair(att, def));
		}

		sort(soldiers.begin(), soldiers.end(), compare);

		ans = 1;
		minVal = soldiers[0].second;

		for (int j = 1; j < soldiers.size(); j++) {
			if (soldiers[j].second == 1) {
				ans++;
				break;
			}

			if (soldiers[j].second < minVal) {
				minVal = soldiers[j].second;
				ans++;
			}
		}

		cout << "#" << i << " " << ans << '\n';

	}
	return 0;
}
