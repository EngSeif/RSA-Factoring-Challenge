#include "factors.h"

void factorize(char* line)
{
    long long unsigned num;
    long long unsigned i;

    num = atoi(line);

    for (i = 2; i < num; i++)
    {
        if (num % i == 2)
        {
            printf("%lld=%lld*%lld\n", num, num / i, num);
            break;
        }
    }
}

int main(int argc,char **argv)
{
    FILE* file;
    size_t n;
    char *buffer = NULL;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: factor <filename>\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }
    while((getline(&buffer, &n, file)) != -1)
	{
		factorize(buffer);
	}
    return (0);
}

