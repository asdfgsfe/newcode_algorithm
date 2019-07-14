#include<iostream>
#include<vector>
#include<string>
#include<memory.h>
#include<map>
#include<queue>
 
using namespace std;
struct Node {
	int x, y, b_x, b_y, step;
	Node(int x, int y, int b_x, int b_y, int step) :
		x(x), y(y), b_x(b_x), b_y(b_y), step(step) {};
};
 
int n, m;
vector<string> path;
// xy bxby 推着箱子走
int visited[50][50][50][50];
const vector<pair<int, int>> direc = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
 
bool valid(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || path[x][y] == '#') return false;
	return true;
}
 
int bfs(int start_x, int start_y, int box_x, int box_y)
{
	queue<Node> que;
	que.push(Node(start_x, start_y, box_x, box_y, 0));
	visited[start_x][start_y][box_x][box_y] = 1;
	while (!que.empty()) {
		Node node = que.front();
		que.pop();
		int bx = node.b_x;
		int by = node.b_y;
		int step = node.step;
		for (int i = 0; i < 4; ++i) {
			int x = node.x + direc[i].first;
			int y = node.y + direc[i].second;
			// 箱子被同方向推动的位置
			int next_x = bx + direc[i].first;
			int next_y = by + direc[i].second;
 
			if (!valid(x, y)) continue;
			// 走到箱子旁边
			if ((x != bx || y != by) && visited[x][y][bx][by] == 0) {  //没有到达箱子的位置
				visited[x][y][bx][by] = 1;
				que.push(Node(x, y, bx, by, step + 1));
				// 推箱子
			}
			else if (x == bx && y == by && valid(next_x, next_y) && visited[x][y][next_x][next_y] == 0) {
				visited[x][y][next_x][next_y] = 1;
				if (path[next_x][next_y] == 'E')
					return step+1;
				que.push(Node(x, y, next_x, next_y, step + 1));
			}
		}
	}
 
	return -1;
}
 
int main()
{
	memset(visited, 0, sizeof(visited));
	cin >> n >> m;
	path = vector<string>(n, string(""));
	for (int i = 0; i < n; ++i) cin >> path[i];
	int start_x, start_y, box_x, box_y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (path[i][j] == 'S') {
				start_x = i, start_y = j;
			}
			else if (path[i][j] == '0') {
				box_x = i, box_y = j;
			}
		}
	}
	cout << bfs(start_x, start_y, box_x, box_y) << endl;
	return 0;
}
--------------------- 
作者：YTea 
来源：CSDN 
原文：https://blog.csdn.net/ansizhong9191/article/details/88370439 
版权声明：本文为博主原创文章，转载请附上博文链接！