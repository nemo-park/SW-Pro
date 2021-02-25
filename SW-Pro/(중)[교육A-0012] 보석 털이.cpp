#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX_N 1001	// ���� ���� MAX Value
#define MAX_M 10001	// ���� ���� MAX Value
using namespace std;

long c[MAX_N];
int w[MAX_N];

// i��° �������� Ȯ���Ͽ� j ���Ը�ŭ ä�������� �ִ밡ġ
long dp[MAX_N][MAX_M];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		// DP Table �ʱ�ȭ
		memset(dp, 0, sizeof(dp));
		memset(c, 0, sizeof(c));
		memset(w, 0, sizeof(w));

		int cnt = 0; int wLimit = 0;
		cin >> cnt >> wLimit;

		for (int i = 1; i <= cnt; i++) {
			cin >> c[i] >> w[i];
		}

		for (int i = 1; i <= cnt; i++) {
			for (int j = 1; j <= wLimit; j++) {
				// i��° ���� �������� �ʴ� ���
				dp[i][j] = dp[i - 1][j];

				if (w[i] <= j) {
					// i��° ���� ����
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
				}
			}
		}

		cout << "#" << tc << " " << dp[cnt][wLimit] << '\n';
	}

	return 0;

}