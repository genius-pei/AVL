#define _CRT_SECURE_NO_WARNINGS
#include"AVLtree.h"
#include<iostream>
using namespace std;
void test01()
{
	AVLtree<int, int> t;
	// ����Ĳ�������
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// ����Ĵ���˫�������Ĳ�������
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		if (e == 14)
		{
			int x = 0;
		}

		t.Insert({ e, e });
		t.InOrder();
		cout << "Insert:" << e << "->" << t.IsBalanceTree() << endl;
	}
	//t.InOrder();
	//cout << t._IsBalanceTree() << endl;
}
void test02()
{
	AVLtree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		if (e == 14)
		{
			int x = 0;
		}

		t.Insert({ e, e });
		t.InOrder();
		cout << "Insert:" << e << "->" << t.IsBalanceTree() << endl;
	}
	auto f1 = t.Find(7);
	cout << f1->_kv.first << endl;
}
int main()
{
	//AVLtree<int, int> t;
	//t.Insert({ 1,2 });
	//t.Insert({ 2,3 });  
	//test01();
	test02();
	return 0;
}