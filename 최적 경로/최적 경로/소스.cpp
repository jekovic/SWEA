/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int sx, sy, hx, hy;
vector<pair<int, int>> house;
vector<int> vis;
int result = 1e9;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return abs(sx - a.first) + abs(sy - a.second) < abs(sx - b.first) + abs(sy - b.second);
}

void input() {
	cin >> N;
	cin >> sx >> sy >> hx >> hy;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		house.push_back({ q, w });
	}
	
	//sort(house.begin(), house.end(), compare);

	vis.assign(N, 0);
}

void init() {
	house.clear();
	result = 1e9;
	vis.clear();
}

int cal_dis(int x1, int y1, int x2, int y2) {
	int dis = 0;

	dis = abs(x1 - x2) + abs(y1 - y2);
	
	return dis;
}

void solve() {
	int dis = 0;
	int stx = sx;
	int sty = sy;

	for (int i = 0; i < N; i++) {
		int idx = vis[i] - 1;
		//int idx = i;
		int d_temp = cal_dis(house[idx].first, house[idx].second, stx, sty);
		dis += d_temp;
		if (dis > result) return;
		stx = house[idx].first;
		sty = house[idx].second;
	}
	
	dis += cal_dis(stx, sty, hx, hy);
	
	result = min(dis, result);
}

void dfs(int cnt) {
	
	if (cnt > N) {
		solve();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		vis[i] = cnt;
		dfs(cnt + 1);
		vis[i] = 0;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		input();

		dfs(1);

		//solve();

		cout << "#" << test_case << ' ' << result << '\n';

		init();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}