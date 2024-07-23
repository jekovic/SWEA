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
#include <algorithm>

#define MAX 2000

using namespace std;

int hex2bin[16][4] = {
	{0, 0, 0, 0},	//1
	{0, 0, 0, 1},	//2
	{0, 0, 1, 0},	//3
	{0, 0, 1, 1},	//4
	{0, 1, 0, 0},	//5
	{0, 1, 0, 1},	//6
	{0, 1, 1, 0},	//7
	{0, 1, 1, 1},	//8	
	{1, 0, 0, 0},	//9	
	{1, 0, 0, 1},	//10
	{1, 0, 1, 0},	//A
	{1, 0, 1, 1},	//B
	{1, 1, 0, 0},	//C
	{1, 1, 0, 1},	//D
	{1, 1, 1, 0},	//E
	{1, 1, 1, 1}	//F
};

int code[5][5][5];
int result;
int N, M;
int map[MAX][MAX];

void setCode() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				code[i][j][k] = -1;
			}
		}
	}

	code[2][1][1] = 0;
	code[2][2][1] = 1;
	code[1][2][2] = 2;
	code[4][1][1] = 3;
	code[1][3][2] = 4;
	code[2][3][1] = 5;
	code[1][1][4] = 6;
	code[3][1][2] = 7;
	code[2][1][3] = 8;
	code[1][1][2] = 9;
}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c <= '9')	c = c - '0';
			else c = c - 'A' + 10;

			for (int k = 0; k < 4; k++) {
				map[i][j * 4 + k] = hex2bin[c][k];
			}
		}
	}

}

void solve() {
	int idx = 7;
	int arr[8] = { 0, };

	for (int i = 1; i < N; i++) {
		for (int j = M * 4 - 1; j >= 0; j--) {
			int part[3] = { 0, 0, 0 };

			if (map[i][j] == 1 and map[i - 1][j] == 0) {
				while (map[i][j] == 1) {
					part[2]++; j--;
				}
				while (map[i][j] == 0) {
					part[1]++; j--;
				}
				while (map[i][j] == 1) {
					part[0]++; j--;
				}
				j++;

				int Min = min(part[0], part[1]);
				Min = min(Min, part[2]);

				for (int i = 0; i < 3; i++) {
					part[i] /= Min;
				}

				arr[idx--] = code[part[0]][part[1]][part[2]];

				if (arr[idx + 1] == -1) {
					result = 0;
					return;
				}

				if (idx == -1) {
					int val = (arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5] + arr[7];
					if (val % 10 == 0) {
						for (int i = 0; i < 8; i++) {
							result = result + arr[i];
						}
					}
					idx = 7;
				}
			}
		}
	}
}

void init() {
	result = 0;
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

	setCode();

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