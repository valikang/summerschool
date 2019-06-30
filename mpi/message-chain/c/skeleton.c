#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{	
		printf("beginning");

    int i, myid, ntasks;
    int msgsize = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;
		printf("Just before MPI");
		
		int source, destination;
		int count;
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
		printf("Just before Barrier");
		/* Set source and destination ranks */
    if (myid < ntasks - 1) {
        destination = myid + 1;
    } else {
        destination = MPI_PROC_NULL;
    }
    if (myid > 0) {
        source = myid - 1;
    } else {
        source = MPI_PROC_NULL;
    }


    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* TODO start */
    /* Send and receive messages as defined in exercise */
		 /* Send and receive messages */
/*
    MPI_Sendrecv(message, msgsize, MPI_INT, destination, myid + 1,
                 receiveBuffer, msgsize, MPI_INT, source, MPI_ANY_TAG,
                 MPI_COMM_WORLD, &status);
    /* Use status parameter to find out the no. of elements received */
   /* MPI_Get_count(&status, MPI_INT, &count);
    printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
           myid, msgsize, myid + 1, destination);
    printf("Receiver: %d. Received elements: %d. Tag %d. Sender: %d.\n",
           myid, count, status.MPI_TAG, status.MPI_SOURCE);
*/

    
		
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
