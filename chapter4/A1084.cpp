#include <iostream>

using namespace std;
bool hashTabel[100010] = {false};
int n = 50;
int m = 30;
bool output[100010] = {false};

int main(int argc, char *argv[]) {
	string yuan;
	string xin;
	cin >> yuan >> xin;
//	cout <<  yuan <<" "<< xin << endl;
	//_为0，a-z为1-26，A-Z为27-52，0-9 为53-62
	for(int i = 0 ; i < xin.size() ; i++){
		char tmp = xin[i];
		if(tmp == '_') hashTabel[0]=true;
		else if(tmp >= 'a' && tmp <= 'z') hashTabel[tmp-'a'+1] = true;
		else if(tmp >= 'A' && tmp <= 'Z') hashTabel[tmp-'A'+ 27] = true;
		else if(tmp >= '0' && tmp <= '9') hashTabel[tmp-'0'+53] = true;
	}
	for(int i = 0 ; i < yuan.size() ; i++){
		char tmp = yuan[i];
		if(tmp == '_' && hashTabel[0] == false &&output[0] == false){
			cout <<"_";
			output[0] = true;
		} 
		else if(tmp >= 'a' && tmp <= 'z' &&hashTabel[tmp-'a'+1] == false && output[tmp-'a'+1] == false){
			cout << char(tmp-'a'+'A');
			output[tmp-'a'+1] = true;
			output[tmp-'a'+27] = true;
		} 
		else if(tmp >= 'A' && tmp <= 'Z' &&hashTabel[tmp-'A'+ 27] == false && output[tmp-'A'+ 27] == false)
		{
			cout << tmp;
			output[tmp-'A'+ 27]= true;
			output[tmp-'A'+ 1]= true;
		}else if(tmp >= '0' && tmp <= '9' &&hashTabel[tmp-'0'+53] == false &&output[tmp-'0'+53] == false ){
			cout << tmp;
			output[tmp-'0'+53]= true;
		}
		
	}
	cout << endl;
//	cout << char('i'-'a'+'A');
}