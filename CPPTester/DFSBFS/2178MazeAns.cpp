// 백준 2178 : 미로 탐색
#include <vector>
#include <string>
#include<queue>
#include <iostream>

using namespace std;

int n, m; // 미로의 세로의 길이 n, 가로의 길이 m
char maze[101][101]; // 각 칸의 이동가능 여부를 저장
queue<pair<int, int>> q;
bool chk[101][101];
int depth[101][101]; // (1, 1)로 부터 각 칸까지 지나야 하는 최소 칸의 수를 저장
int dx[4] = { 1, 0, -1, 0 }; // x좌표의 상하좌우 움직임을 정의
int dy[4] = { 0, 1, 0, -1 }; // y좌표의 상하좌우 움직임을 정의

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}

	// BFS탐색 (BFS알고리즘 특성상 최단거리가 보장됨)
	q.push({ 1, 1 });
	chk[1][1] = true;
	depth[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (maze[next_y][next_x] == '1' && chk[next_y][next_x] == 0) {
				q.push({ next_x, next_y });
				chk[next_y][next_x] = true;
				depth[next_y][next_x] = depth[y][x] + 1;
			}
		}
	}

	cout << depth[n][m] << endl;
}
