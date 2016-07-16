#include<stdio.h>


int even_parity(int value, int n_bits)
{
	int parity = 0;


	while(n_bits > 0){
		parity += value & 1;
		value >>= 1;
		n_bits -= 1;
	
	}

	return (parity % 2) == 0;

}


int main(void)
{
	int num = 10;
	int count = 4;
	int ret = 0;
	ret = even_parity(num, count);
	if (ret){
		printf("There are an even number of 1\n");
	}
	else
		printf("There are an odd number of 1\n");
		
	return;
}
