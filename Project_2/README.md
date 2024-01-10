**Memory Management Simulation: Analyzing Page Replacement Algorithms with Hashed Page Tables**

The application simulates the behavior of a memory management system based on a real reference trace. The simulator reads each file and executes the virtual memory mechanism based on a hashed page table. When a reference occurs in the reference trace, the simulator checks if the specific page is in the main memory. If not, and the memory is already saturated, it decides which page to evict (page replacement) using the LRU or Second Chance algorithms. If the page to be evicted has been modified, it is "saved" to the disk. When a new page is loaded, the page table is appropriately updated.
The program reads alternating sets of references (a total of q) from each trace file, so that there are pages from both processes in the main memory. Specifically, it reads as many references as specified in the second argument alternately from each file until the total number of references (maxrefs) defined in the code is reached.

• To compile the program, use the following command:

	gcc -o something proj2.c
• To run the program, use the following format:

	./something “number of frames” “number of references” “replacement algorithm”
Where all three arguments can be integers. Regarding the replacement algorithm, use '0' for 	Second Chance and '1' for LRU.
For example: 

	./something 5 10 1
This means: a) 5 frames, b) 10 references as explained above, and c) executing the LRU 	algorithm.

During execution, the following menu is displayed: 

    1. Insert 
    2. Show Hash Table 
    3. Exit Program 
    
You need to choose one of the options 1, 2, or 0. \
    • Option 1 reads the references, executes the selected replacement algorithm, and displays the precise execution of the algorithm. \
    • Option 2, which can be selected after option 1, shows the final form of the hash table, along with the total number of page faults, the number of times an element marked as "write(W)" was evicted from the list, and the number of W and R read from the two files. \
    • Option 0 terminates the program and exits.
