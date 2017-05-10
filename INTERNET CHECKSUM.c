#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
 int dectobinary(int x)
  {
 	
	 int n,result=0,i=0;
	
		 	 while(x!=0){
		
					        n = x % 2;
							result=result+n*pow(10,i);
					        x = x / 2;
							i++;
		    			}
      return(result);
 
   }
   
   /*int bintodecimal1(int x)
   {
	   	int rem,decimal_val=0,base=1;
		   	 
				while (x > 0)
			    {
			        rem = x % 10;
			        decimal_val = decimal_val + rem * base;
			        x = x / 10 ;
			        base = base * 2;
			    }
		    return(decimal_val);
   } */
 char checksum[10],checksum1[10];
//binary[0]='\0';
long  bintodecimal(long int x)
   {
	   long	int rem,decimal_val=0,base=1;
		   	 
				while (x > 0)
			    {
			        rem = x % 10;
			        decimal_val = decimal_val + rem * base;
			        x = x / 10 ;
			        base = base * 2;
			    }
		    return(decimal_val);
   }
 long hextodecimal(char hex[])
{

     long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    /*
     * Reads hexadecimal number from user
     */
   
    
    /* Finds the length of total number of hex digit */
    len = strlen(hex); 
    len--;
    
    /*
     * Converts the hexadecimal number to decimal number
     * using algorithm decimal = decimal + (hex[i] * 16 ^ digit)
     */
    for(i=0; hex[i]!='\0'; i++)
    {
        /*
         * Finds the decimal each equivalent hexadecimal digit
         */
        switch(hex[i])
        {
            case '0':
                val = 0;
                break;
            case '1':
                val = 1;
                break;
            case '2':
                val = 2;
                break;
            case '3':
                val = 3;
                break;
            case '4':
                val = 4;
                break;
            case '5':
                val = 5;
                break;
            case '6':
                val = 6;
                break;
            case '7':
                val = 7;
                break;
            case '8':
                val = 8;
                break;
            case '9':
                val = 9;
                break;
            case 'a':
            case 'A':
                val = 10;
                break;
            case 'b':
            case 'B':
                val = 11;
                break;
            case 'c':
            case 'C':
                val = 12;
                break;
            case 'd':
            case 'D':
                val = 13;
                break;
            case 'e':
            case 'E':
                val = 14;
                break;
            case 'f':
            case 'F':
                val = 15;
                break;
        }

        decimal += val * pow(16, len);
        len--;
    }

   // printf("\nHexadecimal number = %s\n", hex);
   
    return (decimal);

}
void dectohexa(char hexadecimalNumber[],long int decimalNumber )
{
	long int remainder,quotient;
    int i=1,j,temp,c;
    char hexadecimalNumber1[100];

    quotient = decimalNumber;

    while(quotient!=0){
         temp = quotient % 16;

      //To convert integer into character
      if( temp < 10)
           temp =temp + 48;
      else
         temp = temp + 55;

      hexadecimalNumber1[i++]= temp;
      quotient = quotient / 16;
  }

    
    for(j = i -1,c=0 ;j> 0;j--,c++)
      hexadecimalNumber[c]=hexadecimalNumber1[j];

}

void hexcomplement(char checksum[] ,char wrapsum[])
{ int i=0;

		while(wrapsum[i]!='\0')
		{
			switch(wrapsum[i])
			{
					
		
			case '0' : strcat(checksum,"F");
				break;
			case '1' : strcat(checksum,"E");
				break;
			case '2' : strcat(checksum,"D");
				break;
			case '3' : strcat(checksum,"C");
				break;
			case '4' : strcat(checksum,"B");
				break;
			case '5' : strcat(checksum,"A");
				break;
			case '6' : strcat(checksum,"9");
				break;
			case '7' : strcat(checksum,"8");
				break;
			case '8' : strcat(checksum,"7");
				break;
			case '9' : strcat(checksum,"6");
				break;
			case 'A' :
			case 'a' : strcat(checksum,"5");
				break;
			case 'B' :
			case 'b' : strcat(checksum,"4");
				break;
			case 'C' :
			case 'c' : strcat(checksum,"3");
				break;
			case 'D' :
			case 'd' : strcat(checksum,"2");
				break;
			case 'E' :
			case 'e' : strcat(checksum,"1");
				break;
			case 'F' :
			case 'f' :  strcat(checksum,"0");
				break;
			
			default : printf("\nInvalid hexadecimal digit %c",wrapsum[i]);
		
			}
			i++;
		}
		checksum[i]='\0';
			
}

