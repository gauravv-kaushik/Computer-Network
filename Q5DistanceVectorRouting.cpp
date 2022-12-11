// IMPLEMENTATION OF DISTANCE VECTOR ROUTING IN COMPUTER NETWORK


#include<iostream>
#include<conio.h>
using namespace std;
 
int main()
{
    int graph[50][50];
    int i,j,k,t;
    int nn;
 
    cout<<"\n Enter Number of Nodes:";
    cin>>nn;
 
    /* Initialize graph*/
    for (i=0; i<nn; i++)
    {
        for(j=0; j<nn; j++)
        {
            graph[i][j]=-1;
        }
    }
 
    /* Vertex names */
    char ch[7]={'A','B','C','D','E','F','G'};
 
    /* Get input */
    for (i=0; i<nn; i++)
    {
        for(j=0; j<nn; j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(graph[i][j]==-1)
            {
                cout<<"\n Enter Distance between "<<ch[i]<<" - "<<ch[j]<<" : ";
                cin>>t;
                graph[i][j]=graph[j][i]=t;
            }
        }
    }
 
    /* Initializing via */
    int via[50][50];
    for (i=0; i<nn; i++)
    {
        for(j=0; j<nn; j++)
        {
            via[i][j]=-1;
        }
    }
 
    cout<<"\n After Initialization";
    /* Display table initialization */
    for (i=0; i<nn; i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<via[i][j];
        }
    }
 
    //sharing table
    int sh[50][50][50];
    for(i=0; i<nn; i++)
    {
        for(j=0; j<nn; j++)
        {
            for (k=0; k<nn; k++)
            {
                /* Check if edge is present or not*/
                if((graph[i][j]>-1)&&(graph[j][k]>-1))
                {
                    sh[i][j][k]=graph[j][k]+graph[i][j];
                }
                else
                {
                    sh[i][j][k]=-1;
                }
            }
        }
    }
 
    /*displaying shared table */
    for(i=0; i<nn; i++)
    {
        cout<<"\n\n For "<<ch[i];
        for (j=0; j<nn; j++)
        {
            cout<<"\n From "<<ch[j];
            for(k=0; k<nn; k++)
            {
                cout<<"\n "<<ch[k]<<" "<<sh[i][j][k];
            }
        }
    }
     
    /* Updating */
    int final[50][50];
    for(i=0; i<nn; i++)
    {
        for(j=0; j<nn; j++)
        {
            /* Copy initial value from input graph*/
            final[i][j]=graph[i][j];
            via[i][j]=i;
             
            //Update them
            /* Check condition a - b - c */
            for(k=0; k<nn; k++)
            {
                 
                if((final[i][j]>sh[i][k][j]) || (final[i][j] == -1))
                {
                    if(sh[i][k][j]>-1)
                    {
                        final[i][j]=sh[i][k][j];
                        via[i][j]=k;
                    }
                }
            }
            /* After considering three vertex if final not found 
                consider 4th
                a- b- c- d
            */
 
            if(final[i][j]==-1)
            {
                for(k=0; k<nn; k++)
                {
 
                    if((final[i][k]!=-1)&&(final[k][j]!=-1))
                    {
                        if((final[i][j]==-1) || ((final[i][j]!=-1) &&(final[i][j]>final[i][k]+final[k][j]))) 
                        {
                            if(final[i][k]+final[k][j]>-1)
                            {
                                final[i][j]=final[i][k]+final[k][j];
                                via[i][j]=k;
                            }
                        }
                    }
                     
                }
            }
        }
    }
 
    cout<<"\n After Update :";
    /* Display table Updation */
    for (i=0; i<nn; i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<final[i][j]<<"\t";
            if(i==via[i][j])
                cout<<"-";
            else
                cout<<ch[via[i][j]];
        }
    }
 
    return 0;
}

