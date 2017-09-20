/* must define union semun ourselves */

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

/*
 * If successful, the return value will be the semaphore set identifier
 */
int binary_semaphore_allocation(key_t key, int sem_flags)
{
    return semget(key, 1, sem_flags);
}

/*
 * Semaphores continue to exist even after all processes 
 * using them have terminated.
 * The last process to use a semaphore set must explicitly remove it 
 * to ensure that the operating system does not run out of semaphores.
 * Unlike shared memory segments, 
 * removing a semaphore set causes Linux to deallocate immediately.
 */
int binary_semaphore_deallocate(int semid)
{
    union semun ignored_argument;
    return semctl(semid, 1, IPC_RMID, ignored_argument);
}


int binary_semaphore_initialize(int semid)
{
    union semun argument;
    unsigned short values[1];
    values[0] = 1;
    argument.array = values;
    return semctl(semid, 0, SETALL, argument);
}


int binary_semaphore_wait(int semid)
{
    struct sembuf operations[1];
    /* the semaphore number in the semaphore set 
     * on which the operation is performed 
     */
    operations[0].sem_num = 0;
    
    /* If sem_op is a negative number, the absolute value of that number
     * is subtracted from the semaphore value. 
     * If this would make the semaphore value negative, the call blocks 
     * until the semaphore value becomes as large as the absolute value 
     * of sem_op (because some other process increments it). */
    operations[0].sem_op = -1;
    
    /* If you specify SEM_UNDO Linux automatically undoes the operation 
     * on the semaphore when the process exits */
    operations[0].sem_flg = SEM_UNDO;

    return semop(semid, operations, 1);
}


int binary_semaphore_post(int semid)
{
    struct sembuf operations[1];
    operations[0].sem_num = 0;
    
    /* If sem_op is a positive number, 
     * that number is added to the semaphore value immediately */
    operations[0].sem_op = 1;
    operations[0].sem_flg = SEM_UNDO;

    return semop(semid, operations, 1);
}

