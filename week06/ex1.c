#include <stdio.h>

#define SIZE 4096

void sort_by_time(int N, int ARRIVAL[], int BURST[]);

void print_stats(int N, int WT[], int CT[], int TAT[], double AVG_TAT,
                 double AVG_WT);

void scheduler(int N, int ARRIVAL[], int BURST[], int WT[], int CT[],
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


// compute metrics
void scheduler(int N, int ARRIVAL[], int BURST[], int WT[], int CT[],
               int TAT[]) {
    int TOTAL_TAT = 0;
    int TOTAL_WT = 0;
    int SUM = 0;

    WT[0] = ARRIVAL[0];
    for (int i = 1; i < N; i++) {
        WT[i] = BURST[i - 1] + WT[i - 1];
        TOTAL_WT += WT[i];
    }
    for (int i = 0; i < N; i++) {
        TAT[i] = BURST[i] + WT[i];
        TOTAL_TAT += TAT[i];
    }

    for (int i = 0; i < N; i++) {
        SUM += BURST[i];
        CT[i] = SUM;
    }

    double AVG_TAT = TOTAL_TAT / N;
    double AVG_WT = TOTAL_WT / N;

    print_stats(N, WT, CT, TAT, AVG_TAT, AVG_WT);
}

// print metrics
void print_stats(int N, int WT[], int CT[], int TAT[], double AVG_TAT,
                 double AVG_WT) {
    printf("[P#]\t[WT]\t[CT]\t[TAT]\n");
    for (int i = 0; i < N; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, WT[i], CT[i], TAT[i]);
    printf("Average TAT = %f\n", AVG_TAT);
    printf("Average WT = %f\n", AVG_WT);
}


int main() {
    int N;
    int CT[SIZE];
    int TAT[SIZE];
    int WT[SIZE];
    int BURST[SIZE];
    int ARRIVAL[SIZE];

    printf("FCFS\nEnter number of processes: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter arrival time of processes %d: ", i + 1);
        scanf("%d", &ARRIVAL[i]);
        printf("Enter burst time of processes %d: ", i + 1);
        scanf("%d", &BURST[i]);
    }

    sort_by_time(N, ARRIVAL, BURST);

    scheduler(N, ARRIVAL, BURST, WT, CT, TAT);

    return 0;
}
