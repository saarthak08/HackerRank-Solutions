#include<iostream>

using namespace std;

/*
Time Complexity: O(n^2) - Worst Case. O(nLogn) - Best Case.
Approach: Pivot is selected from the array.
A pivot is an element which is already sorted according to array.
Then array is divided into halves. One is before pivot and one is after pivot.
Same thing is done recursively.

Approach: Partition Function: 
Pivotal element is choosen as first element.
And then, going from left side to right side & right side to left side simultaneously till the middle element,
check that if any element going from left to right is greater than pivotal element, then swap it with any element which is smaller than pivotal element going from right to left.
After this has completed, replace the index of right to left pointer with pivotal element and then, return the index of right to left pointer. This is the pivot position.


Quick Sort worst case complexity can be improved by:
1) Choosing Randomised pivotal element in partition function instead of first element as if the array is already sorted or reverse sorted, the partition always come at first or last. Thus making complexity O(n^2).
2) Choosing a partition which will always be in the middle i.e. median. For median, we can take approximate median by calculating median of 3 medians.


Still, Quick Sort's worst cannot be completely reduced to O(nLogn) yet it is considered to be the best sorting algorithm.
*/


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