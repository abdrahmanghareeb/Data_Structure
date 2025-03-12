//
// Created by Ghareeb on 3/4/2025.
//

#include <iostream>
#include <cassert>

using namespace std;

class Stack {
private:
    int size{};
    int added_elements{};
    int *array{};
public:
    Stack(int size) :
            size(size), added_elements(0) {
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        assert(!isFull());
        array[added_elements++] = x;
    }

    int pop() {
        assert(!isEmpty());
        return array[--added_elements];
    }

    int peek() {
        assert(!isEmpty());
        return array[added_elements - 1];
    }

    int isFull() {
        return added_elements == size;
    }

    int isEmpty() {
        return added_elements == 0;
    }

    void display() {
        for (int i = added_elements - 1; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }
    void reverse_display() {
        for (int i = 0; i < added_elements ; i++)
            cout << array[i] << " ";
        cout << "\n";
    }

    /*
    * get the length of the line.
    * loop on the line.
    * check the spaces.
    *
    */
    string reverse_subwords(string line) {
        string result; //
        line += ' '; //abc d efg xy .
        Stack s(line.size());

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                while (!s.isEmpty()) {
                    result += s.pop();
                }
                result += ' ';
            } else {
                s.push(line[i]);
            }
        }
        result.erase(line.length() - 1);
        return result;
    }

    int reverse_number(int x) {
        int result = 0;
        while (x) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }

    int reverse_number2(int x) {
        int result = 0;
        Stack s(15);
        while (x) {
            s.push(x % 10); //4 3 2 1
            x /= 10;
        }
        int tens = 1;
        while (!s.isEmpty()) {
            result = s.pop() * tens + result; //4 , 43 , 432 , 4321
            tens *= 10;
        }
        return result;
    }

    /*

    void valid_parentheses2(string line) {
        // "(()())"
        // number of open = number of close
        // () [] {}
        // stack?
        // 3 stack
        // for every open drop one
        Stack s1(15);
        Stack s2(15);
        Stack s3(15);
        for (int i = 0; i < line.length(); i++) {
            switch (line[i]) {
            case '(' :
                s1.push(line[i]);
                break;
            case ')':
                if (s1.isEmpty())
                {
                    cout << "not valid" << endl;
                    return;
                }
                s1.pop();
                break;
            case '[':
                s2.push(line[i]);
                break;
            case ']':
                if (s2.isEmpty())
                {
                    cout << "not valid" << endl;
                    return;
                }
                s2.pop();
                break;
            case '{':
                s3.push(line[i]);
                break;
            case '}':
                if (s3.isEmpty())
                {
                    cout << "not valid" << endl;
                    return;
                }
                s3.pop();
                break;
            }
        }
        if (s1.added_elements == 0 && s2.added_elements == 0 && s3.added_elements == 0)
            cout << "valid" << endl;
        else
            cout << "not valid" << endl;
    }
    */
    void delete_adjacent_duplicates(string line) {
        string result;
        Stack s(line.length());
        for (int i = line.length() - 1; i >= 0; i--) {
            s.push(line[i]);
        }
        for (int i = line.length() - 1; i >= 0; i--) {

        }
        while (!s.isEmpty()) {

        }
    }

    char check_close(char x) {
        if (x == ')')
            return '(';
        else if (x == '}')
            return '{';
        else if (x == ']')
            return '[';
        return ' ';
    }

    bool valid_parentheses(string line) {
        Stack s(line.length());
        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];
            if (ch == '(' || ch == '[' || ch == '{')
                s.push(ch);
            else if (s.isEmpty() || s.pop() != check_close(ch))
                return false;
        }
        return s.isEmpty();
    }
