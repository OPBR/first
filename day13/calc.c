#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quit();
int subtract();
int add();

struct calc_func{
	int (*computer)();
	char key;
	char *name;
};
struct calc_func functions[] = {
	{
		.computer = subtract,
		.key = '-',
		.name = "subtract"
	},
	{
		.computer = add,
		.key = '+',
		.name = "add"
	},
	{
		.computer = quit,
		.key = 'q',
		.name = "quit"
	}

};

int quit()
{
	printf("Good bye\n");
	exit(EXIT_SUCCESS);

}

int add()
{
	char cmd[20];
	int ret = 0;

	printf("Enter numbers to Add\n");
	
	while(fgets(cmd,20,stdin) && cmd[0] != '\n'){
		ret += atoi(cmd);
	}

	printf("Result is %d\n",ret);

}

int subtract()
{
	char cmd[20];
	int ret = 0,num = 0;

	printf("Enter numbers to Subtract\n");

	while(fgets(cmd,20,stdin) && cmd[0] != '\n'){
		if (num == 0){
			ret = atoi(cmd);
		}
		else{
			ret -= atoi(cmd);
		}
		num++;
	}

	printf("Result is %d\n",ret);
	
}

#define NB_FUNCS (sizeof(functions)/sizeof(struct calc_func))

void print_all_functions()
{
	int i = 0;

	for (i = 0; i < NB_FUNCS; i++){
		printf("Press key %c for %s\n",
				functions[i].key,functions[i].name);

	}

}	


int main(void)
{
	int i = 0;
	char cmd[20];
	printf("This is a calc\n");
	print_all_functions();

	while(1){
		printf("Enter a command\n");

		fgets(cmd,20,stdin);
		for (i = 0; i < NB_FUNCS; i++){

			if (functions[i].key == cmd[0]){
				printf("Calling command :%s\n",functions[i].name);
				functions[i].computer();

				break;
			}
		}
	
	}

	return 0;
}
