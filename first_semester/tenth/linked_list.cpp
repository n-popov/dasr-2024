#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int new_value) {
        value = new_value;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    void push_front(int value) {
        if (!front) {
            front = new Node(value);
        } else {
            auto new_node = new Node(value);
            front->prev = new_node;
            new_node->next = front;
            front = new_node;
        }
        size++;
    }
    void pop_front() {
        if (!front) return;

        auto new_front = front->next;
        delete front;
        front = new_front;
        size--;
    }
    void insert(Node* after, int value) {
        if (!after) return;

        auto new_elem = new Node(value);

        new_elem->next = after->next;

        if (after->next)
            after->next->prev = new_elem;

        new_elem->prev = after;
        after->next = new_elem;

        size++;
    }
    void erase(Node* elem) {
        if (!elem) return;

        if (elem->next)
            elem->next->prev = elem->prev;

        if (elem->prev)
            elem->prev->next = elem->next;

        delete elem;
        size--;
    }

    void splice(Node* after, Node* other_elem) {
        if (!after || !other_elem) return;

        if (other_elem->next)
            other_elem->next->prev = other_elem->prev;

        if (other_elem->prev)
            other_elem->prev->next = other_elem->next;

        other_elem->next = after->next;

        if (after->next)
            after->next->prev = other_elem;

        after->next = other_elem;
        other_elem->prev = after;
    }

    List() {
        front = nullptr;
        size = 0u;
    }
    ~List() {
        for(;front;) pop_front();
    }

    Node* front;
    unsigned size;
};

void print_list(List& l) {
    for (auto current = l.front; current; current = current->next) {
        std::cout << current->value << ' ';
    }
    std::cout << std::endl;
}

int main() {
    List l;
    std::cout << "Empty list" << std::endl;
    print_list(l);

    l.push_front(5);
    l.push_front(42);
    l.push_front(3);
    l.push_front(100500);
    std::cout << "Some elems" << std::endl;
    print_list(l);

    l.pop_front();
    std::cout << "Removed front" << std::endl;
    print_list(l);

    l.insert(l.front->next, 55);
    std::cout << "Added after second" << std::endl;
    print_list(l);

    l.erase(l.front->next);
    std::cout << "Removed second" << std::endl;
    print_list(l);


    List other;
    other.push_front(4);
    other.push_front(6);
    other.push_front(8);
    std::cout << "Other list" << std::endl;
    print_list(other);

    l.splice(l.front->next, other.front->next);
    std::cout << "Spliced 6 into initial list" << std::endl;
    print_list(l);
    print_list(other);


}
