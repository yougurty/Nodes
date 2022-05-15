#include<stdio.h>
#include<math.h>

// using namespace std;
const int maxn = 100010;
int arr[maxn];
int n ,m ,sum = 0;
double fun(double x){
    double a = pow(x,5) - 15 * pow(x,4) + 85 * pow(x,3)- 225 * pow(x,2) + 274 * x -121;
    // printf("%lf",a);
    return a;
}
double binary(double left , double right){
    double mid = (left + right)/2;
    if(left - right < 1e-6) return left;
    if(fun(mid) == 0){
        return mid;
    }else if(fun(mid) > 0){
        return binary(mid+0.000001 , right);
    }else{
        return binary(left , mid-0.000001);
    }
}
int main(){
  
    double re = binary(1.5,2.4);
    printf("%lf\n", re);
    // fun(1.849016);
}