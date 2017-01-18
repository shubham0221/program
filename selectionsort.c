#include <stdio.h>
#include <sys/time.h>

#define MAX_SIZE 16000

void exch(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    int a[MAX_SIZE];
    int i;
    for(i = MAX_SIZE;i > 0; i--)
        a[MAX_SIZE - i] = i;


    struct timeval before;
    struct timeval after;

    gettimeofday(&before,NULL);
    for (int i = 0; i < MAX_SIZE; i++ )
    {
        int min = i;
        int j;
 
	 for(j = i+1; j < MAX_SIZE; j++)
	 {
  		if(a[j] < a[min])
		     min = j;
         }
       
        exch(a, i, min);
    }
    gettimeofday(&after,NULL);
    
    printf("%lu\n",(after.tv_sec*1000000L+after.tv_usec) - (before.tv_sec*1000000L+before.tv_usec));
 
    return 0;
}

