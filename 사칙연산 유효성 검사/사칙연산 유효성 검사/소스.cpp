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

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string oper[201];
int tree[201][2];

void input() {
	cin >> N;

	if (N % 2 == 0) {
		for (int i = 1; i <= N / 2 - 1; i++) {
			cin >> i;
			string ch;
			cin >> ch;
			oper[i] = ch;
			int left, right;
			cin >> left >> right;
			tree[i][0] = left;
			tree[i][1] = right;
		}

		int t;
		cin >> t;
		string ch;
		cin >> ch;
		oper[N/2] = ch;
		int left;
		cin >> left;
		tree[N / 2 + 1][0] = left;

		for (int i = N / 2 + 1; i <= N; i++) {
			cin >> i;
			string ch;
			cin >> ch;
			oper[i] = ch;
		}
	}
	else {
		for (int i = 1; i <= N / 2; i++) {
			cin >> i; 
			string ch;
			cin >> ch;
			oper[i] = ch;
			int left, right;
			cin >> left >> right;
			tree[i][0] = left;
			tree[i][1] = right;
		}
		for (int i = N / 2 + 1; i <= N; i++) {
			cin >> i;
			string ch;
			cin >> ch;
			oper[i] = ch;
		}
	}
}

bool inorder() {
	for (int i = 1; i <= N; i++) {
		if (oper[i] == "+" || oper[i] == "-" || oper[i] == "*" || oper[i] == "/") {
			if (tree[i][0] and tree[i][1]) {

			}
			else {
				return false;
			}
		}
		/*if (tree[i][0]) {

		}
		else {
			if (oper[i] == "+" || oper[i] == "-" || oper[i] == "*" || oper[i] == "/") {
				return false;
			}
		}*/
	}
	
	return true;
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
		input();

		int res = inorder();

		cout << "#" << test_case << ' ' << res << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}