/* 二叉树结点类型 */
typedef struct btnode *btlink;/* 二叉树结点指针类型 */
struct btnode{/* 二叉树结点结构 */
    TreeItem element;/* 二叉树结点标号（元素） */ 
    btlink left;/* 左子树 */ 
    btlink right;/* 右子树 */
}Btnode;

btlink NewBNode()
{/* 建新树结点 */
    return (btlink)malloc(sizeof(Btnode));
}

typedef struct binarytree *BinaryTree;/* 二叉树类型 */
typedef struct binarytree{/* 二叉树结构 */
      btlink root;/* 树根 */ 
}BTree;

