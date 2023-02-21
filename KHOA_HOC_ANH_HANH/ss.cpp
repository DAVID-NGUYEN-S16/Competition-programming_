#include<stdio.h>
void sss(int a[], int n){
    printf("%d", a[1]);
}
int main(){
    int a[1000];
    a[1] = 2;
    sss(a, 5);

}