#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	uint32_t src;
	char buffer[128]={0};
	if(argc != 2)
		{printf("usage: %s  <16 system address>\n", argv[0]);return -1;}
	sscanf(argv[1], "%x", &src);
	src = htonl(src);
	//printf("0x%x\n", src);
	if(!inet_ntop(AF_INET, &src, buffer, sizeof(buffer)/sizeof(char)))
	{
		printf("error:inet_ntop");
	}
	else
		printf("%s\n", buffer);

	return 0;
}
