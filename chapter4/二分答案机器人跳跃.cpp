/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-10 21:05:43
 * @LastEditTime: 2022-05-10 21:53:32
 * @LastEditors:  
 * @FilePath: ���ִ𰸻�������Ծ.cpp
 */
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000+10;
int n;
int arr[maxn];
bool check(int e)
{
    for(int i = 0;i < n;i++ ){
        e = 2 * e - arr[i+1];
        // cout << "first,the "<< i << ",e=" << e << endl;
        if(e<0) return false;
       	if(e > 1e5) return true; // �������ֵ�ͷ����棬��������õĻ��������ױ�int��long long
    }
    return true;
}
int check3(int mid){
    //��ʼ����Ϊmid
    int e = mid;
    for(int i = 0 ; i < n ; i++){
        if(arr[i+1] > e){
            e -= arr[i+1] - e;
        }else{
            e += e - arr[i+1];
        }
        if(e < 0) return 0;
        if(e < 1e5) return 1;
        // cout << "second,the "<< i << ",e=" << e << endl;
    }
    if(e < 0) return 0;
    else return 1;
}
int main(){
    cin >> n;
    int r = 0, l = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    // // Խ��Խ�ã��߽�
    while(l < r){
        int mid = (l+r)/2;
        // cout <<"mid="<< mid << endl;
        if(check(mid)){
            // cout << "r = " << r << endl;
            r = mid;
        }else{
            // cout << "l = " << l << endl;
            l = mid + 1;
        }
    }
    cout << r << endl;
    // cout << check(23) << endl;
    // cout << check2(23) << endl;
}