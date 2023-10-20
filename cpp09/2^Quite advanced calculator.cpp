#include <iostream>

using namespace std;

int main(){
	cout << "--------------" << endl;
	cout << "+:addition" << endl;
	cout << "*:multiplication" << endl;
	cout << "--------------" << endl << endl;
	cout << "Select an operator: ";
	char p;
	cin >> p;
	if(!(p == '+' || p == '*')){
		return 0;
	}
	int matrix1[3][3];
	int matrix2[3][3];
	cout << "input matrix1: ";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> matrix1[i][j];
		}
	}
	cout << "input matrix2: ";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> matrix2[i][j];
		}
	}
	if(p == '+'){
		cout << "Answer: " << endl;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cout << matrix1[i][j] + matrix2[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		int sum;
		cout << "Answer: " << endl;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				sum = 0;
				for(int k = 0; k < 3; k++){
					sum += matrix1[i][k] * matrix2[k][j];
				}
				cout << sum << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
