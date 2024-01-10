#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 91 // prime number for size of array
#define h(x) (x % m) //h(x) = x mod m
#define max_refs 30
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	struct page{
		int val;
		int dirty_bit;
	};

// Node for Lru List
typedef struct Node{

	struct page page;
    struct Node *next;
}Node;

// Node for Second Chance List
typedef struct sNode{

	struct page page;
	int data;
    struct sNode *next;
}sNode;



//function's declaration
Node *fill_table(Node *table, int table_range, int number,int dirty_bit);
Node *insert(Node *table, int hash_index, int val, int dirty_bit);
Node *del(Node *table,int table_range,int val);
void print_table(Node *table, int table_range);
void search_table(Node *table, int table_range, int val,int dirty_bit);
void search_tablew(Node *table, int table_range, int val,int dirty_bit);
void searchw(Node *head, int key);
void update_data(int old, int new);
int delete_at_end();
void listprint();
int push_at_end(int x);
void moveToEnd(Node** head_ref); 
int flag=0;
int fl=0;
int f=0;
Node *start = NULL;
sNode *starts = NULL;
Node *startw = NULL;
void update_datas(int old, int new,int y);
void update_s(int old,int y); 
 void moveToEnds(sNode** head_ref);
void listprints(); 
int push_at_ends(int x, int y);
void moveEnd(Node* head, int key);
int coun(Node *table, int table_range);
int count=0;
int pagefault=0;

