#include <iostream>

struct Node {
    std::string m_data;
    Node* m_next{nullptr};
};

class Queue {
private:
    Node* m_first {nullptr};
    Node* m_last {nullptr};
public:
    void push(std::string data) {
        // create a new node
        auto node = new Node;
        node->m_data = std::move(data);

        // are we adding to the start of the queue?
        if (m_first == nullptr) {
            m_first = node;
        } else {
            // other node
            m_last->m_next = node;
        }
        m_last = node;
    }

    void pop() {
        // remove node from start of queue
        Node* node = m_first;
        // check for empty queue
        if (m_first == nullptr) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        // check for last node in queue
        if (m_first == m_last) {
            m_last = nullptr;
        }
        // detach from the queue
        m_first = node->m_next;

        delete node;
    }

    std::string peek() {
        if (m_first == nullptr) {
            return "Empty queue";
        }
        return m_first->m_data;
    }

    friend std::ostream& operator<<(std::ostream& output, Queue& queue) {
        auto node = queue.m_first;
        while (node != nullptr) {
            std::cout << node->m_data << ", ";
            node = node->m_next;
        }
        return output;
    }

};
int main() {
    // test 1 - add a node to a queue
    Queue queue;

    queue.push("apple");
    queue.push("banana");
    queue.push("orange");
    queue.push("grapefruit");
    queue.push("pineapple");

    std::cout << "Test 1 - add nodes to end of queue" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << queue << std::endl;
    std::cout << std::endl;

    // test 2 - remove node from the start of the queue
    queue.pop();

    std::cout << "Test 2 - remove node from start of line(head)" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << queue << std::endl;
    std::cout << std::endl;

    // test 3 - read data from the start of the queue
    std::string data = queue.peek();

    std::cout << "Test 3 - read data from start of queue(head)" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << data << std::endl;
    std::cout << std::endl;

    return 0;
}
