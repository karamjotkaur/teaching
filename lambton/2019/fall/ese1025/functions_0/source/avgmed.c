/*
 * avgmed.c
 *
 *  Created on: Oct. 15, 2019
 *      Author: takis
 */

#include <stdio.h>
#include <stdlib.h>

int comp (const void *elem1, const void *elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

double average (int *s, const unsigned int Ns)
{
	double avg;
	int sum = 0;

	unsigned int i;

	for (i=0; i != Ns; ++i)
	{
		sum += s[i];
	}

	avg = (double) (sum/Ns);
	return avg;
}

double median(int *s, const unsigned int Ns)
{
	double med;

	if ((Ns % 2) == 0)
	{
		med = (double) (s[ Ns/2 - 1 ] + s[ Ns/2 ]) / 2;
	}
	else
	{
		med = s[ Ns/2 ];
	}
	return med;
}

int main(void)
{
	int s[] = {5,4,2,8,0,1,3,6,7};
	size_t Ns = sizeof(s)/sizeof(int);

	qsort(s, Ns, sizeof(int), comp);

	printf("\n");
	printf("Your array has %lu bytes, or %lu elements\n",
			sizeof(s), Ns);

	printf("Your sorted set is:\n");
	for (size_t i = 0; i != Ns; ++i)
	{
		printf("%d\n",s[i]);
	}
	printf("\nYour median is %f \n", median(s,Ns));
	printf("Your average is %f \n", average(s,Ns));

	return 0;
}