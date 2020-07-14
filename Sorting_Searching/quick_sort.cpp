#include<iostream>

using namespace std;

int* quick_sort(int* arr, int l, int r);
int partition(int* a, int l, int r);

int main() {
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	int *arr=new int[n];
	cout << "Enter the elements: " << endl;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	arr=quick_sort(arr,0,n-1);
	cout << "\n\nSorted Array: " << endl;
	for(int i=0;i<n;i++) {
		cout << arr[i] << "\t";
	}
}


int* quick_sort(int* arr, int l, int r) {
	if(l<r) {
		int pivot=partition(arr,l,r);
		arr=quick_sort(arr,l,pivot-1);
		arr=quick_sort(arr,pivot+1,r);
	}
	return arr;
}

int partition(int* a, int l, int r) {
	int pivot_element=a[l];
	int i=l,j=r;
	while(i<j) {
		while(i<=r&&a[i]<=pivot_element) {
			i++;
		}
		while(j>0&&a[j]>pivot_element) {
			j--;
		}
		if(i<j) {
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp=a[j];
	a[j]=pivot_element;
	a[l]=temp;
	return j;
}