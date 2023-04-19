//
// Created by mewalid on 4/18/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node* nodeptr;
typedef struct node
{
    int data ;
    nodeptr next;
} node;
void define_cerc(nodeptr* SECONDS,nodeptr* prd,int e){
    nodeptr new_node = malloc(sizeof(node));
    new_node->data =e ;
    if( *SECONDS == NULL){
        *SECONDS = new_node;
    }else{
        (*prd)->next=new_node;
    }
    (*prd) = new_node;
    (*prd)->next = *SECONDS;
}
void afficher(nodeptr SECONDS){
    nodeptr p = SECONDS;
    do {
        printf("%d   ", SECONDS->data);
        SECONDS = SECONDS->next;
    } while (SECONDS != p);
    printf("\n");
}
void get_hour(nodeptr Seconds, int minute , int hour) {
    while (true) {
        printf("%d:%d:%d \n", hour, minute, Seconds->data);
        if (Seconds->data == 59) {
            minute++;
            if(minute==60){
                minute=0;
                hour++;
            }
        }
        Seconds= Seconds->next;
        if(hour==1 && minute==5){
            return;
        }

    }
}

void get_hour_with_Cerc(nodeptr SECONDS, nodeptr MINUTES,nodeptr HOURS){
    while (true){
        printf("%d:%d:%d \n", HOURS->data, MINUTES->data, SECONDS->data);
        if(SECONDS->data == 59){
            MINUTES = MINUTES->next;
            if (MINUTES->data == 0)
                HOURS = HOURS->next;
        }
        SECONDS = SECONDS->next;
        if(HOURS->data==0 && MINUTES->data==0 && SECONDS->data==0)
            return;
    }
}

int main(){
    nodeptr  SECONDS = NULL , secprd=NULL;
    for (int i = 0; i <= 59; ++i) {
        define_cerc(&SECONDS,&secprd,i);
    }
    nodeptr MINUTES = NULL , minprd = NULL;
    for (int i = 0; i <= 59; ++i) {
        define_cerc(&MINUTES,&minprd,i);
    }
    nodeptr HOURS =NULL , hourprd = NULL;
    for (int i = 0; i <= 23; ++i) {
        define_cerc(&HOURS,&hourprd,i);
    }
//    get_hour(SECONDS,0,0);
    get_hour_with_Cerc(SECONDS,MINUTES,HOURS);
}



