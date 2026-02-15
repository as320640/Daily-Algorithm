#include <stdio.h>
//分区函数
int Paration(int a[],int left,int right){
	int pivot=a[left];
	while(right>left){
		while(right>left&&a[right]>=pivot)
			right--;
		a[left]=a[right];
		while(right>left&&a[left]<=pivot)
			left++;
		a[right]=a[left];
	}
	a[left]=pivot;
	return left;
} 
//递归实现快速排序
void quicksort(int a[],int left,int right){
	if(left>=right)
		return; 
	int pipots=Paration(a,left,right);
	quicksort(a,left,pipots-1);
	quicksort(a,pipots+1,right);
}

void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
//双指针快速排序
void quicksort_plus(int a[],int left,int right){
	if(left>=right)
		return;
	int r=right,l=left,mid=(right+left)/2;
	while(r>=l){
		while(a[l]<a[mid])
			l++;
		while(a[r]>a[mid])
			r--;
		if(r>=l){
			swap(a,l,r);
			l++;
			r--;
		}
	}
	quicksort_plus(a,left,r);
	quicksort_plus(a,l,right);
} 
//快速选择函数，寻找第k小的数
int findK(int a[],int left,int right,int k){
	if(left>right)
		return -1;
	int pivotpop=Paration(a,left,right);
	if(pivotpop==k-1)
		return a[pivotpop];
	else if(pivotpop>k-1)
		return findK(a,left,pivotpop-1,k);
	else
		return findK(a,pivotpop+1,right,k);
} 
/*
qsort以及cmp函数
int compar(const void* p1,const void* p2) {
	return *(int*)p1-*(int*)p2;
}
qsort(a,10,sizeof(int),compar); 
*/

int compar(const void* p1,const void* p2) {
	return *(int*)p1-*(int*)p2;
}

//测试样例
int main(){
	int a[]={21,2498,20,79,23,8,7985,46,546,565},i=0;
	for(i=0;i<=9;i++){
		printf("%5d",a[i]);
	}
	printf("\n"); 
	//quicksort(a,0,9);
	//quicksort_plus(a,0,9);
	qsort(a,10,sizeof(int),compar);
	for(i=0;i<=9;i++){
		printf("%5d",a[i]);
	}
	printf("\n");
	printf("%d",findK(a,0,9,10));
	return 0;
}



