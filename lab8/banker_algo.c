#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //input the resources and processes
	int m,n,i,j;
	printf("Enter the number of processes");
	scanf("%d",&m);
	printf("Enter the number of resources");
	scanf("%d",&n);

	int *available = (int*)malloc(n*sizeof(int));
	bool *completed= (bool*)malloc(m*sizeof(bool));
	int** max = (int**)malloc(m * sizeof(int*));
	int** allocation = (int**)malloc(m * sizeof(int*));
	int** need = (int**)malloc(m * sizeof(int*));	
    	for (i = 0; i < n; i++){
		max[i] = (int*)malloc(n * sizeof(int));
		allocation[i] = (int*)malloc(n * sizeof(int));
		need[i] = (int*)malloc(n * sizeof(int));		
	}
    
    printf("Enter the available resources:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources each process can claim:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        completed[i] = false;
    }
	bool eligible;	
	bool safe=true;
	int completed_no=0;
	while(safe && completed_no<m){
		printf("Safe");
		safe = false;
		for(i=0;i<m;i++){
            if(!completed[i]){
                eligible=true;
                for(j=0;j<n;j++){
                    if(available[j]<need[i][j]){
                        eligible=false;
                        break;
                    }
                }
                if(eligible){
                    printf("Process %d is executing",i);
                    for(j=0;j<m;j++){
                        available[i]+=allocation[i][j];
                    }
                    completed[i]=true;
                    completed_no++;
                    safe=true;
                }	
            }	
		}
		
	}
	if(safe){

    }
}