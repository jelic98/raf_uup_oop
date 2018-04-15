#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 100

/*
	Maintainer:
 		Lazar Jelic
 		https://github.com/jelic98

	Todo:
		- Add NULL checkers
		- Make struct Value to act like wrapper for non-int values
*/

typedef enum Order {
	ASC,
	DESC
} Order;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Creation
Node* createNode(int);

// Addition
Node* addToStart(Node*, Node*);
Node* addToEnd(Node*, Node*);
Node* addToIndex(Node*, Node*, int);
Node* addAfter(Node*, Node*, Node*);
Node* addSorted(Node*, Node*, Order);
Node* addAllToStart(Node*, int*);
Node* addAllToEnd(Node*, int*);
Node* addAllToIndex(Node*, int*, int);
Node* addAllAfter(Node*, int*, Node*);
Node* addAllSorted(Node*, int*, Order);
Node* addAllNodesToStart(Node*, Node*);
Node* addAllNodesToEnd(Node*, Node*);
Node* addAllNodesToIndex(Node*, Node*, int);
Node* addAllNodesAfter(Node*, Node*, Node*);
Node* addAllNodesSorted(Node*, Node*, Order);

// Removal
Node* removeStart(Node*);
Node* removeEnd(Node*);
Node* removeByValue(Node*, int);
Node* removeByIndex(Node*, int);
Node* removeNext(Node*, Node*);
Node* removeFirstOccurrence(Node*, int);
Node* removeLastOccurrence(Node*, int);
Node* removeDuplicates(Node*);

// Clearing
Node* clear(Node*);
Node* clearFrom(Node*, Node*);
Node* clearFromIndex(Node*, int);
Node* clearToIndex(Node*, int);
Node* clearRange(Node*, int, int);

// Movement
Node* sort(Node*, Order);
Node* rotateLeft(Node*, int);
Node* rotateRight(Node*, int);
Node* reverse(Node*);

// Getters
Node* getStart(Node*);
Node* getEnd(Node*);
Node* getByValue(Node*, int);
Node* getByIndex(Node*, int);
Node* getNext(Node*);
int getFirstOccurrenceIndex(Node*, int);
int getLastOccurrenceIndex(Node*, int);

// Setters
Node* set(Node*, int);
Node* setAtIndex(Node*, int, int);

// Cloning
Node* clone(Node*);
Node* cloneFrom(Node*, Node*);
Node* cloneTo(Node*, Node*);
Node* cloneFromIndex(Node*, int);
Node* cloneToIndex(Node*, int);
Node* cloneRange(Node*, int, int);

// Other
int size(Node*);
int contains(Node*, int);
int count(Node*, int);
int hasNext(Node*);
int isSame(Node*, Node*);
int isPalindrome(Node*);
int containsCycle(Node*);
int* toArray(Node*);
char* toString(Node*);

// Helpers
Node* read(Node*);
void write(Node*);

// Example
int main() {
    Node* list = NULL;

	list = read(list);

	list = rotateRight(addAllAfter(list, toArray(list), getByIndex(list, 1)), 2);

	write(list);

    return 0;
}

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
	
	if(!node) {
		printf("Out of memory\n");
		return node;	
	}
    
	node->value = value;
    node->next = NULL;

    return node;
}

Node* addToStart(Node* root, Node* node) {
    if(root) {
        node->next = root;
    }

    return node;
}

Node* addToEnd(Node* root, Node* node) {
    if(root) {
        Node* tmp = root;

        while(tmp->next) {
            tmp = tmp->next;
        }

        tmp->next = node;

        return root;
    }else {
        return node;
    }
}

Node* addToIndex(Node* root, Node* node, int index) {
	if(root) {
        Node* tmp = root;

		if(index) {
			while(tmp->next && --index > 0) {
            	tmp = tmp->next;
       	 	}

			node->next = tmp->next;
			tmp->next = node;
		}else {
			root = addToStart(root, node);
		}

		return root;
    }else {
        return node;
    }
}

Node* addAfter(Node* root, Node* value, Node* node) {
	Node* tmp = value;
	
	if(root && node) {	
		if(tmp) {
			tmp->next = node->next;
			node->next = tmp;
		}
		
		return root;
	}else {
		return tmp;
	}
}