/*       ********** OUTPUT **********

Enter Number of Nodes:6

 Enter Distance between A - B : 6

 Enter Distance between A - C : 3

 Enter Distance between A - D : 7

 Enter Distance between A - E : 5

 Enter Distance between A - F : 2

 Enter Distance between B - C : 7

 Enter Distance between B - D : 4

 Enter Distance between B - E : 3

 Enter Distance between B - F : 6

 Enter Distance between C - D : 3

 Enter Distance between C - E : 2

 Enter Distance between C - F : 1

 Enter Distance between D - E : 1

 Enter Distance between D - F : 2

 Enter Distance between E - F : 3

 After Initialization
A Table
Node    Dist    Via
A       0       -1
B       6       -1
C       3       -1
D       7       -1
E       5       -1
F       2       -1
B Table
Node    Dist    Via
A       6       -1
B       0       -1
C       7       -1
D       4       -1
E       3       -1
F       6       -1
C Table
Node    Dist    Via
A       3       -1
B       7       -1
C       0       -1
D       3       -1
E       2       -1
F       1       -1
D Table
Node    Dist    Via
A       7       -1
B       4       -1
C       3       -1
D       0       -1
E       1       -1
F       2       -1
E Table
Node    Dist    Via
A       5       -1
B       3       -1
C       2       -1
D       1       -1
E       0       -1
F       3       -1
F Table
Node    Dist    Via
A       2       -1
B       6       -1
C       1       -1
D       2       -1
E       3       -1
F       0       -1

 For A
 From A
 A 0
 B 6
 C 3
 D 7
 E 5
 F 2
 From B
 A 12
 B 6
 C 13
 D 10
 E 9
 F 12
 From C
 A 6
 B 10
 C 3
 D 6
 E 5
 F 4
 From D
 A 14
 B 11
 C 10
 D 7
 E 8
 F 9
 From E
 A 10
 B 8
 C 7
 D 6
 E 5
 F 8
 From F
 A 4
 B 8
 C 3
 D 4
 E 5
 F 2

 For B
 From A
 A 6
 B 12
 C 9
 D 13
 E 11
 F 8
 From B
 A 6
 B 0
 C 7
 D 4
 E 3
 F 6
 From C
 A 10
 B 14
 C 7
 D 10
 E 9
 F 8
 From D
 A 11
 B 8
 C 7
 D 4
 E 5
 F 6
 From E
 A 8
 B 6
 C 5
 D 4
 E 3
 F 6
 From F
 A 8
 B 12
 C 7
 D 8
 E 9
 F 6

 For C
 From A
 A 3
 B 9
 C 6
 D 10
 E 8
 F 5
 From B
 A 13
 B 7
 C 14
 D 11
 E 10
 F 13
 From C
 A 3
 B 7
 C 0
 D 3
 E 2
 F 1
 From D
 A 10
 B 7
 C 6
 D 3
 E 4
 F 5
 From E
 A 7
 B 5
 C 4
 D 3
 E 2
 F 5
 From F
 A 3
 B 7
 C 2
 D 3
 E 4
 F 1

 For D
 From A
 A 7
 B 13
 C 10
 D 14
 E 12
 F 9
 From B
 A 10
 B 4
 C 11
 D 8
 E 7
 F 10
 From C
 A 6
 B 10
 C 3
 D 6
 E 5
 F 4
 From D
 A 7
 B 4
 C 3
 D 0
 E 1
 F 2
 From E
 A 6
 B 4
 C 3
 D 2
 E 1
 F 4
 From F
 A 4
 B 8
 C 3
 D 4
 E 5
 F 2

 For E
 From A
 A 5
 B 11
 C 8
 D 12
 E 10
 F 7
 From B
 A 9
 B 3
 C 10
 D 7
 E 6
 F 9
 From C
 A 5
 B 9
 C 2
 D 5
 E 4
 F 3
 From D
 A 8
 B 5
 C 4
 D 1
 E 2
 F 3
 From E
 A 5
 B 3
 C 2
 D 1
 E 0
 F 3
 From F
 A 5
 B 9
 C 4
 D 5
 E 6
 F 3

 For F
 From A
 A 2
 B 8
 C 5
 D 9
 E 7
 F 4
 From B
 A 12
 B 6
 C 13
 D 10
 E 9
 F 12
 From C
 A 4
 B 8
 C 1
 D 4
 E 3
 F 2
 From D
 A 9
 B 6
 C 5
 D 2
 E 3
 F 4
 From E
 A 8
 B 6
 C 5
 D 4
 E 3
 F 6
 From F
 A 2
 B 6
 C 1
 D 2
 E 3
 F 0
 After Update :
A Table
Node    Dist    Via
A       0       -
B       6       -
C       3       -
D       4       F
E       5       -
F       2       -
B Table
Node    Dist    Via
A       6       -
B       0       -
C       5       E
D       4       -
E       3       -
F       6       -
C Table
Node    Dist    Via
A       3       -
B       5       E
C       0       -
D       3       -
E       2       -
F       1       -
D Table
Node    Dist    Via
A       4       F
B       4       -
C       3       -
D       0       -
E       1       -
F       2       -
E Table
Node    Dist    Via
A       5       -
B       3       -
C       2       -
D       1       -
E       0       -
F       3       -
F Table
Node    Dist    Via
A       2       -
B       6       -
C       1       -
D       2       -
E       3       -
F       0       -
--------------------------------
Process exited after 76.26 seconds with return value 0
Press any key to continue . . .




*/
