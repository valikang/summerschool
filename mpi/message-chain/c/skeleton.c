#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int msgsize = 100;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = (int *)malloc(sizeof(int) * msgsize);
    receiveBuffer = (int *)malloc(sizeof(int) * msgsize);
    /* Initialize message */
    for (i = 0; i < msgsize; i++) {
        message[i] = myid;
    }

    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* TODO start */
    /* Send and receive messages as defined in exercise */

    

				printf("Just before");
				if (myid == 0){

					printf("My id is 0");
					MPI_Sendrecv(message,msgsize,MPI_INTEGER,myid+1,myid+1,receiveBuffer,msgsize,MPI_INTEGER,ntasks-1,ntasks-1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				}else if  (myid == ntasks -1){
					printf("My id is last");
					MPI_Sendrecv(message,msgsize,MPI_INTEGER,0,0,receiveBuffer,msgsize,MPI_INTEGER,myid-1,myid-1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				}else {
					printf("My id is in the middle");
					MPI_Sendrecv(message,msgsize,MPI_INTEGER,myid+1,myid+1,receiveBuffer,msgsize,MPI_INTEGER,myid-1,myid-1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        }	


				printf("Receiver: %d. first element %d.\n",
               myid, receiveBuffer[0]);
    
    /* TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
