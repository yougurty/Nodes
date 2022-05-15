/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-15 19:09:44
 * @LastEditTime: 2022-05-15 19:48:36
 * @LastEditors:  
 * @FilePath: P1182.cpp
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000+10;
int n , d;
int arr[maxn];
//如何高效的写check
bool check(int x){
    //对于arr，进行遍历，减
    int num = 1;
    int tmp = x;
    for(int i = 0 ; i < n ; i++){
        tmp -= arr[i];
        if(tmp < 0){
            num++;
            tmp = x - arr[i];
        }
    }
    if(num <= d) return true;
    else return false;
}
int main(){
    int l = 0;
    // int r = 0;
    scanf("%d%d" , &n,&d);
    for (int i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]);
        l = max(arr[i],l);
        // r += arr[i];
    }
    //二分答案
    //越左越好 确定边界
    // int l = 1;      //l取0或者1，第四个测试点过不去。l应该取数组的元素的最大值
    int r = 1e9;
    while(l < r){
        int mid = (l + r)/2;
        if(check(mid)){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    printf("%d" , l);
}