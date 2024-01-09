#define TEXT_SZ  10
#define SEM_PRODUCER_FNAME "/myproducer"
#define SEM_CONSUMER_FNAME "/myconsumer"
#define SEM_MUTEX_NAME "/sem-mutex"
#define SEM_BUFFER_COUNT_NAME "/sem-buffer-count"
#define SEM_SPOOL_SIGNAL_NAME "/sem-spool-signal"
#define MUTEX_NAME "/mutex"
#define BUFFER_COUNT_NAME "/buffer-count"
#define SPOOL_SIGNAL_NAME "/spool-signal"


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include <openssl/md5.h>

struct shared_use_st {
	int written_by_you;
	char some_text[TEXT_SZ];
	char text[TEXT_SZ];
	char hash[20];
};


int main(int *argc, char **argv) 
{ 
    int pid, pid1, pid2,status,flg=0,c=0; 
	int x,d,i=0;
	int result;
	int shmid,shmid1,shmid2,shmid3;
	double a,b=100.0; 
	char s[TEXT_SZ];
	char r[TEXT_SZ];
	char buffer[BUFSIZ];
	int running = 1;
	void *shared_memory = (void *)0,*shared_memory1 = (void *)0,*shared_memory2 = (void *)0,*shared_memory3 = (void *)0,*shared_memory4 = (void *)0,*shared_memory5 = (void *)0,*shared_memory6 = (void *)0,*shared_memory7 = (void *)0,*shared_memory8 = (void *)0,*shared_memory9 = (void *)0,*shared_memory10 = (void *)0,*shared_memory11 = (void *)0,*shared_memory12 = (void *)0,*shared_memory13 = (void *)0;
	
	struct shared_use_st *shared_stuff;
	struct shared_use_st *shared_stuff1;
	struct shared_use_st *shared_stuff2;
	struct shared_use_st *shared_stuff3;
	struct shared_use_st *shared_stuff4;
	struct shared_use_st *shared_stuff5;
	struct shared_use_st *shared_stuff6;
	struct shared_use_st *shared_stuff7;
	struct shared_use_st *shared_stuff8;
	struct shared_use_st *shared_stuff9;
	struct shared_use_st *shared_stuff10;
	struct shared_use_st *shared_stuff11;
	struct shared_use_st *shared_stuff12;
	struct shared_use_st *shared_stuff13;	
	 key_t key = ftok(argv[0], 1);
	 key_t key1 = ftok(argv[1], 1);
	 key_t key2 = ftok(argv[2], 1);
	sem_t *mutex_sem, *buffer_count_sem, *spool_signal_sem,*mutex, *buffer_count, *spool_signal;
	const char *semName = "asdfsd";
	const char *semName1 = "asdfsdd";
	const char *semName2 = "asdfsddd";
	const char *semName3 = "asdfsdddd";
	const char *semName4 = "asdfsddddd";
	const char *semName5 = "asdfsdddddd";

	
	/*create shared_memory*/
	
	//1
	shmid = shmget(key, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//2
	shmid1 = shmget(key1, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid1 == -1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//3
	shmid2 = shmget(key2, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid2 == -1) {
		fprintf(stderr, "sem_open() failed.  errno:%d\n", errno);
		exit(EXIT_FAILURE);
	}
	//4
	shmid3 = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	/*up to here are the shared memories.*/




     /* these are our semaphores*/
	  // 1st semaphore
  if ((mutex_sem = sem_open (SEM_MUTEX_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
    
    // 2nd semaphore
    if ((buffer_count_sem = sem_open (SEM_BUFFER_COUNT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }

     // 3rd semaphore
    if ((spool_signal_sem = sem_open (SEM_SPOOL_SIGNAL_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
	// 4th semaphore
     sem_t *sem_id = sem_open(semName, O_CREAT, 0600, 0);
	
	 // 5th semaphore
	 if ((mutex = sem_open (MUTEX_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
    
    // 6th semaphore
    if ((buffer_count = sem_open (BUFFER_COUNT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }

     // 7th semaphore
    if ((spool_signal = sem_open (SPOOL_SIGNAL_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
  // 8th semaphore
    sem_t *sem_id1 = sem_open(semName1, O_CREAT, 0600, 0);
	
	  // 9th semaphore
    sem_t *sem_id2 = sem_open(semName2, O_CREAT, 0600, 0);
	
	  // 10th semaphore
    sem_t *sem_id3 = sem_open(semName3, O_CREAT, 0600, 0);
	
	 // 11th semaphore
    sem_t *sem_id4 = sem_open(semName4, O_CREAT, 0600, 0);
	
	// 12th semaphore
    sem_t *sem_id5 = sem_open(semName5, O_CREAT, 0600, 0);
	
	
	srand((unsigned int)getpid());
	/*create shared_memory*/
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
				/*attach*/
	///////////////////////////////////////////////////////////// ENC2-P2 /////////////////////////////////////////////////////////////////////////////////////////////////////////
	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1) {
			fprintf(stderr, "shmat failed\n");
			exit(EXIT_FAILURE);
	}
	/*put in shared memory*/
	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff->written_by_you = 0;
	while(running) {



			if (sem_wait(spool_signal_sem) < 0)
			printf("Parent  : [sem_wait] Failed\n");



			if (shared_stuff->written_by_you==3) {
			printf("\nYou wrote: %s", shared_stuff->some_text);
			shared_stuff->written_by_you = 5;

			}



/////////////////////////////////////////////////////////////////////// P2-ENC2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
			if (shared_stuff->written_by_you==5) {
			shared_memory1 = shmat(shmid, (void *)0, 0);
			if (shared_memory1 == (void *)-1) {
					fprintf(stderr, "shmat failed\n");
					exit(EXIT_FAILURE);
			}

			shared_stuff1 = (struct shared_use_st *)shared_memory1;
		

			printf("\nEnter some text: ");
			fgets(buffer, BUFSIZ, stdin);
			strncpy(shared_stuff1->some_text, buffer, TEXT_SZ);
	



			if (sem_post(buffer_count_sem) < 0)
					printf("Child   : [sem_post] Failed \n");

			}
	
			if (sem_post(buffer_count) < 0)
			printf("Child   : [sem_post] Failed \n");
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	}

	exit(EXIT_SUCCESS);
}

