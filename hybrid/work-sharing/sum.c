#include <stdio.h>

#define NX 102400

int main(void)
{
    double vecA[NX], vecB[NX], vecC[NX];
    double sum;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = 1.0 / ((double)(NX - i));
        vecB[i] = vecA[i] * vecA[i];
    }

    /* TODO:
     *   Implement here a parallelized version of vector addition,
     *   vecC = vecA + vecB
     */
		
    /* TODO: Initialize MPI with thread support. */
    /* TODO: Find out the MPI rank and thread ID of each thread and print
     *       out the results. */

    #pragma omp parallel
    {

    		#pragma omp for default(shared) private(i)
				for(i=0;i<NX;i++){
					vecC[i] = vecA[i] + vecB[i];

					}
    		//printf("I'm thread %d in process %d\n",omp_rank, my_id);



    }
    sum = 0.0;
    /* Compute the check value */
    for (i = 0; i < NX; i++) {
        sum += vecC[i];
    }
    printf("Reduction sum: %18.16f\n", sum);

    return 0;
}
