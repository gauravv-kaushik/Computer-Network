//selective Repeate

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


#define TOT_FRAMES 500
# define FRAMES_SEND 10

int i,j;

class sel_repeat{
	
	int fr_send_at_instance;
	int arr[TOT_FRAMES];
	int send[FRAMES_SEND];
	int rcvd[FRAMES_SEND];
	
	char rcvd_ack[FRAMES_SEND];
	
	int sw;
	int rw;
	
	public :
		void input() {
			int n;
			int m;
			
			cout<<"Enter the no of bits for the sequence number : ";
			cin>>n;
			
			m = pow(2,n);
			
			int t = 0;
			
			fr_send_at_instance = (m/2);
			
			for(i=0; i<TOT_FRAMES; i++) {
				arr[i]=t;
				t = (t+1)%m;
			}
			
			for(i=0; i<fr_send_at_instance; i++) {
				send[i] = arr[i];
				rcvd[i] = arr[i];
				rcvd_ack[i] = 'n';
			}
			
			rw = sw = fr_send_at_instance;
			sender(m);
		}
		
		void sender (int m) {
			for(i=0; i<fr_send_at_instance; i++) {
				if(rcvd_ack[i]=='n')
					cout<<" SENDER : Frame "<<send[i]<<" is sent .\n";
			}
			reciever(m);
		}
		
		void reciever(int m) {
			time_t t;
			int f;
			int f1;
			int a1;
			char ch;
			
			srand((unsigned) time(&t));
			
			for(int i=0; i<fr_send_at_instance; i++) {
				if(rcvd_ack[i]=='n') {
					f = rand()%10;
					
					if(f!=5) {
						for(j=0; j<fr_send_at_instance; j++)
							if(rcvd[j] == send[i]) {
								cout<<" RECIEVER : Frame "<<rcvd[j]<<" recevied correctly \n";
								rcvd[j] = arr[rw];
								rw = (rw+1)%m;
								break;
							}
							
							if (j==fr_send_at_instance) 
								cout<<" RECIEVER : Duplicate frame "<<send[i]<<" discard\n";
							
							a1 = rand()%5;
							
							if(a1==3) {
								cout<<"(Acknowledgement "<<send[i]<<" lost)\n";
								cout<<"(SENDER TIMEOUT-> RESEND THE FRAME )\n";
								rcvd_ack[i]='n';
							}	
							
							else {
								cout<<"(Acknowledgement "<<send[i]<<" recieved)\n";
								rcvd_ack[i] = 'p';
							}
						}
						else {
							int Id = rand()%2;
							
							if(Id ==0) {
								cout<<"RECEVIER : Frame "<<send[i]<<" is damaged\n";
								cout<<"RECEVIER : Negative acknowledgment "<<send[i]<<"sent\n";
								
							}
							else {
								cout<<"RECEVIER : Frame "<<send[i]<<" is lost\n";
								cout<<"(SENDER TIMEOUTS--> RESEND THE FRAME)\n";	
							}
							rcvd_ack[i]='n';
						}
					}
				}
				
				for(int j=0; j<fr_send_at_instance; j++) {
					if(rcvd_ack[j]=='n')
						break;
				}
				
				i=0;
				for(int k=j; k<fr_send_at_instance; k++) {
					send[i] = send[k];
					
					if(rcvd_ack[k]=='n')
						rcvd_ack[i]='n';
					else 
						rcvd_ack[i]='p';
						
					i++;		
				}
				if(i!=fr_send_at_instance) {
					for(int k=i; k<fr_send_at_instance; k++) {
						send[k] = arr[sw];
						sw = (sw+1)%m;
						rcvd_ack[k]='n';
					}
				}
				
			cout<<"Want to continue....";
			cin>>ch;
			cout<<"\n";
			
			if(ch=='y')
				sender(m);
			else 
				exit(0);	
		}
};

int main() {
	sel_repeat sr;
	sr.input();
	return 0;
}

/*  ********** OUTPUT **********

Enter the no of bits for the sequence number : 4
 SENDER : Frame 0 is sent .
 SENDER : Frame 1 is sent .
 SENDER : Frame 2 is sent .
 SENDER : Frame 3 is sent .
 SENDER : Frame 4 is sent .
 SENDER : Frame 5 is sent .
 SENDER : Frame 6 is sent .
 SENDER : Frame 7 is sent .
 RECIEVER : Frame 0 recevied correctly
(Acknowledgement 0 recieved)
 RECIEVER : Frame 1 recevied correctly
(Acknowledgement 1 recieved)
 RECIEVER : Frame 2 recevied correctly
(Acknowledgement 2 recieved)
 RECIEVER : Frame 3 recevied correctly
(Acknowledgement 3 recieved)
RECEVIER : Frame 4 is lost
(SENDER TIMEOUTS--> RESEND THE FRAME)
 RECIEVER : Frame 5 recevied correctly
(Acknowledgement 5 recieved)
 RECIEVER : Frame 6 recevied correctly
(Acknowledgement 6 recieved)
 RECIEVER : Frame 7 recevied correctly
(Acknowledgement 7 recieved)
Want to continue....0


--------------------------------
Process exited after 5.148 seconds with return value 0
Press any key to continue . . .



*/


