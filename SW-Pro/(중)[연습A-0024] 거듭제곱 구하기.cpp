#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long a, m;

int getPower(long long a, long long m) {

	// Base Case
	if (m == 1) return a % 1000000007;

	// Modular 합동 사용 : XY mod M = (X mod M * Y mod M)
	// a^b = a^b/2 * a^b/2
	long long temp = getPower(a, m / 2);

	// Overflow 방지를 위해 Modular 연산 수행
	temp = temp * temp % 1000000007;

	if (m % 2 == 0) return temp;
	else return (temp * a) % 1000000007;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> a >> m;

		cout << "#" << tc << " " << getPower(a, m) << '\n';
	}

	return 0;
}