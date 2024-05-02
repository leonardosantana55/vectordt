/*
gcc vectordt.c -o prog
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
	int x;
	int y;
}Vector;
 
typedef struct Node{
    Vector data;
    struct Node* next;
}Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
	int size;
}LinkedList;

//helper functions
//define data structures for linkedlist
LinkedList* vectorCreate(int x, int y);
void vectorPrint(LinkedList* list);
void vectorInsert(LinkedList* list, int x, int y);
//vectorSort
//vectorRemoveDuplicates



int main(int argc, char *argv[]){
	//int x = 10;
	//int y = 20;
	LinkedList* vectors = vectorCreate(2, 5);
	vectorInsert(vectors, 5, 5);
	vectorInsert(vectors, 4, 7);
	vectorInsert(vectors, 3, 9);
	vectorInsert(vectors, 11, 3);
	vectorInsert(vectors, 1, 6);
	vectorPrint(vectors);
	printf("%d", vectors->size);
	
	return 0;
}



LinkedList* vectorCreate(int x, int y){
	Vector* data = malloc(sizeof(Vector));
	data->x = x;
	data->y = y;
	
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = NULL;
	
	LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));;
	ll->head = node; // point to first
	ll->size = 0;
	
	return ll;
}


void vectorPrint(LinkedList* list){
    Node* temp;
    temp = list->head;
    
    while (temp != NULL){
        printf("[%d, %d] ", temp->data.x, temp->data.y);
        temp = temp->next;
    }
    
    return;
}


void vectorInsert(LinkedList* list, int x, int y){
    Vector* data = malloc(sizeof(Vector));
	data->x = x;
	data->y = y;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = *data;
    node->next = NULL;
    //insert second node
    node->next = list->head; 
    list->head = node;
	list->size++;
        
    return;
}


//add a counter in the linkedlist data structure, to track its current size.
