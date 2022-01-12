#include<iostream>
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>
 #include <cstdlib>
 #include <vector>
 #include <iterator>
 #include <algorithm>
 #include <stdio.h>
 #include <stdlib.h>
 using namespace std;

 template<typename Comparable>

 class BinarySearchTree
 {
    
   public:
     BinarySearchTree( )
     {
         root = nullptr;
     }

     ~BinarySearchTree( )
     {
         makeEmpty( );
     }

     bool isEmpty( ) const
     {
         return root == nullptr;
     }

     void makeEmpty( )
     {
         makeEmpty( root );
     }


     void insert( const Comparable & x )
     {
         insert( x, root );
     }
     
     void post_printTree( ostream & out = cout ) const
      {
          if( isEmpty( ) )
              out << "Empty tree" << endl;
          else
              post_printTree( root, out );
      }
      
      void pre_printTree( ostream & out = cout ) const
      {
          if( isEmpty( ) )
              out << "Empty tree" << endl;
          else
              pre_printTree( root, out );
      }
      
     void post_level()
     {
         cout<< " This tree is in post-order form: " <<endl;
     }
      
     void pre_level()
     {
         cout<< " This tree is in pre-order form: " << endl;
     }
     
     int height()
     {
         return height(root);
     }
     
     int isBalanced()
     {
         return isBalanced(root);
     }
     
     bool isBST()
     {
         return isBST(root);
     }
     
     private:
         struct BinaryNode
         {
             Comparable element;
             BinaryNode *left;
             BinaryNode *right;

             BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
             {
                 element = theElement;
                 left = lt;
                 right = rt;
             }
         };

         BinaryNode *root;
     
     void insert( const Comparable & x, BinaryNode * & root_ptr )
     
      // At first, root_ptr was pointing to the null, so when the new node was created by the new keyword, the root_ptr was assigned the adress of the new pointer.
     
      // All the calculations start from the root and since the root_ptr was assigned the adress of the first node ( root node), we can call the root_ptr to make calculations.
     
      // each time a node is created, the address of the newly created node is assigned to the left or right pointer of the passing node, inside the insert function. For example, when insert(1,0) was called, the the address of the newly created node was asssigned to the left poibter of the 200.
      
      {
          if( root_ptr == nullptr )
              root_ptr = new BinaryNode(x, nullptr, nullptr);  // first poiter points to n
          else if( x < root_ptr->element )
              insert( x, root_ptr->left );
          else if( root_ptr->element < x )
              insert( x, root_ptr->right );
          else
              ;  // Duplicate; do nothing
      }
     
     
     void makeEmpty( BinaryNode * & t )   // deleting each node.
     {
         if( t != nullptr )
             
         {   makeEmpty( t->left );
             makeEmpty( t->right );
             delete t;
         }
         t = nullptr;
     }
     

     // post-order traversal
     void post_printTree( BinaryNode *t, ostream & out ) const
     {
         
         if( t != nullptr )
             
         {
             post_printTree( t->left, out );
                     
             post_printTree( t->right, out );
             
             out << t->element << " " <<endl;
         }
     }
     
     //pre_order traversal (N->L->R)
     void pre_printTree( BinaryNode *t, ostream & out ) const
     {
         if( t != nullptr )
         {
             out << t->element << " " << endl;
             pre_printTree( t->left, out );
             pre_printTree( t->right, out );
         }
     }
     
     int height(BinaryNode* t) const // finding the height of the tree.
         {
             if( t==nullptr)
                 return -1;
             else
             {
                 int LeftNodes_H= height(t->left);
                 
                 int RightNodes_H= height(t->right);
        
                 return max(LeftNodes_H, RightNodes_H)+1;
                 
             }
                 
        }
     
    int isBalanced(BinaryNode* t) // checking if the tree is blanced or not
    {
        if( t==nullptr)
            return -1;
        else
        {
            int LeftNodes_H= isBalanced(t->left);
           
            int RightNodes_H= isBalanced(t->right);
    
            if ( abs(LeftNodes_H-RightNodes_H)<=1)
            {
                return max( LeftNodes_H, RightNodes_H)+1;
            }
            else
                return -1;
              
        }
    }
    bool isBST(BinaryNode *t) // checking if the tree is Binary search tree or not.
     {
        if (t == NULL)
        {
            return true;
        }
        
        else
        
        {
            if ((t->left != NULL && t->element < t->left->element) || (t->right != NULL && t->element > t->right->element))
            {
                return false;
            }
            return isBST(t->left) && isBST(t->right);
        }
    }

 };


 int main()
 {
     
     BinarySearchTree<int> t; //instantiate an empty BST of integers
     
     t.insert(6);
     t.insert(2);
     t.insert(8);
     t.insert(1);
     t.insert(4);
     t.insert(3);
     t.post_level();
     t.post_printTree();
     t.pre_level();
     t.pre_printTree();
     
     cout << " The height is : " << t.height() <<endl;
     
     if (t.isBalanced()==-1)
     {
         cout<< " The tree is not balanced " << endl;
     }
     
     else
         cout << " The tree is balanced " << endl;
     
     if ( t.isBST()==true)
     {
         cout<< " The Tree is binary search tree " << endl;
     }
     
     else
     {
         cout<< " The Tree is not a binary search tree " << endl;
     }
     
     
};

