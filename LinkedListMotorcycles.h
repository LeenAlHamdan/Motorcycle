// Created by Leen Al-Hamdan on 11/01/2021.

#ifndef MOTORCYCLE_LINKEDLISTMOTORCYCLE_H
#define MOTORCYCLE_LINKEDLISTMOTORCYCLE_H

#endif //MOTORCYCLE_LINKEDLISTMOTORCYCLE_H

// A linked list node
struct MotorcycleNode {
    Motorcycle motorcycle;
    struct MotorcycleNode *next;
};

class LinkedListMotorcycles {
private:
    MotorcycleNode *head, *tail;
public:
    LinkedListMotorcycles() {
        head = NULL;
        tail = NULL;
    }

    void insert(Motorcycle motorcycle) {
        MotorcycleNode *curr = new MotorcycleNode;
        curr->motorcycle = motorcycle;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = tail->next;
        }
    }

    void remove(int n) {
        MotorcycleNode *nodeBeforeN = head;
        for (int i = 0; i < n - 1; i++) {
            nodeBeforeN = (*nodeBeforeN).next;
        }
        MotorcycleNode *nodeN = (*nodeBeforeN).next;
        (*nodeBeforeN).next = (*nodeN).next;
    }

    int getSize() {
        int count = 0;
        MotorcycleNode *curr = head;

        while (curr != NULL) {
            count++;
            curr = (*curr).next;
        }
        return count;
    }

    MotorcycleNode *getHead() {
        return head;
    }

    void updateMotorcycle(string name) {
        MotorcycleNode *currNode = head;
        while (head != tail) {
            if ((currNode->motorcycle).getMotorcycleName() == name) {
                currNode->motorcycle.setIsBooked(!currNode->motorcycle.isBooked1());
                break;
            }
            currNode = currNode->next;
        }
    }

};
