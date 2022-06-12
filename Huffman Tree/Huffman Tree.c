#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char harf;
	int frekans;
	struct node *next;
	struct node *prev;
	struct node *left;
	struct node *right;
};

struct node* listeOlustur(char* str){
	struct node *ilknode, *yeninode, *eskinode, *dongunode;
	int i=0, j,k;
	while(*(str+i)!= '\0' ){
		if(i==0){
			ilknode = (struct node*) malloc (sizeof(struct node));
			ilknode->harf = str[i];
			ilknode->frekans=1;
			ilknode->next=NULL;
			ilknode->prev=NULL;
			ilknode->left=NULL;
			ilknode->right=NULL;
			eskinode=ilknode;
    	}
    	else{
    		k=0;
    		for(j=i-1;j>=0;j--){
    			if(str[i]==str[j]){
    				k++;
				}
			}
			if(k==0){
			yeninode= (struct node*) malloc (sizeof(struct node));
    		yeninode->harf= str[i];
    		yeninode->frekans=1;
    		yeninode->next=NULL;
    		yeninode->prev=eskinode;
    		yeninode->left=NULL;
    		yeninode->right=NULL;
    		eskinode->next=yeninode;
    		eskinode=yeninode;
    		}
    		else{
				dongunode=ilknode;
    			while(dongunode!=NULL){
    				if(str[i]==dongunode->harf){
    					dongunode->frekans++;
					}
					dongunode=dongunode->next;
				}
			}
    	}
		i++; 
	}
	dongunode=ilknode;
	while(dongunode!=NULL){
    	printf("%c = %d\n",dongunode->harf,dongunode->frekans);
		dongunode=dongunode->next;
	}
	printf("\n");
	printf("Insertion Sorted Linked List\n");			
	return ilknode;
}


struct node *insertionSort(struct node *koknode){
	
	struct node *dongunode, *icdongunode;
	char harftmp;
	int freqtmp;
	dongunode=koknode->next;
	while(dongunode!=NULL){
		icdongunode=dongunode->prev;

		while(icdongunode!=NULL && dongunode->frekans < icdongunode->frekans){
			harftmp=icdongunode->next->harf;
			icdongunode->next->harf=icdongunode->harf;
			icdongunode->harf=harftmp;
			
			freqtmp=icdongunode->next->frekans;
			icdongunode->next->frekans=icdongunode->frekans;
			icdongunode->frekans=freqtmp;
			
			dongunode=icdongunode;
			icdongunode=icdongunode->prev;
		}
		dongunode=dongunode->next;
	}
	printf("\n");
	dongunode=koknode;
	while(dongunode!=NULL){
		
    	printf("%c = %d\n",dongunode->harf,dongunode->frekans);
		dongunode=dongunode->next;
	}
	
	return koknode;
}

struct node *huffmann(struct node *koknode){
	struct node *dongunode=koknode, *yeninode;
	int i=0, j ,k=0;
	while(dongunode!=NULL){
		dongunode=dongunode->next;
		i++;
	}
	for(j=0;j<i-1;j++){
		yeninode= (struct node*) malloc (sizeof(struct node));
		yeninode->frekans=koknode->frekans+koknode->next->frekans;
		yeninode->left=koknode;
		yeninode->right=koknode->next;
		dongunode=koknode->next;
		k=0;
		while(dongunode->next!=NULL){
			if(dongunode!=yeninode && dongunode->next->frekans > yeninode->frekans && dongunode->frekans<=yeninode->frekans){
				yeninode->next=dongunode->next;
				dongunode->next=yeninode;
				k++;
			}
			dongunode=dongunode->next;
		}
		
		if(k==0){
			dongunode=koknode;
			while(dongunode!=NULL){
				if(dongunode->next==NULL && dongunode!=yeninode){
					yeninode->next=dongunode->next;
					dongunode->next=yeninode;	
				}
				dongunode = dongunode->next;
			}
		}
		koknode=koknode->next->next;
	}
	printf("\n");
	printf("Huffman\n");
	return koknode;
	
}


int yukseklik(struct node* koknode) 
{ 
    if (koknode==NULL) 
        return 0; 
    else
    { 
        int lyukseklik = yukseklik(koknode->left); 
        int ryukseklik = yukseklik(koknode->right); 
        if (lyukseklik > ryukseklik) 
            return(lyukseklik+1); 
        else return(ryukseklik+1); 
    } 
}

void printseviye(struct node* koknode, int seviye) 
{ 
    if (koknode == NULL && seviye == 1)
        printf("NULL\t");
    else if (koknode == NULL && seviye != 1) 
        printf("null\tNULL\t");
    else if (seviye == 1)
        printf("%d%c\t", koknode->frekans, koknode->harf); 
    else if (seviye > 1)
    { 
        printseviye(koknode->left, seviye-1); 
        printseviye(koknode->right, seviye-1); 
    } 
} 

void print(struct node* koknode) 
{ 
    int h = yukseklik(koknode); 
    int i; 
    for (i=1; i<=h; i++){
        printseviye(koknode, i);
		printf("\n\n"); 
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[100];
	int ch;
	int index = 0;
	struct node *ilknode;
	
	printf("Sikistirilmasini istediginiz stringi girin: ");
	printf("\n\n");
	
	while ((ch = getchar()) != '\n')
		str[index++] = ch;
	str[index] = '\0';
	printf("\n");
	printf("Unsorted String and Frequencies\n");
	printf("%s\n", str);
	ilknode = listeOlustur(str);
	ilknode=insertionSort(ilknode);
	ilknode=huffmann(ilknode);
	print(ilknode);
	return 0;
	
	
}
