/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		input();

		solve();

		cout << "#" << test_case << ' ' << result << '\n';

		init();

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}