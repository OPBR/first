#include<stdio.h>
#include<malloc.h>

#define DELTA 100

int *readints(int *number)
{
	int *array;
	int size;
	int *count;
	count = number;
	int value;
	*count = 0;
	size = DELTA;
	array = (int *)malloc((size + 1)*sizeof(int));
	if (array == NULL)
		return NULL;

	while(scanf("%d",&value) == 1){
		*count += 1;
		if (*count > size){
			size += DELTA;
			array = realloc(array,(size + 1)*sizeof(int));
			if (array == NULL)
				return NULL;

		}

		array[(*count)] = value;
	
	}
	if (*count < size){
		array = realloc(array,(*count + 1)*sizeof(int));

		if (array == NULL)
			return NULL;
	
	}

	array[0] = *count;

	return array;

}



int main(void)
{
	int *buf,number,i;
	buf = readints(&number);
	for (i = 0; i < (number + 1); i++){
		printf("%d ",*buf++);
	}
	printf("\n");
	return;
}
