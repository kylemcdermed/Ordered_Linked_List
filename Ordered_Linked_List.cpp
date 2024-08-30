class Node {

public:

    int m_data;
    Node* m_link;

    Node() = default;

    Node(int data, Node* node=nullptr)
        : m_data {data}
        , m_link {node} {}

};

class orderedLinkedList {

private:

    Node* m_head;

public:

    orderedLinkedList()
        : m_head {nullptr} {}

    void printList() {

        Node* current = m_head;

        if (current == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        while (current != nullptr) {
            cout << current->m_data << ' ';
            current = current->m_link;
        }
        cout << '\n';
    }

    void insertNode(int value) {

        if (m_head == nullptr) {
            m_head = new Node(value);
            return;
        }

        if (value < m_head->m_data) {
            Node* newNode = new Node(value);
            newNode->m_link = m_head;
            m_head = newNode;
            return;
        }

        Node* current = m_head;

        while (current->m_link != nullptr && current->m_link->m_data < value) {
            current = current->m_link;
        }

        Node* newNode = new Node(value);
        newNode->m_link = current->m_link;
        current->m_link = newNode;

    }

    void deleteNode(int value) {

        if (m_head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (m_head->m_data == value) {
            Node* nodeToDelete = m_head;
            m_head = m_head->m_link;
            delete nodeToDelete;
            return;
        }

        Node* current = m_head;

        while (current->m_link != nullptr) {
            if (current->m_link->m_data == value) {
                Node* nodeToDelete = current->m_link;
                current->m_link = nodeToDelete->m_link;
                delete nodeToDelete;
                return;
            }
            current = current->m_link;
        }
        cout << "Value not found in the list.\n";
    }

    bool searchNode(int value) {

        if (m_head == nullptr) {
            cout << "Ordered Linked List is empty.\n";
            return false;
        }

        if (m_head->m_data == value) {
            return true;
        }

        Node* current = m_head->m_link;

        while (current != nullptr) {
            if (current->m_data == value) {
                return true;
            }
            if (current->m_data > value) {
                return false;
            }
            current = current->m_link;
        }
        return false;
    }

};

int main() {

    orderedLinkedList list;

    list.printList();

    int num = 1;
    while (num <= 9) {
        list.insertNode(num);
        ++num;
    }
    list.printList();

    if (list.searchNode(5)) {
        list.deleteNode(5);
    } else {
        cout << "Value not found in list.\n";
    }
    list.printList();

    if (list.searchNode(6)) {
        list.insertNode(25);
    } else {
        cout << "Value not found in list.\n";
    }
    list.printList();

}
