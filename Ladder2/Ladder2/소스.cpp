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
#include <algorithm>
#include <vector>

using namespace std;

int map[100][100];
int result;

vector<int> start;
vector<pair<int, int>> res;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}

void init() {
	start.clear();
	res.clear();
}

void input() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
			if (i == 0 and map[i][j] == 1) start.push_back(j);
		}
	}
}

void solve() {
	for (int i = 0; i != start.size(); i++)
	{
		int cnt = 1;
		int cr = start[i];
		for (int j = 1; j < 100; j++) {
			++cnt;
			if (j == 99) {
				res.push_back({ start[i], cnt });				
				break;
			}
			else if (map[j][cr] == 1) {
				if (cr + 1 <= 99 and map[j][cr + 1] == 1) {
					while (1) {
						++cr;
						++cnt;
						if (map[j + 1][cr] == 1)
							break;
					}
				}
				else if (cr - 1 >= 0 and map[j][cr - 1] == 1) {
					while (1) {
						--cr;
						++cnt;
						if (map[j + 1][cr] == 1)
							break;
					}
				}
			}
		}
	}

	sort(res.begin(), res.end(), compare);

	result = res[0].first;
}

int main(int argc, char** argv)
{
	int test_case;
	//int T;
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

	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int t;
		cin >> t;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		input();

		solve();

		cout << "#" << t << ' ' << result << '\n';

		init();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}