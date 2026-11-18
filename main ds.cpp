#include <iostream>
#include <string>
using namespace std;

// Node of the linked list that backs the stack
struct Node {
    string url;
    Node* next;
    Node(const string& u) : url(u), next(nullptr) {}
};

// Stack implemented using a singly linked list (LIFO)
class Stack {
    Node* topNode;
    int count;
public:
    Stack() : topNode(nullptr), count(0) {}
    ~Stack() { clear(); }
    Stack(const Stack&) = delete;            // avoid accidental shallow copies
    Stack& operator=(const Stack&) = delete;

    void push(const string& url) {
        Node* n = new Node(url);
        n->next = topNode;
        topNode = n;
        count++;
    }

    bool pop(string& out) {
        if (!topNode) return false;
        Node* temp = topNode;
        out = temp->url;
        topNode = temp->next;
        delete temp;
        count--;
        return true;
    }

    bool isEmpty() const { return topNode == nullptr; }
    int size() const { return count; }

    void clear() {
        string tmp;
        while (pop(tmp)) {}
    }

    void display() const {
        if (!topNode) { cout << "   (empty)\n"; return; }
        for (Node* c = topNode; c; c = c->next)
            cout << "   " << c->url << "\n";
    }
};

// Browser built on two stacks
class Browser {
    Stack backStack;
    Stack forwardStack;
    string current;
public:
    Browser() : current("about:blank") {}

    void visit(const string& url) {
        backStack.push(current);   // save current page
        current = url;
        forwardStack.clear();      // new visit invalidates forward history
        cout << "Visited: " << current << "\n";
    }

    void goBack() {
        string prev;
        if (!backStack.pop(prev)) {
            cout << "No pages to go back to.\n";
            return;
        }
        forwardStack.push(current);
        current = prev;
        cout << "Back to: " << current << "\n";
    }

    void goForward() {
        string next;
        if (!forwardStack.pop(next)) {
            cout << "No pages to go forward to.\n";
            return;
        }
        backStack.push(current);
        current = next;
        cout << "Forward to: " << current << "\n";
    }

    void showStatus() const {
        cout << "\nCurrent page: " << current << "\n";
        cout << "Back stack (top first):\n";
        backStack.display();
        cout << "Forward stack (top first):\n";
        forwardStack.display();
        cout << "\n";
    }
};

int main() {
    Browser browser;
    int choice;
    string url;

    do {
        cout << "===== Browser History Manager =====\n"
             << "1. Visit new page\n"
             << "2. Back\n"
             << "3. Forward\n"
             << "4. Show history\n"
             << "0. Exit\n"
             << "Choice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                browser.visit(url);
                break;
            case 2: browser.goBack(); break;
            case 3: browser.goForward(); break;
            case 4: browser.showStatus(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