int sender(int b[10],int k,int len)
 {
 	 int checksum,sum=0,i,n,wrapsum,c;
        	printf("\n****SENDER****\n");
     
			for(i=0;i<len;i++)
			      		sum+=b[i];
			      		printf("SUM IS: %d",sum);
			                     
			    	c=dectobinary(sum);
			    //	printf("\n c=%d",c);
			    	n=c/(pow(10,k));
			    	c-=n*pow(10,k);
			    //		printf("\n n=%d",n);
			    //		printf("\n c=%d",c);
			    	wrapsum=(bintodecimal(c)+bintodecimal(n));
			    	printf("\nwrapsum=%d",dectobinary(wrapsum));
			    //	checksum=onecomplement(checksum);
			    	printf("\nSENDER's WRAPSUMS IS:%d",wrapsum);
			    	checksum=pow(2,k)-1-wrapsum;   //ons complement.
			    	printf("\nSENDER's CHECKSUM IS:%d",checksum);
			    	return checksum;
			}
			
	int receiver(int c[10],int k,int len,int scheck)
{
		int checksum,sum=0,i,n,wrapsum,b;
     	printf("\n\n****RECEIVER****\n");
     	
		 for(i=0;i<len;i++)
      		sum+=c[i];
      		
			  sum+=scheck;
       	printf("SUM IS: %d",sum);
                     
    	b=dectobinary(sum);
    	printf("\nb=%d",b);
    	n=b/(pow(10,k));
    	printf("\n n=%d",n);
    	b-=n*pow(10,k);
    	
    		
    	wrapsum=(bintodecimal(b)+bintodecimal(n));
    	printf("\n wrapsom=%d",dectobinary(wrapsum));
    	//checksum=onecomplement(checksum);
    	printf("\nSENDER's WRAPSUMS IS:%d",wrapsum);
    	checksum=pow(2,k)-1-wrapsum;
    	printf("\nSENDER's CHECKSUM IS:%d",checksum);
    	return checksum;
  }		
 