//    void asteroid_collesion(){
//        int first , sec , winner;
//        int i = added_elements;
//        while(!isEmpty()&& added_elements >1 && i--) {
//            if( (first>0 && sec>0) || (first<0 && sec<0) )
//                break;
//            first = pop(); //-5
//            sec = pop();  //10
//            winner = 0;
//            // check direction. if(first<0)
//            // check who is the winner
//            if (::abs(first) > ::abs(sec) && first < 0 && sec>0) {
//                winner = first;
//                push(winner);
//            } else if (::abs(sec) > ::abs(first) && first < 0 && sec>0) {
//                winner = sec;
//                push(winner);
//            }else if(::abs(sec) == ::abs(first) && first < 0 && sec>0){
//                //both are losers
//            }
//            else{
//                push(first);
//                push(sec);
//            }
//        }
//        display();
//    }

    bool same_direction(int first, int sec) {
        if (first < 0 && sec >= 0) {
            return false;
        } else {
            return true;
        }
    }

    // if first is +ve pop and add to result
    // if first is -ve check values with the sec
    void asteroid_collesion() {
        Stack s(size);
        int first, sec, winner;
        int temp;
        while (!isEmpty()) {
            first = pop();
            if (first >= 0) {
                s.push(first);
                continue;
            }
            while (first < 0 && !isEmpty()) {
                sec = pop();
                if (!same_direction(first, sec)) {
                    if (::abs(first) < ::abs(sec)) {
                        // this loop will be breaked
                        first = sec;
                        push(sec); // to be loaded again above
                        break; // not mandatory
                    } else if (::abs(first) > ::abs(sec)) {
                        if (added_elements == 1)// this means that only first is in the stack
                            break;
                    } else if (::abs(first) == ::abs(sec)) {
                        first = pop(); // delete both first and sec
                    }
                } else {
                    // push first , pop new
                    s.push(first);
                    first = sec;
                }
            }
        }
        // handel only the last node depending on its direction
        s.display();

    }

    /*
     * if top is +ve add to result
     * if
     * */

    void insert_bottom(int value) {
        int top = added_elements - 1;
        if (!isFull()) {
            // shift all the array to the right
            for (int i = top; i >= 0; i--) {
                array[i + 1] = array[i];
            }
            added_elements++; // update top
            array[0] = value;
        }
    }

    void reverse_stack() {
        size *= 2; // extend the size of the stack
        int top = added_elements - 1; // 3
        int old_added_elements = added_elements;
        int to_be_insserted = 0;
        // if the array is [1 2 3 4]
        for (int i = 0; i < old_added_elements - 1; i++) { // 0,1,2
            to_be_insserted = added_elements - top;// 4-3= 1=> 5-2= 3=> 6-1 = 5
            insert_bottom(array[to_be_insserted]); // added elements var is updated
            top--;                                       // 2 , 1
            // the array is [2 1 2 3 4]     when i = 0
            // the array is [3 2 1 2 3 4]   when i = 1
            // the array is [4 3 2 1 2 3 4] when i = 2
        }
        added_elements = old_added_elements; // reset the added elements pointer
        size /= 2; //reset
    }

    /*
     * 5*4*3*2*1
     * */
    int normal_factorial(int value) {
        if (value > 1)
            return value * normal_factorial(value - 1);
        else
            return 1;
    }

    int stack_factorial(int value) {
        int res = 1;
        while (value) {
            push(value);
            value--;
        }
        while (!isEmpty()) {
            res *= pop();
        }
        return res;
    }

    int find_next_greater(int index) {
        int value = array[index];
        int max = -1;
        bool flag = false;
        for (int i = index; i < added_elements; i++) {
            if (array[i] == value) {
                flag = true;
            } else if (flag && value < array[i]) {
                max = array[i];
                break;
            }
        }
        return max;
    }
    void next_greater_for_all_stack() {
        Stack s(added_elements);
        int i=0;
        while(i <= added_elements-1 ){
            s.push(find_next_greater(i));
            i++;
        }
        s.reverse_display();
    }
};

