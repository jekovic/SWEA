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
#include <algorithm>

using namespace std;

int result;
int map[100][100];
vector<pair<int, int>> one, two;
int update[100][100];

bool compare_one(pair<int, int>& a, pair<int, int>& b) {
	return a.first > b.first;
}

void input() {
	int n;
	cin >> n;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				one.push_back({ i, j });
			}
			else if (map[i][j] == 2) {
				two.push_back({ i, j });
			}
		}
	}
}

void solve() {
	// 1 N - 2 S
	// up N  -- down S 
	sort(one.begin(), one.end(), compare_one);

	vector<int> vis1(one.size(), 0);
	vector<int> vis2(two.size(), 0);

	for(int t=0; t < 100; t++) {
		
		//move_N -> �Ʒ��������� ������ �����͵� ���� �ɸ��� �͸� �����
		for (int i = 0; i != one.size(); i++) {
			//if (vis1[i]) continue;
			int cx = one[i].first;
			int cy = one[i].second;
			map[cx][cy] = 0;

			cx++;

			if (cx >= 100) {
				//vis1[i] = 1;
				continue;
			}
			if (map[cx][cy] == 2 || map[cx][cy] == 1) {
				cx--;
				map[cx][cy] = 1;
				//vis1[i] = 1;
				continue;
			}
			else {
				map[cx][cy] = 1;
			}
		}

		//move_S -> ���������� ���� �ö� �͵� ���� �ɸ��� �͸� �����
		for (int i = 0; i != two.size(); i++) {
			//if (vis2[i]) continue;
			int cx = two[i].first;
			int cy = two[i].second;
			map[cx][cy] = 0;

			cx--;

			if (cx < 0) {
				//vis2[i] = 1;
				continue;
			}
			if (map[cx][cy] == 1 || map[cx][cy] == 2) {
				cx++;
				map[cx][cy] = 2;
				//vis2[i] = 1;
				continue;
			}
			else {
				map[cx][cy] = 2;
			}
		}
	}

	//�ٺ��� �پ��ִ� �ɵ� ���� 

	for (int i = 0; i < 100; i++) {
		bool flag = true;
		for (int j = 0; j < 100; j++) {
			if (map[j][i] == 1 and flag) {
				flag = false;
			}
			if (map[j][i] == 2 and !flag) {
				result++;
				flag = true;
			}
		}
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

		result = 0;
		one.clear();
		two.clear();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}