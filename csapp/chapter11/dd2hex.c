#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char ** argv)
{
	char src[64] = {0};
	uint32_t dest;
	if(argc!=2)
	{
		printf("usage: %s  <dot-decimal-notation>\n", argv[0]);
		return -1;
	}
	sscanf(argv[1],"%s", src);
	if(1!=inet_pton(AF_INET, src, &dest))
	{
		printf("inet_pton error");
	}
	else
	{
		printf("0x%x\n", ntohl(dest));
	}
	return 0;
}
