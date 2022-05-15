#include <iostream>
#include <cstring>
using namespace std;
bool hashTable[1010] = {false};

int main(int argc, char *argv[]) {
	string str1,str2;
	cin >> str2 >> str1;
	//_为0，a-z为1-26，A-Z为27-52，0-9 为53-62,
	for(int i = 0 ; i < str2.length() ; i++){
		if(str2[i] == '+') {
			for(int j = 65 ; j <= 90 ; j++){
				hashTable[j] = true;
			}
		}else if(str2[i] >= 'A' && str2[i] <= 'Z'){
			int a = int(str2[i]);
			hashTable[a] = true;
			hashTable[a+32] = true;
		}else {
			int a = int(str2[i]);
			hashTable[a] = true;
		}
	}
	for(int i = 0 ; i < str1.length() ; i++){
		int a = int(str1[i]);
		if(hashTable[a] == true) continue;
		else cout << str1[i];
	}
	cout << endl;
	return 0;
}