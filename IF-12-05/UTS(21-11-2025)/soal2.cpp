#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

class DLL {
private:
    Node *head = nullptr, *tail = nullptr;

public:
    void insert(int v) {
        Node* n = new Node{v, tail, nullptr};
        if (!head) head = n;
        else tail->next = n;
        tail = n;
    }

    void deleteLast() {
        if (!tail) { cout << "List kosong.\n"; return; }
        Node* temp = tail;
        if (head == tail) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void view() {
        for (Node* c = head; c; c = c->next) cout << c->data << " ";
        cout << endl;
    }

    void reverse() {
        Node* cur = head, *temp = nullptr;
        while (cur) {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if (temp) head = temp->prev;
    }
};

int main() {
    DLL list;
    int c, v;

    do {
        cout << "1 insert, 2 delete, 3 view, 4 reverse+view, 0 exit\n";
        cin >> c;

        if (c == 1) cin >> v, list.insert(v);
        else if (c == 2) list.deleteLast();
        else if (c == 3) list.view();
        else if (c == 4) list.reverse(), list.view();

    } while (c != 0);
}
