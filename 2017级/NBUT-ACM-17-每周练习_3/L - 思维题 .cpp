#include<iostream>

using namespace std;

int n, a[2005], b[2005];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	cout << "Karen" << endl;
}


// ���⣺��X������ѡ��һ��������Y������ѡ��һ���� 
//      ���������������������õ�һ���µ���  �� N=X^Y   ����Ϊpair��X��Y�� 
//      ���X�������Y�����д���N  ��ans+1 
//     ���ansΪż�� ��Karen��ʤ ���Karen
//     ���� ΪKoyomi��ʤ ���Koyomi

//    �����X��Y������ ��ô��Y��X��Ҳ���� ����ans�ض�Ϊż�� ����һ����Karen��ʤ 
