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

		cout << "#" << test_case << ' ';
		cout << same_node << ' ' << ++cnt_node << '\n';

		init();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}