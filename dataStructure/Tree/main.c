#include <stdio.h>
#include "GTree.h"

//main函数为用户，所以客户需要自己写想要打印的方式，风格。
void printf_data(GTreeData* data)
{
	printf("%c", (int)data);	//这里可以定义打印的形式是字符串，还是数字。不同的类型完全可以由用户自己定义。
}

int main(int argc, char const *argv[])
{
	GTree* tree = GTree_Create();
	int i = 0;

	GTree_Insert(tree,(GTreeData*)'A',-1);
	GTree_Insert(tree,(GTreeData*)'B',0);
	GTree_Insert(tree,(GTreeData*)'C',0);
	GTree_Insert(tree,(GTreeData*)'D',0);
	GTree_Insert(tree,(GTreeData*)'E',1);
	GTree_Insert(tree,(GTreeData*)'F',1);
	GTree_Insert(tree,(GTreeData*)'H',3);
	GTree_Insert(tree,(GTreeData*)'I',3);	
	GTree_Insert(tree,(GTreeData*)'J',3);

	printf("Tree Height:%d\n", GTree_Height(tree));
	printf("Tree Degree:%d\n", GTree_Degree(tree));
	printf("Full Tree\n");

	GTree_Display(tree,printf_data,2,'-');

	printf("Get Tree Data:\n"); 

//可以看到在组织链表里的组织形式，和真正展示出来的树的逻辑结构还是有很堵不同的。

	for(i = 0; i < GTree_Count(tree);i++)
	{
		printf_data(GTree_Get(tree,i));
		printf("\n");
	}

	printf("Get Root Data:\n");

	printf_data(GTree_Root(tree));

	printf("\n");

	GTree_Delete(tree,3);

	printf("After Deleting D:\n");
	GTree_Display(tree,printf_data,2,'*');
	GTree_Clear(tree);

	printf("After Cleaning Tree\n");

	GTree_Display(tree,printf_data,2,'#');

	GTree_Destroy(tree);

	return 0;
}