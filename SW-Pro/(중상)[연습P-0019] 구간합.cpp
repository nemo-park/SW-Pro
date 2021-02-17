#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long tree[400001];

void update(int idx, long long diffVal) {
	while (idx > 0) {
		tree[idx] += diffVal;
		idx = idx / 2;
	}
}

long long sum(int s, int e) {

	long long ans = 0;

	while (s <= e) {
		if (s % 2 == 1) ans += tree[s];
		if (e % 2 == 0) ans += tree[e];

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		int N = 0;
		cin >> N;

		int leafSize = 1;
		while (leafSize < N) {
			leafSize *= 2;
		}

		memset(tree, 0, sizeof(tree));

		for (int i = 0; i < N; i++) {
			tree[leafSize + i] = i + 1;
		}

		for (int i = leafSize - 1; i > 0; i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}

		int Q = 0;
		cin >> Q;
		long long ans = 0;

		for (int i = 0; i < Q; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			if (a == 0) update(leafSize - 1 + b, c - tree[leafSize - 1 + b]);
			else if (a == 1) ans = ans + sum(leafSize - 1 + b, leafSize - 1 + c) % 1000000007;
		}

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}