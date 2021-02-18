#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX_L 1000001
using namespace std;

string str;
int limit = 0;
bool isPrime[MAX_L];

bool chkDivide(int num) {

	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		sum = (sum * 10 + (str[i] - '0')) % num;
	}

	if (sum == 0) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> str >> limit;
		memset(isPrime, true, sizeof(isPrime));

		bool divide = false;
		int ans = 0;

		// str�� limit �̸��� �Ҽ��� ������ ���������� üũ
		for (int i = 2; i < limit; i++) {
			// �����佺�׳׽��� ü
			for (int j = i + i; j < limit; j += i) {
				isPrime[j] = false;
			}

			if (!isPrime[i]) continue;

			if (chkDivide(i)) {
				divide = true;
				ans = i;
				break;
			}
		}

		if (!divide)
			cout << "#" << tc << " GOOD" << '\n';
		else
			cout << "#" << tc << " BAD " << ans << '\n';
	}

	return 0;
}