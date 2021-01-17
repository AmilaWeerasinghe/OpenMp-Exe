#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int main ()
{
int i; 
double x, pi, sum = 0.0;
step = 1.0/(double) num_steps ;

double start= omp_get_wtime();
int num_of_threads=0;

#pragma omp parallel
{    double sumt=0;
    printf("thread id: %d\n",omp_get_thread_num());
    int thread_id=omp_get_team_num();
    num_of_threads= omp_get_num_threads();
for (i=((num_steps/num_of_threads)*(thread_id));i< ((num_steps/num_of_threads)* (thread_id +1)); i++){

x = (i+0.5)*step;
sumt = sumt + 4.0/(1.0+x*x);

}
printf("sum of thread id %d is %fl\n",thread_id,sumt);
sum=sum+sumt;

}
pi = step * sum;

double stop= omp_get_wtime();
printf("time for execution: %fl\n",(stop-start));
printf("result: %fl\n",pi);
printf("number of threads: %d\n",num_of_threads);
}
