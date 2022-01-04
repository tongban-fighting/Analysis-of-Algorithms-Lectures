#include <iostream>

using namespace std;

typedef struct Node{
	int value;
	struct Node* next;
}ListNode;

typedef ListNode* List;

List revList(List prevList);

int main(){
	List prevList;
	List temp,prev;
	
	for(int i = 0; i < 5; i++){
		temp = new ListNode;
		temp->value = i;
		temp->next = NULL;
		if(i == 0){
			prevList = temp;
		}
		else{
			prev->next = temp;
		}
		prev = temp;
	}

	cout << "Previous sequence:" << endl;

	temp = prevList;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout<<endl;

	cout << "After Reverse:"<<endl;
	prevList = revList(prevList);
	
	temp = prevList;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout<<endl;

	return 0;
}

List revList(List prevList){
	List first, second, third;
	
	//find the length of prevList
	List temp = prevList;
	int n = 0;
	while(temp != NULL){
		n++;
		temp = temp->next;
	}
	
	if(n == 0 || n == 1)
		return prevList;
	if(n == 2){
		first = prevList;
		second = prevList->next;

		second->next = first;
		first->next = NULL;
		
		return second;
	}
	

	first = prevList;
	second = prevList->next;
	third = second->next;

	while(second != NULL){
		second->next = first;
		first = second;
		second = third;
		if(third != NULL)
			third = third->next;
	}
	prevList->next = NULL;

	return first;
}
