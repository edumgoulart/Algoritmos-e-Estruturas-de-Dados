/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//main
struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL) {
        return head;
    }

    int len = 0;
    
    //newHead aponta para o comeco da lista
    struct ListNode newHead;
    newHead.next = head;

    //tail aponta para newHead
    struct ListNode *tail = &newHead;

    //descobre o tamanho da lista e guarda em len, e tail aponta para o fim da lista
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    //prev aponta para newHead
    struct ListNode *prev = &newHead;
    //cur aponta para head
    struct ListNode *cur = head;

    //como k pode ser maior que len, subitrai-se o modulo de k por len
    len = len - (k % len);

    //cur vai apontar para o elemento que vai comecar a lista rotacionada, ou seja, head = cur
    //prev vai apontar para o ultimo elemento da lista rotacionada
    while (len > 0) {
        prev = cur;
        cur = cur->next;
        len--;
    }

    //verifica se ao rotacionar a lista a lista nao vai ficar igual
    if (cur != NULL) {
        //o ultimo elemento nao vai apontar para mais ninguem
        prev->next = NULL;

        //o que era o ultimo elemento agora aponta para o comeco da lista antiga
        tail->next = head;

        //atualiza head
        head = cur;
    }

    return head;
}