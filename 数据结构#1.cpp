#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem{
	char name[50];
	int quantity;
	struct ShoppingItem *next;
};
struct ShoppingItem *shoppingList=NULL;

void addItem(char itemName[],int itemQuantity){
	struct ShoppingItem *newItem=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	strcpy(newItem->name,itemName);
	newItem->quantity=itemQuantity;
	if(shoppingList==NULL){
		shoppingList=newItem;
		shoppingList->next==NULL;
		newItem->next==NULL;
	}else{
		newItem->next=shoppingList;
		shoppingList==newItem;
	}
	
	
	
}

void removeItem(char itemName[]){
	struct ShoppingItem *current=shoppingList;
	struct ShoppingItem *previous=NULL;
	
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			if(previous!=NULL){
				previous->next=current->next;
			}else{
				shoppingList=current->next;
			}
			free(current);
			break;
		}
		previous=current;
		current=current->next;
	}
}

void displayList(){
	struct ShoppingItem *current=shoppingList;
	
	printf("购物清单:\n");
	while(current!=NULL){
		printf("%s->数量:%d\n",current->name,current->quantity);
		current=current->next;
	}
}

void updateQuantity(char itemName[],int newItemQuantity){
	struct ShoppingItem *current=shoppingList;
	
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			current->quantity=newItemQuantity;
			break;
		}
		current=current->next;
	}
}

void clearList(){
	while(shoppingList!=NULL){
		struct ShoppingItem *temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}

int totalQuantity(){
	struct ShoppingItem *current=shoppingList;
	int total=0;
	
	while(current!=NULL){
		total++;
		current=current->next;
	}
	
	return total;
}

void findItem(char itemName[]){
	struct ShoppingItem *current=shoppingList;
	
	printf("查找商品\"%s\":\n",itemName);
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			printf("%s-数量:%d\n",current->name,current->quantity);
			return;
		}
		current=current->next;
	}
	
	printf("未找到商品\"%s\"。\n",itemName);
}

void sortList(){
	struct ShoppingItem *current=shoppingList;
	struct ShoppingItem *nextItem=NULL;
	char tempName[50];
	int tempQuantity;
	
	while(current!=NULL){
		nextItem=current->next;
		
		while(nextItem!=NULL){
			if(strcmp(current->name,nextItem->name)>0){
				strcpy(tempName,current->name);
				strcpy(current->name,nextItem->name);
				strcpy(nextItem->name,tempName);
				tempQuantity=current->quantity;
				current->quantity=nextItem->quantity;
				nextItem->quantity=tempQuantity;
			}
			nextItem=nextItem->next;
		}
		current=current->next;
	}
}

void mergeLists(struct ShoppingItem **list1,struct ShoppingItem **list2){
	struct ShoppingItem *current=*list1;
	//补充循环语句
	
	;
	current->next=*list2; 
	*list2=NULL;
}

void deleteItem(char itemName[],int deleteALL){
	struct ShoppingItem *current=shoppingList;
	struct ShoppingItem *prev=NULL;
	
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			if(prev==NULL){
				struct ShoppingItem *temp=shoppingList;
				shoppingList=shoppingList->next;
				free(temp);
				if(!deleteALL)break;
			}else{
				prev=current;
				free(current);
				current=prev->next;
				if(!deleteALL)break;
			}
		}else{
			prev=current;
			current=current->next;
		}
	}
}

int main(void)
{
	struct ShoppingItem *newItem=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	scanf("%s",newItem->name);
	scanf("%d",&newItem->quantity);
	if(shoppingList==NULL){
		shoppingList=newItem;
		shoppingList->next==NULL;
		newItem->next==NULL;
	}else{
		newItem->next=shoppingList;
		shoppingList==newItem;
	}
	
	return 0;
	
	
}

