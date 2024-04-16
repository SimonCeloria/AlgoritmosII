#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "stack.h"


typedef struct _s_stack {
  struct _s_stack * next;
  stack_elem elem;
}Stack_;


 stack stack_empty (){
   return NULL;
 }

 stack stack_push(stack s, stack_elem e){
    Stack_ *new_stack;
    new_stack = (Stack_ *) malloc(sizeof(Stack_));
    new_stack -> elem = e;
    new_stack -> next = s;
    s = new_stack;
    return s;
 }

 stack stack_pop(stack s){  
    assert(!stack_is_empty(s));
    stack aux;
    aux = s;
    s = s->next;
    free(aux);
    return s;
 }


 unsigned int stack_size(stack s) {
  unsigned int n;
  Stack_ *aux;
  n = 0u;
  aux = s;
  while(aux != NULL){
      n = n + 1;
      aux = aux -> next;
  }
    return n;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    stack_elem e_pop;
    e_pop = s -> elem;
    return e_pop;
}

bool stack_is_empty (stack s){
  return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    if (stack_is_empty(s)) {
      return NULL;
    }
    //Creo variables locales
    unsigned int length;
    stack copy;
    unsigned int i = 0;
    
    //Defino el largo del arreglo, creo una copia del stack
    length = stack_size(s);
    copy = s;

    //Alojo memoria para el stack
    stack_elem* array = calloc(length, sizeof(stack_elem));
    if (array == NULL) {
    return NULL;
    }

    //Creo el arreglo a partir del stack 
    while (copy != NULL)
    {
       array[i] = copy -> elem;
       copy = copy -> next;
       i = i + 1;
    }
   
    return array;
}

stack stack_destroy (stack s){
  if(!stack_is_empty(s)){
    stack_destroy(s->next);
    free(s);
  }
  return s;
}

