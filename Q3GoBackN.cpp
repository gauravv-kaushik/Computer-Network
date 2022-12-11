//Go Back N

#include<iostream>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int nf , N;
	int no_tr=0;
	srand(time(NULL));
	cout<<"Enter the number of frames : ";
	cin>>nf;
	cout<<"Enter the Window Size : ";
	cin>>N;
	int i=1,j;
	while(i<=nf)
	{
		int x=0;
		for(j=i;j<i+N&&j<=nf;j++)
		{
			cout<<"Sent Frame "<<j<<endl;
			no_tr++;
		}
		for(j=i;j<i+N&&j<=nf;j++)
		{
			int flag = rand()%2;
			if(!flag)
			{
				cout<<"Acknowledgement for Frame "<<j<<endl;
				x++;
			}
			else
			{
				cout<<"Frame "<<j<<" Not Received "<<endl;
				cout<<"Retransmitting Window "<<endl;
				break;
			}
		}
		cout<<endl;
		i+=x;
	}
	cout<<"Total number of transmissions : "<<no_tr<<endl;
	
} 

/*  ********** OUTPUT **********

Enter the number of frames : 4
Enter the Window Size : 3
Sent Frame 1
Sent Frame 2
Sent Frame 3
Frame 1 Not Received
Retransmitting Window

Sent Frame 1
Sent Frame 2
Sent Frame 3
Frame 1 Not Received
Retransmitting Window

Sent Frame 1
Sent Frame 2
Sent Frame 3
Acknowledgement for Frame 1
Acknowledgement for Frame 2
Frame 3 Not Received
Retransmitting Window

Sent Frame 3
Sent Frame 4
Frame 3 Not Received
Retransmitting Window

Sent Frame 3
Sent Frame 4
Acknowledgement for Frame 3
Acknowledgement for Frame 4

Total number of transmissions : 13

--------------------------------
Process exited after 3.274 seconds with return value 0
Press any key to continue . . .



*/
