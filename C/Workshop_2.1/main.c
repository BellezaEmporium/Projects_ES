#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node{
    int valeur;
    Node *next;
    Node *previous;
};

typedef struct stack stack;
struct stack{
    int size;
    Node *last;
};

void init_stack (stack *s) {
    s->last = NULL;
    s->size = 0;
};

bool is_stack_empty (stack *s) {
   return s->last == NULL;
};

void push (stack *s, int v)
    {
    if (s->last == NULL)
        {
        s->last = malloc(sizeof(Node));
        s->last->next = NULL;
        s->last->previous = NULL;
        s->last->valeur = v;
        s->size++;
        }
    else
        {
        s->last->next = malloc(sizeof(Node));
        s->last->next->next = NULL;
        s->last->next->previous = s->last;
        s->last->next->valeur = v;
        s->last = s->last->next;
        s->size++;
        }
    };

int pop (stack *s)
{
    if(s->size==0)
    {
        printf("Il n'y a rien à supprimer car vous n'avez rien enregistré avant.\n");
        exit(-1);
    }
    else
    {
        Node *oldLast=s->last;
        s->last=s->last->previous;
        int res=oldLast->valeur;
        free(oldLast);
        s->size--;
        return res;
    }
};

int main ()
{
    stack s;
    init_stack(&s);
    // Envoyez push pour ajouter un nombre dans la file, pop pour supprimer un nombre, et rien si vous voulez intentionnellement faire planter le programme
    push(&s, 200); // après le &s, ajouter une valeur entière. (décimaux non acceptés).
    // Le pop s'écrira comme ceci : pop(&s);
    while(!is_stack_empty(&s))
        printf("%d\n", pop(&s));

    return 0;
}