Node* addSorted(Node* root, Node* node, Order order) {
	Node* tmp = root;

	if((tmp->value >= node->value && order == ASC)
		|| (tmp->value <= node->value && order == DESC)) {
			node->next = tmp;
			return node;
	}

	while(tmp) {
		if(tmp->next) {
			if((tmp->next->value >= node->value && order == ASC)
				|| (tmp->next->value <= node->value && order == DESC)) {
				node->next = tmp->next;
				tmp->next = node;
				break;
			}
			
			tmp = tmp->next;	
		}else {
			tmp->next = node;
			break;
		}
	}

	return root;
}

Node* addAllToStart(Node* root, int* values) {
	while(*values) {
		root = addToStart(root, createNode(*values++));
	}
	
	return root;
}

Node* addAllToEnd(Node* root, int* values) {
	while(*values) {
		root = addToEnd(root, createNode(*values++));
	}

	return root;
}

Node* addAllToIndex(Node* root, int* values, int index) {
	while(*values) {
		root = addToIndex(root, createNode(*values++), index++);	
	}
	
	return root;
}

Node* addAllAfter(Node* root, int* values, Node* node) {
	while(*values && node) {
		root = addAfter(root, createNode(*values++), node);	
		node = node->next;
	}
	
	return root;
}

Node* addAllSorted(Node* root, int* values, Order order) {
	while(*values) {
		root = addSorted(root, createNode(*values++), order);	
	}

	return root;
}

Node* addAllNodesToStart(Node* root, Node* values) {
	Node* tmp = values;
	
	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = root;
	
	return values;
}

Node* addAllNodesToEnd(Node* root, Node* values) {
	return addAllNodesToStart(values, root);
}

Node* addAllNodesToIndex(Node* root, Node* values, int index) {
	if(!index) {
		return addAllNodesToStart(root, values); 	
	}

	Node* prev = root;
	Node* next = NULL;

	while(prev->next && --index > 0) {
		prev = prev->next;
	}

	next = prev->next;
	prev->next = values;

	while(values->next) {
		values = values->next;
	}

	values->next = next;
	
	return root;
}

Node* addAllNodesAfter(Node* root, Node* values, Node* node) {
	Node* prev = root;
	Node* next = NULL;

	while(prev != node) {
		prev = prev->next;
	}

	next = prev->next;
	prev->next = values;
	
	while(values->next) {
		values = values->next;
	}

	values->next = next;

	return root;
}

Node* addAllNodesSorted(Node* root, Node* values, Order order) {
	Node* tmp = NULL; 
	
	root = sort(root, order);

	while(values) {
		tmp = values->next;
		values->next = NULL;

		root = addSorted(root, values, order);	
		
		values = tmp;
	}
	
	return root;
}

Node* removeStart(Node* root) {
	Node* tmp = root->next;

	free(root);

	return tmp;
}

Node* removeEnd(Node* root) {
	Node* tmp = root;
	Node* prev = NULL;

	while(tmp->next) {
		tmp = (prev = tmp)->next;
	}

	free(tmp);

	if(prev) {
		prev->next = NULL;
	}else {
		root = NULL;
	}

	return root;
}

Node* removeByValue(Node* root, int value) {
    Node* tmp = root;
    Node* prev = NULL;

    while(tmp) {
        if(tmp->value == value) {
			if(prev) {
            	prev->next = tmp->next;

				free(tmp);

				tmp = prev->next;
			}else {
				root = tmp->next;

				free(tmp);

				tmp = root;
			}
        }else {
        	tmp = (prev = tmp)->next;
		}
    }

    return root;
}

Node* removeByIndex(Node* root, int index) {
	Node* tmp = root;
    Node* prev = NULL;

    while(tmp && index-- > 0) {
        tmp = (prev = tmp)->next;
    }

	if(prev) {
		prev->next = tmp->next;

		free(tmp);
	}else {
		root = tmp->next;
		
		free(tmp);
	}

    return root;
}

Node* removeNext(Node* root, Node* node) {
	if(node && node->next) {
		Node* tmp = node->next->next;
	
		free(node->next);

		node->next = tmp;
	}

	return root;
}

Node* removeFirstOccurrence(Node* root, int value) {
	int index = getFirstOccurrenceIndex(root, value);
	
	if(index == -1) {
		return root;
	}

	return removeByIndex(root, index);
}

