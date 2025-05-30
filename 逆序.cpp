#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    // 构造函数
    Node(int x) : val(x), next(nullptr) {}
    //默认参数
    //Node() : val(0), next(nullptr) {}
};
//创建链表(逆序)
Node* createList() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int num;

    while (cin >> num && num != 0) {
        Node* temp = new Node(num);
        temp->next = head;
        head = temp;  // 把新节点作为新的头节点
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
    //cout << "请输入一组正整数（输入0结束）：" << endl;
    Node* head = createList();
    //text
   /* int a,b;
    cin >> a>>b;
    findList(head, a);
     cout << "你输入的链表是：" << endl;*/
    printList(head);

    freeList(head);
}