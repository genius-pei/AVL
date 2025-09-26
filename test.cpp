#define _CRT_SECURE_NO_WARNINGS
#include"AVLtree.h"
int main()
{
	AVLtree<int, int> t;
	t.Insert({ 1,2 });
	t.Insert({ 2,3 });  
	return 0;
}