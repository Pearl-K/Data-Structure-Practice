
#include <stdio.h>
#include <stdlib.h>

// BT to BST 구현하기

// 1. 먼저 BT의 노드 만들기
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// 2. 중위순회로 저장하는 함수 구현
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;

    /* first store the left subtree */
    storeInorder(node->left, inorder, index_ptr);

    /* Copy the root's data */
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry

    /* finally store the right subtree */
    storeInorder(node->right, inorder, index_ptr);
}

// 3. 노드 수 세는 함수 구현
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// 4. array 형태로 저장된 노드들을 BST로 바꿔주는 함수
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;

    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);

    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;

    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}

// 5. BT to BST
void binaryTreeToBST(struct node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;

    /* Count the number of nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);

    // Create a temp array arr[] and store inorder traversal of tree in arr[]
    int* arr = (int*)malloc(sizeof(int) * n);
    int i = 0;
    storeInorder(root, arr, &i);

    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);

    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);

    // 동적 할당된 메모리 해제
    free(arr);
}

// 6. BST 노드 생성하는 함수 구현
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// 7. 중위순회로 바이너리 트리 프린트하는 함수
void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

// 8. 메인함수
int main()
{
    struct node* root = NULL;

    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /     \
    20     5 */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    // convert Binary Tree to BST
    binaryTreeToBST(root);

    printf("Following is Inorder Traversal of the converted BST:");
    printInorder(root);

    return 0;
}