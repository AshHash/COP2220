/*  Atta Saleh
 *  COP2220
 *  program2.c
 *  An atm menu that allows the user to deposit or
 *  withdraw money from 3 different accounts.
 *  We will use a pointer in order to change those values based
 *  on which account the user chooses to deposit to/withdraw from
 *  3/22/2017
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define CREDITLIMIT 3000

// Displays the list of integer options available
//prompts for the user’s choice and sets the value of the choicePtr
void RunChoices(int *choicePtr);
//Asks if they want another transaction
//sets the value of againPtr to (y or n)
void MakeTransaction(char *againPtr);
//Asks the user which type of account they would like to access and sets the
//value of the the character accountPtr
void SelectAccount(char *accountPtr);
//Prompts the user for the amount to deposit
//and adds that value to the amount in the bank account
void AddMoney(double *moneyPtr);
//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *moneyPtr, char account);
//Displays the user’s current account balance for all three accounts
void DisplayBalance(double checking, double savings, double credit);

int main()
{
	char again;
	char *againPtr = &again;
	char account;
	char *accountPtr = &account;
	int choice;
	int *choicePtr = &choice;
	double *moneyPtr;
	double check = 650.00;
	double sav = 800.00;
	double cred = -700.00;
 	printf("Welcome to The Bank. Here are your account balances:\n\n");
 	DisplayBalance(check, sav, cred);
 	do{
 		RunChoices(choicePtr);
 		SelectAccount(accountPtr);
 		switch(*accountPtr){
 		case 'c' :
		moneyPtr = &check;			//Based on user input into SelectAccount						
		break;						//We determine which account is being accessed
		case 's' :					//and thus which account balance we need to have
		moneyPtr = &sav;			//moneyPtr point to
		break;
		case 'r' :
		moneyPtr = &cred;
		}
 		if(*choicePtr == 1){
 			AddMoney(moneyPtr);
 		}	
 		else{
 			printf("To make a Withdrawal, here are your account balances:\n\n");
 			DisplayBalance(check, sav, cred);
			RemoveMoney(moneyPtr, account);
		}
	printf("\n~ Here are your new account balances:\n\n");
	DisplayBalance(check, sav, cred);
 	MakeTransaction(againPtr);
 	}while(*againPtr != 'n');

 	printf("Thank you for using The Bank!\n");
 	return 0;
}

// Displays the list of integer options available
//prompts for the user’s choice and sets the value of the choicePtr
void RunChoices(int *choicePtr){
 	printf("Select an option: \n\n");
 	printf("(1) for DEPOSIT\n(2) for WITHDRAWAL\n");
 	printf("*** to make a TRANSFER\nselect (2) for WITHDRAWAL and\nthen (1) for DEPOSIT\n");
 	scanf("%d", choicePtr);
 	printf("You selected %d\n\n", *choicePtr);
}
//Asks if they want another transaction
//sets the value of againPtr to (y or n)
void MakeTransaction(char *againPtr){
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("*** Would you like to make another transaction (y or n)?\n");
	scanf(" %c", againPtr);
	printf("---You selected: %c\n\n", *againPtr);
	*againPtr = tolower(*againPtr);
}
//Asks the user which type of account they would like to access and sets the
//value of the the character accountPtr
void SelectAccount(char *accountPtr){
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Select the account:\n\n");
	printf("(C) for CHECKING\n(S) for SAVINGS\n(R) for CREDIT\n");
	scanf(" %c", accountPtr);
	printf("---You selected %c for account type\n\n", *accountPtr);
	*accountPtr = tolower(*accountPtr);
}
//Prompts the user for the amount to deposit
//and adds that value to the amount in the bank account
void AddMoney(double *moneyPtr){
	double depAmt;
	printf("~ making a Deposit\n\n");
	printf("Enter the amount you want to deposit: ");
	scanf("%lf", &depAmt);
	*moneyPtr += depAmt;
}
//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *moneyPtr, char account){
	double withAmt;
	printf("Enter the amount you want to withdraw: ");
	scanf("%lf", &withAmt);
	if(account == 'r' && *moneyPtr - withAmt <= -CREDITLIMIT){  //If accessing credit, we use CreditLimit
		printf("Over the limit. \n\n");
	}
	else if(account !='r' && *moneyPtr - withAmt < 0){			//If we are accessing another account
		printf("Insufficient funds. \n\n");						//The limit is 0
	}
	else{
	*moneyPtr -= withAmt;
	}
}
//Displays the user’s current account balance for all three accounts
void DisplayBalance(double checking, double savings, double credit){
	printf("CHECKING:\t\t$%f\nSAVINGS:\t\t$%f\nCREDIT:\t\t\t$%f\n\n", checking, savings, credit);
}