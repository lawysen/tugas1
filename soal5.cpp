#include<stdio.h>
#include<stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head,*tail;

Node *createNode(int angka){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> angka = angka;
    return newNode;
}

void pushHead(int angka){
    Node *temp = createNode(angka);

    if(!head){
        head = tail = temp;
    }

    else{
        temp -> next = head;
        head = temp;
    }

}

void pushTail(int angka){
    Node *temp = createNode(angka);

    if(!head){
        head = tail = temp;
    }

    else{
        tail -> next = temp;
        tail = temp;
    }
}

void popHead(){

    if(!head){
        return;
    }

    else if(head == tail){
        head = tail = NULL;
        free(head);
    }

    else{
       Node *temp = head;
       head = temp -> next;
       temp -> next = NULL;
       free(temp);
    }

}

void popTail(){
    if(!head){
        return;
    }

    else if(head == tail){
        head = tail = NULL;
        free(head);
    }

    else{
        Node *temp = head;

        while(temp -> next != tail){
            temp = temp -> next;
        }

        temp -> next = NULL;
        free(tail);
        tail = temp;
    }

}

void print(){
    Node *curr = head;

    while(curr){
        printf("%d\n",curr -> angka);
        curr = curr -> next;
    }

}

int main(){
    int angka[15] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int banyak = 12;
    int cari = 5;

    for(int i=0;i<banyak;i++){
        pushTail(angka[i]);
    }

    int kurang = banyak - cari;
    
    while(kurang > 0){
        popTail();
        kurang--;
    }

    while(cari > 1){
        popHead();
        cari--;
    }

    print();


    return 0;
}