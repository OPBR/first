#include<stdio.h>

void reverse_string(char *string)
{
	if (string == NULL)
	{
		return;
	}
	
	char *p;
	for (p = string; *p != '\0'; p++)
		;
	p--;

	while(string < p)
	{
		char temp;

		temp = *string;
		*string++ = *p;
		*p-- = temp;

	}

}

int main(void)
{
	char str[] = "helloworld!!!";		//Be careful *str
	
	reverse_string(str);
	printf("%s\n",str);

	return;
}
