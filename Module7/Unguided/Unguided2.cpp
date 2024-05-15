#include <iostream>

using namespace std;


struct Node {
  string NamaMahasiswa171;
  long long int NIMMahasiswa171;
  Node* next;
};


Node* head = NULL; 
Node* tail = NULL; 


bool isEmpty() {
  return head == NULL;
}


void enqueueAntrian(string nama, long long int NIM) {
  Node* newNode = new Node; // Buat node baru
  newNode->NamaMahasiswa171 = nama;
  newNode->NIMMahasiswa171 = NIM;
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
    cout << "Yo! The queue is empty! There's nothing to dequeue!" << endl;
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
    cout << "Hey, the queue is empty!" << endl;
    return;
  }

  cout << "Mahasiswa Queue Data:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->NamaMahasiswa171 << " (" << current->NIMMahasiswa171 << ")" << endl;
    i++;
    current = current->next;
  }
}

int main() {
  cout << "\n Queue Mahasiswa " << endl;

  cout << "\n-=- Enqueue/Add Queue Mahasiswa -=-" << endl;
  enqueueAntrian("Fadhel", 2311102171);
  enqueueAntrian("Fuad", 2311102172);
  enqueueAntrian("Rusdi", 9312011173);
  enqueueAntrian("Hardin", 3211102174);
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Dequeue/Remove Queue Mahasiswa -=-" << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Clear All Queues -=-" << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  return 0;
}