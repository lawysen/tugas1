#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head,*tail;

Node *createNode(int angka){
    Node *newNode = (Node*)malloc(sizeof(Node));
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
    
    if (!head){
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
    if (!head){
        return;
    }
    
     else if(head == tail){
        head = tail = NULL;
        free(head);
    }

    else{
        Node *temp = head;
        while(temp -> next != tail){
            temp = temp->next;
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
    int angka1[11] = {1,1,2,3,4,5,6,2,3,4,5};
    int hapus;
    int jumlah = 11;

    if(jumlah % 2 == 0){
        hapus = jumlah/2 - 1;
    }

    else{
        hapus = jumlah/2;
    }

    int sudah = hapus;

    for(int i=0;i<jumlah;i++){
        pushHead(angka1[i]);
    }

    while(sudah > 0){
        popHead();
        popTail();
        sudah--;
    }
    print();



    return 0;
}