// A program to implement a queue-based first-come, first-served (FCFS) algorithm for flash sales
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a customer in the queue
struct Customer {
    int customerNumber;
    struct Customer* next;
};

// Initialize pointers for the front and rear of the queue
struct Customer* front = NULL;
struct Customer* rear = NULL;

// Function to add a customer to the queue
void enqueue(int customerNumber) {
    // Allocate memory for a new customer
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    newCustomer->customerNumber = customerNumber;
    newCustomer->next = NULL;

    // If the queue is empty, make both front and rear point to the new customer
    if (rear == NULL) {
        front = newCustomer;
        rear = newCustomer;
    } else {
        // Add the new customer to the rear of the queue and update the rear pointer
        rear->next = newCustomer;
        rear = newCustomer;
    }
}

// Function to remove and retrieve a customer from the queue
int dequeue() {
    // If the queue is empty, print a message and return -1 indicating no customers left
    if (front == NULL) {
        printf("No more customers in the queue. Flash sale is over.\n");
        return -1;
    }

    // Remove the front customer from the queue and update the front pointer
    struct Customer* temp = front;
    int customerNumber = temp->customerNumber;
    front = front->next;

    // Free the memory occupied by the removed customer
    free(temp);

    // Return the customer number that was removed
    return customerNumber;
}

// Function to simulate the flash sale process
void flashSale(int saleItems) {
    printf("Flash sale begins with %d items available!\n", saleItems);
    // Continue serving customers until all sale items are sold out
    while (saleItems > 0) {
        // Dequeue a customer from the queue
        int customerNumber = dequeue();

        // If a customer was dequeued successfully, serve them and decrement the sale items count
        if (customerNumber != -1) {
            printf("Serving customer %d\n", customerNumber);
            saleItems--;
        } else {
            // If no more customers are left in the queue, exit the loop
            break;
        }
    }
}

// Main function
int main() {
    int numCustomers; // The number of customers in the queue
    int saleItems; // The number of items available for the flash sale

    // Get the number of customers and the number of sale items from the user
    printf("Enter the number of customers in the queue: ");
    scanf("%d", &numCustomers);
    printf("Enter the number of items available for the flash sale: ");
    scanf("%d", &saleItems);

    // Enqueue customers into the queue
    for (int i = 1; i <= numCustomers; i++) {
        enqueue(i);
    }

    // Start the flash sale simulation with the specified number of sale items
    flashSale(saleItems);

    // End of the program
    return 0;
}