#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"

struct request *append_to_list(struct request *list){

 //add your code
	char new_classroom[ROOM_LEN];
	char new_first[NAME_LEN+1];
	char new_last[NAME_LEN+1];
	// create new request based on user input
	printf("Please enter the classroom: ");
	read_line(new_classroom, ROOM_LEN);
	printf("Enter child's first name: ");
	read_line(new_first, NAME_LEN+1);
	printf("Enter child's last name: ");
	read_line(new_last, NAME_LEN+1);
	
	// check if the list is empty
	if(list == NULL){
		struct request *new_request;
		new_request = malloc(sizeof(struct request));
		strcpy(new_request->classroom, new_classroom);
		strcpy(new_request->first, new_first);
		strcpy(new_request->last, new_last);
		printf("Enter phone number: ");
		read_line(new_request->phone, PHONE_LEN+1);
		new_request->next = NULL;
		list = new_request;
		return list;
	}
	// check if the request already exist
	struct request *p;
	for(p = list; p != NULL; p = p->next){
		if (strcmp(p->classroom, new_classroom)==0){
			if(strcmp(p->first, new_first)==0){
				if(strcmp(p->last, new_last)==0){
					printf("Request already exist, use update function to update existing request.\n");
					return NULL;	
				}
			}	
		}
	}		
	struct request *new_request;
	new_request = malloc(sizeof(struct request));
	if(new_request == NULL){
		printf("malloc failed in append_to_list");
		return NULL;
	}	
	printf("Enter phone number: ");
	read_line(new_request->phone, PHONE_LEN+1);
	strcpy(new_request->classroom,new_classroom);
	strcpy(new_request->first, new_first);
	strcpy(new_request->last, new_last);
	new_request->next = NULL;
	// add the new request to the end of the list
	for(p=list; p->next != NULL; p=p->next);
	p->next = new_request;


	
 return list;

}

void update(struct request *list)
{

  //add your code
	// ask user for the request need to update
	char update_classroom[ROOM_LEN];
	char update_first[NAME_LEN+1];
	char update_last[NAME_LEN+1];

	printf("Please enter the classroom: ");
	read_line(update_classroom, ROOM_LEN);
	printf("Please enter the child's first name: ");
	read_line(update_first, NAME_LEN+1);
	printf("Please enter the child's last name: ");
	read_line(update_last, NAME_LEN+1);

	// find the request in the list
	struct request *p;
	for(p=list; p!=NULL; p=p->next){
		if(strcmp(p->classroom, update_classroom)==0){
			if(strcmp(p->first, update_first)==0){
				if(strcmp(p->last, update_last)==0){
					printf("Please enter the updated classroom: ");
					read_line(update_classroom, ROOM_LEN);
					strcpy(p->classroom, update_classroom);
					return;
				}
			}
		}		
	}
	printf("No request found, please create new request.");
}

void printList(struct request *list){

  //add your code
	// print header
	printf("Classroom\tFirst Name\tLast Name\tPhone Number\n");
	struct request *p;
	// print the list
	for(p=list; p!=NULL; p=p->next){
		printf("%s\t%s\t%s\t%s\n", p->classroom, p->first, p->last,p->phone);
	}
}
void clearList(struct request *list)
{

 //add your code
	// clear the list
	struct request *p;
	while(list != NULL){
		p = list;
		list = list->next;
		if( p!=NULL)
			free(p);
	}
}






































































