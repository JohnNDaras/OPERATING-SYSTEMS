#define TEXT_SZ 10
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
    int pid, pid1, pid2,status,retransmission=0,c=0; 
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
	/*mexri edw einai oi shared memories*/











     /* aytoi einai oi shmaforoi*/
	  // 1os shmaforos
  if ((mutex_sem = sem_open (SEM_MUTEX_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
    
    // 2os shmaforos
    if ((buffer_count_sem = sem_open (SEM_BUFFER_COUNT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }

     // 3os shmaforos
    if ((spool_signal_sem = sem_open (SEM_SPOOL_SIGNAL_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
	// 4os shmaforos
     sem_t *sem_id = sem_open(semName, O_CREAT, 0600, 0);
	
	 // 5os shmaforos
	 if ((mutex = sem_open (MUTEX_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
    
    // 6os shmaforos
    if ((buffer_count = sem_open (BUFFER_COUNT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }

     // 7os shmaforos
    if ((spool_signal = sem_open (SPOOL_SIGNAL_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
  // 8os shmaforos
    sem_t *sem_id1 = sem_open(semName1, O_CREAT, 0600, 0);
	
	  // 9os shmaforos
    sem_t *sem_id2 = sem_open(semName2, O_CREAT, 0600, 0);
	
	  // 10os shmaforos
    sem_t *sem_id3 = sem_open(semName3, O_CREAT, 0600, 0);
	
	 // 11os shmaforos
    sem_t *sem_id4 = sem_open(semName4, O_CREAT, 0600, 0);
	
	// 12os shmaforos
    sem_t *sem_id5 = sem_open(semName5, O_CREAT, 0600, 0);
	/*mexri edw einai oi shmaforoi*/

		
		c=0;
		if (scanf("%lf",&a)>0)
		{	printf("\nEnter some text: ");

		while(running) {

					if(	fgets(buffer, BUFSIZ, stdin)>0  )
					{
						if(c==0)
						{	c++;
							continue;
						}	
						// variable pid will store the 
						// value returned from fork() system call 
						pid = fork(); 
						// If fork() returns zero then it 
						// means it is child process. 
						if (pid == 0) {         //______________________________________________________ENC1_______________________________________________________________
  
							// This is first child process 
							// getpid() gives the process 
							// id and getppid() gives the 
							// parent id of that process. 				
							if (sem_wait(buffer_count_sem) < 0)
							printf("Parent  : [sem_wait] Failed\n");

							sleep(1);
							printf("child[1] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
			   			   
			   
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////P1-ENC1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory1 = shmat(shmid, (void *)0, 0);
							if (shared_memory1 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
							/*put in shared memory*/
							shared_stuff1 = (struct shared_use_st *)shared_memory1;

							printf("You wrote: %s", shared_stuff1->some_text);

							if (strncmp(shared_stuff1->some_text, "end", 3) == 0) {
							running = 0;
							}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			   
							//FIND ENCRYPTED PASSWORD
							MD5(shared_stuff1->some_text, TEXT_SZ,shared_stuff1-> hash);
							printf("encrypted password is: %s\n",shared_stuff1-> hash);
							
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC1-CHAN/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory2 = shmat(shmid1, (void *)0, 0);
							if (shared_memory2 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}
							shared_stuff2 = (struct shared_use_st *)shared_memory2;
							strncpy(shared_stuff2->some_text, shared_stuff1->some_text, TEXT_SZ);

				   
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							strncpy(shared_stuff2->text, shared_stuff2->some_text, TEXT_SZ);	   
			   	   
							if (sem_post(mutex_sem) < 0)
							printf("Child   : [sem_post] Failed \n");
	 
							if (sem_wait(sem_id1) < 0)
							printf("Parent  : [sem_wait] Failed\n");

							if (spool_signal == SEM_FAILED){
							perror("Child   : [sem_open] Failed\n"); return 1;        
							}

							printf("child[1] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
		

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CHAN-ENC1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
							shared_memory11 = shmat(shmid1, (void *)0, 0);
							if (shared_memory11 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}
							/*put in shared memory*/
							shared_stuff11 = (struct shared_use_st *)shared_memory11;
							printf("You wrote: %s", shared_stuff11->some_text);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 

							//FIND ENCRYPTED PASSWORD
							MD5(shared_stuff11->some_text, TEXT_SZ,shared_stuff11-> hash);
							printf("encrypted password is: %s\n",shared_stuff11-> hash);
							
							if(strcmp(shared_stuff11-> some_text, shared_stuff11-> text)!=0) 
							{	
								printf("Retransmission\n");
									while(retransmission==1)
									{	shared_stuff11 = (struct shared_use_st *)shared_memory11;			
										sem_post(sem_id4);
										sem_wait(sem_id5);
										if(strcmp(shared_stuff11-> some_text, shared_stuff11-> text)==0)
										retransmission=0;
									}
									strncpy(shared_stuff11->some_text, shared_stuff11->text, TEXT_SZ);  
							}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC1-P1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 

							shared_memory12 = shmat(shmid, (void *)0, 0);
							if (shared_memory12 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}
							shared_stuff12 = (struct shared_use_st *)shared_memory12;
							strncpy(shared_stuff12->some_text, shared_stuff11->some_text, TEXT_SZ);
	
							if (sem_post(spool_signal) < 0)
							printf("Child   : [sem_post] Failed \n");



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
				} 
  
			else {                      	 //______________________________________________________CHAN_______________________________________________________________
							pid1 = fork(); 
							if (pid1 == 0) { 
							if (sem_wait(mutex_sem ) < 0)
							printf("Parent  : [sem_wait] Failed\n");
							printf("child[2] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC1-CHAN/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory3 = shmat(shmid1, (void *)0, 0);
							if (shared_memory3 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}
	
							/*put in shared memory*/
							shared_stuff3 = (struct shared_use_st *)shared_memory3;
							printf("You wrote: %s", shared_stuff3->some_text);
							if (strncmp(shared_stuff3->some_text, "end", 3) == 0) {
							running = 1;
							}			
		   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   

							double res = b / a;
							srand ( time ( NULL));
							int y=(int)res;
							x=rand()%y+1;
							d=rand()%y+1;
							strncpy( s,shared_stuff3->some_text, TEXT_SZ);
							if(x==d)
							{
								while(s[i]!='\0')
								{
									s[i]=s[i]+1;
									i++;
								}
							strncpy( shared_stuff3->some_text, s,TEXT_SZ);
							}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CHAN-ENC2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory4 = shmat(shmid2, (void *)0, 0);
							if (shared_memory4 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
	
							shared_stuff4 = (struct shared_use_st *)shared_memory4;
							strncpy(shared_stuff4->some_text, shared_stuff3->some_text, TEXT_SZ);
							if (strncmp(buffer, "end", 3) == 0) {
								running = 1;
							}		 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  

							if (sem_post(sem_id) < 0)
							printf("Child   : [sem_post] Failed \n");

		
							if(retransmission==1)
							{
								while(1)
								{
									if (sem_wait(sem_id3 ) < 0)
									printf("Parent  : [sem_wait] Failed\n");
									shared_stuff4 = (struct shared_use_st *)shared_memory4;
									res = b / a;
									srand ( time ( NULL));
									y=(int)res;
									x=rand()%y+1;
									d=rand()%y+1;

									strncpy( s,shared_stuff3->some_text, TEXT_SZ);
									if(x==d)
									{
										while(s[i]!='\0')
										{
											s[i]=s[i]+1;
											i++;
										}

									strncpy( shared_stuff3->some_text, s,TEXT_SZ);
									}
			
									if (sem_post(sem_id2) < 0)
									printf("Child   : [sem_post] Failed \n");

								}
			
							}		
		
		
		
							// needed to be printed first. 
							if (sem_wait(mutex ) < 0)
							printf("Parent  : [sem_wait] Failed\n");

							if (sem_id1 == SEM_FAILED){
							perror("Child   : [sem_open] Failed\n"); return 1;        
							}

							printf("child[2] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
		 	 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC2-CHAN/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory9 = shmat(shmid2, (void *)0, 0);
							if (shared_memory9 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}	
	
							/*put in shared memory*/
							shared_stuff9= (struct shared_use_st *)shared_memory9;
							printf("You wrote: %s", shared_stuff9->some_text);
							shared_stuff9->written_by_you = 8;
							if (strncmp(shared_stuff9->some_text, "end", 3) == 0) {
							running = 1;
							}
				   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   

							res = b / a;
							srand ( time ( NULL));
							y=(int)res;
							x=rand()%y+1;
							d=rand()%y+1;
							i=0;
							strncpy( s,shared_stuff9->some_text, TEXT_SZ);
							if(x==d)
							{
								while(s[i]!='\0')
								{
									s[i]=s[i]+1;
									i++;
								}
							strncpy( shared_stuff9->some_text, s,TEXT_SZ);
							}
		 
		 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CHAN-ENC1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory10 = shmat(shmid1, (void *)0, 0);
							if (shared_memory10 == (void *)-1) {
							fprintf(stderr, "shmat failed\n");
							exit(EXIT_FAILURE);
							}
							shared_stuff10 = (struct shared_use_st *)shared_memory10;
							strncpy(shared_stuff10->some_text, shared_stuff9->some_text, TEXT_SZ);
							if (strncmp(buffer, "end", 3) == 0) {
								running = 1;
							}
		 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
		 
							if (sem_post(sem_id1) < 0)
							printf("Child   : [sem_post] Failed \n");
							
							
							if(retransmission==1)
							{
								while(1)
								{
									if (sem_wait(sem_id4 ) < 0)
									printf("Parent  : [sem_wait] Failed\n");
									shared_stuff4 = (struct shared_use_st *)shared_memory4;
									res = b / a;
									srand ( time ( NULL));
									y=(int)res;
									x=rand()%y+1;
									d=rand()%y+1;
									strncpy( s,shared_stuff3->some_text, TEXT_SZ);
									if(x==d)
									{
										while(s[i]!='\0')
										{
											s[i]=s[i]+1;
											i++;
										}
									strncpy( shared_stuff3->some_text, s,TEXT_SZ);
									}
			
									if (sem_post(sem_id5) < 0)
									printf("Child   : [sem_post] Failed \n");

								}
			
							}

	
					} 
				else { 							//______________________________________________________ENC2_______________________________________________________________
							pid2 = fork(); 
							if (pid2 == 0) 	
						{ 
							// This is third child  

							if (sem_wait(sem_id) < 0)
							printf("Parent  : [sem_wait] Failed\n");


							if (spool_signal_sem == SEM_FAILED){
							perror("Child   : [sem_open] Failed\n"); return 1;        
							}

							printf("child[3] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
		

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CHAN-ENC2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
							shared_memory5 = shmat(shmid2, (void *)0, 0);
							if (shared_memory5 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
							/*put in shared memory*/
							shared_stuff5 = (struct shared_use_st *)shared_memory5;
							printf("You wrote: %s", shared_stuff5->some_text);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
							//FIND ENCRYPTED PASSWORD
							MD5(shared_stuff5->some_text, TEXT_SZ,shared_stuff5-> hash);
							printf("encrypted password is: %s\n",shared_stuff5-> hash);

							if(strcmp(shared_stuff5-> some_text, shared_stuff5-> text)!=0) 
							{	shared_stuff5->written_by_you = 1;
								printf("Retransmission\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC2-P2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
									while(retransmission==1)
									{		
										shared_stuff5 = (struct shared_use_st *)shared_memory5;		
										sem_post(sem_id2);
										sem_wait(sem_id3);
										if(strcmp(shared_stuff5-> some_text, shared_stuff5-> text)==0)
										retransmission=0;	
									}
									strncpy(shared_stuff5->some_text, shared_stuff5->text, TEXT_SZ);  
							}
							shared_memory6 = shmat(shmid3, (void *)0, 0);
							if (shared_memory6 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}

							shared_stuff6 = (struct shared_use_st *)shared_memory6;
							strncpy(shared_stuff6->some_text, shared_stuff5->some_text, TEXT_SZ);
							shared_stuff6->written_by_you = 3;
							
							if (sem_post(spool_signal_sem) < 0)
							printf("Child   : [sem_post] Failed \n");
							
							
							printf("\nEnter some text: ");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 


							if (sem_wait(buffer_count) < 0)
							printf("Parent  : [sem_wait] Failed\n");
		
							if (mutex == SEM_FAILED){
								perror("Child   : [sem_open] Failed\n"); return 1;        
							}

							printf("child[3] --> pid = %d and ppid = %d\n", 
							getpid(), getppid()); 
			   	   
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////P2-ENC2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory7 = shmat(shmid3, (void *)0, 0);
							if (shared_memory7 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
							shared_stuff7 = (struct shared_use_st *)shared_memory7;

							printf("You wrote: %s", shared_stuff7->some_text);
							if (strncmp(shared_stuff7->some_text, "end", 3) == 0) {
							running = 0;
							}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			   
			   
			   				//FIND ENCRYPTED PASSWORD
							MD5(shared_stuff7->some_text, TEXT_SZ,shared_stuff7-> hash);
							printf("encrypted password is: %s\n",shared_stuff7-> hash);		   
			   
			   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC2-CHAN/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							shared_memory8 = shmat(shmid2, (void *)0, 0);
							if (shared_memory8 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
							shared_stuff8 = (struct shared_use_st *)shared_memory8;   
							strncpy(shared_stuff8->some_text, shared_stuff7->some_text, TEXT_SZ);

				   
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
						   	 strncpy(shared_stuff8->text, shared_stuff7->some_text, TEXT_SZ);
							if (sem_post(mutex) < 0)
							printf("Child   : [sem_post] Failed \n");
			   

						} 
  
							// If value returned from fork() 
							// in not zero and >0 that means 
							// this is parent process. 
            else {                                             //______________________________________________________P1_______________________________________________________________

							if (buffer_count_sem == SEM_FAILED){
								perror("Child   : [sem_open] Failed\n"); return 1;        
							}
				
							printf("parent --> pid = %d\n", getpid()); 				    				  
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////P1-ENC1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	   
							/*attach*/
							shared_memory = shmat(shmid, (void *)0, 0);																																		
							if (shared_memory == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}

							shared_stuff = (struct shared_use_st *)shared_memory;
							strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
	
							if (strncmp(buffer, "end", 3) == 0) {
								running = 0;
							}
	
							if (shmdt(shared_memory) == -1) {
								fprintf(stderr, "shmdt failed\n");
								exit(EXIT_FAILURE);
							}
							//exit(EXIT_SUCCESS);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			  				
							if (sem_post(buffer_count_sem) < 0)
							printf("Child   : [sem_post] Failed \n");
						
							if (sem_wait(spool_signal) < 0)
							printf("Parent  : [sem_wait] Failed\n");
	
							printf("parent --> pid = %d\n", getpid()); 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ENC1-P1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
							shared_memory13 = shmat(shmid, (void *)0, 0);
							if (shared_memory13 == (void *)-1) {
								fprintf(stderr, "shmat failed\n");
								exit(EXIT_FAILURE);
							}
							/*put in shared memory*/
							shared_stuff13 = (struct shared_use_st *)shared_memory13;

							printf("You wrote: %s", shared_stuff13->some_text);
								printf("\nEnter some text: ");
							

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		
					} 
				} 
			} 
		}
		}
		}
	exit(EXIT_SUCCESS);
	
    return 0; 
 
}