int main(int argc, char* argv[]){
    Node *table; // hashtable
    int n, i, j, choice, search,y,w=3,dirty_bit,v=0,b,a=0,r=0,l=0,q, art=0, per=1,dyo=2,up=0,yp=0,c=1,writeback=0;
    int hash_num, val;	
	unsigned int framescount=atoi(argv[1]);



	int u=1,x;
    //char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen("bzip.trace", "r"); /* should check the result */
	FILE* file1 = fopen("gcc.trace", "r"); /* should check the result */
    char line[256];
	char format[20] = {0};
    char buf[50] = {0};
	size_t howMuchToRead = 5;
	const char ch = '$';
    char *ret;
	char delim[] = " ";
	char *p1;
    long n1;
	char *p2;
	long n2;


	
    // allocate table
    table = (Node*) malloc(N*sizeof(Node));
    //make table "heads" NULL
    for(i = 0; i < N; i++){
    	table[i].next = NULL;
    }
	
    printf("--h(x) = xmod%d--\n",N);
    printf("\n\n");	 

    while(1){
    	printf("1.Insert \n");
	printf("2.Show Hash Table\n");
	printf("0.Exit Programm\n");		
	printf("\n--------\n");
	printf("Choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 0: return 0;
		case 1:

		printf("                READ FROM bzip.trace\n\n");
		while (u<=max_refs) {
		q=atoi(argv[2]);
		
		up=art*q;
		yp=per*q;
		if(up<u && yp>=u){
			fgets(line, sizeof(line), file);
		}
		else if(yp<u && up>=u){
			fgets(line, sizeof(line), file1);
		}
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
		a++;
		printf("%d) %c         ",a,line[9]);
		if(line[9]=='R') {
			dirty_bit=0;
			r++;	}
		if(line[9]=='W') {
			dirty_bit=1;
			l++;	}
		snprintf(format, sizeof format, "%%.%zus", howMuchToRead);
        snprintf(buf, sizeof buf, format, line);
		printf("%s", buf);
		memset(line,'$',5);
		ret = memchr(line,line[5] , strlen(line));
		char *ptr = strtok(ret,delim);
		printf("(%s)", ptr);
		n1 = strtol(buf, &p1, 16);
		printf(" ---------> %ld", n1);
		n2 = strtol(ptr, &p2, 16);
		printf("  (offset= %ld)\n", n2);
		if(framescount>0)
		printf("__________________________________________________\n");
			

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     LRU	 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(atoi(argv[3])==1)
			{
				if(framescount>0){
				
				search_tablew(table, N, n1,1);
				if(flag==1){
					table = del(table, N, n1);
					table = fill_table(table, N, n1,dirty_bit);
					update_data(n1,n1);
					moveEnd(start, n1);
					listprint();
					b=atoi(argv[1])-framescount;
					printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));
				}
				else if(flag==0)
					{	
						pagefault++;
						table = fill_table(table, N, n1,dirty_bit);
						push_at_end(n1);
						listprint();
						framescount--;
						b=atoi(argv[1])-framescount;
						printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));
					}


			}
			else{ 
				framescount=0;
				 search_tablew(table, N, n1,1);
				 if(flag==0){
					 printf("__________________________________________________\n");
					 pagefault++;
					 search_table(table, N, start->page.val,1);
					 if(fl==1){ writeback++; printf("A Write is out of list\n\n");}
					 table = del(table, N, start->page.val);
					update_data(start->page.val,n1);
					moveToEnd(&start);
					table = fill_table(table, N, n1,dirty_bit);
				 }
				if(flag==1){
					printf("__________________________________________________\n");
					table = del(table, N, n1);
					table = fill_table(table, N, n1,dirty_bit);
					update_data(n1,n1);
					moveEnd(start, n1);
					
				 }

				listprint();
				b=atoi(argv[1])-framescount;
				printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));
				}

			}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   SECOND CHANCE  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		

			if(atoi(argv[3])==0)
			{
				if(framescount>0){
				
				search_tablew(table, N, n1,1);
				if(flag==1){
					
					table = del(table, N, n1);
					table = fill_table(table, N, n1,dirty_bit);
					//print_table(table, N);
					update_datas(n1,n1,1);
					listprints();

					b=atoi(argv[1])-framescount;
					printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));
				}
				else if(flag==0)
					{	
						pagefault++;
						table = fill_table(table, N, n1,dirty_bit);
						//print_table(table, N);
						push_at_ends(n1,0);
						listprints();
						framescount--;
						b=atoi(argv[1])-framescount;
						printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));

					}

			}
			else{ 
				framescount=0;
				 search_tablew(table, N, n1,1);
				 if(flag==0){
					 printf("__________________________________________________\n");
					 pagefault++;
					 while(v!=1)
					 {
						 if(starts->data==0)
						 {	
							search_table(table, N, starts->page.val,1);
							table = del(table, N, starts->page.val);
							if(fl==1){ writeback++; printf("A Write is out of list\n\n");}
							update_datas(starts->page.val,n1,0);
							moveToEnds(&starts);							
							table = fill_table(table, N, n1,dirty_bit);
							//print_table(table, N);
							v=1;
							continue;
						 }
						 if(starts->data==1)
						 {
							update_s(starts->page.val,0);
							moveToEnds(&starts);
						 }
					 } 
				 }
				if(flag==1){
					printf("__________________________________________________\n");
					table = del(table, N, n1);
					table = fill_table(table, N, n1,dirty_bit);
					//print_table(table, N);
					update_datas(n1,n1,1);
					printf("%d",fl);
				 }

				listprints();
				b=atoi(argv[1])-framescount;
				printf("        (Frames:%d/%d)\n\n\n\n",b,atoi(argv[1]));
				}
				v=0;

			
			}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(u>1 && u<max_refs)
			{
				if(u==yp)	{printf("\n\n\n                READ FROM gcc.trace"); art=art+2; c=2;}
				if(u==up)	{printf("\n\n\n                READ FROM bzip.trace"); per=per+2;}

			}
			printf("\n\n");
					u++;
    }
		
		break;

		case 2:
			//print hashtable
			printf("-HASHTABLE-\n\n");
			print_table(table, N);
			printf("\n--------\n");	
			printf("Total Number of Page Faults: %d\n",pagefault);
			printf("Total Number of Writes out of list: %d\n",writeback+coun(table, N));
			printf("\nW appeared %d times\n",l);
			printf("R appeared %d times\n\n",r);
			break;	
	    }
	}	
	return 0;
}
  
// FUNCTIONS
Node *fill_table(Node *table, int table_range, int num,int dirty_bit){
    int i;

	table = insert(table, num % table_range, num, dirty_bit);
    
    return table;
}

void print_table(Node *table, int table_range){
    int i;
    Node* cur;
    for(i = 0; i < table_range; i++){ // for each list
	if(table[i].next == NULL){ // if empty
                printf("Table[%d] is empty!\n", i);
		continue;
	}
	cur = table[i].next;
	printf("Table[%d]", i);
	while(cur!=NULL){ // else print all the values
		printf("->%d(%d)",cur->page.val, cur->page.dirty_bit);
		cur=cur->next; //cur=cur+1;
	}
	printf("\n");	
    }
}

