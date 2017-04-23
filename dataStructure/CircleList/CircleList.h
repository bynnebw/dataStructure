#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;
typedef struct _tag_CircleListNode CircleListNode;

struct _tag_CircleListNode
{
	CircleListNode* next;
};

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list,CircleListNode* node,int pos);

CircleListNode* CircleList_Get(CircleList* list,int pos);

CircleListNode* CircleList_Delete(CircleList* list,int pos);

CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node);	//这里的deletenode与上面的delete有什么区别呢？

CircleListNode* CircleList_Reset(CircleList* list);	//对于循环链表，怎么理解重置？

CircleListNode* CircleList_Current(CircleList* list);	//这里是不是返回当前的元素？

CircleListNode* CircleList_Next(CircleList* list);


#endif