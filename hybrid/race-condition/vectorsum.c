#include <stdio.h>

#define NX 102400

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact):                  %ld\n",
           sumex);

    sum = 0.0;
    /* TODO: Parallelize computation */
		/*
		#pragma omp parallel  for shared(vecA) private(i) reduction(+:sum)

		*/
		#pragma omp parallel for shared(vecA,sum) private(i)	
    for (i = 0; i < NX; i++) {
				#pragma omp critical(moro)
        sum += vecA[i];
				
    }
		
			

		
    printf("Sum: %ld\n", sum);

    return 0;
}
