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
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
vector<int> num;
string N;
int n;

void split_N(){
	string temp;
	for (char n_ : N) {
		if (n_ != '#') {
			temp += n_;
		}
	}
	n = stoi(temp);
}

void input() {
	cin >> N;
	cin >> cnt;

	split_N();

	for (int i = 0; i < cnt; i++) {
		string s;
		cin >> s;

		if (s == "ZRO") {
			num.push_back(0);
		}
		else if (s == "ONE") {
			num.push_back(1);
		}
		else if (s == "TWO") {
			num.push_back(2);
		}
		else if (s == "THR") {
			num.push_back(3);
		}
		else if (s == "FOR") {
			num.push_back(4);
		}
		else if (s == "FIV") {
			num.push_back(5);
		}
		else if (s == "SIX") {
			num.push_back(6);
		}
		else if (s == "SVN") {
			num.push_back(7);
		}
		else if (s == "EGT") {
			num.push_back(8);
		}
		else if (s == "NIN") {
			num.push_back(9);
		}
	}
}

void init() {
	num.clear();
}

void print_res() {
	cout << '#' << n << ' ';

	sort(num.begin(), num.end());
	
	for (int n : num) {
		if (n == 0) {
			cout << "ZRO" << ' ';
		}
		else if (n == 1) {
			cout << "ONE" << ' ';
		}
		else if (n == 2) {
			cout << "TWO" << ' ';
		}
		else if (n == 3) {
			cout << "THR" << ' ';
		}
		else if (n == 4) {
			cout << "FOR" << ' ';
		}
		else if (n == 5) {
			cout << "FIV" << ' ';
		}
		else if (n == 6) {
			cout << "SIX" << ' ';
		}
		else if (n == 7) {
			cout << "SVN" << ' ';
		}
		else if (n == 8) {
			cout << "EGT" << ' ';
		}
		else if (n == 9) {
			cout << "NIN" << ' ';
		}
	}

	cout << '\n';
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

		print_res();

		init();

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}