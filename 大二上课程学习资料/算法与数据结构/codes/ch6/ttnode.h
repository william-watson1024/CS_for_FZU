/* 线索二叉树结点类型 */

typedef struct btnode *tbtlink;
struct tbtnode {
     TreeItem element;
     btlink left;/* 左子树 */
     btlink right;/* 右子树 */
     int leftThread,/* 左线索标志 */
         rightThread;/* 右线索标志 */
}ThreadedNode;


tbtlink NewBNode()
{
    return (tbtlink)malloc(sizeof(ThreadedNode)); 
}

typedef struct binarytree *TBinaryTree;/* 线索二叉树类型 */
typedef struct binarytree{/* 线索二叉树结构 */
      tbtlink root;/* 树根 */ 
}TBTree;

