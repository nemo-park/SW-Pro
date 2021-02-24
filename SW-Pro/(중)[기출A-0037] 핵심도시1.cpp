#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 100001
using namespace std;

int inOrder;
int discover[MAX_V];
bool isCut[MAX_V];
vector<int> v[MAX_V];

int dfs(int current, bool isRoot) {

	// 방문순서 마킹
	discover[current] = ++inOrder;
	int rtn = discover[current];
	int child = 0;

	for (int next : v[current]) {

		// 미발견 노드
		if (discover[next] == -1) {

			// 루트일 경우, 단절점 파악하기위해 사용
			child++;

			// 자식이 올라갈 수 있는 가장 높은 곳
			int subCnt = dfs(next, false);

			// 루트가 아니면서, 자식들이 올라갈 수 있는 가장 높은곳이 나의 방문 위치보다 크다면
			// 나 이전의 방문노드는 접근 불가한 것으로 판단
			if (!isRoot && subCnt >= discover[current]) {
				// 단절점
				isCut[current] = true;
			}

			rtn = min(rtn, subCnt);

		}
		else {
			rtn = min(rtn, discover[next]);
		}
	}

	// 루트인 경우, child >= 2 이면 단절점
	if (isRoot && child >= 2) {
		isCut[current] = true;
	}

	return rtn;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		inOrder = 0;
		memset(discover, -1, sizeof(discover));
		memset(isCut, false, sizeof(isCut));
		for (int i = 0; i < MAX_V; i++) {
			v[i].clear();
		}

		int nodeCnt = 0;	int caseCnt = 0;
		cin >> nodeCnt >> caseCnt;
		for (int i = 0; i < caseCnt; i++) {
			int a = 0;	int b = 0;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		// 모든 노드가 전부 연결되어있다면 dfs(1, true); 도 가능하나
		// 모든 노드가 연결되어있지 않은 상태에서 단절점을 구해야 한다면
		for (int i = 1; i <= nodeCnt; i++) {
			if (discover[i] == -1) {
				dfs(i, true);
			}
		}


		int cutCnt = 0;
		for (int i = 1; i <= nodeCnt; i++) {
			if (isCut[i]) cutCnt++;
		}

		cout << "#" << tc << " " << cutCnt << " ";
		for (int i = 1; i <= nodeCnt; i++) {
			if (isCut[i])
				cout << i << " ";
		}
		cout << '\n';
	}

	return 0;

}