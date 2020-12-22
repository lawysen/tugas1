#include<stdio.h>
#include<stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head,*tail;

Node *createNode(int angka){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> angka = angka;
    return newNode;
}

void pushHead(int angka){
    Node * temp = createNode(angka);

    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void pushTail(int angka){
    Node *temp = createNode(angka);
    if(!head){
        tail = head = temp;
    }
    else{
        tail -> next = temp;
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
    int angka1[6] = {1,1,2,2,3,4};
    int angka2[6] = {1,3,4,5,6,7};
    int simpan[15];
    int banding[10];
    for(int i=0; i<6;i++){
        simpan[i] = angka1[i];
    }

    int masuk =0;
    for(int i=6; i<12;i++){
        simpan[i] = angka2[masuk];
        masuk++;
    }

    int sekarang = 1;
    banding[0] = simpan[0];
    int beda =0;
    for(int i=1;i<12;i++){     // 1 1 2 2 3 4 1 3 4 5 6 7
        for(int j=0;j<sekarang;j++){
            if(simpan[i] == banding[j]){
                break;
            }
            else{
                beda++;
            }
        }

        if(beda == sekarang){
            banding[sekarang] = simpan[i];
            sekarang++;
            beda=0;
        }
        else{
            beda =0;
        }
    }

    for(int i=0;i<sekarang;i++){
        for(int j=0;j<12;j++){
            if(simpan[j] == banding[i]){
                pushTail(simpan[j]);
            }
        }
    }

    print();
    printf("%d",sekarang);

    return 0;
}