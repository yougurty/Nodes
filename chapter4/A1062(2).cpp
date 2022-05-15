#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int n , l , h;
struct Student{
	int d;
	int c;
	long zkz;
	int cls;			//Àà±ğ
}sts[maxn];

bool cmp(Student s1 , Student s2){
	if( s1.cls != s2.cls)  return s1.cls < s2.cls;
	else if(s1.d + s1.c != s2.d +s2.c) return s1.d + s1.c > s2.d +s2.c;
	else if(s1.d != s2.d) return s1.d  > s2.d ;
	else return s1.zkz < s2.zkz;
}
int main(int argc, char *argv[]) {
	cin >> n >> l >> h;
	for(int i =0 ; i < n ; i++){
		cin >> sts[i].zkz >> sts[i].d >> sts[i].c;
	}
	int num = 0;
	for(int i = 0 ; i < n ; i++){
		if(sts[i].d <l || sts[i].c < l){
			sts[i].cls = 5;
		}else if(sts[i].d >=h && sts[i].c >= h){
			sts[i].cls = 1;
			num++;
		}else if(sts[i].d >=h && sts[i].c < h){
			sts[i].cls = 2;
			num++;
		}else if(sts[i].d < h && sts[i].c < h  && sts[i].d >= sts[i].c){
			sts[i].cls = 3;
			num++;
		}else {
			sts[i].cls = 4;
			num++;
		}
	}
	sort(sts , sts +n ,cmp);
	cout << num << endl;
	for(int i = 0 ; i < num ; i++ ){
		cout << sts[i].zkz <<" "<< sts[i].d <<" "<< sts[i].c << endl;
	}
}