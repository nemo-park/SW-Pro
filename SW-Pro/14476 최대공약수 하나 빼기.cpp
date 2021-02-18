#include <iostream>
#include <string>
#include <cstring>
#define MAX_N 1000000
using namespace std;

int arr[MAX_N];
int ltor[MAX_N];
int rtol[MAX_N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}

	ltor[0] = arr[0];
	for (int i = 1; i < cnt; i++) {
		ltor[i] = gcd(ltor[i - 1], arr[i]);
	}

	rtol[cnt - 1] = arr[cnt - 1];
	for (int i = cnt - 2; i >= 0; i--) {
		rtol[i] = gcd(rtol[i + 1], arr[i]);
	}

	int maxGcd = 0;
	int exeNum = 0;
	for (int i = 0; i < cnt; i++) {
		int tempGcd = gcd(ltor[i - 1], rtol[i + 1]);

		if (arr[i] % tempGcd != 0 && maxGcd < tempGcd) {
			maxGcd = tempGcd;
			exeNum = arr[i];
		}
	}

	if (exeNum == 0 && maxGcd == 0) 
		cout << -1;
	else 
		cout << maxGcd << " " << exeNum;

	return 0;

}