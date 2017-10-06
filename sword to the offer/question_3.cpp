//替换字符串中的空格为"%20"

#include <stdio.h>
#define MAX 128

void ReplaceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
		return;

	int old_length = 0;
	int blank_num = 0;
	while (*(string + old_length) != '\0')
	{
		if (*(string + old_length) == ' ')
			++blank_num;

		++old_length;
	}
	int new_length = old_length + blank_num * 2;
	if (new_length - 1 > length)
		return;
	while (old_length >= 0)
	{
		if (*(string + old_length) == ' ')
		{
			*(string + new_length) = '0';
			--new_length;
			*(string + new_length) = '2';
			--new_length;
			*(string + new_length) = '%';
			--new_length;
		}
		else
		{
			*(string + new_length) = *(string + old_length);
			--new_length;
		}
		--old_length;
	}
}

int main()
{
	char str1[MAX] = "I am a dog.";
	printf("%s\n", str1);
	ReplaceBlank(str1,MAX);
	printf("%s\n", str1);

	char str2[MAX] = "HelloWorld";
	printf("%s\n", str2);
	ReplaceBlank(str2, MAX);
	printf("%s\n", str2);

	char str3[MAX] = "  ";
	printf("%s\n", str3);
	ReplaceBlank(str3, MAX);
	printf("%d\n", sizeof(str3)/sizeof(char));
	printf("%s\n", str3);

	char str4[MAX] = "";
	printf("%s\n", str4);
	ReplaceBlank(str4, MAX);
	printf("%s\n", str4);

	return 0;
}