#include <iostream>
#include <string>
#include <cstdlib> // для atoi

using namespace std;

struct Node {
    string move;
    Node* prev;
    Node* next;

    Node(string m) {
        move = m;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void addMove(string move) {
    Node* newNode = new Node(move);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void solveHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        addMove("Move disk 1 from " + string(1, from) + " to " + string(1, to));
        return;
    }
    solveHanoi(n - 1, from, aux, to);
    addMove("Move disk " + to_string(n) + " from " + string(1, from) + " to " + string(1, to));
    solveHanoi(n - 1, aux, to, from);
}

void printMoves() {
    Node* current = head;
    int i = 1;
    while (current) {
        cout << i++ << ". " << current->move << endl;
        current = current->next;
    }
}

void clearList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <number_of_disks> <from> <to> <aux>\n";
        return 1;
    }

    int n = atoi(argv[1]);
    char from = argv[2][0];
    char to = argv[3][0];
    char aux = argv[4][0];

    if (n <= 0) {
        cerr << "Error: number of disks must be positive.\n";
        return 1;
    }

    solveHanoi(n, from, to, aux);
    printMoves();
    clearList();

    return 0;
}
