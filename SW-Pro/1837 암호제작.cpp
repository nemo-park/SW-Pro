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

	// str.length() �� �ƴ�, str[i] �� ���� ������ 
	// str �� �ſ� ū ���� ���� �� �����Ƿ�
	// str ���� ���������� �̵��ϰ� for �� �����
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
		cout << "GOOD" << '\n';
	else
		cout << "BAD " << ans << '\n';

	return 0;
}