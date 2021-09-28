#include <stdio.h>

#define SIZE 4096

void sort_by_time(int N, int ARRIVAL[], int BURST[]);

void print_stats(int N, int WT[], int CT[], int TAT[], double AVG_TAT,
                 double AVG_WT);

void scheduler(int N, int QUANTUM, int BURST[], int ARRIVAL[], int WT[], int CT[],
               int TAT[]);

// sort by arrival time
void sort_by_time(int N, int ARRIVAL[], int BURST[]) {
    int i, j, temp, temp2;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (ARRIVAL[j] > ARRIVAL[j + 1]) {
                temp = ARRIVAL[j];
                ARRIVAL[j] = ARRIVAL[j + 1];
                ARRIVAL[j + 1] = temp;
                temp2 = BURST[j];
                BURST[j] = BURST[j + 1];
                BURST[j + 1] = temp2;
            }
        }
    }
}

// print metrics
void print_stats(int N, int WT[], int CT[], int TAT[], double AVG_TAT,
                 double AVG_WT) {
    printf("[P#]\t[WT]\t[CT]\t[TAT]\n");
    for (int i = 0; i < N; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, WT[i], CT[i], TAT[i]);
    printf("Avg turn around time = %f\n", AVG_TAT);
    printf("Avg waiting time = %f\n", AVG_WT);
}

// compute metrics
void scheduler(int N, int QUANTUM, int ARRIVAL[], int BURST[], int WT[], int CT[],
               int TAT[]) {
    int TOTAL_TAT = 0, TOTAL_WT = 0;
    int temp[SIZE];

    for (int i = 0; i < N; i++)
        temp[i] = BURST[i];

    int TOTAL = 0;
    int i = 0;
    int FLAG = 0;
    int PROC = N;
    while (PROC != 0) {
        if (temp[i] <= QUANTUM && temp[i] > 0) {
            TOTAL += temp[i];
            temp[i] = 0;
            FLAG = 1;
        } else if (temp[i] > 0) {
            temp[i] -= QUANTUM;
            TOTAL += QUANTUM;
        }

        if (temp[i] == 0 && FLAG == 1) {
            PROC--;
            TAT[i] = TOTAL - ARRIVAL[i];
            WT[i] = TOTAL - ARRIVAL[i] - BURST[i];
            CT[i] = TOTAL;
            TOTAL_WT += TOTAL - ARRIVAL[i] - BURST[i];
            TOTAL_TAT += TOTAL - ARRIVAL[i];
            FLAG = 0;
        }

        if (i == N - 1)
            i = 0;
        else if (ARRIVAL[i + 1] <= TOTAL)
            i++;
        else
            i = 0;
    }

    double AVG_TAT = TOTAL_TAT * 1.0 / N;
    double AVG_WT = TOTAL_WT * 1.0 / N;

    print_stats(N, WT, CT, TAT, AVG_TAT, AVG_WT);
}

int main() {
    int N;
    int QUANTUM;
    int CT[SIZE];
    int TAT[SIZE];
    int WT[SIZE];
    int BURST[SIZE];
    int ARRIVAL[SIZE];

    printf("Round Robin\nEnter number of processes: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter arrival time of processes %d: ", i + 1);
        scanf("%d", &ARRIVAL[i]);
        printf("Enter burst time of processes %d: ", i + 1);
        scanf("%d", &BURST[i]);
    }

    printf("Enter QUANTUM: ");
    scanf("%d", &QUANTUM);

    sort_by_time(N, ARRIVAL, BURST);

    scheduler(N, QUANTUM, ARRIVAL, BURST, WT, CT, TAT);

    return 0;
}
