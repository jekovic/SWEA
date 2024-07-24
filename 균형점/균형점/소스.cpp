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

vector<double> result;
vector<int> px;
vector<int> mass;
int N;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		px.push_back(t);
	}

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		mass.push_back(t);
	}
}

double cal_grav(int m1, double d) {
	double ret = 0.0;

	ret = (double)m1 / (d * d);

	return ret;
}

void solve() {
	double r = 0.0;
	for (int i = 0; i < N - 1; i++) {
		int x1 = px[i];
		int m1 = mass[i];
		int x2 = px[i+1];
		int m2 = mass[i+1];
		
		double left = x1;
		double right = x2;

		while (right - left >= 1e-12) {
			//if (abs(left - right) < 1e-12) break;
			double mid = (left + right) / 2;
			//if (abs(mid - left) < 1e-12 || abs(right - mid) < 1e-12) break;
			double a = 0.0, b = 0.0;
			for (int t = 0; t <= i; t++) {
				a += cal_grav(mass[t], mid - px[t]);
			}
			for (int t = i + 1; t < N; t++) {
				b += cal_grav(mass[t], px[t] - mid);
			}
			/*double a = cal_grav(m1, mid - x1);
			double b = cal_grav(m2, x2 - mid);*/

			if (a < b) {
				right = mid;
			}
			else if (a > b) {
				left = mid;
			}

			r = mid;
			 
			 if (a == b) break;
		}
		result.push_back(r);
	}
}

void init() {
	result.clear();
	px.clear();
	mass.clear();
}

void print_res(int t) {

	cout << fixed;
	cout.precision(10);

	cout << "#" << t << ' ';

	for (auto r : result) {
		cout << r << ' ';
	}
	cout << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

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

		print_res(test_case);

		init();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}