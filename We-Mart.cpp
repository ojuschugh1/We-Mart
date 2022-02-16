
#include <stdio.h> #include <stdlib.h> #include <string.h>

char CustomerName[20]; long long int CustomerPhone; int totalCustomer;

struct item
{

char name[20]; int id;
int price;
int quantity; int discount;
struct item *next;
} * head;


void Insert_Items()
{

struct item *temp;
temp = (struct item*)malloc(sizeof(struct item));



printf("\t\tEnter the Item Name: "); scanf("%s", temp->name);
printf("\n");


int flag; do
{

flag = 0;
printf("\t\tEnter the Item ID: "); scanf("%d", &temp->id);
printf("\n");


struct item *p = head; while (p != NULL)
{

if (p->id == temp->id)
{

flag = 1; break;
}

p = p->next;
}

if (flag)
{



printf("\t\tId=%d with Item is Already in the List.", temp->id); printf("\n");
}

} while (flag == 1);


printf("\t\tEnter the Item Price: "); scanf("%d", &temp->price); printf("\n");
printf("\t\tEnter the Item Quantity: "); scanf("%d", &temp->quantity); printf("\n");
printf("\t\tEnter the Item Discount: "); scanf("%d", &temp->discount); printf("\n");
printf("\n");


temp->next = NULL; if (head == NULL)
{

head = temp;
}

else
{

struct item *t;



t = head;
while (t->next != NULL)
{

t = t->next;
}

t->next = temp;
}
}


