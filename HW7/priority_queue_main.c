#include "priority_queue.h"
#include <stdio.h>

//Testing our funcitons
int main(void){
    // Testing the initializer function
    PRIORITY_QUEUE pQ = priority_queue_init_default();

    // Testing the is empty function
    if (!priority_queue_is_empty(pQ)){
        printf("priority_queue_is_empty() returned False for an empty queue.\n");
    }

    // Testing inserting one item
    Status status = priority_queue_insert(pQ, 7, 29);
    if (status == FAILURE){
        printf("The insert failed. \n");
    }
    // Testing the is empty function
    if (priority_queue_is_empty(pQ)){
        printf("priority_queue_is_empty() returned True for a non-empty queue.\n");
    }

    // Testing the front function
    int front = priority_queue_front(pQ, &status);
    if (front != 29){
        printf("priority_queue_front() did not return 29.\n");
	printf("It instead returned: %d \n", front);
    }
    if (status == FAILURE){
        printf("status was not correctly changes in priority_queue_front(). \n");
    }

    // Testing the service function
    status = priority_queue_service(pQ);
    if (status == FAILURE){
        printf("Queue could not be serviced. \n");
    }
    
    // Testing the front function
    front = priority_queue_front(pQ, NULL);
    if (front != -999999){
        printf("priority_queue_front() did not return -999999.\n");
    }
    if (status == FAILURE){
        printf("status was not correctly ignored in priority_queue_front() when passed in as NULL. \n");
    }

    // Testing the is empty fucntion
    if (!priority_queue_is_empty(pQ)){
        printf("priority_queue_is_empty() returned False for an empty queue.\n");
    }

    // Adding enough functions to test the hidden resize. 
    int i;
    for (i = 20; i > 0; i--){
        Status status = priority_queue_insert(pQ, i, i + 10);
        if (status == FAILURE){
            printf("The insert failed. \n");
       }
    }
    
    // Testing the front and service funcitons a few times. 
    // Testing the front function
    front = priority_queue_front(pQ, &status);
    if (front != 11){
        printf("priority_queue_front() did not return 10.\n");
    }
    if (status == FAILURE){
        printf("status was not correctly changes in priority_queue_front(). \n");
    }
    
    // Testing the service function
    status = priority_queue_service(pQ);
    if (status == FAILURE){
        printf("Queue could not be serviced. \n");
    }

    // Testing the front function
    front = priority_queue_front(pQ, &status);
    if (front != 12){
        printf("priority_queue_front() did not return 11.\n");
    }
    if (status == FAILURE){
        printf("status was not correctly changes in priority_queue_front(). \n");
    }

    // Testing the service function
    status = priority_queue_service(pQ);
    if (status == FAILURE){
        printf("Queue could not be serviced. \n");
    }

    // Testing the front function
    front = priority_queue_front(pQ, &status);
    if (front != 13){
        printf("priority_queue_front() did not return 12.\n");
    }
    if (status == FAILURE){
        printf("status was not correctly changes in priority_queue_front(). \n");
    }


    // freeing the memory, this will be tested using valgrind
    priority_queue_destroy(&pQ);

    printf("If there is no other print statments and no memory leaks with valgrind,\n");
    printf("then everything works as expected. \n");

    return 1;
}
