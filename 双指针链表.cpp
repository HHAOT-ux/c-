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
// 删除指定位置的节点（0 表示删除头部）
void deleteList(Node*& head, int pos)
{
    if (!head) return;
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    int index = 0;
    while (curr->next && index < pos - 1) {
        curr = curr->next;
        index++;
    }
    //删除位置超出链表长度
    if (!curr->next) {
        return;
    }
    //删除节点（非头节点）
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
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

// 插入：在 pos 位置插入一个值为 val 的节点（从 0 开始）
void insertList(Node*& head, int pos, int val)
{
    Node* temp = new Node(val);
    if (pos == 0) {
        temp->next = head;
        head = temp;
        return;
    }
    Node* tou = head;
    int i = 0;
    //减一是因为从 0 开始
    while (tou && i < pos-1) {
        tou = tou->next;
        i++;
    }
    if (tou) {
        temp->next = tou->next;
        tou->next = temp;
    }
    else {
        delete temp;
    }
}
// 查找
void findList(Node*& head, int pos) {
    int i = 0;
    Node *temp = head;
    while (temp && i < pos ) {
        i++;
        temp = temp->next;
    }
    if(temp)
    cout << temp->val;
    return;
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
