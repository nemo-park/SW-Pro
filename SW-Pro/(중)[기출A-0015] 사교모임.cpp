#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int parent[1001];
int member[1001];

// Find Function : �μ��� �ѱ� ������ �θ� ������ �˷���
int getParent(int a) {

	// ������ �θ� �ڱ� �ڽ�. ������ ã���� �� return
	if (parent[a] == a) return a;

	// parent[x] = parent[parent[x]] = parent[parent[parent[x]]] �̷���! x�� ������ ���ϵ�. 
	return parent[a] = getParent(parent[a]);

}

// Union Function : �θ� ���� �׷����� �� ������ ������
void unionParent(int a, int b) {

	int aRoot = getParent(a);
	int bRoot = getParent(b);

	// ��Ʈ�� ���ٸ� �̹� ���� Ʈ��
	if (aRoot == bRoot)	return;

	// �� ������ �θ�� ��ġ�� ����, ���� �� ���� ���� ���� �θ�� �����Ѵ�.
	if (aRoot < bRoot) {
		parent[bRoot] = aRoot;
		member[aRoot] += member[bRoot];
		member[bRoot] = 0;
	}
	else {
		parent[aRoot] = bRoot;
		member[bRoot] += member[aRoot];
		member[aRoot] = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		memset(parent, 0, sizeof(parent));
		memset(member, 0, sizeof(member));

		int pCnt = 0;	int caseCnt = 0;
		cin >> pCnt >> caseCnt;

		// Initialize
		for (int i = 1; i <= pCnt; i++) {
			parent[i] = i;
			member[i] = 1;
		}

		for (int i = 0; i < caseCnt; i++) {
			int a = 0; int b = 0;
			cin >> a >> b;
			unionParent(a, b);
		}

		int gCnt = 0;
		int maxCnt = 0;
		for (int i = 1; i <= pCnt; i++) {
			if (member[i] > 1) {
				gCnt++;
				maxCnt = max(maxCnt, member[i]);
			}
		}

		cout << "#" << tc << " " << gCnt << " " << maxCnt << '\n';
	}

	return 0;

}