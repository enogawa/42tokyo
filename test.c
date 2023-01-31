# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

int ft_put_str(void)
{
	printf("eiki");
	return (0);
}

int main(void)
{
	int i = 0;

	if (i == 1 || !ft_put_str())
	{
		printf("nogawa");
	}
	return (0);
}