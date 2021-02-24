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

	// �湮���� ��ŷ
	discover[current] = ++inOrder;
	int rtn = discover[current];
	int child = 0;

	for (int next : v[current]) {

		// �̹߰� ���
		if (discover[next] == -1) {

			// ��Ʈ�� ���, ������ �ľ��ϱ����� ���
			child++;

			// �ڽ��� �ö� �� �ִ� ���� ���� ��
			int subCnt = dfs(next, false);

			// ��Ʈ�� �ƴϸ鼭, �ڽĵ��� �ö� �� �ִ� ���� �������� ���� �湮 ��ġ���� ũ�ٸ�
			// �� ������ �湮���� ���� �Ұ��� ������ �Ǵ�
			if (!isRoot && subCnt >= discover[current]) {
				// ������
				isCut[current] = true;
			}

			rtn = min(rtn, subCnt);

		}
		else {
			rtn = min(rtn, discover[next]);
		}
	}

	// ��Ʈ�� ���, child >= 2 �̸� ������
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

		// ��� ��尡 ���� ����Ǿ��ִٸ� dfs(1, true); �� �����ϳ�
		// ��� ��尡 ����Ǿ����� ���� ���¿��� �������� ���ؾ� �Ѵٸ�
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