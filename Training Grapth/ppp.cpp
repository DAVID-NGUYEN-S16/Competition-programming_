#include<stdio.h>
int main(){
	int n,tong=0;

	printf("\nnhap n ");
	scanf("%d",&n);
	/*
	n = 1234
	sum = 0
	--
	sum += 1234 %10
	n /= 10 --> n == 123
	--
	sum += 123 % 10
	n /= 10 --> n== 12
	--
	sum += 12 % 10
	n/=10 -- > n == 1
	--
	sum += 1 % 10;
	n/=10 --> n
	*/
	while(n/10!=0){

        tong=tong+n%10;
        n=n/10;
	}
	printf("\ntong cac chu so bang %d ",tong+n%10);
	return 0;
}
