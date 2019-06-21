#include <stdio.h>
#include <stdlib.h>

typedef struct subnode
{
    int data,
        id;
    struct subnode *next;
} subnode;

typedef struct node
{
    int data;
    struct node *next;
    struct subnode *sublist;
} node;

node *addNode(node *head, int data);
subnode *addSubnode(subnode *head, int id, int data);
node *readNode(node *head, char *path);
subnode *readSubnode(subnode *head, int node_id, char *path);
node *searchNode(node *head, int id);
void showOff(node *head);

int main()
{
    node *list = NULL;
    subnode *sublist = NULL;
    list = readNode(list, "SDA/Practice/Lists/assets/list.txt");
    showOff(list);
    return 0;
}

node *addNode(node *head, int data)
{
    node *token,
        *q1, *q2;
    token = (node *)malloc(sizeof(node));
    token->data = data;
    token->next = NULL;
    token->sublist = NULL;
    for (q1 = q2 = head; q1 != NULL && q1->data > token->data; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}
subnode *addSubnode(subnode *head, int id, int data)
{
    subnode *token,
        *q1, *q2;
    token = (subnode *)malloc(sizeof(subnode));
    token->id = id;
    token->data = data;
    token->next = NULL;
    for (q1 = q2 = head; q1 != NULL && q1->data > token->data; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}

subnode *readSubnode(subnode *head, int node_id, char *path)
{
    FILE *f = NULL;
    int id,
        data;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %d", &id, &data);
            if (id == node_id)
                head = addSubnode(head, id, data);
        }
        fclose(f);
    }
    return head;
}

node *readNode(node *head, char *path)
{
    FILE *f = NULL;
    int data;
    node *list;
    subnode *sublist;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &data);
            head = addNode(head, data);
            sublist = head->sublist;
            sublist = readSubnode(sublist, data, "SDA/Practice/Lists/assets/sublists.txt");
            head->sublist = sublist;
        }
        fclose(f);
    }
    return head;
}

void showOff(node *head)
{
    node *q;
    for (q = head; q != NULL; q = q->next)
    {
        printf("\nnode: %d", q->data);
        if (q->sublist != NULL)
            printf("\n\tsubnode: %d", q->sublist->data);
    }
}