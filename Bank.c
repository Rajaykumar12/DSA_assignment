#include<stdio.h>
#include<stdlib.h>

int num = 1000;
struct node{
    int accNUm;
    char name[20];
    int age;
    float amount;
    char phone[10];
    struct node *link;
};

typedef struct node *NODE;

NODE head = NULL;

void insertRear(NODE temp){
    NODE cur;
    if(head == NULL){
        head = temp;
    }
    else{
        cur = head;
        while(cur->link!=NULL){
            cur = cur->link;
        }
        cur->link = temp;
    }

}


void createAccount(){
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter name of the account holder: ");
    scanf("%s",temp->name);
    printf("Enter age: ");
    scanf("%d",&(temp->age));
    printf("Enter the initial deposit: ");
    scanf("%f",&(temp->amount));
    printf("Enter the phone number: ");
    scanf("%s",temp->phone);
    printf("-------------------");
    printf("Your account number is: %d\n",(num + 1));
    printf("-------------------");
    num = num + 1;
    temp->accNUm = num;
    temp->link = NULL;
    insertRear(temp);
}


void depositMoney(int num1){
    if(num1>num){
        printf("Invalid Account number\n");
    }
    else{
        NODE cur;
        if(head==NULL){
            printf("No accounts");
        }
        else{
            cur = head;
            while(cur!=NULL){
                if(cur->accNUm == num1){
                    float amount1;
                    printf("Enter the amount to be deposited: ");
                    scanf("%f",&amount1);
                    cur->amount = cur->amount + amount1;
                    printf("AMount Deposited\n");
                    printf("Available balance: %.2f",cur->amount);
                    printf("\n");
                }
                cur = cur->link;
            }
        }
    }
}


void withdrawMoney(int num2){
    if(num2 > num){
        printf("Invalid account\n");
    }
    else{
        NODE cur;
        if(head==NULL){
            printf("No accounts");
        }
        else{
            cur = head;
            while(cur!=NULL){
                if(cur->accNUm == num2){
                    float amount1;
                    printf("Enter the amount to be withdrawn: ");
                    scanf("%f",&amount1);
                    if(amount1 > cur->amount){
                        printf("Insufficent balance\n");
                    }
                    else{
                        cur->amount = cur->amount - amount1;
                        printf("AMount Withdrawn\n");
                        printf("Available balance: %.2f\n",cur->amount);
                    }
                }
                cur = cur->link;
            }
        }
    }
    
}


void getDetails(int num3){
    if(num3 > num){
        printf("Invalid account\n");
    }
    else{
        NODE cur;
        if(head==NULL){
            printf("No accounts\n");
        }
        else{
            cur = head;
            while(cur!=NULL){
                if(cur->accNUm == num3){
                    printf("-----Account Holder details-----\n");
                    printf("Name: %s\n",cur->name);
                    printf("Account NUmber: %d\n",cur->accNUm);
                    printf("Age: %d\n",cur->age);
                    printf("Liquidity: %.2f\n",cur->amount);
                    printf("Phone Number: %s\n",cur->phone);
                    printf("------------------------\n");
                }
                cur = cur->link;
            }
        }
    }
}

void ToFile(int num4) {
    if(num4 > num){
        printf("Invalid account\n");
    }
    else{
        FILE *file = fopen("accounts.txt", "w");
        if (file == NULL) {
            printf("Error opening file for writing\n");
            return;
        }

        NODE cur = head;
        while (cur != NULL) {
            if(cur->accNUm == num4){
                fprintf(file, "-----Account Details-----\n");
                fprintf(file, "Account Number: %d\n", cur->accNUm);
                fprintf(file, "Name: %s\n", cur->name);
                fprintf(file, "Age: %d\n", cur->age);
                fprintf(file, "Balance: %.2f\n", cur->amount);
                fprintf(file, "Phone Number: %s\n", cur->phone);
                fprintf(file, "------------------------\n\n");
            }
            cur = cur->link;
        }
        fclose(file);
        printf("Account details saved to 'accounts.txt'\n");
    }
}

void main(){
    int choice =0, num1;
    while(1){
        choice = 0;
        printf("--------------------\n");
        printf("1.Create a account\n");
        printf("2.Deposit money to the account\n");
        printf("3.Withdraw money from the account\n");
        printf("4.Get details of the account\n");
        printf("5.Save details in a file\n");
        printf("6.Exit\n");
        printf("---------------------\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : createAccount();
                break;
            case 2 :
                    printf("Enter the account number: ");
                    scanf("%d",&num1);
                    depositMoney(num1);
                break;
            case 3 :
                    printf("Enter the account number: ");
                    scanf("%d",&num1);
                    withdrawMoney(num1);
                break;
            case 4 :
                    printf("Enter the account number: ");
                    scanf("%d",&num1); 
                    getDetails(num1);
                break;
            case 5 :
                    printf("Enter the account number: ");
                    scanf("%d",&num1);
                    ToFile(num1);
                break; 
            case 6 : exit(0);
            case 7 : printf("Invalid choice\n");
        }
    }
}
