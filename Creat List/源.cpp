﻿#include <iostream>
using namespace std;

// 定义链表节点结构体
struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
};

// 添加新节点到链表尾部
void open(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;  // 第一个节点
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// 主函数
int main() {
    Node* head = nullptr;  // 初始化空链表
    int num;

    cout << "请输入一组正整数（输入0结束）：" << endl;

    // 从用户输入中建立链表
    while (cin >> num && num != 0) {
        if (num > 0) {
            open(head, num);
        }
        else {
            cout << "请输入正整数！" << endl;
        }
    }

    // 输出链表
    cout << "你输入的链表是：" << endl;
    printList(head);

    // ⭐ 释放链表占用的内存
    freeList(head);

    return 0;
}
