#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
	bool debug_mode = false;

	if(argc<=1)
	{
		printf("Brak podanych argumentow. Podaj jedna z dwoch flag: \"\"-f\"\" lub \"\"-d\"\"\n");
		return -1;
	}

	if(strcmp("-d", argv[1])==0) debug_mode = true;

	if(debug_mode==true) printf("DEBUG: %s\n", argv[1]);
	else printf("%s\n", argv[1]);

	return 0;
}
