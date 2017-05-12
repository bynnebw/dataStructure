#include <stdio.h>
#include <sys/malloc.h>
#include "BTree.h"

/*
**  书写二叉树，主要的关键地方是寻找插入位置，这里的方法采用的是“指路法”进行定位
**  核心在于，如何解决指针一步一步移动的问题。在C语言中利用bit位进行指路。
*/

typedef struct _tag_BTree TBTree;
struct _tag_BTree
{
    int count;
    BTreeNode* root;
};

static void recursive_display(BTreeNode* node,BTree_Printf* pFunc,int format,int gap,char div)
{
    int i = 0;

    if ( (node!=NULL) && (pFunc!=NULL) )
    {
        for ( i=0;i<format;i++)
        {
            printf("%c", div);
        }
        pFunc(node);
        printf("\n");

        if ( (node->left != NULL) || (node->right != NULL) )
        {
            recursive_display(node->left,pFunc,format + gap,gap,div);
            recursive_display(node->right,pFunc,format + gap,gap,div);
        }
    }
    else
    {
        for(i=0;i<format;i++)
        {
            printf("%c", div);
        }
        printf("\n");
    }
}

static int recursive_count(BTreeNode* root)
{
    int ret = 0;

    if ( root != NULL )
    {
        ret = recursive_count(root->left) + 1 + recursive_count(root->right);
    }

    return ret;
}

static int recursive_height(BTreeNode* root)
{
    int ret = 0;

    if ( root!= NULL )
    {
        int lh = recursive_height(root->left);
        int rh = recursive_height(root->right);

        ret = ((lh > rh) ? lh : rh) + 1;
    }

    return ret;
}

static int recursive_degree(BTreeNode* root)
{
    int ret = 0;

    if ( root != NULL )
    {
        if( root->left != NULL )
        {
            ret ++;
        }
        if ( root->right != NULL )
        {
            ret ++;
        }
        if ( ret == 1 )
        {
            int ld = recursive_degree(root->left);
            int rd = recursive_degree(root->right);

            if ( ret <ld )
            {
                ret = ld;
            }
            if ( ret <rd )
            {
                ret = rd;
            }
        }
    }
    return ret;
}

BTree* BTree_Create()
{
    TBTree* ret = (TBTree*)malloc(sizeof(TBTree));

    if ( ret != NULL )
    {
        ret->count = 0;
        ret->root = NULL;
    }
    return ret;
}

void BTree_Destroy(BTree* tree)
{
    free(tree);
}

void BTree_Clear(BTree* tree)
{
    TBTree*btree = (TBTree*)tree;

    if ( btree!= NULL )
    {
        btree->count = 0;
        btree->root = NULL;
    }
}

/*
**  Fully not understand the whole meanning of the Insert algorithm 
*/
int BTree_Insert(BTree* tree,BTreeNode* node,BTPos pos,int count,int flag)  //O(n),and this is the core of the code.
{
    TBTree* btree = (TBTree*)tree;
    int ret = (btree!=NULL) && (node!=NULL) && (flag==BT_LEFT) || (flag==BT_RIGHT); //注意，这里应该是“或”,因为这里的逻辑错误导致之前程序不能正常显示树。
    int bit = 0;

    if ( ret )
    {
        BTreeNode* parent = NULL;
        BTreeNode* current = btree->root;

        node->left = NULL;
        node->right = NULL;

        while ( (count>0) && (current!=NULL) )
        {
            bit = pos & 1;
            pos = pos >> 1;

            parent = current;   //执行这句话后，parent指针永远指向current指针的上面，也就保证了parent指针永远为current指针的父节点。

            if ( bit == BT_LEFT )
            {
                current = current->left;
            }
            else if ( bit == BT_RIGHT )
            {
                current = current->right;
            }

            count --;
        }

        if ( flag == BT_LEFT )
        {
            node->left = current;
        }
        else if ( flag == BT_RIGHT )
        {
            node->right = current;
        }

        if ( parent!= NULL )
        {
            if ( bit == BT_LEFT )
            {
                parent->left = node;
            }
            else if ( bit == BT_RIGHT )
            {
                parent->right = node;
            }
        }
        else
        {
            btree->root = node;
        }

        btree->count ++;          //这里的count与函数中的参数count完全不一样。指的是这颗二叉树的结点数量。
    }
    return ret;
}

BTreeNode* BTree_Delete(BTree* tree,BTPos pos,int count)    //根绝pos和count来定位。
{
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;
    int bit = 0;

    if ( btree != NULL )
    {
        BTreeNode* parent =  NULL;
        BTreeNode* current = btree->root;

        while ( (count>0) && (current!=NULL) )
        {
            bit = pos & 1;
            pos = pos >> 1;

            parent = current;

            if  ( bit == BT_LEFT)
            {
                current = current->left;
            }
            else if ( bit == BT_RIGHT )
            {
                current = current->right;
            }
            count--;
        }
        if ( parent != NULL )
        {
            if(bit == BT_LEFT )
            {
                parent->left = NULL;
            }
            else if ( bit == BT_RIGHT )
            {
                parent->right = NULL;
            }
        }
        else
        {
            btree->root = NULL;
        }
        ret = current;
        btree->count = btree->count - recursive_count(ret);
    }

    return  ret;
}

BTreeNode* BTree_Get(BTree* tree,BTPos pos,int count)
{
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;
    int bit = 0;

    if ( btree != NULL )
    {
        BTreeNode* current = btree->root;

        while ( (count>0) && (current!=NULL) )
        {
            bit = pos & 1;
            pos = pos >> 1;

            if ( bit == BT_LEFT )
            {
                current = current->left;
            }
            else if( bit == BT_RIGHT)
            {
                current = current->right;
            }
            count--;
        }
        ret = current;
    } 
    return ret;
}

BTreeNode* BTree_Root(BTree* tree)
{
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;

    if ( btree!= NULL )
    {
        ret = btree->root;
    }

    return ret;
}

int BTree_Height(BTree* tree)
{
    TBTree* btree = (TBTree*)tree;
    int ret = 0;

    if(btree!=NULL)
    {
        ret = recursive_height(btree->root);
    }

    return ret;
}

int BTree_Count(BTree* tree)
{
    TBTree* btree = (TBTree*)tree;
    int ret = 0;

    if( btree != NULL )
    {
        ret = btree->count;
    }

    return ret;
}

int BTree_Degree(BTree* tree)
{
    TBTree* btree = (TBTree*)tree;
    int ret = 0;

    if(btree!= NULL)
    {
        ret = recursive_degree(btree->root);
    }

    return ret;
}

void BTree_Display(BTree* tree,BTree_Printf* pFunc,int gap,char div)
{
    TBTree* btree = (TBTree*)tree;

    if ( btree != NULL )
    {
        recursive_display(btree->root,pFunc,0,gap,div);
    }
}
