#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        fprintf(stderr, "ERROR! Usage:\n./a.out [N]\nWhere N >= 1!\n");
        return EXIT_FAILURE;
    }

    int N = strtol(argv[1], NULL, 10);
    if (N <= 0) {
        fprintf(stderr, "N need to be more than zero!\n");
        return EXIT_FAILURE;
    }

    double sum = 0;
    double partial_sum = 0;

    #pragma omp parallel private(partial_sum) shared(sum)
    {
        #pragma omp for
            for(int i = 1; i <= N; i++){
                partial_sum += 1/(float)i;
            }
        
        #pragma omp critical
        {
            sum += partial_sum;
        }
    }

    printf("Sum is: %lf\n", sum);

    sum = 0;
    for (double i = 1; i <= N; i++) {
        sum += 1 / i;
    }

    printf("Expected is: %lf\n", sum);

    return 0;
}
