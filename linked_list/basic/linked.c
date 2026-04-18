#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;
node *delete_at_tail(node *head)
{
    if (head == NULL)
    {

        printf("The list is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
void reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        traverse(head);
        return;
    }
    node *cur = head;
    node *prev = NULL;
    node *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    traverse(prev);
    return;
}
node *delete_at_head(node *head)
{
    if (head == NULL)
    {
        printf("The List is empty.\n");
        return head;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
node *insert_at_tail(node *head, int val)
{
    node *cur = (node *)malloc(sizeof(node));
    cur->data = val;
    cur->next = NULL;

    if (head == NULL)
        return cur;

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = cur;
    return head;
}
node *insert_after_position(node *head, int n, int val)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    node *temp, *cur;
    temp = head;
    for (int i = 1; i < n && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range .\n");
        return head;
    }
    cur = (node *)(malloc(sizeof(node)));
    cur->data = val;
    cur->next = temp->next;
    temp->next = cur;
    return head;
}
node *delete_node(node *head, int n)
{
    if (head == NULL)
    {
        printf("The List is empty.\n");
        return head;
    }
    if (n == 1)
    {
        head = delete_at_head(head);
        return head;
    }
    node *temp = head;
    node *cur;
    for (int i = 1; i < n - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Position out of range\n");
        return head;
    }
    cur = temp->next;
    temp->next = cur->next;
    free(cur);
    return head;
}
node *insert_at_head(node *head, int val)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = val;
    temp->next = head;
    return temp;
}

node *insert(node *head, int n, int val)
{
    node *temp = head;
    node *cur;
    if (n == 1)
    {
        head = insert_at_head(head, val);
        return head;
    }
    for (int i = 1; i < n - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    cur = (node *)(malloc(sizeof(node)));
    cur->data = val;
    cur->next = temp->next;
    temp->next = cur;

    return head;
}

void traverse(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty \n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

node *read(node *start, int n)
{
    if (n == 0)
        return NULL;
    node *temp, *cur;
    int val;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &val);

        if (i == 1  )
        {
            start = (node *)malloc(sizeof(node));
            start->data = val;
            cur = start;
        }
        else
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = val;
            cur->next = temp;
            cur = temp;
        }
    }
    cur->next = NULL;

    return start;
}

int main()
{
    node *head = NULL;
    int choice, n, pos, val;

    while (1)
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Create List\n");
        printf("2. Traverse\n");
        printf("3. Insert at Head\n");
        printf("4. Insert at Tail\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Head\n");
        printf("7. Delete at Tail\n");
        printf("8. Delete at Position\n");
        printf("9. Traverse the reverse linked list\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            head = read(head, n);
            break;

        case 2:
            printf("Linked List: ");
            traverse(head);

            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            head = insert_at_head(head, val);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &val);
            head = insert_at_tail(head, val);
            break;

        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &val);
            head = insert(head, pos, val);
            break;

        case 6:
            head = delete_at_head(head);
            break;

        case 7:
            head = delete_at_tail(head);
            break;

        case 8:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = delete_node(head, pos);
            break;

        case 9:
            printf("The reversed list : ");
            reverse(head);
            break;

        case 10:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}