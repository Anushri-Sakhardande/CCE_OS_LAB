#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fcfs(int *track,int n){
	int overhead=0;
	for(int i=1;i<n+1;i++){
		printf("%d\t",track[i]);
		overhead+=abs(track[i]-track[i-1]);
	}
	return overhead;
}

int main()
{
	int n, head;
    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &n);
    getchar(); 

    int *track = (int*)malloc((n + 1) * sizeof(int));
    printf("Enter the current head position: ");
    scanf("%d", &head);
    getchar(); 
    track[0]=head;
    printf("Enter the tracks to be checked:\n");
    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &track[i]);
    }

	
	int overhead=fcfs(track,n);
	printf("\nOverhead:%d\n",overhead);
}

//82 170 43 140 24 16 190