//array of two stacks
class DStack {
private:
    //top1+top2 = size-1
    // top2 = size-1 - top1
    // for the first stack, add elements from the start of the array to the top.
    // for the sec stack, add elements from the end of the stack to the begaining.
    // this is better than shifting all the elements forward and backward everytime we do push of pop.
    int top1{};
    int top2{};
    int size{};
    int *array{};
public:
    DStack(int size) : size(size) {
        top1 = -1, top2 = size;
        array = new int[size];
    }

    bool is_full() {
        if (top1 == top2 - 1)
            return true;
        else
            return false;
    }

    bool is_empty() {
        if (size - 1 == top2 + top1)
            return true;
        else
            return false;
    }

    void push(int stack_index, int value) {
        if (!is_full()) {
            if (stack_index == 1) {
                array[++top1] = value;
            } else if (stack_index == 2) {
                array[--top2] = value;
            }
        }
    }

    void pop(int stack_index) {
        if (!is_empty()) {
            if (stack_index == 1) {
                top1--;
            } else if (stack_index == 2) {
                top2++;
            }
        }
    }

    int peek(int stack_index) {
        if (!is_empty()) {
            if (stack_index == 1) {
                return array[top1];
            } else if (stack_index == 2) {
                return array[top2];
            }
        }
        return -1;
    }

    void display(int stack_index) {
        if (!is_empty()) {
            if (stack_index == 1) {
                for (int i = top1; i >= 0; i--) {
                    cout << array[i] << " ";
                }
            } else if (stack_index == 2) {
                for (int i = top2; i <= size - 1; i++) {
                    cout << array[i] << " ";
                }
            }
        }
        cout << endl;
    }

};

void test1() {
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);

    if (!stk.isFull())
        stk.push(50);
    else
        cout << "Full Stack\n";
    stk.display();    // 30 20 10
    cout << stk.peek() << "\n";    // 30

    while (!stk.isEmpty()) {
        cout << stk.peek() << " ";
        stk.pop();
    } // 30 20 10
}

void test2() {
    Stack stack(4);
    string line = "abc d efg xy";
    cout << stack.reverse_subwords(line) << endl;
}

void test3() {
    Stack stack(4);
    int x = 1234;
    cout << stack.reverse_number2(x) << endl;
}

void test4() {
    Stack stack(4);
    string line = "([[({})]])[()]{{{}()}}";
    if (stack.valid_parentheses(line)) {
        cout << "valid" << endl;
    } else {
        cout << "not valid" << endl;
    }
}

void test5() {
    DStack dstack(10);
    dstack.push(1, 1);
    dstack.push(1, 2);
    dstack.push(1, 3);
    dstack.push(1, 4);
    dstack.push(2, 5);
    dstack.push(2, 6);
    dstack.push(2, 7);
    dstack.push(2, 8);
    dstack.push(2, 9);
    dstack.push(2, 10);

    cout << dstack.peek(1) << endl;
    cout << dstack.peek(2) << endl;
    dstack.display(1);
    dstack.display(2);
}

void test6() {
    Stack s(4);
//    s.push(10);
//    s.push(2);
//    s.push(-5);
    /////////////////////////
    s.push(2);
    s.push(-5);
    s.push(2);
    s.push(10);
    ///////////////////////////
    s.asteroid_collesion();
}

void test7() {
    Stack s(9);

    s.push(2);
    s.push(3);
    s.push(-5);
    s.push(-6);
    s.push(-7);
    s.push(10);
    s.push(-2);
    s.push(1);
    s.push(4);
    s.asteroid_collesion();
    s.display();
}

void test8() {
    Stack s(9);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.display();
    s.reverse_stack();
    s.display();
}

void test9() {
    Stack s(9);
    s.push(8);
    s.push(73);
    s.push(74);
    s.push(75);
    s.push(71);
    s.push(69);
    s.push(72);
    s.push(76);
    s.push(73);
    cout << s.find_next_greater(3) << endl;
    s.next_greater_for_all_stack();

}

int main() {

    test9();
    cout << "NO RTE!!";

    return 0;
}