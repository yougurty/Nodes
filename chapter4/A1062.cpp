#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int n , l , h;
struct Student{
	int d;
	int c;
	int zkz;
//	int cls;			//类别
}sts[maxn];
bool cmp(Student s1 , Student s2){
	int sum1 = s1.d + s1.c;
	int sum2 = s2.d + s2.c;
	if(sum1 != sum2) return sum1 > sum2;
	else if(s1.d != s2.d) return s1.d > s2.d;
	else if(s1.zkz != s2.zkz) return s1.zkz < s2.zkz;

}
int main(int argc, char *argv[]) {
	vector<Student> c1,c2,c3,c4;
	
	cin >> n >> l >> h;
	for(int i = 1 ; i <= n ; i++){
		cin >> sts[i].zkz >> sts[i].d >> sts[i].c;
	}
	//先分为四类
	for(int i = 1 ; i <= n ; i++){
		if(sts[i].d <l || sts[i].c < l){
			continue;
		}else if(sts[i].d >=h && sts[i].c >= h){
			c1.push_back(sts[i]);
		}else if(sts[i].d >=h && sts[i].c < h){
			c2.push_back(sts[i]);
		}else if(sts[i].d < h && sts[i].c < h  && sts[i].d >= sts[i].c){
			c3.push_back(sts[i]);
		}else {
			c4.push_back(sts[i]);
		}
	}
	sort(c1.begin(), c1.end() ,cmp);
	sort(c2.begin(), c2.end() ,cmp);
	sort(c3.begin(), c3.end() ,cmp);
	sort(c4.begin(), c4.end() ,cmp);
	int num = c1.size() +c2.size() + c3.size() + c4.size();
	cout << num << endl;
	for(int i = 0 ; i < c1.size() ; i++){
		cout << c1[i].zkz <<" "<< c1[i].d <<" "<< c1[i].c << endl;
//		cout << "c1 end" << endl;
	}
//	cout << "c1 end" << endl;
	for(int i = 0 ; i < c2.size() ; i++){
		cout << c2[i].zkz <<" "<< c2[i].d <<" "<< c2[i].c << endl;
	}
	for(int i = 0 ; i < c3.size() ; i++){
		cout << c3[i].zkz <<" "<< c3[i].d <<" "<< c3[i].c << endl;
	}
	for(int i = 0 ; i < c4.size()-1 ; i++){
		cout << c4[i].zkz <<" "<< c4[i].d <<" "<< c4[i].c << endl;
	}
	cout << c4[c4.size() - 1].zkz <<" "<< c4[c4.size() - 1].d <<" "<< c4[c4.size() - 1].c << endl;
	return 0;
}