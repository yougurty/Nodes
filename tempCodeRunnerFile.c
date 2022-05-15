#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000+10;
int n;
int arr[maxn];
int check(int mid){
    //初始能量为mid
    int e = mid;
    for(int i = 0 ; i < n-1 ; i++){
        if(e < 0) return 0;
        if(arr[i+1] > e){
            e -= arr[i+1] - e;
        }else{
            e += e - arr[i+1];
        }
    }
    return 1;
}
int main(){
    cin >> n;
    int r = 0, l = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    //越左越好，边界
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid -1;
        }
    }
    cout << l << endl;

}