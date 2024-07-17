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

using namespace std;

int result;
int N;
int ins;
vector<int> pw;

void do_insert(int x, int y) {
	vector<int> temp;
	for (int i = 0; i < y; i++) {
		int t;
		cin >> t;
		temp.push_back(t);
	}
	pw.insert(pw.begin() + x, temp.begin(), temp.end());
}

void do_delete(int x, int y) {
	for (int i = 0; i < y; i++) {
		pw.erase(pw.begin() + x);
	}
}

void do_append(int y) {
	vector<int> temp;
	for (int i = 0; i < y; i++) {
		int t;
		cin >> t;
		temp.push_back(t);
	}
	pw.insert(pw.end(), temp.begin(), temp.end());
}

void input_solve() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		pw.push_back(q);
	}

	cin >> ins;

	for (int i = 0; i < ins; i++) {
		char c;
		int x, y;
		cin >> c;

		if (c == 'I') {
			cin >> x >> y;
			do_insert(x, y);
		}
		else if (c == 'D') {
			cin >> x >> y;
			do_delete(x, y);
		}
		else if (c == 'A') {
			cin >> y;
			do_append(y);
		}
	}
}

void print_res() {
	for (int i = 0; i < 10; i++) {
		cout << pw[i] << ' ';
	}
	cout << '\n';
}

void init() {
	pw.clear();
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
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
	//cin >> T;
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

		input_solve();

		cout << '#' << test_case << ' ';

		print_res();

		init();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}