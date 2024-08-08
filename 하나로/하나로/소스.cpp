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
#include<queue>
#include <algorithm>
#include<cmath>

using namespace std;

long long N;
double E;
long long result;
vector<long long> t_x;
vector<long long> t_y;
vector<pair<long long, long long>> tunnel;

class Edge {
public:
	long long node[2];
	double dis;
	Edge(long long a, long long b, double dis) {
		this->node[0] = a;
		this->node[1] = b;
		this->dis = dis;
	}
	bool operator < (Edge& e) {
		return this->dis < e.dis;
	}
};

long long getparent(vector<long long>& parent, long long a) {
	if (parent[a] == a) return a;
	return parent[a] = getparent(parent, parent[a]);
}

void unionparent(vector<long long>& parent, long long a, long long b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

	if (a < b) parent[b] = a;
	else if (a > b) parent[a] = b;
}

long long findparent(vector<long long>& parent, long long a, long long b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

	if (a == b) return 1;
	else return 0;
}

vector<Edge> v;

double cal(long long x1, long long y1, long long x2, long long y2) {
	double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	double res = E * pow(d, 2);
	//res = round(res);
	return res;
}

void cal_dis() {
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++) {
			if (i == j) continue;
			v.push_back(Edge(i, j, cal(tunnel[i].first, tunnel[i].second, tunnel[j].first, tunnel[j].second)));
		}
	}
}

void input() {
	cin >> N;

	for (long long i = 0; i < N; i++) {
		long long q;
		cin >> q;
		t_x.push_back(q);
	}

	for (long long i = 0; i < N; i++) {
		long long q;
		cin >> q;
		t_y.push_back(q);
	}

	cin >> E;

	for (long long i = 0; i < N; i++) {
		tunnel.push_back({ t_x[i], t_y[i] });
	}
}

void solve() {
	cal_dis();

	sort(v.begin(), v.end());

	vector<long long> d(N, 0);
	for (long long i = 0; i < N; i++) {
		d[i] = i;
	}
	
	double res = 0;

	for (long long i = 0; i != v.size(); i++) {
		if (!findparent(d, v[i].node[0], v[i].node[1])) {
			res += v[i].dis;
			unionparent(d, v[i].node[0], v[i].node[1]);
		}
	}
	result = round(res);
}

void init() {
	t_x.clear();
	t_y.clear();
	tunnel.clear();
	v.clear();
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

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

		cout << "#" << test_case << ' ' << result << '\n';

		init();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}