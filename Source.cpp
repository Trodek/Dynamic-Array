#include <iostream>
#include "dynArray.h"
using namespace std;


int main(){

	dynArray<int> test;
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);
	test.PushBack(5);

	test[0] = 2;
	dynArray<int> a(5);
	a = test;
	printf("%d %d %d %d %d", test[0], test[17], a[0], a[3], test[0]);
	getchar();
	return 0;
}