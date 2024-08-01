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
#include<algorithm>
#define MAX 10001

using namespace std;

int V, E, node1, node2;
vector<int> top_down[MAX];
vector<int> botton_up[MAX];
int same_node, cnt_node;

void input() {
	cin >> V >> E >> node1 >> node2;

	for (int i = 0; i < E; i++) {
		int q, w;
		cin >> q >> w;
		top_down[q].push_back(w);
		botton_up[w].push_back(q);
	}
}

// same ancestor find
int find_same(vector<int>& v1, vector<int>& v2) {
	int ret = 0;
	int idx = 1e9;

	for (int i = 0; i != v1.size(); i++) {
		if (find(v2.begin(), v2.end(), v1[i]) != v2.end()) {
			ret = v1[i];
			break;
		}
	}

	return ret;
}

void dfs(int cur, vector<int>& v) {
	if (cur == 1) {
		return;
	}

	for (int a : botton_up[cur]) {
		v.push_back(a);
		dfs(a, v);
	}
}

// find node from same ancestor
void find_son(int cur) {
	if (top_down[cur].size() == 0) {
		//cnt_node++;
		return;
	}

	for (int a : top_down[cur]) {
		cnt_node++;
		find_son(a);
	}
}

void solve() {
	vector<int> v1, v2;
	
	dfs(node1, v1);
	dfs(node2, v2);

	same_node = find_same(v1, v2);
	
	find_son(same_node);
}

void init() {
	/*
		int V, E, node1, node2;
		vector<int> top_down[MAX];
		vector<int> botton_up[MAX];
		int same_node, cnt_node;
		vector<int> vis;
	*/
	V = 0, E = 0, node1 = 0, node2 = 0;
	same_node = 0, cnt_node = 0;

	for (int i = 0; i < MAX; i++) {
		top_down[i].clear();
		botton_up[i].clear();
	}
}

int main(int argc, char** argv)
{
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

		solve();

		cout << "#" << test_case << ' ';
		cout << same_node << ' ' << ++cnt_node << '\n';

		init();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}