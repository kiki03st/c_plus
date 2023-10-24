#include <iostream>
#include <string>

using namespace std;

// 구조체는 배열과는 달리 사용자가 정의한 "자료형"으로 취급됨
typedef struct{
	int id;
	int department;
	string name;
	double score;
} Student;

int main(){
	Student person;
	person.id = 53363;
	person.department = 4232;
	person.name = "Taejune park";
	person.score = 4.5;

	cout << person.id << endl;
	cout << person.department << endl;
	cout << person.name << endl;
	cout << person.score << endl;
	return 0;
}
