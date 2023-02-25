#include <stdio.h>
#include <stdlib.h>

struct Data
{
	int value;
	struct Data *left,*right;
}*root = 0;

struct Data *createData(int value)
{
	struct Data *curr = (struct Data*)malloc(sizeof(struct Data));
	curr->value = value;
	curr->left=curr->right=0;
	return curr;
}

struct Data *insertData(struct Data *curr,struct Data *newData)
{
	if(curr == 0)
	{
		return newData;
	}else if(newData->value < curr->value)
	{
		curr->left = insertData(curr->left,newData);
	}else if(newData->value > curr->value)
	{
		curr->right = insertData(curr->right,newData);
	}
	return curr;
}
void view(struct Data *curr)
{
	if(curr != 0)
	{
		view(curr->left);
		printf("%d ",curr->value);
		view(curr->right);
	}
}

struct Data *deleteData(struct Data *curr, int value)
{
	if(curr == 0)
	{
		printf("data tak ada\n");
		return 0;
	}else if(value < curr->value)
	{
		curr->left = deleteData(curr->left,value);
	}else if(value > curr->value)
	{
		curr->right = deleteData(curr->right,value);
	}else
	{
		if(curr->left == 0 && curr->right == 0)
		{
			free(curr);
			curr = 0;
		}else if(curr->left == 0)
		{
			struct Data *temp = curr;
			curr = curr->right;
			free(temp);
			temp = 0;
		}else if(curr->right == 0)
		{
			struct Data *temp = curr;
			curr = curr->left;
			free(temp);
			temp = 0;
		}else
		{
			struct Data *temp = curr->left;
			while(temp->right != 0)
			{
				temp = temp->right;
			}
			curr->value = temp->value;
			curr->left = deleteData(curr->left,temp->value);
		}
	}
	return curr;
}
int main()
{
	root = insertData(root,createData(33));
	root = insertData(root,createData(12));
	root = insertData(root,createData(66));
	root = insertData(root,createData(2));
	root = insertData(root,createData(8));
	root = insertData(root,createData(90));
	root = insertData(root,createData(11));
	view(root);
	printf("\n");
	root = deleteData(root,34);
	view(root);
	printf("\n");
	root = deleteData(root,33);
	view(root);
	printf("\n");
	root = deleteData(root,12);
	view(root);
	
}
