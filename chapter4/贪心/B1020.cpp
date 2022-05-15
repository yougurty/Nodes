/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-15 17:22:46
 * @LastEditTime: 2022-05-15 18:03:14
 * @LastEditors:  
 * @FilePath: B1020.cpp
 */
#include<iostream>
#include<algorithm>
using namespace std;
int n ;
double d;
struct YB
{
    /* data */
    double num;
    double zj;
    double dj;
}yb[1010];
bool cmp(YB yb1, YB yb2){
    return yb1.dj > yb2.dj;
    
}

int main(){
    cin >> n >> d;
    for( int i = 0 ; i < n ; i++){
        cin >> yb[i].num;
    }
    for( int i = 0 ; i < n ; i++){
        cin >> yb[i].zj;
        yb[i].dj =yb[i].zj/yb[i].num;
        // printf("%.2xlf ", yb[i].dj);
    }
    sort(yb , yb + n ,cmp);
    // cout << yb[0].zj << " " <<  yb[1].zj << endl;
    double sy = 0;
    int  i = 0;
    while(d > 0 ){
        if(d > yb[i].num ){
            sy += yb[i].zj;
            d -= yb[i].num;
            // printf("%.2lf\n" , sy);
            // printf("%d\n",d);
        }else {
            // printf("enter this\n");
            double tmp = (d*yb[i].zj)/double(yb[i].num);
            sy += tmp;
            // printf("%.2lf " , tmp);
            d = 0;
        }
        i++;
    }
    printf("%.2lf" , sy);
}

