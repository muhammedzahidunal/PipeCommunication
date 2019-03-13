#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    srand(time(NULL));
    int random = rand() % 6 +1 ; //random sayı üretme
    write(4, &random, sizeof(int)); // pipe'a yazma
	

    return 0;
}
