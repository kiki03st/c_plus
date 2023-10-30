#include <iostream>

using namespace std;

void merge(int arr[], int arr_result[], int left, int mid, int right){
	int cnt_l = left, cnt_r = mid + 1;
	int cnt = left;
	while(cnt_l <= mid && cnt_r <= right){
		if(arr[cnt_l] < arr[cnt_r]){
			arr_result[cnt++] = arr[cnt_l++];
		}
		else{
			arr_result[cnt++] = arr[cnt_r++];
		}
	}
	int etc = cnt_l > mid ? cnt_r : cnt_l;
	while(etc <= right) arr_result[cnt++] = arr[etc++];
	for(int i = left; i <= right; i++) arr[i] = arr_result[i];
}
void mergesort(int arr[], int arr_result[], int left, int right){
	if(right <= left) return;
	int mid = (left + right) / 2;
	mergesort(arr, arr_result, left, mid);
	mergesort(arr, arr_result, mid + 1, right);
	merge(arr, arr_result, left, mid, right);
}

int main(){
	int arr[10] = {8, 6, 4, 3, 1, 5, 2, 7};
	int arr_result[8];
	cout << "origin : ";
	for(int i = 0; i < 8; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	mergesort(arr, arr_result, 0, 7);
	cout << "mergesort : ";
	for(int i = 0; i < 8; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
