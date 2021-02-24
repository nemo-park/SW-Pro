#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> s;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	// ������ �������� ����
	if (a.first == b.first) return b.second > b.second;
	return a.first > b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		int bCnt = 0;	// ������ ����
		int sCnt = 0;	// �����ؾ��ϴ� ������ ����
		cin >> bCnt >> sCnt;

		s.clear();
		v.clear();
		int ans = 0;

		for (int i = 0; i < bCnt; i++) {
			int score;
			cin >> score;
			s.push_back(score);
		}

		for (int i = 0; i < bCnt; i++) {
			int idx = 0;
			cin >> idx;
			v.push_back(make_pair(s[i], idx));
		}

		// ���� ������ �������� ���� - ū ������ ���� �̱� ����!
		sort(v.begin(), v.end(), compare);


		// �ش� ���� �� �� �ִ� ���� ū Index�� ����
		for (int i = sCnt; i > 0; i--) {

			// ������ �Ǿ��ֱ� ������ ū ������ ���� 
			// ���� ������ ���� ������ �ش� ��Ȳ���� ���� ū ������ �����
			for (int j = 0; j < bCnt; j++) {

				// ���� Index�� �� �� �ִ� ���̸� ����
				if (v[j].second >= i && v[j].first > 0) {
					ans = ans + v[j].first;

					// �ݿ��� score �ʱ�ȭ
					v[j].first = 0;

					break;
				}
			}
		}

		cout << "#" << t << " " << ans << '\n';
	}

	return 0;

}