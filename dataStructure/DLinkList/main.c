#include <stdio.h>
#include <sys/malloc.h>
#include "DLinkList.h"

//与前面的循环链表类似，双向链表也有类似游标的概念，我理解这个游标主要是指向当前指针所指向的元素。

struct Value
{
	DLinkListNode header;
	int v;
};

int main(int argc,char* argv[])
{
	int i = 0;
	DLinkList* list = DLinkList_Create();
	struct Value* pv = NULL;
	struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;
    struct Value v5;

    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;

    DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");

    //----------the next paragraph should be the unique part of the DLinkList-------//

    DLinkList_Delete(list, DLinkList_Length(list)-1);
    DLinkList_Delete(list, 0);

    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Next(list);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    //-------------the next of the code is the unique part----------------------------//

    DLinkList_Reset(list);
    DLinkList_Next(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);


    DLinkList_Pre(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);

    printf("Length: %d\n", DLinkList_Length(list));

    DLinkList_Destroy(list);

	return 0;
}