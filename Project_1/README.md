The project describes the implementation of a two-tier message exchange architecture according to the following scheme. There are five processes: P1, P2, ENC1, ENC2, and CHAN.
Processes P{1|2} receive and present data to the user. The input to processes P{1|2} is a text line entered as a message with the prospect of being sent to the other process (i.e., P1 → P2 or P2 → P1). If the message is entered in P1, it is "transmitted" from the underlying layers to P2. If the correctness of the message is verified, it is presented to the user of P2. Processes ENC1 and ENC2 receive messages from P{1|2}, calculate the checksum value of the given character string (message checksum), and then redirect the augmented message (plain + checksum) to the CHAN process, which simulates the transport network.


![Picsart_24-01-10_06-07-59-423~2](https://github.com/JohnNDaras/OPERATING-SYSTEMS/assets/117290033/8eea8572-51da-45cb-935f-baca2daee69f)











The CHAN process replaces the characters of the message with others randomly based on a provided probability (change), which is an external parameter of the overall program. If the symbol string-message en route from P1 to P2 (and vice versa) is found altered in the ENC?, the checksum check leads to the rejection of the incoming message. If the message, despite the random replacement process, is received unchanged, it is decapsulated (from the control information) and provided to the higher-level application (for user visualization). If the message (e.g., from P1) is omitted due to its intentional alteration, with mismatches between the character string and checksum, the ENC2 process requests the retransmission of the relevant information.
The transmission of the TERM message by a P{1|2} process and its passage through the remaining processes (ENC?, CHAN, etc.) signals the termination of all processes and the final release of synchronization structures. The edges between the above processes are implemented using shared memory spaces (in/out structures) and are surrounded by appropriate semaphores.
