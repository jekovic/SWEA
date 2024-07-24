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
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int num, change;
int result;
bool isSame = false;
string str;
/*
	�� �ڸ����� ������ �ڸ����� ���� ū���� �ش� �ڸ����� �ٲٱ�
*/
void input() {
	cin >> num >> change;

	str = to_string(num);

	for (int i = 0; i != str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[i] == str[j]) isSame = true;
			break;
		}
		if (isSame) break;
	}
}

int getNum(int n, int step, int tr) {
	string s = to_string(n);

	if (s.size() == 1) {
		return n;
	}
	if (tr == 0) {
		return n;
	}
	if (step == s.size()) {
		if (tr > 0) {
			if (isSame) {
				return n;
			}
			else {
				if (tr % 2 == 0) {
					return n;
				}
				else {
					swap(s[s.size() - 1], s[s.size() - 2]);
					return stoi(s);
				}
			}
		}
		else {
			return n;
		}
	}

	int ret = 0;

	for (int i = step; i != s.size(); i++) {
		if (s[i] < s[step]) continue;
		swap(s[i], s[step]);
		if (step == i) {
			ret = max(ret, getNum(stoi(s), step + 1, tr));
		}
		else {
			ret = max(ret, getNum(stoi(s), step + 1, tr - 1));
		}
		swap(s[i], s[step]);
	}
	return ret;
}

void init() {
	isSame = false;
	result = 0;
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

		result = getNum(num, 0, change);

		cout << "#" << test_case << ' ' << result << '\n';
	
		init();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}