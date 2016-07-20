#include<stdio.h>

void binary_to_ascii( unsigned int value )
{
	unsigned int tmp;
	tmp = value;
	tmp /= 16;

	if ( tmp != 0 ){
	
		binary_to_ascii(tmp);

	}

	value %= 16;
	printf("%c","0123456789ABCDEF"[value]);

}



int main(void)
{
	printf("%x\n",20138);		//only test

	binary_to_ascii(20138);
	printf("\n");
	return 0;
}
