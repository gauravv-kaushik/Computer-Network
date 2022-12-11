#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	// Declaring and initializing necessary variables
	int i,j,keylen,msglen;
	char input[100],key[30],temp[30],quot[100],rem[30],key1[30];
	
	cout<<"\n Please enter data:";
	cin>>input;
	cout<<"\n Please enter key:";
	cin>>key;
	
	// Determining lengths
	keylen=strlen(key);
	msglen=strlen(input);
	
	// Using temporary Key
	strcpy(key1,key);
	
	// Appending '0' to input data to form dividend
	for(i=0; i<keylen-1; i++)
	{
		input[msglen+i]='0';
	}
	
	// Extracting values for doing division of input data through key
	for(i=0; i<keylen; i++)
	{
		temp[i]=input[i];
	}
	
	// Continuous Division of input data with key to obtain quotient and remainder
	for(i=0; i<msglen; i++)
	{
		quot[i]=temp[0];
		if(quot[i]=='0')
		{
			for(j=0; j<keylen; j++)
			key[j]='0';
		}
		else
		{
			for(j=0; j<keylen; j++)
			key[j]=key1[j];	
		}
		for(j=keylen-1; j>0; j--)
		{
			if(temp[j]==key[j])
			rem[j-1]='0';
			else
			rem[j-1]='1';
		}
		rem[keylen-1]=input[i+keylen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	
	cout<<"\nquoteint is = ";
	for(i=0; i<msglen; i++)
		cout<<quot[i];
		
	cout<<"\nremainder is = ";
	for(i=0; i<keylen; i++)
		cout<<rem[i];
		
	cout<<"\nfinal data is = ";
	for(i=0; i<msglen; i++)
		cout<<input[i];
	for(i=0; i<keylen; i++)
		cout<<rem[i];

    return 0;
}