Node* removeLastOccurrence(Node* root, int value) {
	int index = getLastOccurrenceIndex(root, value);
	
	if(index == -1) {
		return root;
	}

	return removeByIndex(root, index);
}

Node* removeDuplicates(Node* root) {
	Node* tmp = root;
	
	while(tmp){
		Node* curr = tmp->next;
		Node* prev = tmp;

		while(curr) {
			if(curr->value == tmp->value){
				prev->next = curr->next;
			}else {
				prev = curr;
			}
	
			curr = curr->next;
		}
		
		tmp = tmp->next;
	}

	return root;
}

Node* clear(Node* root) {
	Node* tmp = NULL;

	while(root) {	
		tmp = root->next;

		free(root);

		root = tmp;
	}

	return root;
}

Node* clearFrom(Node* root, Node* node) {
	Node* tmp = root;
	
	if(tmp != node) {
		while(tmp && tmp->next != node) {
			tmp = tmp->next;
		}
	}

	clear(node);

	tmp->next = NULL;
	
	return root;
}

Node* clearFromIndex(Node* root, int index) {
	clear(getByIndex(root, index));

	Node* prev = getByIndex(root, index - 1);

	if(prev) {
		prev->next = NULL;
	}else {
		root = NULL;
	}

	return root;
}

Node* clearToIndex(Node* root, int index) {
	while(root->next && index-- > 0) {
		free(root);

		root = root->next;

		if(!root->next && index > 0) {
			root = NULL;
			break;
		}
	}

	return root;
}

Node* clearRange(Node* root, int start, int end) {
	Node* tmp = root;
	Node* prev = NULL;
	int offset = -1;

	while(tmp && ++offset < start) {
		tmp = (prev = tmp)->next;
	}

	while(tmp && start++ <= end) {
		free(tmp);

		tmp = tmp->next;
	}

	if(prev) {
		prev->next = tmp;
	}else {
		root = tmp;
	}

	return root;
}

Node* sort(Node* root, Order order) {
	Node* tmp = root;
	Node* curr = NULL;
	int i, j, p;

	while(tmp->next) {
		curr = tmp->next;

		while(curr) {
			if((curr->value < tmp->value && order == ASC)
				|| (curr->value > tmp->value && order == DESC)) {
				p = tmp->value;
				tmp->value = curr->value;
				curr->value = p;
			}

			curr = curr->next;
		}

		tmp = tmp->next;
	}

	return root;
}

Node* rotateLeft(Node* root, int offset) {
	Node* end = getEnd(root);

	while(offset-- > 0) {
		end->next = root;
		root = root->next;
		end = end->next;
		end->next = NULL;
	}

	return root;
}

Node* rotateRight(Node* root, int offset) {
    Node* tmp = root;

    int len = 0;

    while(tmp->next){
        tmp = tmp->next;
        len++;
    }

    tmp->next=root;

    int preLen = len - offset % len;

    Node *pre = root;

    while(preLen--) {
        pre = pre->next;
    }

    root = pre->next;
    pre->next = NULL;

    return root;
}

Node* reverse(Node* root) {
	root = clone(root);

    Node* tmp = root;
	Node* prev = NULL;
    Node* next = NULL;

    while(tmp) {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }

	root = prev;

	return root;
}

Node* getStart(Node* root) {
	return root;
}

Node* getEnd(Node* root) {
	while(root->next) {
		root = root->next;
	}

	return root;
}

Node* getByValue(Node* root, int value) {
	return getByIndex(root, getFirstOccurrenceIndex(root, value));
}

Node* getByIndex(Node* root, int index) {
	if(index >= 0) {
		while(root->next && --index >= 0) {
			root = root->next;
		}
	}else {
		root = NULL;
	}
	
	if(index > 0) {
		root = NULL;	
	}

	return root;			
}

Node* getNext(Node* root) {
	return root->next;
}

int getFirstOccurrenceIndex(Node* root, int value) {
	int index = 0;

	while(root) {
		if(root->value == value) {
			return index;
		}

		index++;

		root = root->next;
	}

	return -1;
}

int getLastOccurrenceIndex(Node* root, int value) {
	int index = 0;
	int occurrence = -1;

	while(root) {
		if(root->value == value) {
			occurrence = index;
		}

		index++;

		root = root->next;
	}

	return occurrence;
}

