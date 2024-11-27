#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
}node;

node* create(){
    node* temp;
    printf("Enter data: ");
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert(node* root, node* temp){
    if(temp->data<root->data){
        if(root->left!=NULL){
            insert(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }
    if(temp->data>root->data){
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}
void inOrder(node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("\n%d",root->data);
        inOrder(root->right);
    }
}
void preOrder(node* root){
    if(root!=NULL){
        printf("\n%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("\n%d",root->data);
    }
}
int main() {
    node *root = NULL, *temp;
    int n, i, choice;

    while (1) {
        printf("\nBST Operations Menu:\n");
        printf("1. Insert nodes into BST\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes to insert: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    temp = create();
                    if (root == NULL) {
                        root = temp;
                    } else {
                        insert(root, temp);
                    }
                }
                break;

            case 2:
                printf("\nIn-order traversal:\n");
                inOrder(root);
                break;

            case 3:
                printf("\nPre-order traversal:\n");
                preOrder(root);
                break;

            case 4:
                printf("\nPost-order traversal:\n");
                postOrder(root);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
