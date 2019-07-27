/*
	Maintainer:
 		Lazar Jelic	(https://github.com/jelic98)

	TODO:
		- Add NULL checkers
		- Make union Value to act like a wrapper for non-int values
*/

#ifndef H_TREE_INCLUDE
#define H_TREE_INCLUDE

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Creation
Node* createNode(int);

// Addition
Node* addValue(Node*, int);
Node* addNode(Node*, Node*);
Node* addAll(Node*, int*);

// Removal
Node* removeValue(Node*, int);

// Clearing
Node* clear(Node*);

// Getters
Node* getRoot(Node*);
Node* getByValue(Node*, int);
Node* getMin(Node* root);
Node* getMax(Node* root);

// Setters
Node* set(Node*, int);

// Cloning
Node* clone(Node*);

// Other
int size(Node*);
int contains(Node*, int);
int count(Node*, int);
int hasLeft(Node*);
int hasRight(Node*);
int isLeaf(Node*);
int isSame(Node*, Node*);
int* toArray(Node*);
char* toString(Node*);

// Helpers
Node* read(Node*);
void write(Node*);

#ifdef H_TREE_IMPLEMENT

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
	
	if(!node) {
		printf("Out of memory\n");
		return node;	
	}
    
	node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* addValue(Node* root, int value) {
	return addNode(root, createNode(value));
}

Node* addNode(Node* root, Node* node) {
	if(!root) {
		return node;
	}
  
    if(root->value > node->value) {
        root->left = addNode(root->left, node);
	}else if(root->value < node->value) {
        root->right  = addNode(root->right, node);
	}

    return root;
}

Node* addAll(Node* root, int* values) {
	while(*values) {
		root = addValue(root, *values++);
	}
	
	return root;
}

Node* removeValue(Node* root, int value) {
	if(!root) {
		return root;
	}

    if(value < root->value) {
        root->left = removeValue(root->left, value);
	}else if(value > root->value) {
        root->right = removeValue(root->right, value);
    }else {
        if(!hasLeft(root)) {
            Node* tmp = root->right;
			free(root);
			return tmp;
        }else if(!hasRight(root)) {
            Node* tmp = root->left;
			free(root);
			return tmp;
        }
  
        Node* tmp = getMin(root->right);
        root->value = tmp->value;
        root->right = removeValue(root->right, tmp->value);
    }

	return root;
}

Node* clear(Node* root) {
	if(!root) {
		return root;
	}

	clear(root->left);
	clear(root->right);
	
	free(root);

	root->value = 0;
	root->left = NULL;
	root->right = NULL;
	root = NULL;

	return root;
}

Node* getRoot(Node* root) {
	return root;
}

Node* getByValue(Node* root, int value) {
	if(!root) {
		return root;
	}
 
    if(root->value > value) {
        return getByValue(root->left, value);
	}else if(root->value < value) {
        return getByValue(root->right, value);
	}

	return NULL;
}

Node* getMin(Node* root) {
	Node* current = root;

	while(current->left) {
		current = current->left;
	}

	return current;
}

Node* getMax(Node* root) {
	Node* current = root;

	while(current->right) {
		current = current->right;
	}

	return current;
}

Node* set(Node* root, int value) {
	root->value = value;

	return root;
}

Node* clone(Node* root) {
	if(!root) {
		return root;
	}

	Node* node = createNode(root->value);
	node->left = clone(root->left);
	node->right = clone(root->right);

	return node;
}

int size(Node* root) {
	if(!root) {
		return 0;
	}

	return size(root->left) + size(root->right) + 1;
}

int contains(Node* root, int value) {
	if(!root) {
		return 0;
	}

	if(root->value == value) {
		return 1;
	}

	return contains(root->left, value) || contains(root->right, value);
}

int count(Node* root, int value) {
	if(!root) {
		return 0;
	}

	int count = contains(root->left, value) + contains(root->right, value);
	
	return count + root->value == value;
}

int hasLeft(Node* root) {
	return root && root->left;
}

int hasRight(Node* root) {
	return root && root->right;
}

int isLeaf(Node* root) {
	return !hasLeft(root) && !hasRight(root);
}

int isSame(Node* first, Node* second) {
	if(!first && !second) {
		return 1;
	}

	if((!first && second) || (first && !second)) {
		return 0;
	}

	if(first->value != second->value) {
		return 0;
	}

	return isSame(first->left, second->left) && isSame(first->right, second->right);
}

Node* read(Node* root) {
    int value;

    while(1) {
        scanf("%d", &value);

        if(value == 0) {
            break;
        }

        root = addValue(root, value);
    }

    return root;
}

void write(Node* root) {
	if(!root) {
		return;
	}

	write(root->left);

	printf("%d\n", root->value);
	
	write(root->right);
}

#endif
#endif
