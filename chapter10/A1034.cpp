#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
//A1034
//map用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回

using namespace std;

const int maxn = 2010;
struct Gang{		//	一个团伙的信息
	string head;
	int numMember;
}arrayGang[maxn];
int numGang = 0;		//团伙的数量


int main(int argc, char *argv[]) {
	
}