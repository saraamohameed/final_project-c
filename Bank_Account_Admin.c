#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_Account_Admin.h"
#include "Bank_Account_Client.h"
#include "STD_Types.h"


extern int counter ;
extern user_t arr[100] ;

void Admin_Window(){ 

int opt_1;

	printf("\nWhat do you want to do?");
    printf("\n\n1.Create New Account");
    printf("\n2.Open Existing Account");
    printf("\n3.Exit System");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt_1);
	switch(opt_1){
		case 1:
		 if(counter>=200)
        {
            printf("the maximum number of user is 200 so you can't add anymore\n");
            break ;
        }
			Create_Account();

			break;

		case 2:
			Open_Existing_Account();

			break;

		case 3:
			printf("\n*****Thank You For Using Our System*****");

			//Exit(1);
		default:
			printf("\nEnter the correct choice!!!");
	}
}


void Create_Account(void){
// asked to enter the following parameters
// 1- Full Name
// 2- Full Address
// 3- Age
// 4- National ID
// 5- Guardian National ID
// 6- Balance
u64 pass;
user_t new_user ;
	
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
	
    printf("\n\n Enter your Full Name  %i:",counter+1);
    fflush(stdin);
    gets(new_user.Full_Name);

	printf("\n\n Enter your Full Address %i:",counter+1);
    fflush(stdin);
    gets(new_user.Full_Address);


     printf("\n\n Enter your Bank Account ID %i:",counter+1);
    scanf("%i",&(new_user.Bank_Account_ID));



  label:  printf("\n\n please enter the Balance of the user %i:",counter+1);
    scanf("%lf",&(new_user.Balance));
    if(new_user.Balance<0)
    {
      printf(" \n\n the Balance money should be positive number and greater than or equal zero  \n");
      goto label ;
    }


 labe2:  printf("\n\n please enter the National_ID of the user %i:",counter+1);
    fflush(stdin);
     gets(new_user.National_ID);
    if(new_user.National_ID[14] =! '\0')
    {
      printf("\n\n The National_ID should be 14 number Pleas Try Again \n");
      //goto labe2 ;
    }

printf("\n\n Enter your Age %d:",counter+1);
    fflush(stdin);
    scanf("%d",&new_user.Age);
	
	 if(new_user.Age <21)
    {
      labe3: printf("\n\n Enter your Guardian National ID  \n");
	      fflush(stdin);
		  
     gets(new_user.Guardian_National_ID);
       if(new_user.Guardian_National_ID[14]=! '\0')
    {
      printf("The Guardian National ID should be 14 number Pleas Try Again \n");
      //goto labe3;
    }
    }
	
	printf("******************\n");
	fflush(stdin);
	
    pass=generatePassword();
	printf("\n\n paasword %d",pass);

	fflush(stdin);
    arr[counter]=new_user;
	
    counter++ ;
	printf("\n\n Account Successfully \n");
	fflush(stdin);
}

u64 generatePassword(){
	u64 n = rand(); // the rand function generates only 4 bytes so
	n = (n<<32) | rand(); // I used it twice to generate an 8 byte random num.
    return n;
}



