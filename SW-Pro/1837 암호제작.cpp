#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX_L 1000001
using namespace std;

string str;
int limit;
bool isPrime[MAX_L];

bool chkDivide(int num) {

	int sum = 0;

	// str.length() 가 아닌, str[i] 로 쓰는 이유는 
	// str 이 매우 큰 수가 들어올 수 있으므로
	// str 가장 마지막까지 이동하고 for 문 종료됨
	for (int i = 0; str[i]; i++) {
		sum = (sum * 10 + (str[i] - '0')) % num;
	}

	if (sum == 0) return true;

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> limit;
	memset(isPrime, true, sizeof(isPrime));

	bool divide = false;
	int ans = 0;

	// str이 limit 미만의 소수로 나누어 떨어지는지 체크
	for (int i = 2; i < limit; i++) {

		// 에라토스테네스의 체
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
		cout << "GOOD" << '\n';
	else
		cout << "BAD " << ans << '\n';

	return 0;
}