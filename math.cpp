#include <iostream>
#include <cmath>

using namespace std;

float sum(float *arr, int num){
	float sum = 0;
	for(int i = 0; i < num; i++) sum += arr[i];
	return sum;
}

float average(float *arr, int num){
	return sum(arr, num) / (float)num;
}

float variance(float *arr, int num){
	float av = average(arr, num);
	float result = 0;
	for(int i = 0; i < num; i++)
		result += pow(arr[i] - av, 2);
	result = result / (float)num;
	return result;
}

float sd(float *arr, int num){
	return sqrt(variance(arr, num));
}
float operation(float *arr, int num){
	float av = average(arr, num);
	float x;
	cout << "모평균 : ";
	cin >> x;
	float s = sd(arr, num);
	return (av - x) / (s / sqrt(num));
}
float v_s(float *arr, int num){
	return variance(arr, num) * num / (num - 1);
}
float sd_s(float *arr, int num){
	return sqrt(v_s(arr, num));
}

void function(int n, float *arr, int num){
	float result;
	if(n == 1) result = average(arr, num);
	else if(n == 2) result = variance(arr, num);
	else if(n == 3) result = sd(arr, num);
	else if(n == 4) result = operation(arr, num);
	else if(n == 5) result = sd_s(arr, num);
	else if(n == 6){
		float x;
		cout <<  "모평균 : ";
		cin >> x;
		cout << "표본평균 : " << average(arr, num) << endl;
		cout << "모분산 : " << variance(arr, num) << endl;
		cout << "모 표준편차 : " << sd(arr, num) << endl;
		cout << "표본 분산 : " << v_s(arr, num) << endl;
		cout << "표본 표준편차 : " << sd_s(arr, num) << endl;
		cout << "연산 결과(z) : " << (average(arr, num) - x) / (sd(arr, num) / sqrt(num)) << endl;
		cout << "연산 결과(t) : " << (average(arr, num) - x) / (sd_s(arr, num) / sqrt(num)) << endl;
		return;
	}
	cout << "result : " << result << endl;
}

int main(){
	int n = -1;
	while(true){
		cout << "1. 평균\t\t2. 분산\t\t3. 표준편차" << endl;
		cout << "4. 확률 분포\t5. 표본표준편차\t6. info" << endl;
		cout << "7. 나가기" << endl;
		cout << "input : ";
		cin >> n;
		if(n == 7){
			cout << "Exit" << endl;
			return 0;
		}
		cout << "개수 : ";
		int num;
		cin >> num;
		float *arr = new float[num];
		for(int i = 0; i < num; i++) cin >> arr[i];
		function(n, arr, num);
	}
	return 0;
}
