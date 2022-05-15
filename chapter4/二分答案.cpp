/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-10 19:53:03
 * @LastEditTime: 2022-05-10 20:40:17
 * @LastEditors:  
 * @FilePath: ���ִ�.cpp
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000+10;
int n , k;
int arr[maxn];
// ��ľ�γ���Ϊmid
bool check(int mid){
    int num = 0;
    for(int i = 0 ; i < n ; i++){
        num += arr[i] / mid;
    }
    if(num >= k) return true;
    else return false;
}
//���ִ� Խ��Խ��
int binary(int l ,int r){
    // int mid = (l + r + 1)/2;
    while( l < r){
        int mid = (l + r + 1)/2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    // cout <<  l << endl;
    return r;
}
int main(){
    
    cin >> n >> k;
    int minn = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        minn = max(arr[i] , minn);
    }
    // cout << endl;
    int re = binary(0,minn);
    cout << re;
}