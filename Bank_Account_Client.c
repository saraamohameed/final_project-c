#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_Account_Admin.h"
#include "Bank_Account_Client.h"
#include "STD_Types.h"

extern int counter ;
extern user_t arr[200] ;


void Client_Window(){
 int id_check ;
   int id_from ;
   int id_to ;
   double money_transfer ;
   double money_Get ;
   double money_Deposit ; 
    int opt_2;
	
	system("cls");
    
    printf("\nWhat do you want to do?");
    printf("\n\n1.Make Transaction");
    printf("\n2.Change Account Password");
    printf("\n3.Get Cash");
    printf("\n4.Deposit in Account");
    printf("\n5.Return to main menu");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt_2);
	switch(opt_2){
		case 1:
			 printf("please enter the id of the user who the money will transfer from his cash  :");
        scanf("%i",&id_from);
        printf("please enter the id of the user who the money will transfer to his cash  :");
        scanf("%i",&id_to);
		
   L2:  printf("please enter the money which will be transfered  :");
        scanf("%lf",&money_transfer);
        break;

		case 2:
		printf("please enter the id of the user :");
        scanf("%i",&id_check);
			Change_Account_Password(id_check);
        break;

		case 3:
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
		case 4:
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
        break;
		case 5:
			printf("\n*****Thank You For Using Our System*****");

		default:
			printf("\nEnter the correct choice!!!");
	
}
}

void Change_Account_Password(int user_id){
	
	int i ;
    for(i=0;i<=counter;i++)
    {
      if(user_id==arr[i].Bank_Account_ID)
      {
    printf("please enter the password :");
    fflush(stdin);
   scanf("password %d ",&arr[i].pass);

}
	}
}