#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    INT,
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO,
} TypeTag;


typedef struct Node
{
    char isNode;
    TypeTag tag;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

/* Function type for arithmetic operations */
typedef Node* (*OperatingFunc)(void *, void *);

Node* createNode(TypeTag type)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->tag = type;
    node->left = NULL;
    node->right = NULL;
    node->isNode = 1;
    node->isNode = 'y';

    if (type == INT)
    {
        node->isNode = 0;
    }

    return node;
}

Node* createIntegerNode(int value)
{
    Node* node = createNode(INT);
    node->value = value;
    return node;
}

int isNode(void* node)  
{
    if ((int*)node > 650000)
    {
        if (*(char*)node == 'y')
        {
            return 1;
        }
    }
    
    return 0;
}

Node* createNodeOperation(void *left, void *right, TypeTag type)
{
    Node* node = createNode(type);

    if (isNode(left))
    {
        node->left = (Node*)left;
    }
    else
    {  
        node->left = createIntegerNode((int*)left);
    }

    if (isNode(right))
    {
        node->right = (Node*)right;
    }
    else
    {
        node->right = createIntegerNode((int*)right);
    }

    return node;  
}

Node* addition(void* left, void* right)
{
    Node* addNode = createNodeOperation(right, left, ADD);
    return addNode;
}

Node* subtraction(void* left, void* right)
{
    Node* subNode = createNodeOperation(right, left, SUB);
    return subNode;
}

Node* multiplication(void* left, void* right)
{
    Node* mulNode = createNodeOperation(right, left, MUL);
    return mulNode;
}

Node* division(void* left, void* right)
{
    Node* divNode = createNodeOperation(right, left, DIV);
    return divNode;
}

Node* fibo(void* left, void* right)
{
    Node* fiboNode = createNodeOperation(left, right, FIBO);
    return fiboNode;
}

OperatingFunc makeFunc(TypeTag type)
{   
    switch (type)
    {
    case ADD:
        return &addition;
        break;

    case SUB:
        return &subtraction;
        break;
    
    case MUL:
        return &multiplication;
        break;
    
    case DIV:
        return &division;
        break;
    case FIBO:
        return &fibo;
        break;
    default:
        printf("Invalid operation\n");
        return NULL;
        break;
    }
}

int fibonacci(int n)
{
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    if (n == 0 || n == 1)
        return 0;
    
    if (n<0){
        for (int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    }
    
    for (int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n-1];
}

void calc(Node* node){
    if (node == NULL) return;
    
    if (node->tag == FIBO)
    {
        // Handle special case for FIBO with a NULL second argument
        if (node->right != NULL && node->right->isNode == 'y' && node->right->value == 0)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            return;
        }
        else
        {
            // Regular FIBO calculation
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            return;
        }
    }
    

    switch (node->tag)
    {
    case ADD:
        if (node->left->value == NULL)
        {
            node->value = fibonacci(abs(node->right->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        if (node->right->value == NULL)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        node->value = node->left->value + node->right->value;
        printf("add: %d\n", node->value);
        break;
    case SUB:
        if (node->left->value == NULL)
        {
            node->value = fibonacci(abs(node->right->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        if (node->right->value == NULL)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        node->value = node->left->value - node->right->value;
        printf("sub: %d\n", node->value);
        break;
    case MUL:
        if (node->left->value == NULL)
        {
            node->value = fibonacci(abs(node->right->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        if (node->right->value == NULL)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        node->value = node->left->value * node->right->value;
        printf("mul: %d\n", node->value);
        break;
    case DIV:
        if (node->left->value == NULL)
        {
            node->value = fibonacci(abs(node->right->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        if (node->right->value == NULL)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        node->value = node->left->value / node->right->value;
        printf("div: %d\n", node->value);
        break;
    case FIBO:
        if (node->left->value == NULL)
        {
            node->value = fibonacci(abs(node->right->value));
            printf("fibo: %d\n", node->value);
            break;
        }
        if (node->right->value == NULL)
        {
            node->value = fibonacci(abs(node->left->value));
            printf("fibo: %d\n", node->value);
            break;
        }
            node->value = node->left->value + node->right->value;
            printf("fibo: %d\n", node->value);
            break;
    default:
            printf("Invalid operation\n");
            break;
    }
}

int main(void){
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *div = (*makeFunc(DIV))(3, 12);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);
    Node *fibo2 = (*makeFunc(FIBO))(4, NULL);
    

    calc(add);
    calc(mul);
    calc(sub);
    calc(div);
    calc(fibo);
    calc(fibo2);

    return 0;

}