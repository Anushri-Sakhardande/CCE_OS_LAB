#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int look(int *track, int n, int head, bool direction) {
    int overhead = 0;
    int currentIndex = -1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (track[j] > track[j + 1]) {
                int temp = track[j];
                track[j] = track[j + 1];
                track[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (track[i] == head) {
            currentIndex = i;
            break;
        }
    }

    if (currentIndex == -1) {
        track[n] = head;
        n++;
        for (int i = 0; i < n - 1; i++) {
            if (track[i] > head) {
                currentIndex = i;
                break;
            }
        }
    }

    int dir = direction ? 1 : -1;

    for (int i = currentIndex; i >= 0 && i < n; i += dir) {
        overhead += abs(track[i] - head);
        head = track[i];
    }

    dir *= -1;
    for (int i = currentIndex + dir; i >= 0 && i < n; i += dir) {
        overhead += abs(track[i] - head);
        head = track[i];
    }

    return overhead;
}

int main() {
    int n, head;
    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &n);
    getchar();

    int *track = (int*)malloc((n + 1) * sizeof(int));
    printf("Enter the current head position: ");
    scanf("%d", &head);
    getchar();

    printf("Enter the tracks to be checked:\n");
    for (int i = 0; i < n; i++) {
        printf("Track %d: ", i + 1);
        scanf("%d", &track[i]);
        getchar();
    }

    printf("Enter the initial direction of movement (0 for left, 1 for right): ");
    bool direction;
    scanf("%d", &direction);

    int overhead = look(track, n, head, direction);
    printf("\nOverhead: %d\n", overhead);

    free(track);
    return 0;
}
