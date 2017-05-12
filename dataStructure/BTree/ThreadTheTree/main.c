#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

struct Node
{
    BTreeNode header;
    char v;
};

void printf_data(BTreeNode* node)
{
    if ( node!=NULL )
    {
        printf("%c", ((struct Node*)node)->v);
    }
}

void thread_via_left(BTreeNode* root,BTreeNode** pp)
{
    if ( (root!=NULL) && (pp!=NULL) )
    {
        if ( *pp != NULL )
        {
            (*pp)->left = root;
            *pp = root;
        }
        if ( root->left == NULL )
        {
            *pp = root;
        }
        thread_via_left(root->left,pp);
        thread_via_left(root->right,pp);
    }
}

int main(int argc, char const *argv[])
{
    BTree* tree = BTree_Create();
    BTreeNode* current = NULL;
    BTreeNode* p = NULL;
    int i = 0;


    struct Node n1 = {{NULL,NULL},'A'};
    struct Node n2 = {{NULL,NULL},'B'};
    struct Node n3 = {{NULL,NULL},'C'};
    struct Node n4 = {{NULL,NULL},'D'};
    struct Node n5 = {{NULL,NULL},'E'};
    struct Node n6 = {{NULL,NULL},'F'};

    BTree_Insert(tree,(BTreeNode*)&n1,0,0,0);
    BTree_Insert(tree,(BTreeNode*)&n2,0x00,1,0);
    BTree_Insert(tree,(BTreeNode*)&n3,0x01,1,0);
    BTree_Insert(tree,(BTreeNode*)&n4,0x00,2,0);
    BTree_Insert(tree,(BTreeNode*)&n5,0x02,2,0);
    BTree_Insert(tree,(BTreeNode*)&n6,0x02,3,0);

    printf("Full Tree: \n");

    BTree_Display(tree,printf_data,4,'-');

    printf("Thread via left: \n");

    current = BTree_Root(tree);

    thread_via_left(current,&p);

    while ( current != NULL )
    {
        printf("%c, ", ((struct Node*)current)->v);

        current = current->left;
    }
    
    printf("\n");
    

    BTree_Destroy(tree); 

    return 0;
}