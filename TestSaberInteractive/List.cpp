#include "List.h"

#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <random>

void List::Serialize(std::ostream& stream)
{
	assert(stream.good());

	stream << count << std::endl;
	std::map<ListNode*, int> idxRandListNode;

	int idx = 0;
	for (auto node = head; node != nullptr; node = node->next) {
		stream << node->data << std::endl;
		idxRandListNode.emplace(node, idx++);
	}

	for (auto node = head; node != nullptr; node = node->next) {
		stream << idxRandListNode[node->rand] << std::endl;
	}
}

void List::Deserialize(std::istream& stream)
{
	assert(stream.good());

	clear();

	int length = 0;
	stream >> length;

	assert(length >= 0);

	if (length == 0)
		return;

	std::vector< ListNode*> idxRandListNode;
	idxRandListNode.reserve(length);

	std::string data;
	std::getline(stream, data); //move file ptr.
	for (int i = 0; i < length; ++i) {
		std::getline(stream, data);
		this->push_back(data);
		idxRandListNode.push_back(tail);
	}

	int idx;
	for (auto node = head; node != nullptr; node = node->next) {
		stream >> idx;
		assert(idx >= 0 && idx < count);
		node->rand = idxRandListNode[idx];
	}
}

bool List::empty()
{
	return this->count == 0;
}

void List::clear()
{
	if (empty())
		return;

	auto node = head; 
	while (node) {
		auto next = node->next;
		delete node;
		node = next; 
	}

	head = tail = nullptr;
	count = 0;
}

void List::setRandNode()
{
	if (this->empty())
		return; 
	std::vector< ListNode*> idxRandListNode;
	idxRandListNode.reserve(count);

	int nodeIdx = 0;
	for (auto node = head; node != nullptr; node = node->next)
		idxRandListNode.push_back(node);

	std::random_device rd;
	std::uniform_int_distribution<int> uid(0, count - 1);
	for (auto node = head; node != nullptr; node = node->next) {
		int randIdx = uid(rd);
		node->rand = idxRandListNode[randIdx];
	}
}

void List::print()
{
	for (auto node = head; node != nullptr; node = node->next)
		std::cout << "str = " << node->data << " : rand str = " << node->rand->data << std::endl;
}

void List::push_back(const std::string& data)
{
	if (!head) {
		head = new ListNode();
		head->data = data;
		tail = head;
		head->next = head->prev = nullptr;
	}
	else {
		tail->next = new ListNode();
		tail->next->prev = tail;
		tail = tail->next;
		tail->next = nullptr;
		tail->data = data;
	}
	++count;
}

bool operator==(const List& left, const List& right)
{
	if (left.count != right.count)
		return false; 

	auto p_left = left.head, p_right = right.head;
	while (p_left) {
		if (p_left->data != p_right->data)
			return false;
		p_left = p_left->next;
		p_right = p_right->next; 
	}
	return true; 
}
