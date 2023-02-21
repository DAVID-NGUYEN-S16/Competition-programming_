#include <stdio.h>
int main()
{
	int a,b,n,s;
	do
	{
		printf("Nhap so nguyen duong co hai chu so: ");
		scanf("%d", &n);
	}while(n<10 || n>100);
		a=n/10;
		b=n%10;
		s=a+b;
	if(n%s==0)
	{
		printf("\nLa so boi k:%d");
    }else
    {
    	printf("\nKhong la so boi k:%d");
	}
		return 0;
}

