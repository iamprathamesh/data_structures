// C code to illustrate Internal Linkage
#include <stdio.h>
 
int main(){
	int* p,n;
	int a = 10;
	p = &a;
	printf("%d\n", *p);	
	return 0;
}
