#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int findClosestTrack(int *track, int n, int head, bool *completed) {
    int minDistance = INT_MAX;
    int closestTrack = -1;
    
    for (int i = 0; i < n; i++) {
        if (!completed[i]) {
            int distance = abs(track[i] - head);
            if (distance < minDistance) {
                minDistance = distance;
                closestTrack = i;
            }
        }
    }
    
    return closestTrack;
}

int sstf(int *track, int n, int head) {
    int overhead = 0;
    bool *completed = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        completed[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        int closestTrack = findClosestTrack(track, n, head, completed);
        overhead += abs(track[closestTrack] - head);
        head = track[closestTrack];
        completed[closestTrack] = true;
    }
    
    free(completed);
    return overhead;
}

int main() {
    int n, head;
    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &n);
    getchar(); 

    int *track = (int*)malloc(n * sizeof(int));
    printf("Enter the current head position: ");
    scanf("%d", &head);
    getchar(); 

    printf("Enter the tracks to be checked:\n");
    for (int i = 0; i < n; i++) {
        printf("Track %d: ", i + 1);
        scanf("%d", &track[i]);
        getchar(); 
    }

    int overhead = sstf(track, n, head);
    printf("\nOverhead: %d\n", overhead);

    free(track);
    return 0;
}
