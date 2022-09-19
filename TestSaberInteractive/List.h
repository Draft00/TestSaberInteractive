#ifndef LIST_H
#define LIST_H

#include <string>

class ISerializable {
	virtual void Serialize(std::ostream& stream) = 0;
	virtual void Deserialize(std::istream& stream) = 0;
};

struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand;
	std::string data;
};


class List : public ISerializable {
public:
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int count = 0;

public:
	void Serialize(std::ostream& stream) override;
	void Deserialize(std::istream& stream) override;

	bool empty();
	void clear();
	void setRandNode();
	void print();	
	void push_back(const std::string& data);

	friend bool operator == (const List& left, const List& right);
};

#endif // !LIST_H
