#ifndef _GTREE_H_
#define _GTREE_H_

typedef void GTree;
typedef void GTreeData;

//重命名一个函数指针，返回类型是void型，函数名称是GTree_Printf，参数是GTreeData*。
typedef void (GTree_Printf)(GTreeData*);		//这是一个函数指针，用于给用户自定义打印方式。属于一个回调函数。

GTree* GTree_Create();

void GTree_Destroy(GTree* tree);

void GTree_Clear(GTree* tree);

int GTree_Insert(GTree* tree,GTreeData* data,int pPos);

GTreeData* GTree_Delete(GTree* tree,int pos);

GTreeData* GTree_Get(GTree* tree,int pos);

GTreeData* GTree_Root(GTree* tree);

int GTree_Height(GTree* tree);

int GTree_Count(GTree* tree);

int GTree_Degree(GTree* tree);

void GTree_Display(GTree* tree,GTree_Printf* pFunc,int gap,char div);

#endif