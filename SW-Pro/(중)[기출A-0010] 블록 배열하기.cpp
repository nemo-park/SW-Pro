#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	// 점수별 내림차순 정렬
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

		int bCnt = 0;	// 블록의 개수
		int sCnt = 0;	// 선택해야하는 블록의 개수
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

		// 블록 점수순 내림차순 정렬 - 큰 점수를 먼저 뽑기 위함!
		sort(v.begin(), v.end(), compare);

		// 해당 값이 들어갈 수 있는 가장 큰 Index에 저장
		for (int i = sCnt; i > 0; i--) {

			// 정렬이 되어있기 때문에 큰 값부터 나옴 
			// 현재 나오는 값은 언제나 해당 상황에서 제일 큰 값임이 보장됨
			for (int j = 0; j < bCnt; j++) {

				// 현재 Index에 들어갈 수 있는 값이면 저장
				if (v[j].second >= i && v[j].first > 0) {
					ans = ans + v[j].first;
					// 반영한 score 초기화
					v[j].first = 0;
					break;
				}
			}
		}

		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}