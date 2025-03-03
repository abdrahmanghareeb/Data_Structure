////
//// Created by Ghareeb on 2/13/2025.
////
//
//#include <iostream>
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
//
//    Node(int data) :
//            data(data) {
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
//    int length = 0;    // let's maintain how many nodes
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
//    ~LinkedList() {
//
//        while (head) {
//            Node *cur = head->next;
//            delete head;
//            head = cur;
//        }
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
//        cout << node->data << " ";
//        if (node->next == nullptr)
//            cout << "X ";
//        else
//            cout << node->next->data << " ";
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
//            return;
//        }
//
//        assert(head != nullptr);
//        assert(tail != nullptr);
//        assert(tail->next == nullptr);
//
//        if (length == 1)
//            assert(head == tail);
//        else {
//            assert(head != tail);
//
//            if (length == 2)
//                assert(head->next == tail);
//            else if (length == 3) {
//                assert(head->next);
//                assert(head->next->next == tail);
//            }
//        }
//        int len = 0;
//        Node *prev = nullptr;
//        for (Node *cur = head; cur; prev = cur, cur = cur->next, len++)
//            assert(len < 10000);    // Consider infinite cycle?
//
//        assert(length == len);
//        assert(length == (int) debug_data.size());
//        assert(prev == tail);    // last node is tail
//    }
//
//    ////////////////////////////////////////////////////////////
//    void print_length() {
//        cout << "length: " << length << endl;
//    }
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
//    void insert_end(int value) {
//        Node *item = new Node(value);
//        add_node(item);
//
//        if (!head)
//            head = tail = item;
//        else
//            tail->next = item, tail = item;
//
//        debug_verify_data_integrity();
//    }
//
//    void get_nth(int n) {
//        int j = 1;
//        for (Node *cur = head; cur; cur = cur->next) {
//            if (j == n) {
//                cout << cur->data << endl;
//                break;
//            }
//            j++;
//        }
////        //OR
////        Node* tempHead = head ;
////        if (n <= length && n >0 ){
////            for(int i =1  ; i != n ; i ++){
////                tempHead = tempHead->next;
////            }
////            cout<< tempHead->data;
////        }else{
////            cout<<"null";
////        }
//    }
//
//    void search(int value) {
//        int index = 0;
//        for (Node *cur = head; cur; cur = cur->next) {
//            if (cur->data == value) {
//                cout << index << endl;
//                break;
//            }
//            index++;
//            if (index > length - 1) cout << "item " << value << " not found!" << endl;
//        }
//    }
//
//    void improvedSearch(int value) {
//        int index = 0;
//        Node *previous = nullptr;
//        for (Node *cur = head; cur; previous = cur, cur = cur->next) {
//            if (cur == head) {
//                if (cur->data == value) {
//                    cout << index << endl;
//                    break;
//                }
//                index++;
//            } else {
//                if (cur->data == value) {
//                    cout << index << endl;
//                    //swap
//                    Node *temp = new Node(0);
//                    temp->data = previous->data;
//                    previous->data = cur->data;
//                    cur->data = temp->data;
//                }
//                index++;
//            }
//            if (index > length - 1) cout << "item " << value << " not found!" << endl;
//        }
//    }
//
//    void insert_front(int value) {
//        Node *new_node = new Node(value);
//        add_node(new_node);
//        if (!head) {
//            head = tail = new_node;
//            length++;
//            return;
//        }
//        new_node->next = head;
//        head = new_node;
//        length++;
//        debug_verify_data_integrity();
//    }
//
//    void delete_front() {
//        if (!head) return;
//        Node *temp = head;
//        head = head->next;
////        length--; // length is decreased in the delete_node once
//        delete_node(temp);
//        if (!head) tail = nullptr;
//        debug_verify_data_integrity();
//    }
//
//    void get_nth_back(int value) {
//        int ctr = 0;
//        bool flag = false;
//        for (Node *cur = head; cur; cur = cur->next, ctr++) {
//            if (cur->data == value) {
//                cout << "get_nth_back: " << length - ctr << endl;
//                flag = true;
//            }
//        }
//        if (!flag) cout << "the node not found" << endl;
//    }
//
//    void is_same1(LinkedList &list) {
//        Node *cur1 = head;
//        Node *cur2 = list.head;
//        if (length != list.length) {
//            cout << "is not the same" << endl;
//            return;
//        }
//        for (int i = 0; i < length; i++) {
//            if (cur1->data == cur2->data) {
//                cur1 = cur1->next;
//                cur2 = cur2->next;
//            } else {
//                cout << "is not the same " << endl;
//                return;
//            }
//        }
//        cout << "is the same" << endl;
//    }
//
//    void is_same2(const LinkedList &list) {
//        Node *cur1 = head;
//        Node *cur2 = list.head;
////        bool flag = true;
//        while (1) {
//            //one and one
//            if (!cur1 || !cur2) {
//                cout << "is not the same" << endl;
//                return;
//            }
//            if (cur1->data != cur2->data) {
//                cout << "is not the same" << endl;
//                return;
//            }
//            cur1 = cur1->next;
//            cur2 = cur2->next;
//            if (!cur1 && !cur2) {
//                cout << "is the same" << endl;
//                return;
//            }
//        }
//    }
//
//    void insert_end2(int value) {
//        if (!head) {
//            head = new Node(value);
//            return;
//        }
//        for (Node *cur = head; cur; cur = cur->next) {
//            if (cur->next == nullptr) {
//                cur->next = new Node(value);
//                return;
//            }
//        }
//    }
//
//    //1 1 3 4 5 2 1 1 2 2 2
//    void move_back(int key) {
//        Node *temp = tail;
//        int ctr = 1;
//        // ctr <= length we can check using ctr++ but this will increase the time
//        for (Node *cur = head, *prev = nullptr; cur != temp;) {
//            if (cur->data == key && cur == head) {
//                head = cur->next;
//                tail->next = cur;
//                cur->next = nullptr;
//                tail = cur;
//                cur = head;
//                continue;
//            }
//            if (cur->data == key) {
//                prev->next = prev->next->next;
//                tail->next = cur;
//                tail = cur;
//                cur->next = nullptr;
//                cur = prev->next;
//                continue;
//
//            }
//            prev = cur;
//            cur = cur->next;
//        }
//        debug_verify_data_integrity();
//    }
//
//    void get_max(Node *cur = nullptr, int max = 0) {
//        if (!head) { cout << "list is empty"; return;}
//        else if (!cur) {
//            cur = head;
//            max = head->data;
//        }else if (cur->data > max) {
//            max = cur->data;
//        }
//        if (cur == tail) {
//            cout << "max: " << max << endl;
//            return;
//        }
//        get_max(cur->next, max);
//    }
//
//    void delete_nth(int n) {
//        int ctr = 1;
//        Node *cur;
//        for (cur = head; cur; cur = cur->next, ctr++) {
//            if (n < 1 || n > length) return;
//            if (n == 1) {
//                delete_front();
//                return;
//            }
//            if (ctr == n - 1) {
//                Node *temp = cur->next;
//                cur->next = cur->next->next;
//                // handel tail
//                if (n == length)
//                    tail = cur;
//                // update the length and delete the node.
//                delete_node(temp);
//                break;
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//    void delete_even() {
//        int ctr = 2;
//        int old_length = length;
//        while (ctr <= old_length) {
//            delete_nth(ctr);
//            ctr += 1;
//        }
//    }
//
//    void delete_even2() {
//        bool even = (length % 2 == 0);
//        for (Node *cur = head; cur; cur = cur->next) {
//            Node *temp = cur->next;
//            cur->next = cur->next->next;
//            delete_node(temp);
//            if (cur->next->next == nullptr && even) tail = cur;
//        }
//        debug_verify_data_integrity();
//    }
//
////check if there is an element in the list have the same data
//    bool check_if_exist(const LinkedList &list, int data) {
//        for (Node *cur = list.head; cur; cur = cur->next) {
//            if (cur->data == data) return true;
//        }
//        return false;
//    }
//
//    void delete_duplicate() {
//        LinkedList list;
//        Node *temp; // to carry the tail
//        for (Node *cur = head, *prev = nullptr; cur; ) {
//            if (check_if_exist(list, cur->data)) { // ture
//                prev->next = prev->next->next;
//                delete_node(cur);
//                cur = prev->next; // in the next loop the cur will be cur-> next which is prev->next->next
//            } else {
//                list.insert_end(cur->data);
//                temp = cur; // carry the last expected tail.
//                // update prev and cur
//                prev = cur;
//                cur = cur->next;
//            }
//        }
//        tail = temp;
//        debug_verify_data_integrity();
//    }
//
//
//
//    void delete_last_occurance(int key) {
//        int n; // number of last occurance node
//        int ctr = 1;
//        for (Node *cur = head; cur; cur = cur->next, ctr++) {
//            if (cur->data == key) n = ctr;
//        }
//        delete_nth(n);
//        debug_verify_data_integrity();
//    }
//
//    void delete_next(Node* &prev, Node* &cur){
//        Node* temp = prev->next;
//        if(!prev->next) return;
//        if(prev->next == tail) {
//            tail = prev;
//        }
//        prev->next = prev->next->next;
//        cur = prev->next;
//        delete_node(temp);
//        debug_verify_data_integrity();
//    }
//
//    void delete_cur(Node* &prev, Node* &cur){
//        if(!cur || !prev) return;
//        if(cur == head) { delete_front(); return;}
//        Node* temp  = cur;
//        if(cur == head) {
//            head = head->next;
//        }else if(cur == tail){
//            tail = prev;
//        }
//        cur = cur->next;
//        prev->next = cur;
//        delete_node(temp);
//    }
//
//    void delete_rear(){
//        if(!head) return;
//        for(Node* cur = head ; cur ; cur = cur->next){
//            if(cur->next == tail){
//                delete_node(tail);
//                tail = cur;
//                tail->next= nullptr;
//            }else if(cur == tail){ // head = tail
//                delete_node(tail);
//                head = tail = nullptr;
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//
//
//    void delete_all_duplicates(){
//        Node * prev = head , * cur =head->next  ,*deleted;
//        int temp = 0 ; // to delete the first repeated node 1(2)2(3)33
//        while(cur ){
//            if(prev->data == cur->data){
//                temp = prev->data;
//                delete_cur(prev, cur);
//            }
//            else if(prev->data == temp){
//                if(prev == head) head = head->next;
//                deleted = prev;
//                // relink
//                for(Node* curr = head ; curr ; curr = curr->next){
//                    if(curr->next == prev){
//                        prev = curr;
//                        prev->next= cur;
//                        break;
//                    }
//                }
//                delete_node(deleted);
//                prev = cur;
//                cur = cur->next;
//            }else{
//                prev = cur;
//                cur = cur->next;
//            }
//        }
//        // delete the last node if it is repeated 122(3)33 and update tail
//        if(!cur& prev->data == temp){
//            //delete rear
//            delete_rear();
//        }
//
//        debug_verify_data_integrity();
//    }
//
//
//    void reverse_list2() {
//        Node *prev = head;
//        Node *cur = head->next;
//        while (cur) {
//            if (prev == head) {
//                prev->next = nullptr;
//            }
//            Node *temp = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = temp;
//        }
//        swap(tail, head);
//        debug_verify_data_integrity();
//    }
//
//    void reverse_list3(){
//        Node* temp;
//        if(!head) return;
//
//        for(Node* prev = head, *cur = head->next ; cur ; prev = cur , cur = temp  ){
//            if(prev==head){
//                prev->next = nullptr;
//            }
//            temp = cur->next;
//            cur->next = prev ;
//
//        }
//        swap(head, tail);
//        debug_verify_data_integrity();
//    }
//
//    void reverse_with_key(int key){
//        int x = length/key; // number of series will be reversed.
//        int rem = length%key; // to calculate the number of iterations needed for the last series// rem is the special key for the last series (3 2 1 6 5 4 *8 7* )
//        if(!head) return;
//        if(length<=  key) { reverse_list3();  return;}
//        Node* prev = head , *cur = head->next , * temp , *fairy_tail1 , *fairy_tail2; // fairy tails to carry the head of the new series and the tail of the last series
//        bool tick_tock = true ; // if the iteration even or odd and reverse the fairy_tail1 and fairy_tail2
//        ////////////////////////////////////////////////////////////////////////
//        // save the old head 3 2 (1) 4 5 6
//        fairy_tail1 = prev;
//        for(int i = 1 ; i < key && temp ; i++, prev = cur, cur = temp ){
//            temp = cur->next;
//            cur->next = prev ;
//            cout<<"";
//            if(fairy_tail1 == head && i == key-1){
//                //reposition the head
//                head->next = temp;
//                head = cur;
//                // rearrange the pointers
//                fairy_tail2 = fairy_tail1->next ;
//                i=-1;
//                x--;
//                cout<<""; // -1 0 1 rem-1  //
//            } else if ( i== rem-2 && x==0 && !tick_tock){
//                fairy_tail2->next = temp;
//                fairy_tail1->next = nullptr;
//                tick_tock = true;
//            }else if ( i== rem -2 && x==0 && tick_tock){
//                fairy_tail1->next = temp;
//                fairy_tail2->next = nullptr;
//                tick_tock = false;
//            }
//            else if(i == key-1 && tick_tock){
//                if ( !temp ) fairy_tail2->next = nullptr;
//                else fairy_tail2->next = temp;
//                fairy_tail1->next = cur;
//                tick_tock =false;
//                // rearrange the pointers
//                 fairy_tail1 = fairy_tail2->next;
//                 i = -1;
//                 x--;
//                cout<<"";
//            }else if(i == key-1 && !tick_tock){
//                if ( !temp ) fairy_tail1->next = nullptr;
//                else fairy_tail1->next = temp;
//                fairy_tail2->next = cur;
//                tick_tock = true;
//                // rearrange the pointers
//                 fairy_tail2 = fairy_tail1->next;
//                 i = -1;
//                 x--;
//                cout<<"";
//            }
//        }
//        if(tick_tock){
//            tail = fairy_tail1;
//        }else{
//            tail = fairy_tail2;
//        }
//    }
//
//        ///////////////////////////////////////////////////////////////////////
//
//
//    void swap_pairs() {
//        //update head and tail
//        if (head) {
//            for (Node *cur = head; cur; cur = cur->next->next) {
//                if (cur->next) {
////                    if(cur == head ) head = cur->next;
////                    if(cur->next == tail) tail = cur;
//
//                } else break;
//            }
//        }
//        debug_verify_data_integrity();
//    }
//
//    void swap_head_and_tail() {
//        if (head && head != tail) {
//            tail->next = head->next;
//            for (Node *cur = head; cur; cur = cur->next) {
//                if (cur->next == tail) {
//                    cur->next = head;
//                    head->next = nullptr;
//                }
//            }
//
//            swap(head, tail);
//        }
//        debug_verify_data_integrity();
//    }
//
//    void rotate_left(int k) {
//        k = k % length;
//        while (k--) {
//            Node *temp = head;
//            head = head->next;
//            tail->next = temp;
//            tail = temp;
//            tail->next = nullptr;
//        }
//        debug_verify_data_integrity();
//    }
//
//
//    void insert_sorted(int value) {
//        Node *node = new Node(value);
//        if (!head) { head = tail = node; }
//        else if (head->data > node->data) {
//            node->next = head;
//            head = node;
//        } else if (tail->data < node->data) {
//            tail->next = node;
//            tail = node;
//        } else {
//            Node *prev = head;
//            for (Node *cur = head->next; cur; prev = prev->next, cur = cur->next) {
//                if (node->data > prev->data && node->data < cur->data) {
//                    node->next = cur;
//                    prev->next = node;
//                }
//            }
//        }
//        add_node(node);
//        debug_verify_data_integrity();
//    }
//    //insert odd and even position
//    void arrange_odd_even(){
//        Node* even_start = head->next;         // node to hold the even sequence
//        Node* odd = head , *even = head->next; // to pass through the even and odd nodes
//        while(odd->next){                      // break the loop
//            odd->next = even->next;
//            if(odd->next){
//                odd = odd->next;
//                even->next = odd->next;
//                even = even->next;
//            }
//        }
//        odd->next = even_start;  // link the two sequence
//        tail = even;             // update the tail
//    }
//
//
//    void insert_alternate(LinkedList &list){
//
//        if(length == 0 || list.length ==0 ) return;
//
//        Node *first_cur = head->next , *sec_cur = list.head->next;
//        Node *first_prev = head , *sec_prev = list.head;
//        while(first_cur && sec_cur){
//            // link the nodes
//            first_prev->next = sec_prev;
//            sec_prev->next = first_cur;
//            //move forward in the two lists
//            first_prev =  first_cur; first_cur = first_cur->next;
//            sec_prev = sec_cur ;     sec_cur = sec_cur->next;
//        }
//        // handel tail and ends
//        if(length <= list.length) {
//            // list the last two nodes in the lists
//            first_prev->next = sec_prev; // link the ends
//            tail = list.tail;
//        }
//        else if(length > list.length) {
//            first_prev->next = sec_prev;
//            sec_prev->next = first_cur;
//        }
//        // update the length
//        length = length + list.length;
////        debug_verify_data_integrity();
//    }
//
//////////////////////////////////////////////////////////////
//
////REVERSE LIST
//    Node *f(Node *cur) {
//        if (cur && cur->next) {
//            Node *rem = f(cur->next);
//            rem->next = cur;
//            cur->next = nullptr;
//        }
//        return cur;
//    }
//
//    void reverse_list() {
//        f(head);
//        swap(head, tail);
//        debug_verify_data_integrity();
//    }
//
//};
//
//void test1() {
//    cout << "\n\ntest1\n";
//    LinkedList list;
//    LinkedList list2;
//
//    list.insert_end2(1);
//    list.insert_end2(2);
//    list.insert_end2(3);
//    list.insert_end2(4);
//    list.insert_end2(5);
//    list.insert_end2(6);
//
//    list2.insert_end(1);
//    list2.insert_end(2);
//    list2.insert_end(3);
//    list2.insert_end(4);
//    list2.insert_end(5);
//    list2.insert_end(6);
////    list2.insert_end(6);
//    // some actions
//    list.is_same2(list2);
//
//    list.print();
//
//    string expected = "1 2 3 4 5 6";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result
//             << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//void test2() {
//    cout << "\n\ntest2\n";
//    LinkedList list;
//    LinkedList list2;
//
//
//    list.insert_end(1);
//    list.insert_end(2);
//    list.insert_end(3);
//    list.insert_end(4);
//    list.insert_end(5);
//    list.insert_end(6);
//    list.insert_end(7);
//    list.insert_end(8);
//    list.insert_end(9);
//    list.insert_end(10);
//    list.insert_end(11);
//    list.insert_end(12);
//    list.insert_end(13);
//    list.insert_end(14);
//
//
//    list.reverse_with_key(9);
//    list.print();
//
//    string expected = "9 8 7 6 5 4 3 2 1 14 13 12 11 10";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result
//             << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//void test3() {
//    cout << "\n\ntest3\n";
//    LinkedList list;
//    LinkedList list2;
//
//
//    list2.insert_end(1);
//    list2.insert_end(2);
//    list2.insert_end(3);
//    list2.insert_end(4);
//    list2.insert_end(5);
//    list2.insert_end(6);
//
//
//    list.insert_alternate(list2);
//    list.print();
//
//    string expected = "9 8 7 6 5 4 3 2 1 14 13 12 11 10";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " << expected << "\nResult  : " << result
//             << "\n";
//        assert(false);
//    }
//    list.debug_print_list("********");
//}
//
//
//int main() {
////    test1();
//    test3();
//    // must see it, otherwise RTE
//    cout << "\n\nNO RTE\n";
//
//    return 0;
//}
//