void Open_Existing_Account(){
    //Existing Account
		//1- Make Transaction
		//2- Get Cash
		//3- Deposit in Account
		//4- Change Account Status
		//5- Return to main menu

		int opt_3;
		 char choice ;
   int id_check ;
   int id_from ;
   int id_to ;
   double money_transfer ;
   double money_Get ;
   double money_Deposit ;
   
		system("cls");

    L6:     printf("\nWhat do you want to do?");

			printf("\n\n1.Make Transaction");
			printf("\n2.Get Cash");
			printf("\n3.Deposit in Account");
			printf("\n4.Change Account Status");
			printf("\n5.Return to main menu");
			printf("\n\nYour choice:\t");

			scanf("%d",&opt_3);
		switch(opt_3)
		{
			
			case 1:
			    printf("please enter the id of the user who the money will transfer from his cash  :");
        scanf("%i",&id_from);
        printf("please enter the id of the user who the money will transfer to his cash  :");
        scanf("%i",&id_to);
		
   L2:  printf("please enter the money which will be transfered  :");
        scanf("%lf",&money_transfer);

         if(money_transfer<=0)
        {
            printf("the money transfered should be positive number and greater than zero \n");
            goto L2 ;
        }
        Make_Transaction(id_from,id_to,money_transfer);
        break;
			
		case 2: 
	     printf("please enter the id of the user :");
        scanf("%i",&id_check);
   L3:  printf("please enter the money which will be Get :");
         scanf("%lf",&money_Get);

         if(money_Get <=0)
        {
             printf("the money Get should be positive number and greater than zero \n");
            // goto L3 ;
        }
		Get_Cash(id_check,money_Get);
		break;
			
		case 3:
		printf("please enter the id of the user :");
        scanf("%i",&id_check);
    L4:  printf("please enter the money which will be Deposit :");
        scanf("%lf",&money_Deposit);

         if(money_Deposit<=0)
        {
            printf("the money Deposi should be positive number and greater than zero \n");
            goto L4 ;
			
			Deposit_in_Account(id_check,money_Deposit);
			break;
		}
			// case 4:Change_Account_Status();
			// break;
			
			// case 5:
			// printf("\n*****Thank You For Using Our System*****");
        
		 // goto L6;
		// default:
			// printf("\nEnter the correct choice!!!");
	// }
	
}
}

void Make_Transaction(int source_id ,int destination_id,double money){
         int i ;
         int index_from=-1 ;
         int index_to=-1 ;
     L1:    for(i=0;i<=counter;i++)
         {
          if(arr[i].Bank_Account_ID==source_id)
          {
              index_from=i ;
          }
          else if (arr[i].Bank_Account_ID==destination_id)
          {
              index_to=i ;
          }
          if((index_from!=-1)&&(index_to!=-1))
          {
             break;
          }

        }
         if((index_from==-1)||(index_to==-1))
         {
             printf("please enter valid id\n");

         }
         if(money>arr[index_from].Balance)
        {
            printf("the money transfered is greater than your Balance\n");
            printf("please enter the money transfered again and take care :");
            scanf("%lf",&money);
            //goto L1;
        }

         arr[index_from].Balance=arr[index_from].Balance-money;
         arr[index_to].Balance=arr[index_to].Balance+money;
         }
	
void Get_Cash(int user_id, double money){
	int i ;
         int index_from=-1 ;
     L1:    for(i=0;i<=counter;i++)
         {
          if(arr[i].Bank_Account_ID==user_id)
          {
              index_from=i ;
          }
         
         }

         if(money>arr[index_from].Balance)
        {
            printf("the money cash is greater than your Balance\n");
            printf("please enter the money get again and take care :");
            scanf("%lf",&money);
            //goto L1;
        }

         arr[index_from].Balance=arr[index_from].Balance-money;
        printf("\n\n please enter the Balance :%i\n\n",arr[index_from].Balance );
         }
	
void Deposit_in_Account(int user_id, double money){
	int i ;
         int index_from=-1 ;
     L1:    for(i=0;i<=counter;i++)
         {
          if(arr[i].Bank_Account_ID==user_id)
          {
              index_from=i ;
          }
         
         }
            printf("please enter the Deposit Money :");
            scanf("%lf",&money);

         arr[index_from].Balance = arr[index_from].Balance + money;
		 
        printf("\n\n please enter the Balance :%i\n\n",arr[index_from].Balance );
}

void Change_Account_Status(){
	int choice_1;
	printf("\n\t\t\t Enter the Bank Account Status you want for: ");
			printf("\n\n1.Set Account to Active State");
			printf("\n2.Set Account to Restricted State");
			printf("\n3.Set Account to Closed");
			printf("\n\nYour choice:\t");
			scanf("%d",&choice_1);
			_flushall();

			switch(choice_1)
		{
			case 1:printf("\n Your Account to In Active State");
                 //fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			case 2:printf("\n Your Account to In Restricted State");
                //fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			case 3:printf("Your Account Closed");
			//fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			default:
			break;
		}
}


