#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    
    // Check if the head is NULL to make sure that we do not dereference a NULL pointer
    //because that would result in a segfault */
    if(head==NULL)
    {
     return 0;
     
    }
    
    
    //two pointers declaration
    node *fast_ptr, *slow_ptr;
    
    //Start that two pointers at the head of list
    
    fast_ptr = head;
    slow_ptr = head;
    
    while( fast_ptr != NULL && slow_ptr!= NULL && fast_ptr->next != NULL)
    {
       //Advance fast_ptr by two nodes
        for(int i =0; i < 2; i ++)
        {
          fast_ptr = fast_ptr->next;
        }
        
        //Advance slow_ptr by one node
        
        slow_ptr = slow_ptr->next;
        
        //If the fast_ptr and slow_ptr ever point to the same node
        if(fast_ptr == slow_ptr)
        {
          //the list is cyclic, so return true
          
          return 1;
        }
        
    }
    
  return 0;
  
}  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

