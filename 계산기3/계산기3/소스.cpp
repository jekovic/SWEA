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
#include <stack>
#include <vector>

using namespace std;

long long result;

void input_solve() {
	result = 0;

	int N;
	cin >> N;

	string s;
	cin >> s;

	stack<int> stk;

	for (int i = 0; i != s.size(); i++) {
		if (s[i] == '+') {
			//stk.push(-1);
		}
		else if (s[i] == '*') {
			stk.push(-2);
		}
		else if (s[i] == '(') {
			stk.push(-3);
		}
		else if (s[i] == ')') {
			vector<int> temp;
			while (stk.top() != -3) {
				temp.push_back(stk.top());
				stk.pop();
			}
			stk.pop(); // -3
			//reverse(temp.begin(), temp.end());
			stack<int> st;

			for (int i = 0; i != temp.size(); i++) {
				if (st.empty()) {
					st.push(temp[i]);
				}
				else if (st.top() == -2) {
					st.pop();
					int t = st.top() * temp[i];
					st.pop();
					st.push(t);
				}
				else {
					st.push(temp[i]);
				}
			}

			int res = 0;

			while (!st.empty()) {
				res += st.top();
				st.pop();
			}

			stk.push(res);
		}
		else {
			if (stk.empty()) {
				stk.push((int)s[i] - '0');
			}
			else if (stk.top() == -2) {
				stk.pop();
				int t = stk.top() * ((int)s[i] - '0');
				stk.pop();
				stk.push(t);
			}
			else {
				stk.push((int)s[i] - '0');
			}
		}
	}

	result = 0;

	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
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
//	cin >> T;
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

		cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}