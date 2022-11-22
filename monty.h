#ifndef _MAIN_H_
#define _MAIN_H_

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


stack_t *push(stack_t **head, unsigned int n);
size_t pall(stack_t *h);
int count_words(char *str);
int in_len(char *str);
char **_strtok(char *str);
int countstr(char **strs);
int streq(char *str1, char *str2);
void free_grid(char **grid);
void free_stack(stack_t *head);
size_t dlistint_len(stack_t *h);
#endif /* main.h */
