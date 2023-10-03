#include <stdio.h>
#include<pthread.h>
#include <stdlib.h>

struct stack {
    pthread_mutex_t mtx;
    int buf[128];
    int count;

};



void stack_init(struct stack* stk)
{
    pthread_mutex_init(&stk->mtx, NULL);
    stk->count = 0;
}

void stack_push(struct stack* stk, int val)
{
    pthread_mutex_lock(&stk->mtx);
    stk->buf[stk->count++] = val;
    pthread_mutex_unlock(&stk->mtx);
}

int stack_pop(struct stack* stk)
{
    //pthread_mutex_lock(&stk.mtx);
    if (stk->count <= 0) {
        fprintf(stderr, "ERROR: stack is empty\n");
        abort();
    }
    //pthread_mutex_unlock(&stk->mtx);

    return stk->buf[--stk->count];
}

void* stack_thread(void* arg){
    struct stack* pstk = (struct stack*)arg;
    
    for(int i=0; i<1000000; i++){
        stack_push(pstk, i);
        printf("%d\n", stack_pop(pstk));
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    struct stack stk;
    pthread_t threads[2];
    stack_init(&stk);

    for(int i = 0;i < 2; i++){
        pthread_create(&threads[i], NULL, stack_thread, &stk);

    }
    
    for(int i = 0; i< 2; i++){
        void* ret;
        pthread_join(threads[i],&ret);
    }
    
    return 0;
}