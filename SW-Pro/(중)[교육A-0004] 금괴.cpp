#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int gold = 0;
		int fCnt = 0;
		cin >> gold >> fCnt;

		int chk = gcd(gold, fCnt);

		if (chk > 1) {
			cout << "#" << tc << " " << ((fCnt / chk) - 1) * chk << '\n';
		}
		else {
			cout << "#" << tc << " " << fCnt - 1 << '\n';
		}
	}
	return 0;
}