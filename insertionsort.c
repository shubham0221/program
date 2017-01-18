#include <stdio.h>
#include <sys/time.h>

#define MAX_SIZE 32000

void exch(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


int main()
{
    int a[MAX_SIZE];
    int i, j;
   
    for(int i = MAX_SIZE; i >= 1; i--)
        a[MAX_SIZE - i] = i;

    struct timeval before;
    struct timeval after;
    
    gettimeofday( &before, NULL);
    for(int i = 0; i < MAX_SIZE; i++)
    {
       int j = i;
         while(j > 0 && a[j-1] > a[j])
         {
             exch(a, j, j-1);
             j--;
         }
    }
   
    gettimeofday( &after, NULL);
     
   printf("%lu\n",(after.tv_sec * 1000000L + after.tv_usec) - (before.tv_sec * 1000000L + before.tv_usec));

   /* for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", a[i]);
    */
}

