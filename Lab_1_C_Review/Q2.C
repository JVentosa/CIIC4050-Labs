//#include "ex2.h"

//n, amount of series to compute
void tribonacci(int n){
	//initialize array (int* seq) to 1, using malloc/calloc
    int* seq; 
    seq = (int*)malloc(1*sizeof(int));

	int i;
	for(i = 0; i <= n; i++){ //FIX iteration parameters

    	// Recompute the whole series
    	tribonacciHelper(i, seq);

	    //print array
    	int j;
    	for(j = 0; j <= i; j++){ //FIX iteration parameters
            // Complete code to print array
            printf("%d ",seq[j]);
        }
        printf("\n");

		//resize array, with realloc
        seq = (int*)realloc(seq,(i+2)*sizeof(int));

	}
	//free array
    free(seq);
}

//n=amount of numbers in the series to compute, seq=array to store series
void tribonacciHelper(int n, int *seq){
    //TODO
    if (n == 0 ){
        seq[0] = 0;
    }

    else if (n==1){
        seq[0] = 0;
        seq[1] = 1;

    }
    else if (n==2){
        seq[0] = 0;
        seq[1] = 1;
        seq[2] = 1;
    } 
    else{
    seq[n] = seq[n-1] + seq[n-2] + seq[n-3];
    }
}