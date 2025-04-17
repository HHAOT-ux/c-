#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
  // 构造函数
    Node(int x) : val(x), next(nullptr) {}
};
//创建链表
Node* createList() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int num;

    while (cin >> num && num != 0) {
        if (num > 0) {
            Node* newNode = new Node(num);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        else {
            cout << "请输入正整数！" << endl;
        }
    }

    return head;
}
// 遍历输出
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
// 释放内存
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "请输入一组正整数（输入0结束）：" << endl;
    Node* head = createList();

    cout << "你输入的链表是：" << endl;
    printList(head);

    freeList(head);
    return 0;
}
