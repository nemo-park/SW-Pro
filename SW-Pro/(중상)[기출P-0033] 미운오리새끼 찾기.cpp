#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX_N 1000001
using namespace std;

int arr[MAX_N];
// ��Ŭ����ȣ����
// GCD(a,b,c) = GCD(GCD(a,b),c) 
int ltor[MAX_N];	// ���ʺ��� ������ �������� gcd �� ���
int rtol[MAX_N];	// �����ʺ��� ���� �������� gcd �� ���

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

		memset(arr, 0, sizeof(arr));

		int totCnt = 0;
		cin >> totCnt;

		for (int i = 0; i < totCnt; i++) {
			cin >> arr[i];
		}

		// ltor ä���
		ltor[0] = arr[0];
		for (int i = 1; i < totCnt; i++) {
			ltor[i] = gcd(ltor[i - 1], arr[i]);
		}

		// rtol ä���
		rtol[totCnt - 1] = arr[totCnt - 1];
		for (int i = totCnt - 2; i >= 0; i--) {
			rtol[i] = gcd(rtol[i + 1], arr[i]);
		}

		int maxGcd = 0;
		int exeNum = 0;

		for (int i = 0; i < totCnt; i++) {

			int tempGcd = gcd(ltor[i - 1], rtol[i + 1]);

			if (arr[i] % tempGcd != 0 && maxGcd < tempGcd) {
				maxGcd = tempGcd;
				exeNum = arr[i];
			}
		}

		cout << "#" << tc << " " << maxGcd << " " << exeNum << '\n';

	}
	return 0;
}