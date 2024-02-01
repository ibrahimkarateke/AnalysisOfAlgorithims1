// EB
// Implementing Binary Search Tree in C++

/*

@author: İbrahim Karateke -- 150210705


*/

#include <iostream>

namespace BST {
  struct Node {
    int data;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;
  };
}

class BinarySearchTree {
      private:
        BST::Node *root;
        // insert helper function
        BST::Node* inserter(BST::Node* node, int data, const std::string& name) 
        {
              if (node == NULL) {  //checking if the root is null, if null first insertion node becomes root
                  node = new BST::Node;
                  node->data = data;
                  node->name = name;
                  node->left = NULL;
                  node->right = NULL;
                  node->parent = NULL;
              } else if (data < node->data) { // if population is less than the node insert it as left child -- recursively
                  node->left = inserter(node->left, data, name);
                  node->left->parent = node;
              } else {
                  node->right = inserter(node->right, data, name); // if population is greater than or equal the node insert it as right child -- recursively
                  node->right->parent = node;
              }
              return node; // returns the root
          }

        //inorder helper function
        void inorderTraverse(BST::Node* node,std::pair<std::string, int> array[], int& index)
        {
          if(node!=NULL){
            this->inorderTraverse(node->left,array,index);
            array[index].first = node->name; 
            array[index].second = node->data;
            index++;
            this->inorderTraverse(node->right,array,index);
          }
        }
        //preorder helper function
        void preorderTraverse(BST::Node* node,std::pair<std::string, int> array[], int& index)
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
        void postorderTraverse(BST::Node* node,std::pair<std::string, int> array[], int& index)
        {
          if(node!=NULL){
            this->postorderTraverse(node->left,array,index);
              // Update index after storing data
            this->postorderTraverse(node->right,array,index);
            array[index].first = node->name;
            array[index].second = node->data;
            index++;
          }
        }              
        
        //deleteNode helper function
        BST::Node* deleter (BST::Node* root, int pop){
        // If the root is NULL, return the root
        if (root == NULL)
            return root;
        // If the data to be deleted is smaller, go to the left subtree
        if (root->data > pop) {
            root->left = deleter(root->left, pop);
            return root;
        }
        // If the data to be deleted is greater, go to the right subtree
        else if (root->data < pop) {
            root->right = deleter(root->right, pop);
            return root;
        }
        // If the node has one child or no child
        if (root->left == NULL) {
            BST::Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            BST::Node* temp = root->left;
            delete root;
            return temp;
        }
        // If the node has two children
        else {   
            BST::Node* succParent = root;
            BST::Node* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            // Connect the parent of the successor to the right child of the successor (could be NULL)
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
    
            // Copy Successor Data to root
            root->data = succ->data;   
            // Delete Successor and return root
            delete succ;
            return root;
        }
        }
        //getHeight helper function
        int heightCalculator(BST::Node* root)
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
        int Counter(BST::Node* root)
        {
            // If the root is NULL, return 0
            if (root==NULL)
                return 0;
            // Return 1 (for the current node) + the count of nodes in the left subtree + count of nodes in the right subtree
            return 1+ Counter(root->left)+ Counter(root->right);
        }
        //destructor helper function
        void destroy(BST::Node* x)
        {
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
      // constructor
        BinarySearchTree() {
          this->root=NULL;
        }
        // desctructor 
        ~BinarySearchTree(){
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
        BST::Node *searchTree(int pop) {
            BST::Node *current = root; // Assuming 'root' is the pointer to the root node of the BST
            // Traverse the tree until either 'pop' is found or the current node becomes NULL
            while (current != NULL && current->data != pop) {
                if (pop < current->data) {
                    current = current->left;
                } 
                // If 'pop' is greater than or equal to the data in the current node, move to the right subtree
                else {
                    current = current->right;
                }
            }

        return current; // Returns either the node containing 'pop' or nullptr if 'pop' is not found
        }

        //finding successor node of a given node
        BST::Node *successor(BST::Node *myNode) {
           if (myNode == nullptr) {
                return nullptr; // If the node is null, there is no successor
            }

            // Case 1: Node has a right subtree
            if (myNode->right != nullptr) {
                // Find the leftmost node in the right subtree
                BST::Node *current = myNode->right;
                while (current->left != nullptr) {
                    current = current->left;
                }
                return current;
            }

            // Case 2: Node doesn't have a right subtree
            // Traverse up to find the first ancestor where myNode is in the left subtree
            BST::Node *successor = nullptr;
            BST::Node *ancestor = root; // Assuming 'root' is the pointer to the root node of the BST

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
        BST::Node *predecessor(BST::Node* myNode) {
              if (myNode == nullptr) {
                  return nullptr; // If the node is null, there is no predecessor
              }

              // Case 1: Node has a left subtree
              if (myNode->left != nullptr) {
                  // Find the rightmost node in the left subtree
                  BST::Node *current = myNode->left;
                  while (current->right != nullptr) {
                      current = current->right;
                  }
                  return current;
              }

              // Case 2: Node doesn't have a left subtree
              // Traverse up to find the ancestor where myNode is in the right subtree
              BST::Node *predecessor = nullptr;
              BST::Node *ancestor = root; // Assuming 'root' is the pointer to the root node of the BST

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
        //inserting new node to the structure
        void insert(std::string city, int population) 
        {
        // Call the helper function 'inserter' to insert the city with its population into the BST 
          this->root = inserter(this->root, population, city);
        }

        //deleting a node 
        void deleteNode(int pop) 
        {   
            // Call the helper function 'deleter' to delete the city with its population into the BST                    
            deleter(this->root,pop);
        }
        
        //height of a tree
        int getHeight() 
        {
            // Calculate the height of the tree using the heightCalculator function and subtract 1 (does not count root only edges)
            return heightCalculator(this->root)-1;
        }

        // node which has the minimum population
        BST::Node* getMinimum()
        {
            // If the tree is empty, return NULL
            if(root==NULL)
                return NULL;
            BST::Node* current = root; // Start from the root node
            // Traverse towards the leftmost node (which will have the minimum value in a BST)    
            while(current->left!=NULL)
                current=current->left; // Move to the left child  
            return current;    // Return the node containing the minimum value
        }

        // node which has the maximum population
        BST::Node* getMaximum()
        {
            // If the tree is empty, return NULL
            if(root==NULL)
                return NULL;
            BST::Node* current = root; // Start from the root node
            // Traverse towards the rightmost node (which will have the maximum value in a BST)     
            while(current->right!=NULL)
                current=current->right;  
            return current;   // Return the node containing the maximum value
        }

        // get total nodes  
        int getTotalNodes() 
        {
            // Return the total number of nodes in the tree by calling the Counter function
            return Counter(this->root);
        }
          
        };