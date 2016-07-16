#include<stdio.h>
#include<stdarg.h>

void itoa(int num,char *buf,int base) 
{
	const char *hex = "0123456789ABCDEF";
	int rest;
	int i = 0;
	int j = 0;
	do{
		rest = num % base;
		
		buf[i++] = *(hex+rest);		//==buf[i++] = hex[rest];
		num /= base;	

	}while(num);
	buf[i] = '\0';

#define SWAP(a,b)	\
	do{	\
		a = a + b;	\
		b = a - b;	\
		a = a - b;	\
	}while(0)

	for (j = 0; j < i / 2; j++){
		SWAP(buf[j],buf[i-1-j]);
	}
}

void myputs(char *buf)
{
	while(*buf)
		putchar(*buf++);
	return;
}

void myprintf(const char * format,...)
{
	va_list ap;
	int value;
	va_start(ap,format);	//auto ap++
	char c;
	char buf[32];
	while((c = *format++) != '\0')
	{
		if (c != '%')
		{
			putchar(c);
			continue;
		}	
		else
		{
			c = *format++;
			if (c == 'd')
			{
				value = va_arg(ap,int);
				itoa(value,buf,10);
				myputs(buf);
			}
			if (c == 'x')
			{
				value = va_arg(ap,int);
				itoa(value,buf,16);
				myputs(buf);
			}
			if (c == 'c')
			{
				putchar(va_arg(ap,int));
			}
			if (c == 's')
			{
				myputs(va_arg(ap,char *));
			}
		}
	
	}
	va_end(ap);
}

int main(void)
{
	myprintf("a = %d,b = %x\n",100,100);

	myprintf("a = %c,b = %s\n",'A',"HelloWorld!");
}
