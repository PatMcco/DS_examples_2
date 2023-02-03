#include <iostream>
struct Student {
    std::string m_id;
    std::string m_name;
};

struct Node {
    Student m_data;
    Node* m_next{nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};
public:
    void push(Student student) {
        // create a new node
        auto node = new Node();
        node->m_data = std::move(student);
        // add the first node
        node->m_next = m_top;
        m_top = node;
    }

    // pop is the delete function
    void pop() {
        auto node = m_top;
        // check for empty stack
        m_top = m_top ? m_top->m_next : nullptr;
        delete node;
    }

    auto peek() {
        return m_top ? m_top->m_data : Student{"", "Empty stack"};
    }

    friend std::ostream& operator<<(std::ostream& output, Stack& stack) {
        auto node = stack.m_top;
        while (node != nullptr) {
            std::cout << "Name: " << node->m_data.m_id << ", " << "ID: ";
            std::cout << node->m_data.m_name << std::endl;
            node = node->m_next;
        }
        return output;
    }
};

int main() {

    // test 1 - add a node to the stack
    Stack stack;

    stack.push({"w0183220", "patrick"});
    stack.push({"w0132424", "joe"});
    stack.push({"w0123456", "jane"});
    stack.push({"w2342245", "jim"});

    std::cout << stack << std::endl;

    // test 2 - remove a node from the stack
    stack.pop();

    std::cout << stack << std::endl;

    // peek at the stack
    std::cout << "Peek: " << stack.peek().m_id << ", " << stack.peek().m_name << std::endl;

    return 0;
}