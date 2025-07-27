#include "philo_bonus.h"
void	 test()
{
	//t_data *da;
	//sem_wait(da->sem);
	int v = 10;
	while(1)
	{
		printf("|[%d]|\n", v);
		if(v == 0)
		{
			printf("LLLL\n");
			break;
		}
		v--;
	}
}
int main()
{
	test();
}