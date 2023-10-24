#include <iostream>

using namespace std;

int main(){
	int decimal = 31;	//일반적인 10진수
	int octal = 031;	//수의 앞에 0이 붙을 경우, 8진수를 의미함
	int hex = 0x31;		//수의 앞에 0x가 붙을 경우, 16진수를 의미함
	cout << "decimal: " << decimal << endl;
	//일반 10진수 출력(3 * 10 + 1)
	cout << oct;
	//8진수라 선언했던 것을 다시 10진수로 변환(031 -> 31)
	cout << "octal: " << octal << endl;
	//8진수 출력(3 * 8 + 1 = 24 + 1 = 25)
	cout << std::hex;
	//16진수라고 선언했던 것을 다시 10진수로 변환(0x31 -> 31)
	//hex 함수를 굳이 std::hex라고 한 이유는 이름이 겹치는 변수인 hex가 있기 때문임. 그렇기에 namespace를 써줘서 변수가 아닌 외부 항목을 가져온 것이라 명명하는 것
	cout << "hex: " << hex << endl;
	//16진수 출력(3 * 16 + 1 = 48 + 1 = 49)
	return 0;
}
