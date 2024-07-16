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

		print_res();

		init();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}