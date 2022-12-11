/*    
  2)     Simulate and implement stop and wait protocol for noisy channel.
*/

#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

class timer
{

	private:
		unsigned long begTime;
		
    public:
    	void start()
    	{
    		begTime = clock();
		}
		
		unsigned long elapsedTime()
		{
			return(((unsigned long)clock()-begTime)/CLOCKS_PER_SEC);
		}
};

int main()
{
	
	int frames[] = {1,2,3,4,5,6,7,8,9,10};
	
	unsigned long seconds = 5;    // set timer of 5 seconds
	
	srand(time(NULL));       // intialise clock time
	
	timer t;
	cout<<"Sender has to send frames:";
	for(int i=0; i<10; i++)
	{
		cout<<frames[i]<<" ";
	}
	cout<<endl;
	
	int count=0;
	unsigned int delay=0;     // bool delay=false
	
	cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
	
	do
	{
		unsigned int timeout=0;
		cout<<"Sending Frame:"<<frames[count];
		cout.flush();
		cout<<"\t\t";
		t.start();     // start() is called
		if(rand()%2)     // 0,1
		{
			// Creating time delay till which receiver receives frame from sender
			
			int to = 2460+rand()%(6400-2460)+1;
			for(int i=0; i<6400; i++)
			{
				for(int j=0; j<to; j++)      // 11*17=187
				{
					
				}
			}
    	}
    	
		if(t.elapsedTime()<=seconds)       // within timer time
		{
			cout<<"\tReceived Frame:"<<frames[count]<<" ";
				
			if(delay)
			{
				cout<<"Duplicate";
				delay=0;
			}
			cout<<endl;
			count++;          // count=1
		}
			
		else
		{
		   cout<<"---"<<endl;
		   cout<<"Timeout"<<endl;
		   timeout=1;
		}
			
		t.start();
		if(rand()%2 || !timeout)
		{
			int to = 2460+rand()%(6400-2460)+1;
			for(int i=0; i<6400; i++)
				for(int j=0; j<to; j++)     // Achieve Delay for Acknowledgement
				{
				   	
				}
				   
				if(t.elapsedTime()>seconds)
				{
			    	cout<<"Delayed Ack"<<endl;
				   	count--;
				   	delay=1;
				}
				else if(!timeout)
				{
				   	cout<<"Acknowledgement:"<<frames[count+1]-1<<endl;
				}
		}
			
	}
	
	while(count!=10);
	return 0;
}

/*  ********** OUTPUT **********

Sender has to send frames:1 2 3 4 5 6 7 8 9 10

Sender                                  Receiver
Sending Frame:1                 Received Frame:1
Acknowledgement:2
Sending Frame:2                 Received Frame:2
Acknowledgement:3
Sending Frame:3                 Received Frame:3
Acknowledgement:4
Sending Frame:4                 Received Frame:4
Acknowledgement:5
Sending Frame:5                 Received Frame:5
Acknowledgement:6
Sending Frame:6                 Received Frame:6
Acknowledgement:7
Sending Frame:7                 Received Frame:7
Acknowledgement:8
Sending Frame:8                 Received Frame:8
Acknowledgement:9
Sending Frame:9                 Received Frame:9
Acknowledgement:0
Sending Frame:10                        Received Frame:10
Acknowledgement:-1

--------------------------------
Process exited after 1.949 seconds with return value 0
Press any key to continue . . .


*/
