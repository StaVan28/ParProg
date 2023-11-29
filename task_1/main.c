#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel 
        printf("Hello world! Thread: [%d]!\n", omp_get_thread_num());

    return 0;
}
