#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char address[15]; //Page request count
    int counter;
    struct Node* next; //Pointer next node
    struct Node* prev; //Pointer prev node
};

void write(struct Node *head){
    struct Node* current;
    current = head;
    while(current != NULL) {
        printf("%s %d",current->address, current->counter);
        printf("<->");
        current = current->next;
    }
}

void deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    struct Node* tmp = temp->prev;
    free(temp);
    tmp->next = NULL;
}

struct Node* push(struct Node* head_ref, char *new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->address,new_data);
    new_node->next = head_ref;
    new_node->prev = NULL;
    
    return new_node;
    
}

void deleteNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }
    struct Node* temp = head;
    struct Node* tmp = temp->prev;
    free(temp);
    tmp->next = NULL;
}


int main(int argc, char *argv[]) {
    int flag = 0;
    FILE *fp;
    char *c;
    char *x;
    struct Node *head, *current;
    int maxCounter, cacheCapacity, capacity = 0;
    fp=fopen("input.txt", "r"); //input.txt dosyasini r (read) ile okuduk.
    if(fp==NULL){
        perror("Error opening file");
    }
    c = (char *) malloc (sizeof(char)*50);
    fgets(c,50,fp); //Satir satir okuma yapma
    maxCounter=(int)c[2]-48; //Satirin 2.elemani sayac sayisina denk geliyor
    fgets(c,50,fp);
    cacheCapacity=c[2]-48;
    head=(struct Node*)malloc(sizeof(struct Node));
    fgets(c,50,fp);
    strcpy(head->address,c);
    head->counter=1;
    head->next=NULL;
    head->prev=NULL;
    capacity++;
    write(head);
    x=fgets(c,50,fp);
    do{
        current=head; 
        flag = 0;
        while(current!=NULL){
            if(strcmp(current->address,c)==0){
                current->counter+=1;
                flag = 1; //Flag 1 oluyorsa demek ki ayný eleman gelior, push etmeye gerek yok.
                if(current->counter>maxCounter){
                    deleteNode(current);
                    head = push(head, current->address);
                    write(head);
                }
            }
            current=current->next;
        }
        if(flag == 0){
            head = push(head,c); //push'ta yeni node oluË›turuyor olmalË.
            head->counter=1;
            write(head);
            capacity+=1;
            if(capacity>cacheCapacity){
                deleteEnd(head);
            }
        }
                
        x=fgets(c,50,fp);
       
    }while(x!=NULL);
    
    return 0;
}


















#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define R 50
#define L 5
int main(int argc, char *argv[]) {
	char * fileName, *c;
	char *text[R][L];
	char *oldString;
	char *newString;
	FILE *fp;
	printf("Arama yapilacak text adini giriniz. \n");
	scanf("%s",&fileName);
	fp=fopen(&fileName, "r");
    if(fp==NULL){
        perror("Error opening file");
        exit(1);
    }
    
    int i=0, N=0;
    
    while(fgets(text[i], R, fp)) 
	{
        text[i][strlen(text[i]) - 1] = '\0';
        i++;
    }
    N=i;
    for(i = 0; i < N; ++i)
    {
        printf(" %s", text[i]);
    }
    fclose(fp); 
    printf("Aranacak stringi giriniz");
	scanf("%s", &oldString);
	printf("Yeni stringi giriniz\n");
	scanf("%s", &newString);
	
	
	return 0;
}
























#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char * fileName, *c;
	char *text;
	char *oldString;
	char *newString;
	FILE *fp;
	printf("Arama yapilacak text adini giriniz. \n");
	scanf("%s",&fileName);
	fp=fopen(&fileName, "r");
    if(fp==NULL){
        perror("Error opening file");
        exit(1);
    }
    c = (char *) malloc (sizeof(char)*50);
    c = fgetc(fp); 
    //int i=0;
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fp);       
    } 
    fclose(fp); 
    printf("Aranacak stringi giriniz");
	scanf("%s", &oldString);
	printf("Yeni stringi giriniz\n");
	scanf("%s", &newString);
	int j, N=strlen(text), M=strlen(oldString), L=strlen(newString);
	printf("%d",N);
	
	return 0;
}
