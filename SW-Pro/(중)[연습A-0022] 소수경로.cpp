#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAX_INPUT 10001
using namespace std;

int s, e;
bool isPrime[MAX_INPUT];
int check[MAX_INPUT];
queue<int> q;

bool chkChar(int a, int b) {

	string s1 = to_string(a);
	string s2 = to_string(b);

	int chk = 0;
	for (int j = 0; j < 4; j++) {
		if (s1[j] != s2[j]) {
			chk++;
			if (chk > 1) return false;
		}
	}
	return true;
}

void bfs() {

	q.push(s);
	check[s] = 0;

	while (!q.empty()) {

		int chkVal = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			string val_s = to_string(chkVal);

			for (int j = 0; j < 10; j++) {
				// ASCII 활용하여 int > char 변경
				val_s[i] = j + '0';

				int nextVal = stoi(val_s);

				if (nextVal >= 1000 && isPrime[nextVal] == true && check[nextVal] == -1) {
					q.push(nextVal);
					check[nextVal] = check[chkVal] + 1;
				}
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> s >> e;

		memset(isPrime, true, sizeof(isPrime));

		// Start, End 같은 값인 경우 구별하기 위함
		memset(check, -1, sizeof(check));

		for (int i = 2; i <= sqrt(MAX_INPUT); i++) {
			if (isPrime[i] == true) {
				for (int j = i + i; j <= MAX_INPUT; j += i) {
					isPrime[j] = false;
				}
			}
		}

		bfs();

		cout << "#" << tc << " " << check[e] << '\n';
	}

	return 0;
}