void ShowItems()
{

struct item *temp; temp = head;
if (temp == NULL)
{

printf("List is Empty! Please Add the item first.\n");
}

else
{

printf("\n");
printf("\t\tThe list of the items are as follows\n");

printf("=============================================================
============================\n");



printf("	%20s	%5s	%5s	%10s	%10s\n", "NAME", "ID", "PRICE", "QUANTITY", "DISCOUNT");


while (temp != NULL)
{

printf("
 	|	|	|	| 	
 	\n");
printf("	%20s%s%5d%s%5d%s%10d%s%10d %\n", temp->name, " | ", temp->id, " | ", temp->price, " | ", temp->quantity, " | ", temp->discount);
temp = temp->next;

}

printf("=============================================================
============================\n");
printf("\n");

}
}


void DeleteItemById()
{

struct item *temp; struct item *pre; int id;

if (head == NULL)



{
printf("\n");
printf("\t\tList is Empty! Please Add the item first.\n\n"); printf("\n");
return;
}


ShowItems();
printf("\t\tEnter the id of item which you want to Remove:- "); scanf("%d", &id);

int flag = 0; pre = NULL; temp = head;
while (temp != NULL)
{

if (temp->id == id)
{

flag = 1; break;
}

pre = temp;
temp = temp->next;
}



if (flag == 0)
{

printf("\t\tItem with %d id is not in the List.\n", id);
}

else
{

printf("\t\tItem with id=%d Name = %s is Removed.\n", temp->id, temp-
>name);
if (temp == head)
{

head = temp->next;
}

else
{

pre->next = temp->next;
}

temp->next = NULL; free(temp);
}

ShowItems();
}


struct item *FindItemById()
{

int id;



printf("\t\tEnter the id of item:- "); scanf("%d", &id);

struct item *t; t = head;
while (t != NULL)
{

if (t->id == id)
{

printf("\t\t\t\t	THE DETAILS OF ITEM \n");

printf("\t\t\t\t		\n"); printf("\t\t\t\t	NAME = %s\n", t->name);

printf("\t\t\t\t		\n"); printf("\t\t\t\t	ID = %d\n", t->id);

printf("\t\t\t\t		\n"); printf("\t\t\t\t	PRICE = %d\n", t->price);

printf("\t\t\t\t	\n"); printf("\t\t\t\tAVAILABLE QUANTITY = %d\n", t->quantity);

printf("\t\t\t\t		\n"); printf("\t\t\t\t	DISCOUNT = %d\n", t->discount);




printf("\t\t\t\t	\n"); return t;


}
t = t->next;
}

printf("\n");
printf("\n");
printf("\t\tNo item found with id =%d.\n", id); printf("\n");
return NULL;
}


void ModifyItem()
{

struct item *temp; temp = FindItemById(); if (temp != NULL)
{

printf("\n");
printf("\t\tEnter the New Name of Item:- "); scanf("%s", temp->name);
printf("\n");
printf("\t\tEnter the New ID of Item:- ");



scanf("%d", &temp->id);
printf("\n");
printf("\t\tEnter the New Price of Item:- "); scanf("%d", &temp->price);
printf("\n");
printf("\t\tEnter the New Quantity of Item:- "); scanf("%d", &temp->quantity);
printf("\n");
printf("\t\tEnter the New Discount on item:- "); scanf("%d", &temp->discount);
printf("\n");
printf("\n");
printf("\t\tItem is Modify successfully.\n"); printf("\n");
printf("\n");
}
}


struct purchaseItem
{

char *name; int price;
int quantity; int discount;



float total;
struct purchaseItem *next;
};

struct purchaseItem *purchaseItemHead; struct purchaseItem *last;
void addItemToCart(struct item *t, int quantity)
{

struct purchaseItem *b;
b = (struct purchaseItem *)malloc(sizeof(struct purchaseItem));


b->discount = t->discount; b->name = t->name;
b->price = t->price;
b->quantity = quantity;


b->total = ((b->price * (100 - b->discount)) / 100) * b->quantity; b->next = NULL;

if (purchaseItemHead == NULL)
{

purchaseItemHead = b; last = b;
}

else



{
last->next = b; last = b;
}
}

void printBill()
{

float subTotal = 0; struct purchaseItem *t; t = purchaseItemHead;



printf("=============================================================
===========================\n");
printf("\n	BILL\n");
printf("	NAME:- %s\n", CustomerName);
printf("	PHONE NUMBER:- %lld\n", CustomerPhone);

printf("=============================================================
===========================\n");
printf("	%20s	%5s	%10s	%10s	%8s\n", "NAME", "PRICE", "QUANTITY", "DISCOUNT", "AMOUNT");
while (t != NULL)
{



printf("
 	|	|	|	| 	
 	\n");
printf("	%20s%s%5d%s%10d%s%10d%s%5.2f\n", t->name, " | ", t->price, "
| ", t->quantity, " | ", t->discount, " | ", t->total); subTotal += t->total;
t = t->next;

}

printf("=============================================================
===========================\n");
printf("%68s %5.2f\n", "TOTAL : ", subTotal);

printf("=============================================================
===========================\n");
}


struct queue
{

char name[20];
long long int phoneNumber; struct purchaseItem *bill; struct queue *next;
};

struct queue *front; struct queue *end;





void pushQueue(char *n, long int pn, struct purchaseItem *b)
{

struct queue *t;
t = (struct queue *)malloc(sizeof(struct queue)); t->bill = b;
t->phoneNumber = pn; strcpy(t->name, n);
t->next = NULL;


if (front == NULL)
{

front = t; end = t;
}

else
{

end->next = t; end = t;
}

totalCustomer++;
}


void displayQueue()



{
if (front == NULL)
{

printf("\n");
printf("\t\tQueue is empty.\n"); return;
}


struct queue *p; p = front;
while (p != NULL)
{

printf("\n"); printf("\t\t%10s", p->name); p = p->next;
printf("\n");
}

printf("\n");
}


void adminFeature()
{

int choice = 0; while (choice != 9)



{
printf("\n");
printf("\t\t1.ADD ITEMS IN YOUR SHOPPING CART");
printf("\n");
printf("\n");
printf("\t\t2.REMOVE ITEMS FROM YOUR SHOPPING CART");
printf("\n");
printf("\n"); printf("\t\t3.SHOW CART"); printf("\n");
printf("\n");
printf("\t\t4.SEARCH ITEM IN CART"); printf("\n");
printf("\n"); printf("\t\t5.MODIFY CART"); printf("\n");
printf("\n"); printf("\t\t6.CUSTOMER CART"); printf("\n");
printf("\n");
printf("\t\t7.GO TO THE BACK"); printf("\n");
printf("\n"); printf("\t\t8.EXIT");



printf("\n");
printf("\n");
printf("\t\tEnter your choice from 1 to 8:-"); scanf("%d", &choice);
printf("\n");


int c;
switch (choice)
{
case 1:
Insert_Items(); break;
case 2:
DeleteItemById(); break;
case 3:
ShowItems(); break;
case 4:
FindItemById(); break;
case 5:
ModifyItem(); break;



case 6:
displayQueue(); case 7:
choice = 9; break;
case 8:
printf("\n\n=====================================\n");
printf("	THANK YOU\n"); printf("=====================================\n");
exit(0); break;

default:
printf("\t\tPlease Enter The valid choice");

}
}
}





void customerFeatures()
{

int id, q, choice, trollyNo;


struct item *t;





do
{

ShowItems();


t = FindItemById();


if (t != NULL)
{

do
{

if (t->quantity == 0)
{

printf("\n");
printf("\t\tThis Item is not available.\n"); break;
}

printf("\n");
printf("\t\tEnter the quantity of item: "); scanf("%d", &q);
if (q > t->quantity || q < 1)
{

printf("\t\tQuantity should be in range of 1 to %d.\n", t->quantity);
}



} while (q > t->quantity || q < 1); if (t->quantity != 0)
{

t->quantity -= q; addItemToCart(t, q);
}
}


printf("\t\t1.KEEP ON SHOPPING"); printf("\n");
printf("\t\t2.END THE SHOPPING"); printf("\n");
printf("\n");
printf("\t\tEnter Your Choice from 1 and 2:- "); scanf("%d", &choice);
} while (choice != 2); printf("\n");
printf("\t\tEnter your Name:- "); scanf("%s", CustomerName); printf("\n");
printf("\t\tEnter Your Phone Number:- "); scanf("%lld", &CustomerPhone); printf("\n");
pushQueue(CustomerName, CustomerPhone, purchaseItemHead);





printBill(); purchaseItemHead = NULL; last = NULL;




}


int main()
{

int choice;


printf("\n"); printf("\t\t\t===============================\n");
printf("\t\t\t\tWELCOME TO WE-MART \n"); printf("\t\t\t===============================\n");
printf("\n"); do
{

printf("\t\t1.ADMIN"); printf("\n");
printf("\n"); printf("\t\t2.CUSTOMER"); printf("\n");



printf("\n");
printf("\t\t3.EXIT THE STORE"); printf("\n");
printf("\n");
printf("\t\tEnter your choice-"); scanf("%d", &choice); printf("\n");
int f;
switch (choice)
{
case 1:
adminFeature(); break;
case 2:
f = 0;
if (head == NULL)
{

f = 1;
printf("\t\tThere are no Items in the Mall.\n");
printf("\t\tPlease Go to Administrator section and Add the Items.\n");
}

if (f == 0 )
{

printf("\t\tWELCOME");



printf("\n");
printf("\t\tWhat would you like to order:"); printf("\n");
customerFeatures();
}

break; case 3:
printf("\n"); printf("\t\t\t\tTHANK YOU\n"); break;
default:
printf("\t\tPlease Enter the Valid Choice.\n");

}


} while (choice != 3);


return 0;
}
