// EB
// Implementing Red-Black Tree in C++

/*

@author: İbrahim Karateke -- 150210705


*/
#include <iostream>

namespace RBT {
  struct Node {
    int data;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;
    int color;
  };
}

class RedBlackTree {
private:
    RBT::Node* root;
    // Perform left rotation on the Red-Black Tree with respect to node 'x'
    void leftRotate(RBT::Node *x) 
    {
        RBT::Node *y = x->right; // Store the right child of 'x' as 'y'
        x->right = y->left; // Set the right child of 'x' to be the left child of 'y'
        // If 'y' has a left child, update its parent to 'x'
        if (y->left != NULL) {
            y->left->parent = x;
        }
        y->parent = x->parent; // Set 'y's parent as 'x's parent
        // Adjust the parent of 'x's parent according to 'x's position
        if (x->parent == NULL) {
            root = y; // If 'x' was the root, set 'y' as the new root
        } else if (x == x->parent->left) {
            x->parent->left = y; // If 'x' was the left child, set 'y' as the left child of 'x's parent
        } else {
            x->parent->right = y; // If 'x' was the right child, set 'y' as the right child of 'x's parent
        }
        y->left = x; // Set 'x' as the left child of 'y'
        x->parent = y; // Update 'x's parent to be 'y'
    }

    // Perform right rotation on the Red-Black Tree with respect to node 'y'
    void rightRotate(RBT::Node *y) 
    {
        RBT::Node *x = y->left; // Store the left child of 'y' as 'x'
        y->left = x->right; // Set the left child of 'y' to be the right child of 'x'
        // If 'x' has a right child, update its parent to 'y'
        if (x->right != NULL) {
            x->right->parent = y; 
        }
        x->parent = y->parent; // Set 'x's parent as 'y's parent
        // Adjust the parent of 'y's parent according to 'y's position
        if (y->parent == NULL) {
            root = x; // If 'y' was the root, set 'x' as the new root
        } else if (y == y->parent->left) {
            y->parent->left = x; // If 'y' was the left child, set 'x' as the left child of 'y's parent
        } else {
            y->parent->right = x; // If 'y' was the right child, set 'x' as the right child of 'y's parent
        }
        x->right = y; // Set 'y' as the right child of 'x'
        y->parent = x; // Update 'y's parent to be 'x'
    }

