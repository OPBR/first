#include<stdio.h>

int ascii_to_integer(char *string)
{
	int sum = 0;
	if (string == NULL)
		return;
	for (; *string != '\0'; string++){
		while(*string < '0' || *string > '9')
			return;
		sum *= 10;
		sum += *string - '0';
		printf("sum = %d\n",sum);
	}

	return sum;
}



int main(void)
{
	char str[] = "3424";
	int number = 0;

	number = ascii_to_integer(str);
	printf("number = %d\n",number);
	
	return;
}
