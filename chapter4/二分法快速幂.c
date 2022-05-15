/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-10 19:10:21
 * @LastEditTime: 2022-05-10 20:15:07
 * @LastEditors:  
 * @FilePath: 二分法快速幂.c
 */
#include<stdio.h>
typedef long long ll;
int qpow(int a , int b , int m){
    if( b == 0 ) return 1;
    else if(b % 2 == 1){
        return (qpow(a,b-2,m) * a) % m;
    }else{
        ll re = qpow(a , b/2 , m);
        return (re*re) % m;
    }
}

//二分法求快速幂,a^b % m
int main(){


    return 0;
}