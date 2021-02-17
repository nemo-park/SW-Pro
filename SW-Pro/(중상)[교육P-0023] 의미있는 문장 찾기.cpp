#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int totCnt, mCnt, result;
int word[1000001];
int wordCnt[1000001];

int twoPointer() {

	int start = 0;
	int end = 0;
	int findWordCnt = 0;
	int usedCnt = 0;
	int minVal = INT_MAX;

	while (start <= end && end <= totCnt) {

		if (findWordCnt < mCnt) {
			
			if (wordCnt[word[end]] == 0) findWordCnt++;

			usedCnt++;
			wordCnt[word[end++]]++;
		}
		else if (findWordCnt == mCnt) {

			minVal = min(usedCnt, minVal);

			if (wordCnt[word[start]] == 1) findWordCnt--;

			usedCnt--;
			wordCnt[word[start++]]--;
		}
	}

	if (minVal == INT_MAX) return -1;
	else return minVal;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> totCnt >> mCnt;

		result = 0;
		memset(word, 0, sizeof(word));
		memset(wordCnt, 0, sizeof(wordCnt));

		for (int i = 0; i < totCnt; i++) {
			cin >> word[i];
		}

		cout << "#" << tc << " " << twoPointer() << '\n';
	}
	return 0;
}