Node *insert(Node *table, int hash_index, int val,int dirty_bit){
    Node *nn, *cur;

    nn = (Node*)malloc(sizeof(Node));
    nn->page.val=val;
	nn->page.dirty_bit=dirty_bit;
    nn->next=NULL;
	
    if(table[hash_index].next == NULL){
	table[hash_index].next = nn;
	return table;
    }
	
    cur = table[hash_index].next;
    while(cur->next != NULL){
	cur=cur->next; //cur=cur+1;
    }
    cur->next = nn;
    return table;
}

void search_table(Node *table, int table_range, int val,int dirty_bit){
    int index = val % table_range;
    Node *cur;
	
    if(table[index].next == NULL){ // if empty
			
                return;
    }

    cur = table[index].next;
    while(cur!=NULL){
	if(cur->page.val == val){
	if(cur->page.dirty_bit == dirty_bit) {fl=1;}
		return;
	}
	cur = cur->next;

    }
	
	fl=0;
   // printf("Value %d not found in Hashtable!\n", val);
}



void search_tablew(Node *table, int table_range, int val,int dirty_bit){
    int index = val % table_range;
    Node *cur;
	
    if(table[index].next == NULL){ // if empty
	flag=0;
	fl=0;
			
                return;
    }

    cur = table[index].next;
    while(cur!=NULL){
	if(cur->page.val == val){
	//	printf("Value %d was found!\n", val);
		if(cur->page.dirty_bit == dirty_bit) {fl=1;}
		else fl=0;
		flag=1;
		return;
	}
	cur = cur->next;
    }
	flag=0;
	fl=0;
}




Node *del(Node *table, int table_range, int val){
    int index = val % table_range;
    Node *prev;
	
    if(table[index].next == NULL){ // if empty
	return table;
    }
	
    if(table[index].next->page.val== val){ // if first item
	table[index].next = table[index].next->next;
	return table;
    }

    prev = table[index].next;
    while(prev->next!=NULL){
	if(prev->next->page.val== val){
		prev->next = prev->next->next;
		return table;
	}
	prev = prev->next;
    }

    return table;
}






int push_at_end(int x){
  		Node* t;
  		Node* temp;
      	t=(Node*)malloc(sizeof(Node));
      	t->page.val=x;
      	count++;
      	if(start==NULL)
      	  {
      		start=t;
      		start->next=NULL;
      		return 1;
		  }
		  temp =start;
		  while(temp->next!=NULL)
		  {
		    temp=temp->next;
		  }
      	 temp->next =t;
      	 t->next = NULL;
      	return x;
	  }