 // Insertion operation for Red-Black Tree starting from node 'z'
    void inserterRBT(RBT::Node *z) 
    {
      // Continue the loop until 'z' is not the root and its parent's color is red
        while (z != root && z->parent->color == 1) {
          // If 'z's parent is the left child of its grandparent
            if (z->parent == z->parent->parent->left) { // 'y' is the uncle of 'z'
                RBT::Node *y = z->parent->parent->right;
                // Case 1: Uncle 'y' is red
                if (y != NULL && y->color == 1) {
                    z->parent->color = 0;
                    y->color = 0;
                    z->parent->parent->color = 1;
                    z = z->parent->parent;
                } else {
                  // Case 2: Uncle 'y' is black and 'z' is a right child
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                   // Case 3: Uncle 'y' is black and 'z' is a left child 
                    z->parent->color = 0;
                    z->parent->parent->color = 1;
                    rightRotate(z->parent->parent);
                }
            } else { // Similar operations for the right side of the tree
                RBT::Node *y = z->parent->parent->left;
                if (y != NULL && y->color == 1) {
                    z->parent->color = 0;
                    y->color = 0;
                    z->parent->parent->color = 1;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = 0;
                    z->parent->parent->color = 1;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = 0; // Set the color of the root to black
    }
    // Find and return the node with the minimum value in the subtree rooted at 'x'
    RBT::Node* minimumNode(RBT::Node* x)
     {
      // Traverse towards the leftmost node (minimum value node) in the subtree
        while (x->left != nullptr) {
            x = x->left; // Move to the left child
        }
        return x; // Return the node with the minimum value
    }

    // Replace subtree rooted at 'u' with subtree rooted at 'v'
    void transplant(RBT::Node* u, RBT::Node* v)
    {
        if (u->parent == nullptr) {
            root = v; // If 'u' is the root, replace it with 'v'
        } else if (u == u->parent->left) {
            u->parent->left = v; // If 'u' is a left child, replace it with 'v'
        } else {
            u->parent->right = v; // If 'u' is a right child, replace it with 'v'
        }
        if (v != nullptr) {
            v->parent = u->parent; // Set 'v's parent to 'u's parent
        }
    }

    // Fix the Red-Black Tree properties after deletion starting from node 'x'
    void fixDelete(RBT::Node* x) {
        while (x != root && x != nullptr && x->color == 0) {
            if (x == x->parent->left) {
                RBT::Node* w = x->parent->right;  // 'w' is the sibling of 'x'
                // Case 1: Sibling 'w' is red
                if (w->color == 1) {
                    w->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                // Case 2: Sibling 'w' is black and both of 'w's children are black
                if ((w->left == nullptr || w->left->color == 0) &&
                    (w->right == nullptr || w->right->color == 0)) {
                    w->color = 1;
                    x = x->parent;
                } else {
                  // Case 3: Sibling 'w' is black, 'w's right child is black, and 'w's left child is red
                    if (w->right == nullptr || w->right->color == 0) {
                        if (w->left != nullptr)
                            w->left->color = 0;
                        w->color = 1;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    // Case 4: Sibling 'w' is black, 'w's right child is red
                    w->color = x->parent->color;
                    x->parent->color = 0;
                    if (w->right != nullptr)
                        w->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            } else { // Similar operations for the right side of the tree
                RBT::Node* w = x->parent->left;
                if (w->color == 1) {
                    w->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if ((w->right == nullptr || w->right->color == 0) &&
                    (w->left == nullptr || w->left->color == 0)) {
                    w->color = 1;
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->color == 0) {
                        if (w->right != nullptr)
                            w->right->color = 0;
                        w->color = 1;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = 0;
                    if (w->left != nullptr)
                        w->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr)
            x->color = 0; // Set the color of 'x' to black
    }
    // inorder helper function
    void inorderTraverse(RBT::Node* node,std::pair<std::string, int> array[], int& index)
        {
          if(node!=NULL){
            this->inorderTraverse(node->left,array,index);
            array[index].first = node->name;
            array[index].second = node->data;
            index++;
            this->inorderTraverse(node->right,array,index);
          }
        }
    // preorder helper function    
    void preorderTraverse(RBT::Node* node,std::pair<std::string, int> array[], int& index)
        {
          if(node!=NULL){
            array[index].first = node->name;
            array[index].second = node->data;
            index++;
            this->preorderTraverse(node->left,array,index);
            this->preorderTraverse(node->right,array,index);
          }
        }
    //postorder helper function    
    void postorderTraverse(RBT::Node* node,std::pair<std::string, int> array[], int& index)
        {
          if(node!=NULL){
            this->postorderTraverse(node->left,array,index);
            this->postorderTraverse(node->right,array,index);
            array[index].first = node->name;
            array[index].second = node->data;
            index++;
          }
        }  
    //delete node helper function 
    void deleter(RBT::Node* z) {
        if (z == nullptr)
            return; // Node with key k not found

        RBT::Node* y = z;
        RBT::Node* x = nullptr;
        int y_original_color = y->color;
        // Find the node to be deleted and store its original color
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimumNode(z->right);
            y_original_color = y->color;
            x = y->right;

            if (y->parent == z) {
                if (x != nullptr)
                    x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                if (y->right != nullptr)
                    y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            if (y->left != nullptr)
                y->left->parent = y;
            y->color = z->color;
        }
        // Fix the Red-Black Tree properties after deletion if the original color was black
        if (y_original_color==0){
            fixDelete(x);
        }

        delete z; // Free memory allocated for the deleted node
    }
    //getHeight helper function
    int heightCalculator(RBT::Node* root)
        {
          // If the root is NULL, the height is 0
            if(root==NULL){
                return 0;
            }
                // Recursively calculate the height of the left subtree
                int Left=heightCalculator(root->left);
                // Recursively calculate the height of the right subtree
                int Right=heightCalculator(root->right);
                // Return the maximum height of the left or right subtree plus 1 (for the root node)
                return 1+std::max(Left,Right);
        }
    // getTotalNodes helper function    
    int Counter(RBT::Node* root)
        {
          // If the root is NULL, return 0
            if (root==NULL)
                return 0;
            // Return 1 (for the current node) + the count of nodes in the left subtree + count of nodes in the right subtree
            return 1+ Counter(root->left)+ Counter(root->right);
        }
    //destructor helper function    
    void destroy(RBT::Node* x){
      // If x is not NULL, continue with the destruction process
      if(x!=NULL){
        // Recursively destroy the left subtree
        destroy(x->left);
        // Recursively destroy the right subtree
        destroy(x->right);
        // Delete the current node
        delete x;
      }
    }
public:
//constructor
RedBlackTree() {
    root=NULL;
  }
//destructor
~RedBlackTree(){
  destroy(this->root);
}
//moving nodes of tree into array preorder
void preorder(std::pair<std::string, int> array [], int index)
{
    preorderTraverse(this->root,array,index);
}

//moving nodes of tree into array inorder   
void inorder(std::pair<std::string, int> array [], int index) 
{
    inorderTraverse(this->root,array,index);
}

//moving nodes of tree into array postorder    
void postorder(std::pair<std::string, int> array [], int index) 
{
    postorderTraverse(this->root,array,index);
}

//searching a node with given population
RBT::Node *searchTree(int pop) 
    {
    RBT::Node *current = root; // Assuming 'root' is the pointer to the root node of the RBT
    // Traverse the tree until either 'pop' is found or the current node becomes NULL
    while (current != NULL && current->data != pop) {
        if (pop < current->data) {
            current = current->left;
        }
       // If 'pop' is greater than or equal to the data in the current node, move to the right subtree
        else
        {
            current = current->right;
        }
    }

      return current; // Returns either the node containing 'pop' or nullptr if 'pop' is not found
        }
 //finding successor node of a given node
RBT::Node *successor(RBT::Node *myNode) {
    if (myNode == nullptr) {
        return nullptr; // If the node is null, there is no successor
    }

    // Case 1: Node has a right subtree
    if (myNode->right != nullptr) {
        // Find the leftmost node in the right subtree
        RBT::Node *current = myNode->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Case 2: Node doesn't have a right subtree
    // Traverse up to find the first ancestor where myNode is in the left subtree
    RBT::Node *successor = nullptr;
    RBT::Node *ancestor = root; // Assuming 'root' is the pointer to the root node of the RBT

    while (ancestor != nullptr && ancestor != myNode) {
        if (myNode->data < ancestor->data) {
            successor = ancestor; // Update the potential successor
            ancestor = ancestor->left; // Move to the left subtree
        } else {
            ancestor = ancestor->right; // Move to the right subtree
        }
    }

    return successor;
}
 //finding predecessor node of a given node
RBT::Node *predecessor(RBT::Node* myNode) {
    if (myNode == nullptr) {
        return nullptr; // If the node is null, there is no predecessor
    }

    // Case 1: Node has a left subtree
    if (myNode->left != nullptr) {
        // Find the rightmost node in the left subtree
        RBT::Node *current = myNode->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    // Case 2: Node doesn't have a left subtree
    // Traverse up to find the ancestor where myNode is in the right subtree
    RBT::Node *predecessor = nullptr;
    RBT::Node *ancestor = root; // Assuming 'root' is the pointer to the root node of the RBT

    while (ancestor != myNode) {
        if (myNode->data > ancestor->data) {
            predecessor = ancestor; // Update the potential predecessor
            ancestor = ancestor->right; // Move to the right subtree
        } else {
            ancestor = ancestor->left; // Move to the left subtree
        }
    }

    return predecessor;
        }

// insert helper function
void insert(const std::string& name,int data) 
    {
        RBT::Node *z = new RBT::Node;
        z->data = data;
        z->name = name;
        z->left = NULL;
        z->right = NULL;
        z->color = 1; // Red color for the new node

        RBT::Node *y = NULL;
        RBT::Node *x = root;
         // Find the position for insertion
        while (x != NULL) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        // Set the new node as the root if the tree was empty
        if (y == NULL) {
            root = z; // Tree was empty, set z as root
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        inserterRBT(z); // Fix any violations after insertion
    }
// deleting a node 
void deleteNode(int data) 
{
    RBT::Node* k= searchTree(data);
    deleter(k);
}

//get height 
int getHeight() 
{
    return heightCalculator(this->root)-1;
}

//get minimum
RBT::Node* getMinimum()
{
    if(root==NULL)
        return NULL;
    RBT::Node* current = root;    
    while(current->left!=NULL)
        current=current->left;  
    return current;      
}

//get maximum
RBT::Node* getMaximum()
{
    if(root==NULL)
        return NULL;
    RBT::Node* current = root;    
    while(current->right!=NULL)
        current=current->right;  
    return current;   
}

//get total nodes
int getTotalNodes() 
{
    return Counter(this->root);
}
   
};