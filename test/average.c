#include<stdio.h>
#include<stdarg.h>

float average(int n_values,...)
{
	va_list var_arg;
	int count = 0;
	float sum = 0;
	va_start(var_arg,n_values);
	
	for (count = 0;count < n_values;count++){
		sum += va_arg(var_arg,int);
	
	}

	va_end(var_arg);

	return sum / n_values;


}


int main(void)
{
	int num = 5,ret = 0;

	ret = average(num,1,2,3,4,5);
	printf("ret = %d\n",ret);	

	return;
}
