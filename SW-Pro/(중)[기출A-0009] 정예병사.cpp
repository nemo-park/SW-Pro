#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct soldier {
	int attack;
	int defense;
};

struct compare {
	bool operator()(soldier& a, soldier& b) {
		// attack 기준 오름차순 정렬
		if (a.attack == b.attack)
			return a.defense > b.defense;
		else
			return a.attack > b.attack;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {

		int cnt = 0; int att = 0; int def = 0;
		cin >> cnt;

		priority_queue<soldier, vector<soldier>, compare> pq;

		for (int j = 1; j <= cnt; j++) {
			cin >> att >> def;
			pq.push({ att, def });
		}

		int ans = 1;
		int minDefense = pq.top().defense;
		pq.pop();

		while (!pq.empty()) {

			if (pq.top().defense == 1) {
				ans++;
				break;
			}

			if (pq.top().defense < minDefense) {
				minDefense = pq.top().defense;
				ans++;
			}

			pq.pop();
		}

		cout << "#" << i << " " << ans << '\n';
	}
	return 0;
}