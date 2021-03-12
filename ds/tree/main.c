#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE	32

struct stu_st {
	int id;
	char name[NAMESIZE];
};

struct node_st {
	struct stu_st data;
	struct node_st *left;
	struct node_st *right;
};

// 插入新结点
static int treeInsert(struct node_st **root, const struct stu_st *data)
{
	struct node_st *new;

	if (*root == NULL) {
		new = malloc(sizeof(*new));
		if (NULL == new)
			return -1;
		memcpy(&new->data, data, sizeof(struct stu_st));	
		new->left = new->right = NULL;
		*root = new;
		return 0;
	}
	if (data->id <= (*root)->data.id) {
		return treeInsert(&(*root)->left, data);	
	} else {
		return treeInsert(&(*root)->right, data);	
	}
}

// 中序
static void treeMidTraval(const struct node_st *root)
{
	if (root == NULL)
		return;
	treeMidTraval(root->left);
	printf("%d %s\n", root->data.id, root->data.name);
	treeMidTraval(root->right);
}

static void treeDestroy(struct node_st **root)
{
	if (*root == NULL)
		return ;
	treeDestroy(&(*root)->left);
	treeDestroy(&(*root)->right);
	// printf("%d %s will be destoryed\n", (*root)->data.id, (*root)->data.name);
	free(*root);
	*root = NULL;
}

static void _draw(const struct node_st *root, int level)
{
	if (root == NULL)
		return ;
	_draw(root->right, level+1);
	for (int i = 0; i < level; i++)
		printf("        ");
	printf("%d %s\n", root->data.id, root->data.name);
	_draw(root->left, level+1);
}

static void treeDraw(const struct node_st *root)
{
	_draw(root, 0);
}

static struct node_st **_deleteFind(struct node_st **root, int id)
{
	if (*root == NULL)
		return NULL;
	if ((*root)->data.id == id)
		return root;
	if ((*root)->data.id >= id)
		return _deleteFind(&(*root)->left, id);
	else
		return _deleteFind(&(*root)->right, id);
}

static struct node_st *treeMaxNode(const struct node_st *root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return (struct node_st *)root;
	return treeMaxNode(root->right);
}

static int treeDelete(struct node_st **root, int id) 
{
	struct node_st **find = _deleteFind(root, id);
	struct node_st *left, *right;
	if (find == NULL)
		return -1;
	left = (*find)->left;
	right = (*find)->right;
	(*find)->left = (*find)->right = NULL;
	free(*find);
	
	if (left != NULL) {
		*find = left;
		if (right != NULL) {
			treeMaxNode(left)->right = right;	
		}
	} else {
		*find = right;
	}

	return 0;
}

// 给定的树中结点的个数
static int treeCountNode(const struct node_st *root)
{
	if (root == NULL)
		return 0;
	return 1 + treeCountNode(root->left) + treeCountNode(root->right);
}

static struct node_st *treeMinNode(const struct node_st *root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return (struct node_st *)root;
	return treeMinNode(root->left);
}

static void treeTurnRight(struct node_st **root)
{
	struct node_st *l, *cur;

	cur = *root;
	l = cur->left;

	*root = l;
	cur->left = NULL;
	treeMaxNode(l)->right = cur;	
}

static void treeTurnLeft(struct node_st **root)
{
	struct node_st *r, *cur;

	cur = *root;
	r = cur->right;

	*root = r;
	cur->right = NULL;
	treeMinNode(r)->left = cur;
}

// 平衡
static void treeBalance(struct node_st **root)
{
	int val;
	
	if (*root == NULL)
		return ;
	while (1) {
		val = treeCountNode((*root)->left) - treeCountNode((*root)->right);
		if (val > 1) {
			treeTurnRight(root);
		} else if (val < -1) {
			treeTurnLeft(root);
		} else
			break;
	}
	treeBalance(&(*root)->left);
	treeBalance(&(*root)->right);
}

int main(void)
{
	struct node_st *t = NULL;
	struct stu_st stu;
	int ids[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int delid;

	for (int i = 0; i < sizeof(ids) / sizeof(*ids); i++) {
		stu.id = ids[i];
		snprintf(stu.name, NAMESIZE, "stu%d", ids[i]);
		treeInsert(&t, &stu);
	}

	treeMidTraval(t);

	treeDraw(t);

#if 0
	printf("********************delete********************\n");
	delid = 7;
	treeDelete(&t, delid);
	treeDraw(t);

	printf("********************delete********************\n");
	delid = 5;
	treeDelete(&t, delid);
	treeDraw(t);
#endif
	treeBalance(&t);
	treeDraw(t);

	treeDestroy(&t);

	return 0;
}
