#include <iostream>

using namespace std;

char* mystrcat(const char *str1, const char *str2){
	int cnt = 0, len_1 = 0, len_2 = 0;
	for(len_1; str1[len_1] != '\0'; len_1++){}
	for(len_2; str2[len_2] != '\0'; len_2++){}
	char* strsum = new char[len_1 + len_2 + 1];
	for(cnt; cnt < len_1; cnt++) strsum[cnt] = str1[cnt];
	for(cnt; cnt - len_1 < len_2; cnt++) strsum[cnt] = str2[cnt - len_1];
	strsum[cnt] = '\0';
	return strsum;
}

int main(){
	char *str = mystrcat("Hello!", "World!");
	cout << str << endl;
}
