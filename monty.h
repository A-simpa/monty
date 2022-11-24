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


void push(stack_t **h, char **num_list, int lc, char *line, FILE *fp);
void pint(stack_t *h, int lc, char **cmd, char *line, FILE *fp);
void pop(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void swap(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void add(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void sub(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void divs(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void muls(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void mods(stack_t **s, int lc, char **cmd, char *line, FILE *fp);
void pchar(stack_t *h, int lc, char **cmd, char *line, FILE *fp);
void pstr(stack_t *head);
stack_t *add_stack(stack_t **h, unsigned int n);
size_t pall(stack_t *h);
int count_words(char *str);
int in_len(char *str);
char **_strtok(char *str);
int countstr(char **strs);
int streq(char *str1, char *str2);
void free_grid(char **grid);
void free_stack(stack_t *head);
size_t stack_len(stack_t *h);
int digit_count(char *s);
int pow_10(int n);
int sign(char *s);
int _atoi(char *s);
int _isdigit(char c);
int numcheck(char *str);
void _error(char **str, int line_count, char *line, FILE *fp, stack_t *s);
int cmd_exec(FILE *fp);
void run_func(stack_t *stack, char **cmd, int lc, char *line, FILE *fp);
#endif /* main.h */
