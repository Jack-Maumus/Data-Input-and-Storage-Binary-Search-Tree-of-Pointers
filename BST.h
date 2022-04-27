/**
 *Provides useful functions for a Binary Search Tree of Vehicle pointers
 *
 *@author Jack Maumus
 *@since 4-19-22
 */

//Creates a new node root
struct Treenode* NewNode(vehicle *Vehicle);

//inserts a node into the BST
struct Treenode* InsertNode(struct Treenode* root, vehicle *Vehicle);

//traverses the BST inorder and prints out the information in readable format
void InorderTraversal(FILE* outFile, struct Treenode* root);

//deallocates the node's vehicle attributes and the node itself
void FreeNode(struct Treenode* root);

//outputs information in a readable format (used by InoderTraversal)
void OutputInfo(FILE* outFile, vehicle *veh);