int push_at_endw(int x){
  		Node* t;
  		Node* temp;
      	t=(Node*)malloc(sizeof(Node));
      	t->page.val=x;
      	count++;
      	if(startw==NULL)
      	  {
      		startw=t;
      		startw->next=NULL;
      		return 1;
		  }
		  temp =startw;
		  while(temp->next!=NULL)
		  {
		    temp=temp->next;
		  }
      	 temp->next =t;
      	 t->next = NULL;
      	return x;
	  }

	void searchw(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->page.val == key)
        {
            printf("key found\n");
			f=1;
            return;
        }
        head = head->next;
    }
	f=0;
    printf("Key not found\n");
}

	  void listprintw(){
	  	int i;
	  	Node* temp;
	  	temp=startw;
	  	if(temp ==NULL){
	  		printf("\nList is empty");
	  		return ;
	  	 }
	  	while(temp->next!=NULL)
	  	{  printf("%d\t",temp->page.val);
	  	  temp=temp->next;
		}
		 printf("%d\t",temp->page.val);
		 return ;
	  }


	  void moveToEnd(Node** head_ref) 
{ 
    /* If linked list is empty, or it contains  
       only one node, then nothing needs to be  
       done, simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
  
    /* Initialize first and last pointers */
	Node* first = *head_ref; 
    Node* last = *head_ref; 
  
    /*After this loop last contains address  
    of last node in Linked List */
    while (last->next != NULL) { 
        last = last->next; 
    } 
  
    /* Change the head pointer to point  
       to second node now */
    *head_ref = first->next; 
  
    /* Set the next of first as NULL */
    first->next = NULL; 
  
    /* Set the next of last as first */
    last->next = first; 
} 


	  void listprint(){
	  	int i;
	  	Node* temp;
	  	temp=start;
	  	if(temp ==NULL){
	  		printf("\nList is empty");
	  		return ;
	  	 }
	  	while(temp->next!=NULL)
	  	{  printf("%d\t",temp->page.val);
	  	  temp=temp->next;
		}
		 printf("%d\t",temp->page.val);
		 return ;
	  }



	void update_data(int old, int new) {
   int pos = 0;
   Node* current;
   if(start==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = start;
   while(current->next!=NULL) {
      if(current->page.val == old) {
         current->page.val = new;
		 pos=0;
         return;
      }
      
      current = current->next;
      pos++;
   }
}




int push_at_ends(int x, int y){
  		sNode* t;
  		sNode* temp;
      	t=(sNode*)malloc(sizeof(sNode));
      	t->page.val=x;
		t->data=y;
      	count++;
      	if(starts==NULL)
      	  {
      		starts=t;
      		starts->next=NULL;
      		return 1;
		  }
		  temp =starts;
		  while(temp->next!=NULL)
		  {
		    temp=temp->next;
		  }
      	 temp->next =t;
      	 t->next = NULL;
      	return x;
	  }


	  void listprints(){
	  	int i;
	  	sNode* temp;
	  	temp=starts;
	  	if(temp ==NULL){
	  		printf("\nList is empty");
	  		return ;
	  	 }
	  	while(temp->next!=NULL)
	  	{  printf("%d(%d)\t",temp->page.val,temp->data);
	  	  temp=temp->next;
		}
		 printf("%d(%d)\t",temp->page.val,temp->data);
		 return ;
	  }
	  
	  
 void moveToEnds(sNode** head_ref) 
{ 
    /* If linked list is empty, or it contains  
       only one node, then nothing needs to be  
       done, simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
  
    /* Initialize first and last pointers */
	sNode* first = *head_ref; 
    sNode* last = *head_ref; 
  
    /*After this loop last contains address  
    of last node in Linked List */
    while (last->next != NULL) { 
        last = last->next; 
    } 
  
    /* Change the head pointer to point  
       to second node now */
    *head_ref = first->next; 
  
    /* Set the next of first as NULL */
    first->next = NULL; 
  
    /* Set the next of last as first */
    last->next = first; 
} 



	void update_datas(int old, int new,int y) {
   int pos = 0,i=0;
   sNode* current;
   if(starts==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = starts;
    while(i!=(count+1)) {
      if(current->page.val == old) {
         current->page.val = new;
		 current->data = y;
		 pos=0;
         return;
      }
      
      current = current->next;
      pos++;
	  i++;
   }
}



	void update_s(int old,int y) {
   int pos = 0;
   sNode* current;
   if(starts==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = starts;
   while(current->next!=NULL) {
      if(current->page.val == old) {
         // current->page.val = new;
		 current->data = y;
		 pos=0;
         return;
      }
      
      current = current->next;
      pos++;
   }
}


void moveEnd(Node* head, int key)
{
    // Keeps track of locations where key
    // is present.
    Node* pKey = head;
 
    // Traverse list
    Node* pCrawl = head;
    while (pCrawl != NULL) {
        // If current pointer is not same as pointer
        // to a key location, then we must have found
        // a key in linked list. We swap data of pCrawl
        // and pKey and move pKey to next position.
        if (pCrawl != pKey && pCrawl->page.val != key) {
            pKey->page.val = pCrawl->page.val;
            pCrawl->page.val = key;
            pKey = pKey->next;
        }
 
        // Find next position where key is present
        if (pKey->page.val != key)
            pKey = pKey->next;
 
        // Moving to next Node
        pCrawl = pCrawl->next;
    }
}


int coun(Node *table, int table_range){
    int i,co=0;
    Node* cur;
    for(i = 0; i < table_range; i++){ // for each list
	if(table[i].next == NULL){ // if empty
        
		continue;
	}
	cur = table[i].next;

	while(cur!=NULL){ // else print all the values
		if(cur->page.dirty_bit == 1) {co ++;}
		cur=cur->next; //cur=cur+1;
	}
		
    }
	return co;
}











