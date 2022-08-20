#include<stdio.h>
#include<stdlib.h>

int main() 
{
		int i, j, capacity, ns, t, count, size, a, choice, p[10], cap, rate, delay, flag=1, t1, t2;

		printf ("enter the queue size:");
		scanf ("%d",&size);

		count=size;

		printf ("enter leaky bucket capacity:");
		scanf ("%d",&cap);

		capacity = cap;

		printf ("enter the size of the packets in the queue:");
		for (i=0; i<size; i++){
				scanf ("%d", &a);
				if (a > cap){
						i--;
						printf ("packets cannot be entered");
				}
				else
					p[i] = a;
		}

		printf ("enter the output rate:");
		scanf ("%d", &rate);

		delay = cap / rate;

		printf ("delay=%d\n", delay);
		while (flag){
				capacity = cap;
				while (capacity >= p[0] && count > 0){
						printf ("\npacket of size %d is put into the bucket\n", p[0]);
						capacity = capacity - p[0];
						printf ("\navailable space %d\n", capacity);
						count--;
						p[i] = p[i+1];
				}

				t = delay;
				long int t1= (long) time(NULL);
				long int t2 = (long) time(NULL);

				while ( (t2-t1) < delay){
						t2 = (long) time(NULL);
						if ( (delay-t) == (t2 - t1)){
								printf ("\ntransmitting packets in the leaky bucket:%d seconds\n", t);
								t--;
						}
				}


				printf ("\npackets in the queue:\n");
				for (i=0; i<count; i++)
					printf ("%d\t", p[i]);

				printf ("\ndo u want to enter more packets in the queue? (1 or 0)\n");
				scanf ("%d", &choice);

				while (choice && count < size){
						printf ("enter the no of packets (<=%d)\n", size-count);
						scanf ("%d", &ns);
						if (ns > (size-count))
								printf ("\nexceeding queue size\n");
						else{
								printf ("\nenter the size of the packets to put in the queue:\n");
								for (i=0; i<ns; i++){
										scanf ("%d", &a);
										if ( a > cap)
												printf ("packets cannot be entered");
										else
												p[count++]=a;
								}
						}
						printf ("\ndo u want to enter more? (0 or 1)\n");
						scanf ("%d", &choice);
						if ( choice != 0)
								if (count >= size)
										printf ("queue is full");
				}
				if (count == 0)
						flag = 0;
		}
}