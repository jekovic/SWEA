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
#include <string>

using namespace std;

int N, M;
vector<string> num;
string digit[] = {
	"0001101",
	"0011001",
	"0010011",
	"0111101",
	"0100011",
	"0110001",
	"0101111",
	"0111011",
	"0110111",
	"0001011"
};
string str;
int odd, even;
int result;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		num.push_back(s);
	}
}

int compare(string s_) {
	for (int i = 0; i < 10; i++) {
		if (digit[i] == s_) {
			return i;
		}
	}
	return -1;
}

void solve() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (num[i][j] == '1') {
				while (1) {
					if (j == M) {
						flag = false;
						break;
					}
					str += num[i][j];
					j++;
				}
				break;
			}
			if(!flag)
				break;
		}
	}

	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '1') {
			break;
		}
		str.pop_back();
	}

	int t = 56 - str.size();
	for (int i = 0; i < t; i++) {
		str.insert(str.begin(), '0');
	}

	string temp = "";
	for (int i = 0; i < 56; i++) {
		temp += str[i];
		if (i % 7 == 6) {
			int idx = compare(temp);
			if (i % 2 == 0) {
				odd += idx;
			}
			else {
				even += idx;
			}
			temp = "";
		}
	}

	result = odd * 3 + even;

	if (result % 10 != 0) {
		result = 0;
	}
	else {
		result = odd + even;
	}
}

void init() {
	num.clear();
	str = "";
	odd = 0;
	even = 0;
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

		cout << "#" << test_case << ' ' << result << '\n';

		init();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}