int main()
{	
	int ch,n,a[50],rapsum,i,rcheck,len,j,flag,checksumd;
	long int a1[50],sum=0,wrapsumint=0,checksumint=0,binaryint;
	char str[10][10],strsum[100],a2[10],b[10],wrapsum[10],wrapsum1[10];
	
	printf("\n *******************Internet check sum*************\n");
	printf("\n 1.DECIMAL \t2 HEXADECIMAL");
	printf("\n ENTER YOUR CHOICE:");
	
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:		
			
					printf("\nENTER THE SIZE OF THE Array:");
				     	scanf("%d",&n);
				     	getchar();
				     	printf("\nENTER THE ELEMENTS OF THE ARRAY:\n");
				     	for(i=0;i<n;i++)
				    	scanf("%d",&a[i]);
				    	do{
						
				printf("\n ************DECIMAL INTERNET CHECKSUM************");
				printf("\n1. SENDER 2.RECIEVER");
					printf("\n ENTER YOUR CHOICE:");
					scanf("%d",&ch);
					if(ch==1)
					{
						sender(a,4,n);
					}
					else if(ch==2)
					{
						printf("\n WHAT  IS SENDERS CHECKSUM:");
						scanf("%d",&checksumd);
						rcheck=receiver(a,4,n,checksumd);
						
						if(rcheck==0)
      		printf("\n\nNO ERROR IN TRANSMISSION\n\n");
    	else
      		printf("\n\nERROR DETECTED");
               getch();
						
					}
					getchar();
					printf("\n Do to you exit(0)(y/n):");
					char cha1=getchar();
					if(cha1=='Y'||cha1=='y')
					{
						return(0);
					}
					
				}while(ch==2 || ch==1);

				break;
		case 2:		
							printf("\n ENTER THE SIZE OF THE ARRAY:");
					scanf("%d",&n);
					getchar();
					printf("\n ENTER THE ELEMENT: \n");
					
					for(i=0;i<n;i++)
					{	//printf("\ni=%d\n",i);
						gets(str[i]);
						//getchar();
						
					}
					for(i=0;i<n;i++)
						{
							sum+=hextodecimal(str[i]);	
						}
						
					dectohexa(strsum,sum);
					do{
						
					
				printf("\n **********HEXADECIMAL INTERNET CHECKSUM************");
				printf("\n1. SENDER 2.RECIEVER");
					printf("\n ENTER YOUR CHOICE:");
					scanf("%d",&ch);
					getchar();
					if(ch==1)
					{	
										
						
						printf("\n THE SUM IN DECIMAL IS:%ld",sum);
						printf("\n Its Hexa decimal SUM is :%s",strsum);
						len=strlen(strsum)-1;
						
						for(i=len,j=3;j>=0;j--)
					      a2[j]=strsum[i--];
					      a2[4]='\0';
					      j=0;
					    for(i=len-4;i>=0;i--)
						{	b[i]=strsum[i]; j++;  }
							b[j]='\0';
						    
					    printf("\n The A=%s",a2);
					    printf("\n The B=%s",b);
					    wrapsumint=hextodecimal(a2)+hextodecimal(b);
					    dectohexa(wrapsum,wrapsumint);
					    printf("\n WRAPSUM=%s",wrapsum);
					    hexcomplement(checksum,wrapsum);
					   // hexcomplement(binary,wrapsum);
					    //printf("\n BINARY:%s",binary);
					    	printf("\n CHECKSUM IS:%s",checksum);
					}
					else if(ch==2)
					{
						    //decryption
						    long int sum1;
						    char strsum1[30];
						   
						    printf("\n ENTER THE SENDERS CHECKSUM:");
						    gets(checksum);
						    
						    sum1=hextodecimal(checksum)+hextodecimal(strsum);
						    dectohexa(strsum1,sum1);
						    printf("\n SUM IN HEXA IS:%s \n SUM IN DECIMAL=%ld",strsum1,sum1);
						    
							len=strlen(strsum1)-1;
							
							for(i=len,j=3;j>=0;j--)
						      a2[j]=strsum1[i--];
						      a2[4]='\0';
						      j=0;
						    for(i=len-4;i>=0;i--)
							{	b[i]=strsum1[i]; j++;  }
								b[j]='\0';
							    
						    printf("\n The A=%s",a2);
						    printf("\n The B=%s",b);
						    wrapsumint=hextodecimal(a2)+hextodecimal(b);
						    dectohexa(wrapsum1,wrapsumint);
						    printf("\n WRAPSUM=%s",wrapsum1);
						     hexcomplement(checksum1,wrapsum1);
						     printf("\n CHECKSUM=%s",checksum1);
						     i=0;
						     flag=0;
						    
						     if(strcmp(checksum1,"0000")==0)
						     {
						     	printf("\n\nNO ERROR IN TRANSMISSION\n\n");
						     	
							 }
							 else if(strcmp(checksum1,"00")==0)
							 {
							 	printf("\n\nNO ERROR IN TRANSMISSION\n\n");
							 }
							 else if(strcmp(checksum1,"000")==0)
							 {
							 	printf("\n\nNO ERROR IN TRANSMISSION\n\n");
							 }
							 else{
							 	printf("\n\nERROR DETECTED");
							 }
					}
					getchar();
					printf("\n Do to you exit(0)(y/n):");
					char cha2=getchar();
					if(cha2=='Y'||cha2=='y')
					{
						return(0);
					}
			
		}while(ch==2||ch==1);
				break;
		default: return(0);
				
	}
}
	

