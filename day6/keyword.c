#include<stdio.h>

//int lookup_keyword(char const * const desired_word,
//		char const *keyword_table[],int const size)
int lookup_keyword(char const * const desired_word,
		char const *keyword_table[])
{
	char const **kwp;

//	for (kwp = keyword_table;kwp < keyword_table + size;kwp++)
	for (kwp = keyword_table; *kwp != NULL; kwp++)
		if (strcmp(desired_word, *kwp) == 0)
			return kwp - keyword_table;
	return -1;

}


int main(void)
{
	int local;
	char const *keyword[] = {
		"do",
		"for",
		"if",
		"register",
		"return",
		"switch",
		"while",
		NULL
	};
	char *str = "return";
//	local = lookup_keyword(str, keyword,7);
	local = lookup_keyword(str, keyword);
	printf("local = %d\n",local + 1);


	return;
}
