/*
 *	simple tests: initialized (or not) variables and const
 *  to inspect memory section mapping
 */

#include <stdlib.h>
#include <stdio.h>

int a=12;
int b=35;
int const c=10;
int d;

int main()
{
    a=a+c;
    d=a+b;
    
	while(1) ;
	
	return 0;
}
