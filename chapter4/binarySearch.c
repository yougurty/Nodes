/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-09 18:28:52
 * @LastEditTime: 2022-05-09 19:25:15
 * @LastEditors:  
 * @FilePath: binarySearch.c
 */
#include<stdio.h>
//A[]严格递增，left，right. 递归
int binarySearch(int A[] , int left , int right , int aim){
    int mid = (right + left)/2;
    if(right <= left) return -1;
    if(A[mid] == aim) return mid;
    else if(A[mid] < aim){
        return binarySearch(A , mid+1 , right , aim);
    }else{
        return binarySearch(A , left , mid-1 , aim);
    }
    
}
//不递归版本
int binarySearch(int A[] , int left , int right , int aim){
    while(left <= right){
        int mid = (right + left)/2;
        if(A[mid] == aim) return mid;
        else if(A[mid] > aim) right = mid - 1;
        else left = mid +1;
    }
    return -1;
    
}
//找第一个大于x的元素
int upper_bound(int A[], int x , int left , int right){
    // int mid = (left + right)/2;
    while(left < right){
        int mid = (left + right)/2;
        if(A[mid] > x){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}
//找第一个大于等于x的元素
int lower_bound(int A[] , int x ,int left , int right){
    while(left < right){
        int mid = (left+right)/2;
        if(A[mid] >= x){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int re = binarySearch(A,0,9,9);
    printf("%d\n" , re);
}