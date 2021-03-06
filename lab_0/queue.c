/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if(q == NULL)
        return NULL;
    /* bind initial value with q */
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if(q == NULL)
        return ;
    list_ele_t *a, *b;
    for(a = q->head; a != NULL; a = b) {
        b = a->next;
        free(a);
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if(q == NULL)
        return false;
    list_ele_t *p = malloc(sizeof(list_ele_t)); /* new space for a node */
    if(p == NULL)                  /* as mentioned above */
        return false;
    
    /* construct the node */
    p->value = v;
    p->next = q->head;
    q->head = p;
    ++q->length;
    if (q->length == 1)
        q->tail = p;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  == O(1) time ==
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* malloc new space */
    if(q == NULL)
        return false;
    list_ele_t *p = malloc(sizeof(list_ele_t));
    if(p == NULL)
        return false;
    
    p->value = v;
    p->next = NULL;

    /* for good reading, I write "q->tail = p" twice */
    if (q->length == 0) {
        q->head = p;
        q->tail = p;
    } else {
        q->tail->next = p;
        q->tail = p;
    }
    ++q->length;
    return true;
}

/*
  Attempt to remove element at head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if(q == NULL || q->length == 0)
        return false;
    
    list_ele_t *head = q->head;
    if(vp != NULL)
        *vp = head->value;
    q->head = head->next;
    --(q->length);
    if(q->length == 0)
        q->tail = NULL;
    free(head);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q != NULL)
        return q->length;
    return 0;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* no need to reverse */
    if (q == NULL || q->length == 0 || q->length == 1)
        return ;
    /* 
      use three points(may be a little silly) 
      I do believe there is a better way to solve this.
    */
    list_ele_t *a, *b, *c;
    q->tail = q->head;
    for(a = q->head, b = a->next; b != NULL; a = b, b = c)
    {
        c = b->next;
        b->next = a;
        if (a == q->head)
            a->next = NULL;
    }
    q->head = a;
}
