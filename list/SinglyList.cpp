/* https://leetcode-cn.com/problems/design-linked-list
下标从 0 开始！！！ 头节点 -> 节点0 -> 节点1  */
#include <iostream>

// 定义单链表
struct SinglyListNode {
  int val;
  SinglyListNode *next;
  SinglyListNode(int x) : val(x), next(NULL) {} //  构造函数
};

class MyLinkedList {
public:
  MyLinkedList() { this->head = new SinglyListNode(0); }

  /* 获取链表中第 index 个节点的值。如果索引无效，则返回-1。 */
  int get(int index) {
    if ((index + 1) > this->head->val || index < 0)
      return -1;
    else {
      SinglyListNode *p;
      p = this->head->next; // 节点 0
      for (int i = 0; i < index; i++) {
        p = p->next;
      }
      return p->val;
    }
  }

  /* 在链表的第一个元素之前添加一个值为 val
   * 的节点。插入后，新节点将成为链表的第一个节点。 */
  void addAtHead(int val) {
    SinglyListNode *q = this->head->next;
    SinglyListNode *p = new SinglyListNode(val);
    p->next = q;
    this->head->next = p;
    this->head->val++; // 链表长度标记加一
  }

  /* 将值为 val 的节点追加到链表的最后一个元素。 */
  void addAtTail(int val) {
    SinglyListNode *p = this->head;
    while (p->next) {
      p = p->next;
    }
    SinglyListNode *q = new SinglyListNode(val);
    p->next = q;
    this->head->val++;
  }

  /*   在链表中的第 index 个节点之前添加值为 val  的节点。如果
   * index等于链表的长度，则该节点将附加到链表的末尾。如果 index
   * 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
   */
  void addAtIndex(int index, int val) {
    if (index <= this->head->val && index > 0) { 
      SinglyListNode *p;
      p = this->head;
      for (int i = 0; i < index; i++) {
        p = p->next;
      }
      SinglyListNode *q = new SinglyListNode(val);
      q->next = p->next;
      p->next = q;
      this->head->val++;
    } else if (index <= 0) {
      this->addAtHead(val);
    }
  }

  /* 如果索引 index 有效，则删除链表中的第 index 个节点。 */
  void deleteAtIndex(int index) {
    if (index < this->head->val && index > 0) {
      SinglyListNode *p;
      p = this->head->next;
      for (int i = 1; i < index; i++) {
        p = p->next;
      }
      SinglyListNode *q = p->next;
      p->next = q->next;
      delete q;
      this->head->val--;
    } else if ((index+1) == this->head->val) { // 删除尾巴节点
      SinglyListNode *p;
      p = this->head;
      for (int i = 1; i < index; i++) {
        p = p->next;
      }
      SinglyListNode *q = p->next;
      p->next = NULL;
      delete q;
      this->head->val--;
    }else if (index==0) { // 删除节点 0
    SinglyListNode *p;
      p = this->head;
      SinglyListNode *q = p->next; // 节点 0
      p->next = q->next;
      delete q;
      this->head->val--;
    }
  }

  /* 显示列表元素 */
  void showList(char div = ' ') {
    SinglyListNode *p = this->head->next;
    while (p) {
      std::cout << p->val << div;
      p = p->next;
    }
    std::cout << std::endl;
  }

private:
  SinglyListNode *head; // 头节点指针，值代表链表长度
};

int main() {
  MyLinkedList linkedList = *new MyLinkedList();
  linkedList.addAtHead(1);
  linkedList.addAtTail(3);
  linkedList.addAtIndex(1, 2); // 链表变为1-> 2-> 3
  linkedList.showList();
  std::cout << linkedList.get(1) << std::endl; // 返回2
  linkedList.deleteAtIndex(1); // 现在链表是1-> 3
  linkedList.showList();
  std::cout << linkedList.get(1) << std::endl; // 返回3
  
  return 0;
}