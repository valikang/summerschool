#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int my_id, omp_rank;
    int provided, required = MPI_THREAD_FUNNELED;


		
	   /* This macro can be used to check the return code of
   MPI function calls */
#ifndef NDEBUG
#define MPI_CHECK(errcode)                                              \
    if(errcode != MPI_SUCCESS) {                                        \
        fprintf(stderr, "MPI error in %s at line %i\n",                 \
                __FILE__, __LINE__);                                    \
        MPI_Abort(MPI_COMM_WORLD, errcode);                             \
        MPI_Finalize();                                                 \
        exit(errcode);                                                  \
    }
#endif



    /* TODO: Initialize MPI with thread support. */
		MPI_Init_thread(&argc,&argv, required, &provided);
		MPI_Comm_rank(MPI_COMM_WORLD, &my_id);	
    /* TODO: Find out the MPI rank and thread ID of each thread and print
     *       out the results. */
		
		#pragma omp parallel private(omp_rank)
		{

		omp_rank = omp_get_thread_num();
		printf("I'm thread %d in process %d\n",omp_rank, my_id);
		
		

		}
    /* TODO: Investigate the provided thread support level. */

    MPI_Finalize();
    return 0;
}
