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
#include <algorithm>

using namespace std;

vector<double> result;
vector<int> px;
vector<int> mass;
int N;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		px.push_back(t);
	}

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		mass.push_back(t);
	}
}

double cal_grav(int m1, double d) {
	double ret = 0.0;

	ret = (double)m1 / (d * d);

	return ret;
}

void solve() {
	double r = 0.0;
	for (int i = 0; i < N - 1; i++) {
		int x1 = px[i];
		int m1 = mass[i];
		int x2 = px[i+1];
		int m2 = mass[i+1];
		
		double left = x1;
		double right = x2;

		while (right - left >= 1e-12) {
			//if (abs(left - right) < 1e-12) break;
			double mid = (left + right) / 2;
			//if (abs(mid - left) < 1e-12 || abs(right - mid) < 1e-12) break;
			double a = 0.0, b = 0.0;
			for (int t = 0; t <= i; t++) {
				a += cal_grav(mass[t], mid - px[t]);
			}
			for (int t = i + 1; t < N; t++) {
				b += cal_grav(mass[t], px[t] - mid);
			}
			/*double a = cal_grav(m1, mid - x1);
			double b = cal_grav(m2, x2 - mid);*/

			if (a < b) {
				right = mid;
			}
			else if (a > b) {
				left = mid;
			}

			r = mid;
			 
			 if (a == b) break;
		}
		result.push_back(r);
	}
}

void init() {
	result.clear();
	px.clear();
	mass.clear();
}

void print_res(int t) {

	cout << fixed;
	cout.precision(10);

	cout << "#" << t << ' ';

	for (auto r : result) {
		cout << r << ' ';
	}
	cout << '\n';
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

		print_res(test_case);

		init();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}