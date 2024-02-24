#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char cwd[1024], *path;

	path = getenv("PWD");

	printf("%s\n", path);
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current working directory: %s\n", cwd);
	}
	else
	{
		perror("getcwd");
	}
	
	return 0;
}

