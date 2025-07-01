#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class List {
  Node *head;
  Node *tail;

public:
  List() { head = tail = nullptr; }

  void push_front(int val) {
    Node *newNode = new Node(val);

    if (head == nullptr) {
      head = tail = newNode;
      return;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  void push_back(int val) {
    Node *newNode = new Node(val);

    if (head == nullptr) {
      head = tail = newNode;
      return;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void pop_front() {
    if (head == nullptr) {
      cout << "Linked List is empty!\n";
      return;
    } else {
      Node *temp = head;
      head = head->next;
      temp->next = nullptr;
      delete temp;
    }
  }

  void pop_back() {
    if (head == nullptr) {
      cout << "Linked List is empty!\n";
      return;
    } else {
      Node *temp = head;

      while (temp->next != tail) {
        temp = temp->next;
      }

      temp->next = nullptr;
      delete tail;
      tail = temp;
    }
  }

  void insert(int val, int pos) {
    if (pos < 0) {
      cout << "Invalid position!\n";
      return;
    } else if (pos == 0) {
      push_front(val);
      return;
    } else {
      Node *temp = head;
      int index = 0;

      for (int i = 0; i < pos - 1; i++) {
        if (temp == nullptr) {
          cout << "Invalid position!\n";
          return;
        }

        temp = temp->next;
      }

      Node *newNode = new Node(val);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  void printLL() {
    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }

    cout << "NULL\n";
  }

  int search(int key) {
    Node *temp = head;
    int index = 0;

    while (temp != nullptr) {
      if (temp->data == key) {
        return index;
      } else {
        temp = temp->next;
        index++;
      }
    }

    return -1;
  }
};
