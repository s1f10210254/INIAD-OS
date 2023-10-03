#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

void* count_thread(void* arg)
{
    int i = (int)(intptr_t)arg;
    for (int j = i * 10 + 1; j <= i * 10 + 10; j++)
    {
        printf("%d\n",j);
    }

    
}

int main()
{
    pthread_t threads[3];
    for (int i = 0; i < 3; i++){
        pthread_create(&threads[i], NULL, &count_thread, (void*)(intptr_t)i);
    }

    for(int i = 0; i < 3; i++){
        void* ret;
        pthread_join(threads[i], &ret);
    }

    return 0;
}