#include "philo.h"
pthread_mutex_t g;
void	*fun()
{
	int i = 0;
	///////////
	static int n = 0;
	pthread_mutex_lock(&g);
	printf("***********>[%d]\n", n);
	while(i < 1000000)
	{
		n++;
		i++;
	}
	printf("==>[%d]\n", n);
	pthread_mutex_unlock(&g);
	return NULL;
}
int main()
{
	pthread_t a;
	pthread_t b;
	printf("|%ld|\n", a);
	pthread_mutex_init(&g, NULL);
	pthread_create(&a, NULL, fun, NULL);
	pthread_create(&b, NULL, fun, NULL);
	pthread_join(a, NULL);
	pthread_join(b, NULL);
}