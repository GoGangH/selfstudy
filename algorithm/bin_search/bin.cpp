#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main(){
    int numTestCases;
    cin>>numTestCases;
    while(numTestCases--){
        int num;
        struct node* root = NULL;
        cin>>num;
        for (int i=0;i<num;i++){
            int data;
            cin>>data;
            insert(&root, data);
        }
        printf("%d\n", size(root)-1);
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root); printf("\n");
        inOrder(root); printf("\n");
        postOrder(root); printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제

        if (root == NULL) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
}

// 데이터 삽입(recursion)
void insert(struct node** root, int data){
    node* &nd = *root;
    if(nd == NULL){
        node* nw = new node;
        nw->data = data;
        nw->left = NULL;
        nw->right = NULL;
        nd = nw;
        return;
    }
    if(nd->data < data) insert(&nd->right, data);
    else insert(&nd->left, data);
}
// 전위(preorder)탐색(recursion)
void preOrder(struct node* root){
    if (root == NULL)
        return;
    else
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// 중위(inOrder)탐색(recursion)
void inOrder(struct node* root){
    if (root == NULL)
        return;
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
// 후위(postorder)탐색(recursion)
void postOrder(struct node* root){
    if (root == NULL)
        return;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
// 노드의 개수(recursion)
int size(struct node* root){
    if(root == NULL) return 1;
    return size(root->left) + size(root->right);
}
// 높이(recursion)
int height(struct node* root){
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}
// 미러 이미지로 변환하기(recursion)
void mirror(struct node** root){
    node* &nd = *root;
    if(nd == NULL) return;

    mirror(&(nd->left));
    mirror(&(nd->right));

    swap(nd->left, nd->right);
}
// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node* root){
    if(root == NULL) return 0;
    else return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data;
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합
int maxPathWeight(struct node* root){
    if(root == NULL) return 0;
    else return max(maxPathWeight(root->left), maxPathWeight(root->right)) + root->data;
}
// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node** root){
    node* &nd = *root;
    if(*root == NULL) return;
    
    destruct(&nd->right);
    destruct(&nd->left);

    delete nd;
    *root = NULL;
}