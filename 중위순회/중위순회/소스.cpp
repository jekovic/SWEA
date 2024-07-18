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

const int n = 101;
int N;

typedef struct node* treepointer;
typedef struct node {
	char data;
	treepointer left, right;
}node;

void inorder(treepointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data;
		inorder(ptr->right);
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
		
		cin >> N;

		node nodes[n + 1];

		for (int i = 1; i <= N; i++) {

			nodes[i].data = 'a';
			nodes[i].left = NULL;
			nodes[i].right = NULL;
		}

		if (N % 2 == 0) {
			for (int i = 1; i <= N / 2 - 1; i++) {
				int q, w, e;
				char r;
				cin >> q >> r >> w >> e;
				nodes[i].data = r;
			}
			int q, w;
			char r;
			cin >> q >> r >> w;
			nodes[N / 2].data = r;
			for (int i = N / 2 + 1; i <= N; i++) {
				int q; char r;
				cin >> q >> r;
				nodes[i].data = r;
			}
		}
		else {
			for (int i = 1; i <= N / 2; i++) {
				int q, w, e;
				char r;
				cin >> q >> r >> w >> e;
				nodes[i].data = r;
			}
			for (int i = N / 2 + 1; i <= N; i++) {
				int q; char r;
				cin >> q >> r;
				nodes[i].data = r;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (i % 2 == 0) {
				nodes[i / 2].left = &nodes[i];
			}
			else {
				nodes[i / 2].right = &nodes[i];
			}
		}

		cout << "#" << test_case << ' ';

		inorder(&nodes[1]);

		cout << '\n';		

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}