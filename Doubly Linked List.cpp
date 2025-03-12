////
//// Created by Ghareeb on 3/2/2025.
////
//
//#include <iostream>
//#include <cmath>
//#include <cassert>
//#include <climits>
//
//#include <vector>        // for debug
//#include <algorithm>
//#include <sstream>
//
//using namespace std;
//
//struct Node {
//    int data{};
//    Node *next{};
//    Node *prev{};     // Previous node!
//
//    Node(int data) : data(data) {}
//
//    void set(Node *next, Node *prev) {
//        this->next = next;
//        this->prev = prev;
//    }
//
//    ~Node() {
//        cout << "Destroy value: " << data << " at address " << this << "\n";
//    }
//};
//
//class LinkedList {
//private:
//    Node *head{};
//    Node *tail{};
//    int length = 0;
//
//    // let's maintain how many nodes
//
//    vector<Node *> debug_data;    // add/remove nodes you use
//
//    void debug_add_node(Node *node) {
//        debug_data.push_back(node);
//    }
//
//    void debug_remove_node(Node *node) {
//        auto it = std::find(debug_data.begin(), debug_data.end(), node);
//        if (it == debug_data.end())
//            cout << "Node does not exist\n";
//        else
//            debug_data.erase(it);
//    }
//
//public:
//
//    // Below 2 deletes prevent copy and assign to avoid this mistake
//    LinkedList() {
//    }
//
//    LinkedList(const LinkedList &) = delete;
//
//    LinkedList &operator=(const LinkedList &another) = delete;
//
//    void debug_print_address() {
//        for (Node *cur = head; cur; cur = cur->next)
//            cout << cur << "," << cur->data << "\t";
//        cout << "\n";
//    }
//
//    void debug_print_node(Node *node, bool is_seperate = false) {
//        if (is_seperate)
//            cout << "Sep: ";
//        if (node == nullptr) {
//            cout << "nullptr\n";
//            return;
//        }
//
//        if (node->prev == nullptr)
//            cout << "X\t";
//        else
//            cout << node->prev->data << "\t";
//
//        cout << " <= [" << node->data << "]\t => \t";
//
//        if (node->next == nullptr)
//            cout << "X\t";
//        else
//            cout << node->next->data << "\t";
//
//        if (node == head)
//            cout << "head\n";
//        else if (node == tail)
//            cout << "tail\n";
//        else
//            cout << "\n";
//    }
//
//    void debug_print_list(string msg = "") {
//        if (msg != "")
//            cout << msg << "\n";
//        for (int i = 0; i < (int) debug_data.size(); ++i)
//            debug_print_node(debug_data[i]);
//        cout << "************\n" << flush;
//    }
//
//    string debug_to_string() {
//        if (length == 0)
//            return "";
//        ostringstream oss;
//        for (Node *cur = head; cur; cur = cur->next) {
//            oss << cur->data;
//            if (cur->next)
//                oss << " ";
//        }
//        return oss.str();
//    }
//
//    void debug_verify_data_integrity() {
//        if (length == 0) {
//            assert(head == nullptr);
//            assert(tail == nullptr);
//        } else {
//            assert(head != nullptr);
//            assert(tail != nullptr);
//            if (length == 1)
//                assert(head == tail);
//            else
//                assert(head != tail);
//            assert(!head->prev);
//            assert(!tail->next);
//        }
//        int len = 0;
//        for (Node *cur = head; cur; cur = cur->next, len++) {
//            if (len == length - 1)    // make sure we end at tail
//                assert(cur == tail);
//        }
//
//        assert(length == len);
//        assert(length == (int) debug_data.size());
//
//        len = 0;
//        for (Node *cur = tail; cur; cur = cur->prev, len++) {
//            if (len == length - 1)    // make sure we end at head
//                assert(cur == head);
//        }
//        cout << "\n";
//    }
//    ////////////////////////////////////////////////////////////
//
//    void print() {
//        for (Node *cur = head; cur; cur = cur->next)
//            cout << cur->data << " ";
//        cout << "\n";
//    }
//
//    // These 2 simple functions just to not forget changing the vector and length
//    void delete_node(Node *node) {
//        debug_remove_node(node);
//        --length;
//        delete node;
//    }
//
//    void add_node(Node *node) {
//        debug_add_node(node);
//        ++length;
//    }
//
//    void link(Node *first, Node *second) {
//        if (first)
//            first->next = second;
//        if (second)
//            second->prev = first;
//    }
//
//    void insert_end(int value) {
//        Node *item = new Node(value);
//        add_node(item);
//
//        if (!head)
//            head = tail = item;
//        else {
//            link(tail, item);
//            tail = item;
//        }
//        debug_verify_data_integrity();
//    }
//
//    void insert_front(int value) {
//        Node *item = new Node(value);
//        add_node(item);
//
//        if (!head)
//            head = tail = item;
//        else {
//            link(item, head);
//            head = item;
//        }
//        debug_verify_data_integrity();
//    }
//
//    void print_reversed() {
//        for (Node *cur = tail; cur; cur = cur->prev)
//            cout << cur->data << " ";
//        cout << "\n";
//    }
//
//    void delete_front() {
//        if (!head)
//            return;
//        Node *cur = head->next;
//        delete_node(head);
//        head = cur;
//
//        // Integrity change
//        if (head)
//            head->prev = nullptr;
//        else if (!length)
//            tail = nullptr;
//
//        debug_verify_data_integrity();
//    }
//
//    void delete_end() {
//        if (!head)
//            return;
//        Node *cur = tail->prev;
//        delete_node(tail);
//        tail = cur;
//
//        // Integrity change
//        if (tail)
//            tail->next = nullptr;
//        else if (!length)
//            head = nullptr;
//
//        debug_verify_data_integrity();
//    }
//
//    Node *delete_and_link(Node *cur) {
//        // remove this node, but connect its neighbors
//        Node *ret = cur->prev;
//        link(cur->prev, cur->next);
//        delete_node(cur);
//
//        return ret;
//    }
//
//    void delete_node_with_key(int key) {
//        if (!head) return;
//        if (head->data == key)
//            delete_front();
//        else {
//            for (Node *cur = head; cur; cur = cur->next) {
//                if (cur->data == key) {
//                    if (cur == tail) {
//                        delete_end();
//                        break;
//                    } else {
//                        cur = delete_and_link(cur);
//                    }
//                }
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//    void delete_even_positions() {
//        int ctr = 1;
//        if (!head || head == tail) return;
//        for (Node *cur = head; cur; cur = cur->next, ctr++) {
//            if (ctr % 2 == 0) {
//                if (cur == tail) {
//                    delete_end();
//                    break;
//                }
//                cur = delete_and_link(cur);
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//    void delete_odd_positions() {
//        insert_front(-1);
//        delete_even_positions();
//        delete_front();
//    }
//
//    void delete_odd_positions2() {
//        int ctr = 1;
//        if (!head || head == tail) return;
//        delete_front();
//        for (Node *cur = head; cur; cur = cur->next, ctr++) {
//            if (ctr % 2 == 0) {
//                if (cur == tail) {
//                    delete_end();
//                    break;
//                }
//                cur = delete_and_link(cur);
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//    bool check_palindrome() {
//        int i = ceil(length / 2);
//        Node *front = head, *back = tail;
//        while (i--) {
//            if (front->data == back->data) {
//                front = front->next;
//                back = back->prev;
//            } else {
//                cout << "the list is not palindrome\n";
//                return false;
//            }
//        }
//        cout << "the list is palindrome\n";
//        return true;
//    }
//
//
//    void embed_after(Node *node_before, int value) {
//        // Add a node with value between node and its next
//        Node *middle = new Node(value);
//        ++length;
//        debug_add_node(middle);
//
//        Node *node_after = node_before->next;
//        link(node_before, middle);
//        link(middle, node_after);
//    }
//
//    void embed_node_after(Node *node_before, Node *middle) {
//        // Add a node with value between node and its next
//        Node *node_after = node_before->next;
//        link(node_before, middle);
//        link(middle, node_after);
//    }
//
//    void swap_head_tail(Node *&h, Node *&t, Node *front, Node *back) {
//        link(t->prev, front);
//        link(back, h->next);
//        front->next = nullptr;
//        back->prev = nullptr;
//        h = back;
//        t = front;
//    }
//
//    void swap_forward_and_backward(int k) {
//        if (!head || length < k) return;
//        Node *temp;
//        Node *front = head, *back = tail;
//        while (k--) { // 1 // 0
//            if (k == 0 && front == head || front == tail) {
//                if (front == head) {
//                    swap_head_tail(head, tail, front, back);
//                } else {
//                    swap_head_tail(head, tail, back, front);
//                }
//            } else if (k == 0 && front->next == back) {
//                link(front->prev, front->next);
//                link(front->prev, front->next);
//                cout << "";
//                embed_node_after(back, front);
//            } else if (k == 0 && front != back) { // handle odd length
//                link(front->prev, front->next);
//                link(back->prev, back->next);
//                temp = back->prev;
//                embed_node_after(front->prev, back);
//                embed_node_after(temp, front);
//            }
//            front = front->next;
//            back = back->prev;
//        }
//        debug_verify_data_integrity();
//    }
//
//    //You can implement it with only one pointer using fast cur.next.next and slow cur.next pointer.
//    void find_middle() {
//        if (!head) return;
//        Node *front = head, *back = tail;
//        while (front != back && front != back->prev) {
//            front = front->next;
//            back = back->prev;
//        }
//        cout << "The middle : " << back->data << endl;
//    }
//
//    void reverse_list_nodes() {
//        Node *temp;
//        for (Node *cur = tail; cur;) {
//            temp = cur->prev;
//            cur->prev = cur->next;
//            cur->next = temp;
//            cur = temp;
//        }
//        swap(head, tail);
//        debug_verify_data_integrity();
//    }
//
//    // merge two sorted lists
//    void merge_lists(LinkedList &list) {
//        cout<<"";
//        Node *cur1 = head, *cur2 = list.head, *next1, *next2;
//        while (cur1 && cur2) {
//            if (cur1->data < cur2->data && cur2->data < cur1->next->data) {
//                next1 = cur1->next;
//                next2 = cur2->next;
//                embed_node_after(cur1, cur2);
//                cur1 = cur1->next;
//                cur2 = next2;
//                cout << "";
//            } else {
//                cur1 = cur1->next;
//            }
//        }
//        if(list.tail->data > tail->data) tail = list.tail;
//        length += list.length;
////        debug_verify_data_integrity();
//    }
//
//
//    void insert_sorted(int value) {        // O(n) time - O(1) memory
//        // 3 special cases for simplicity
//        if (!length || value <= head->data)
//            insert_front(value);
//        else if (tail->data <= value)
//            insert_end(value);
//        else {
//            // Find the node I am less than. Then I am before it
//            for (Node *cur = head; cur; cur = cur->next) {
//                if (value <= cur->data) {
//                    embed_after(cur->prev, value);
//                    break;
//                }
//            }
//        }
//        debug_verify_data_integrity();
//
//        // This idea is used in Insertion Sort Algorithm
//    }
//};
//
//void test1() {
//    cout << "\n\ntest1\n";
//    LinkedList list;
//
//    list.insert_end(3);
//    list.insert_end(5);
//    list.insert_end(7);
//    list.insert_front(7);
//    list.delete_front();
//    list.delete_end();
//    list.insert_sorted(2);
//    list.insert_sorted(9);
//    list.insert_sorted(7);
//    list.insert_sorted(4);
//    list.insert_sorted(1);
//    list.delete_node_with_key(7);
//
//    list.print();
//    //list.print_reversed();
//
//    string expected = "1 2 3 4 5 9";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//void test2() {
//    cout << "\n\ntest2\n";
//    LinkedList list;
//
//    list.insert_end(3);
//    list.insert_end(5);
//    list.insert_end(7);
//    list.insert_front(7);
//    list.delete_front();
//    list.delete_end();
//    list.insert_sorted(2);
//    list.insert_sorted(9);
//    list.insert_sorted(7);
//    list.insert_sorted(4);
//    list.insert_sorted(1);
//    list.delete_node_with_key(1);
//
//    list.print();
//    list.print_reversed();
//
//    string expected = "1 2 3 4 5 7";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//void test3() {
//    cout << "\n\ntest2\n";
//    LinkedList list;
//    LinkedList list2;
//
//    list.insert_end(10);
//    list.insert_end(20);
//    list.insert_end(30);
//    list.insert_end(40);
//    list.insert_end(50);
//
//    list2.insert_end(15);
//    list2.insert_end(17);
//    list2.insert_end(22);
//    list2.insert_end(24);
//    list2.insert_end(35);
//
//    list.merge_lists(list2);
//    list.print();
//
//    string expected = "9 8 7 6 5 4 3 2 1";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//
//int main() {
////    test1();
//    test3();
//
//    // must see it, otherwise RTE
//    cout << "\n\nNO RTE\n";
//
//    return 0;
//}
//
