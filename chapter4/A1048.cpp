/*
 * @Description: 
 * @Author: Xu Jiaming
 * @Date: 2022-05-07 19:20:10
 * @LastEditTime: 2022-05-07 19:48:03
 * @LastEditors:  
 * @FilePath: A1048.cpp
 */
#include<iostream>
#include<algorithm>
using namespace std;

int n , m;
int hashTable[1010] = {0};
bool cmp(int a, int b){
    return a < b;
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        if(a < 1010) hashTable[a]++;
    }
    for(int i = 0 ; i < 1010 ; i++){
        if(hashTable[i] !=0 ){
            hashTable[i]--;
            if(hashTable[m-i] !=0  && m-i >= i){
                cout << i << " " << m-i<< endl;
                break;
            }
            hashTable[i]++;
        }
        if(i == 1009 ){
            cout << "No Solution" << endl;
        }
    }

}