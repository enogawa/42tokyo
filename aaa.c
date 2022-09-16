#include <stdio.h>

typedef struct    s_list
{
    int v;
    struct s_list *next;
    struct s_list *prev;
}                t_list;

void    add(t_list **head, t_list *new)
{
    //t_list *old_head;
    t_list *tmp;

    //old_head = *head;
    tmp = *head;

    if (tmp == NULL)
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
    else
    {
        // head .. .. .. tmp new
        tmp = tmp->prev;
        tmp->next = new;
        new->prev = tmp;
        new->next = *head;
        (*head)->prev = new;
    }
    return ;
    /*
    while (head->next)
    {
        head = head->next;
    }
    head->next = new;
    new->prev = head;*/
}

int        main()
{
    printf("---\n");

    t_list    ary[100];
    t_list    *head = NULL;

    for (int i = 0; i < 10; i++)
    {
        ary[i].v = i;
        ary[i].next = NULL;
        ary[i].prev = NULL;
        add(&head, &ary[i]);
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d\n", ary[i].v);
    // }

    // add(&head, &ary[0]);
    // add(&head, &ary[1]);
    // add(&head, &ary[2]);
    // add(&head, &ary[3]);
    // add(&head, &ary[4]);

    printf("head %d\n", head->v);

    t_list *tmp = head;
    for (int i = 0; i < 10; i++)
    {
        printf("tmp %d\n", tmp->v);
        tmp = tmp->prev;
    }

}