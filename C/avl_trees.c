#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
typedef long long int ll;
typedef struct Node
{
    ll data;
    ll height;
    struct Node *left;
    struct Node *right;
} Node;

void setHeight(Node *root, Node *p);
Node *insertBST(Node *root, ll x);
void display(Node *root, ll spaces);
void create(Node *root, ll x);
void rightC(Node *p, ll x);
void leftC(Node *p, ll x);
Node *search(Node *p, ll x);
ll height(Node *p);
ll max(ll x1, ll x2)
{
    if (x2 > x1)
        return x2;
    else
        return x1;
}
//search in binary search tree
Node *search(Node *p, ll x)
{
    if (p->data == x)
        return p;
    else if (p == NULL)
        return p;
    else if (x > p->data)
        search(p->right, x);
    else if (x < p->data)
        search(p->left, x);
}

//inserting a value in a binary search tree
ll height(Node *p)
{
    if (p)
        return p->height;
    else
        return 0;
}

Node *llRotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = pl->right;
    pl->right = p;
    p->left = plr;
    pl->height = 1 + max(height(pl->left), height(pl->right));
    p->height = 1 + max(height(p->right), height(p->left));
    return pl;
}
Node *rrRotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;
    pr->left = p;
    p->right = prl;
    pr->height = 1 + max(height(pr->right), height(pr->left));
    p->height = 1 + max(height(p->left), height(p->right));
    return pr;
}
Node *lrRotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = p->left->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->height = 1 + max(height(p->right), height(p->left));
    plr->height = 1 + max(height(plr->right), height(plr->left));
    pl->height = 1 + max(height(pl->left), height(pl->right));

    return plr;
}
Node *rlRotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = p->right->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    p->height = 1 + max(height(p->left), height(p->right));
    prl->height = 1 + max(height(prl->right), height(prl->left));
    pr->height = 1 + max(height(pr->right), height(pr->left));

    return prl;
}
ll BalanceFactor(Node *p)
{
    return height(p->left) - height(p->right);
}
Node *insertBST(Node *p, ll x)
{

    if (p == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        assert(temp);
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }
    else if (p->data < x)
    {
        p->right = insertBST(p->right, x);
    }
    else if (p->data > x)
    {
        p->left = insertBST(p->left, x);
    }
    p->height = 1 + max(height(p->right), height(p->left));

    if (BalanceFactor(p) == -2)
    {
        if (BalanceFactor(p->right) == -1)
            return rrRotation(p);
        else if (BalanceFactor(p->right) == 1)
            return rlRotation(p);
    }
    else if (BalanceFactor(p) == 2)
    {
        if (BalanceFactor(p->left) == 1)
            return llRotation(p);
        else if (BalanceFactor(p->left) == -1)
            return lrRotation(p);
    }
    return p;
}

void display(Node *p, ll spaces)
{

    for (ll i = 0; i < spaces; i++)
        printf("   ");

    printf("|--%lld(h:%lld)(bf:%lld)\n ", p->data, p->height, BalanceFactor(p));
    //printf("  %d\n", height(p));

    if (p->left)
        display(p->left, spaces + 1);

    if (p->right)
        display(p->right, spaces + 1);
}

void leftC(Node *p, ll x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    assert(temp);
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    p->left = temp;
}
void rightC(Node *p, ll x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    assert(temp);
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    p->right = temp;
}
