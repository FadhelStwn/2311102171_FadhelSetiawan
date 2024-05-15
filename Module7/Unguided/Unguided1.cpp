#include <iostream>
using namespace std;


struct Node {
  string dat171;
  Node* next;
};


Node* head = NULL;
Node* tail = NULL; 


bool isEmpty() {
  return head == NULL;
}


void enqueueAntrian(string dat171) {
  Node* newNode = new Node; 
  newNode->dat171 = dat171; 
  newNode->next = NULL; 

  if (isEmpty()) { 
    head = newNode;
    tail = newNode;
  } else { 
    tail->next = newNode;
    tail = newNode;
  }
}


void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Huh, this queue is empty! Nothing to dequeue!" << endl;
    return;
  }

  Node* temp = head; 
  head = head->next; 
  delete temp; 

  if (head == NULL) { 
    tail = NULL;
  }
}


int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}


void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}


void viewQueue() {
  if (isEmpty()) {
    cout << "The queue is empty!" << endl;
    return;
  }

  cout << "Data antrian teller:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->dat171 << endl;
    i++;
    current = current->next;
  }
}

int main() {
    cout << "\n TELLER QUEUE \n" << endl;
    cout << "-=- Enqueue/Add Tellers -=-" << endl;
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Dequeue/Remove Tellers -=-" << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Remove All Tellers -=-" << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    return 0;
}