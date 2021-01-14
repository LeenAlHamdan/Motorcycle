// Created by Leen Al-Hamdan on 11/01/2021.

#ifndef MOTORCYCLE_LINKEDLISTRECORDS_H
#define MOTORCYCLE_LINKEDLISTRECORDS_H

#endif //MOTORCYCLE_LINKEDLISTRECORDS_H

#include "Record.h"

// A linked list node
struct RecordNode {
	Record record;
	struct RecordNode *next;
};

class LinkedListRecords {
private:
	RecordNode *head, *tail;
public:
	LinkedListRecords() {
		head = NULL;
		tail = NULL;
	}

	void insert(Record record) {
		RecordNode *curr = new RecordNode;
		curr->record = record;
		curr->next = NULL;

		if (head == NULL) {
			head = curr;
			tail = curr;
		} else {
			tail->next = curr;
			tail = tail->next;
		}
	}
		
	void remove(RecordNode *curr)
	{
		if(curr==head)
		{
			head=curr->next;
		}
		else
		{
		RecordNode *prev = head;
		while (prev->next != curr) // to get previous node
		{
			prev = (*prev).next;
		}
		if (curr == tail)//remove last node
		{
			prev->next=NULL;
			tail = prev;
		}
		else {
			RecordNode *nodeN = (*prev).next;
			(*prev).next = (*nodeN).next;
		}
		}
	}

	int getSize() {
		int count = 0;
		RecordNode *curr = head;

		while (curr != NULL) {
			count++;
			curr = (*curr).next;
		}
		return count;
	}

	RecordNode *getHead() {
		return head;
	}

	bool isCustomerHasAlreadyReserved(Customer customer) {
		RecordNode *curr = head;
		while (curr!=NULL) {
			if (customer.getFirstName() ==curr->record.getCustomer().getFirstName() &&
					customer.getSurName() ==curr->record.getCustomer().getSurName())
				return true;
			curr=curr->next;
		}
		return false;
	}
};