int size(Node* root) {
	int size = 0;

	while(root) {
		size++;
		root = root->next;
	}

	return size;
}

int contains(Node* root, int value) {
	while(root) {
		if(root->value == value) {
			return 1;	
		}	

		root = root->next;
	}

	return 0;
}

int count(Node* root, int value) {
	int count = 0;

	while(root) {
		if(root->value == value) {
			count++;	
		}

		root = root->next;
	}

	return count;
}

int hasNext(Node* root) {
	if(root && root->next) {
		return 1;
	}

	return 0;	
}

Node* set(Node* root, int value) {
	root->value = value;

	return root;
}

Node* setAtIndex(Node* root, int index, int value) {
	Node* tmp = getByIndex(root, index);
	tmp->value = value;

	return root;
}

Node* clone(Node* root) {
	Node* newRoot = NULL;
	
	if(root) {
		newRoot = createNode(root->value);
		Node* tmp = newRoot;
		
		root = root->next;

		while(root) {
			tmp = tmp->next = createNode(root->value);
			
			root = root->next;
		}
	}	

	return newRoot;
}

Node* cloneSingle(Node* node) {
	return createNode(node->value);	
}

Node* cloneFrom(Node* root, Node* node) {
	return clone(node);
}

Node* cloneTo(Node* root, Node* node) {
	Node* newRoot = NULL;
	Node* tmp = NULL;

	if(root && node && root != node) {
		tmp = newRoot = cloneSingle(root);

		root = root->next;

		while(root && root->next != node) {
			tmp->next = cloneSingle(root);
			tmp = tmp->next;

			root = root->next;
		}
	}

	return newRoot;	
}

Node* cloneFromIndex(Node* root, int index) {
	return clone(getByIndex(root, index));
}

Node* cloneToIndex(Node* root, int index) {
	Node* newRoot = NULL;
	Node* tmp = NULL;

	while(root->next && index-- > 0) {
		if(newRoot) {	
			tmp->next = cloneSingle(root);
			tmp = tmp->next;
		}else {
			newRoot = cloneSingle(root);
			tmp = newRoot;
		}
		
		root = root->next;
	}

	return newRoot;
}

Node* cloneRange(Node* root, int start, int end) {
	Node* newRoot = NULL;
	Node* tmp = NULL;
	int offset = -1;

	while(root && ++offset < start) {
		root = root->next;
	}

	while(root && start++ <= end) {
		if(newRoot) {
			tmp->next = cloneSingle(root);
			tmp = tmp->next;
		}else {
			newRoot = cloneSingle(root);
			tmp = newRoot;
		}

		root = root->next;
	}

	return newRoot;
}

int isSame(Node* first, Node* second) {
	while(1) {
		if(!first && !second) {
			return 1;	
		}else if((first && !second) || (!first && second)) {
			return 0;
		}else if(first->value != second->value) {
			return 0;
		}
	
		first = first->next;
		second = second->next;
	}
}

int isPalindrome(Node* root) {
	return isSame(root, reverse(root));
}

int containsCycle(Node* root) {
	Node* slow = NULL;

	while(root && root->next && slow) {
		root = root->next;
		slow = slow->next;

		if(slow->value == root->value) {
			return 1;
		}
	}

	return 0;
}

int* toArray(Node* root) {
	int i = 0;
	int* arr;

	arr = (int*) malloc(ARR_SIZE * sizeof(arr));

	if(!arr) {
		printf("Out of memory\n");
		return arr;	
	}

	while(root) {
		arr[i++] = root->value;

		root = root->next;
	}

	return arr;
}

char* toString(Node* root) {
	int i = 0;
	
	char* s;

	s = (char*) malloc(ARR_SIZE * sizeof(s));
	
	if(!s) {
		printf("Out of memory\n");
		return s;	
	}

	while(root) {
		s[i++] = '[';
		s[i++] = root->value + '0';
		s[i++] = ']';
		s[i++] = '-';
		s[i++] = '>';

		root = root->next;
	}

	s[i - 2] = '\0';
	
	return s;
}

Node* read(Node* list) {
    int value;

    while(1) {
        scanf("%d", &value);

        if(value == 0) {
            break;
        }

        list = addToEnd(list, createNode(value));
    }

    return list;
}

void write(Node* list) {
	while(list) {
        printf("%d ", list->value);
		list = list->next;
    }

    printf("\n");
}
