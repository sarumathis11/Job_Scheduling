#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <regex.h>
#define MAX 50
// Structure to store user details
struct User
{
    char name[50];
    int id;
    long long int phoneNumber;
    char email[50];
    double cgpa;
    double experience;
    double languagesKnown;
    char jobTitle[50]; 
    struct User *next;
};

// Structure to store job details
struct JobDetail
{
    char userName[50];
    int userId;
    char jobTitle[50];
    struct JobDetail *next;
};

// Structure to store job details in a BST
struct Job
{
    char title[50];
    struct Job *left;
    struct Job *right;
    char id;      // Job ID
    int deadline; // Deadline of the job
    // char title[20];  // Job title
    int profit; // Profit associated with the job
};

// Structure to represent a node in the stack
struct StackNode
{
    char userName[50];
    int userId;
    char jobTitle[50];
    struct StackNode *next;
};

// Structure to represent the stack
struct Stack
{
    struct StackNode *top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
}

// Function to push a job onto the stack
void push(struct Stack *stack, char *userName, int userId, char *jobTitle)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newNode->userName, userName);
    newNode->userId = userId;
    strcpy(newNode->jobTitle, jobTitle);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a job from the stack
void pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct StackNode *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

// Function to display the welcome message and theme of the page
void displayvacant(){
     
    printf("\nLevel 1 Jobs\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-96s |\n", "Company", "                                      Jobs                         ");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "", "Manager", "Supervisor", "Tester");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "1. Google", "Vacant", "Vacant", "Vacant");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "2. Amazon", "Vacant", "Vacant", "Vacant");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "3. Microsoft", "Vacant", "Vacant", "Vacant");
    printf("------------------------------------------------------------------------------------------------------------------------------------|\n");
    

    printf("\nLevel 2 Jobs\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-96s |\n", "Company", "                                      Jobs                         ");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "", "Manager", "Supervisor", "Tester");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "1. TLC", "Vacant", "Vacant", "Vacant");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "2. VISA", "Vacant", "Vacant", "Vacant");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %-30s | %-30s | %-30s | %-30s |\n", "3. EDISON", "Vacant", "Vacant", "Vacant");
    printf("------------------------------------------------------------------------------------------------------------------------------------|\n");
    

}
// Function to display the welcome message and theme of the page
void displayHomePage()
{
    int screenWidth = 80;
    printf("Welcome to Job Scheduling Application\n");
    printf("=====================================\n");
    printf("The Wanted List\n\n");
    displayvacant();
    
    printf("\n");
    printf("%*s\n", (screenWidth + 8) / 2, " Sign in ");
}




// Function to validate a mobile number
int isValidPhoneNumber(long long int phoneNumber) {
    // Check if the phone number is a positive integer
    if (phoneNumber <= 0) {
        return 0;
    }

    // Count the number of digits in the phone number
    int count = 0;
    while (phoneNumber != 0) {
        phoneNumber /= 10;
        count++;
    }

    // Check if the phone number has exactly 10 digits
    return (count == 10);
}
// Function to validate an email address
int isValidEmail(const char *email) {
    // Define a basic pattern for email validation
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    // Compile the regular expression
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return 0;  // Unable to compile regex
    }

    // Execute the regular expression
    int result = regexec(&regex, email, 0, NULL, 0);

    // Free the compiled regular expression
    regfree(&regex);

    return (result == 0);
}

// Function to get user details and store them in a linked list
struct User *getUserDetails() {
    struct User *newUser = (struct User *)malloc(sizeof(struct User));
    if (newUser == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("\nEnter your name: ");
    scanf("%s", newUser->name);

    printf("Enter your ID: ");
    scanf("%d", &newUser->id);

    // Get and validate phone number
    do {
        printf("Enter your phone number: ");
        scanf("%lld", &newUser->phoneNumber);

        if (!isValidPhoneNumber(newUser->phoneNumber)) {
            printf("Invalid phone number. Please enter a 10-digit positive number.\n");
        }
    } while (!isValidPhoneNumber(newUser->phoneNumber));

    // Get and validate email address
    do {
        printf("Enter your email: ");
        scanf("%s", newUser->email);

        if (!isValidEmail(newUser->email)) {
            printf("Invalid email address. Please enter a valid email.\n");
        }
    } while (!isValidEmail(newUser->email));

    newUser->next = NULL;
    return newUser;
}



// Function to display application page
void displayApplicationPage(struct User *user)
{
    printf("\nWelcome, %s!\n", user->name);
    printf("ID: %d\n", user->id);
    printf("Phone Number: %lld\n", user->phoneNumber);
    printf("Email: %s\n", user->email);
    printf("\nApplication Page\n");
    printf("Enter 1 for further steps in Schedule Job: \n");
}

// Function to create a new job node in the BST
struct Job *createJobNode(char *title)
{
    struct Job *newNode = (struct Job *)malloc(sizeof(struct Job));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->title, title);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a job node into the BST
struct Job *insertJob(struct Job *root, char *title)
{
    if (root == NULL)
    {
        return createJobNode(title);
    }

    if (strcmp(title, root->title) < 0)
    {
        root->left = insertJob(root->left, title);
    }
    else if (strcmp(title, root->title) > 0)
    {
        root->right = insertJob(root->right, title);
    }

    return root;
}

// Function to display job details stored in the BST in inorder traversal
void printJobTree(struct Job *root)
{
    if (root != NULL)
    {
        printJobTree(root->left);
        printf("Job Title: %s\n", root->title);
        printJobTree(root->right);
    }
}

// Function to display user details including assigned job title
void printUserDetails(struct User *user)
{
    printf("\nUser Details\n");
    printf("Name: %s\n", user->name);
    printf("ID: %d\n", user->id);
    printf("Assigned Job Title: %s\n", user->jobTitle);
}

// Function to display job details including user name and ID in linkedlist
void printJobDetails(struct JobDetail *jobDetails)
{
    while (jobDetails != NULL)
    {
        printf("\nThe job Details:\n");
        printf("Name: %s, ID: %d, Job Title: %s\n", jobDetails->userName, jobDetails->userId, jobDetails->jobTitle);
        jobDetails = jobDetails->next;
    }
}

// Function to store job details in the linked list
struct JobDetail *storeJobDetails(struct JobDetail *head, char *userName, int userId, char *jobTitle)
{
    struct JobDetail *newJobDetail = (struct JobDetail *)malloc(sizeof(struct JobDetail));
    if (newJobDetail == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newJobDetail->userName, userName);
    newJobDetail->userId = userId;
    strcpy(newJobDetail->jobTitle, jobTitle);
    newJobDetail->next = head;

    return newJobDetail;
}

// // Structure to represent a job
// struct Job {
//     char id;        // Job ID
//     int deadline;   // Deadline of the job
//     char title[20];  // Job title
//     int profit;     // Profit associated with the job
// };

// Structure to represent a node in the queue
struct QueueNode
{
    struct Job job;
    struct QueueNode *next;
};

// Structure to represent a queue
struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue a job into the queue
void enqueue(struct Queue *queue, struct Job job)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->job = job;
    newNode->next = NULL;

    if (isQueueEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a job from the queue
struct Job dequeue(struct Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty.\n");
        exit(1);
    }

    struct QueueNode *temp = queue->front;
    struct Job job = temp->job;

    queue->front = queue->front->next;
    free(temp);

    return job;
}

// Function to compare jobs based on profit (used for sorting)
int compareJobs(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to schedule jobs and calculate total profit
void jobSequencingWithDeadlines(struct Job jobs[], int n)
{
    // Sort jobs based on profit in non-ascending order
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    struct Queue queue;
    initializeQueue(&queue);

    int maxDeadline = 0;
    for (int i = 0; i < n; ++i)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    int *timeSlots = (int *)malloc((maxDeadline + 1) * sizeof(int));
    if (timeSlots == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize time slots
    for (int i = 0; i <= maxDeadline; ++i)
    {
        timeSlots[i] = -1; // -1 indicates that the slot is unoccupied
    }

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; ++i)
    {
        int deadline = jobs[i].deadline;

        while (deadline > 0 && timeSlots[deadline] != -1)
        {
            --deadline;
        }

        if (deadline > 0)
        {
            // Enqueue the job
            enqueue(&queue, jobs[i]);
            timeSlots[deadline] = 1; // Mark the time slot as occupied

            // Update total profit
            totalProfit += jobs[i].profit;
        }
    }

    // Display scheduled jobs and total profit
    printf("Scheduled Jobs:\n");
    while (!isQueueEmpty(&queue))
    {
        struct Job job = dequeue(&queue);
        printf("Job %c with Profit %d\n", job.id, job.profit);
    }

    printf("Total Profit: %d\n", totalProfit);

    free(timeSlots);
}


int main()
{
    struct User *head = NULL;            // Head of the linked list
    struct Job *jobTree = NULL;          // Root of the BST for job assignment
    struct Stack jobStack;               // Stack to store job details
    struct JobDetail *jobDetails = NULL; // Linked list to store job details

    // Initialize the stack
    initializeStack(&jobStack);

    // Display the home page
    displayHomePage();

    // Get the number of members
    int numMembers;
    printf("\nEnter the number of members: ");
    scanf("%d", &numMembers);
    int numJobs = numMembers;

    struct Job *jobs = (struct Job *)malloc(numJobs * sizeof(struct Job));
    char title[50];

    // Get user details for each member and add them to the linked list
    for (int i = 0; i < numMembers; ++i)
    {
        printf("\nEnter details for Member %d:\n", i + 1);
        struct User *newUser = getUserDetails();

        // Add the new user to the linked list
        newUser->next = head;
        head = newUser;

        // Display the application page for each user
        displayApplicationPage(newUser);

        // Ask the user to enter 1 to proceed with job assignment
        int choice;
        printf("\nEnter '1' to proceed with job assignment: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Ask user-specific questions and calculate job assignment percentage
            printf("\nEnter your CGPA (out of 10): ");
            scanf("%lf", &newUser->cgpa);

            printf("Enter your years of experience (out of 10): ");
            scanf("%lf", &newUser->experience);

            printf("Enter the number of languages known (out of 10): ");
            scanf("%lf", &newUser->languagesKnown);

            // Assign job title based on the calculated percentage
            double percentage = ((0.2 * newUser->cgpa) + (0.5 * newUser->experience) + (0.3 * newUser->languagesKnown)) * 10;
            // Display calculated percentage
            printf("\nCalculated Percentage: %.2lf%%\n", percentage);

            char comp[MAX];
            int companyChoice;
            printf("Enter the company choices as: \n");

            if (percentage >= 70 && percentage <= 100)
            {

                printf(" 1 for Google\n 2 for Amazon\n 3 for Microsoft\n");
                printf("Enter your choice:\n");
                scanf("%d", &companyChoice);
                switch (companyChoice)
                {
                case 1:
                    strcpy(comp, "Google");
                    break;
                case 2:
                    strcpy(comp, "Amazon");
                    break;
                case 3:
                    strcpy(comp, "Microsoft");
                    break;
                default:
                    printf("Invalid company choice.\n");
                    break;
                }
            }
            else if (percentage >= 10 && percentage < 70)
            {

                printf(" 1 for TLC\n 2 for EDISN\n 3 for VISA\n");
                printf("Enter your choice:\n");
                scanf("%d", &companyChoice);
                switch (companyChoice)
                {
                case 1:
                    strcpy(comp, "TLC");
                    break;
                case 2:
                    strcpy(comp, "EDISN");
                    break;
                case 3:
                    strcpy(comp, "VISA");
                    break;
                default:
                    printf("Invalid company choice.\n");
                    break;
                }
            }
            // Assign job title using BST
            // char title[50];
            if (percentage >= 70 && percentage <= 100)
            {
                // First-level job offers
                if (percentage >= 90)
                {
                    sprintf(title, "Manager for %s", comp);
                }
                else if (percentage >= 80 && percentage < 90)
                {
                    sprintf(title, "Supervisor for %s", comp);
                }
                else
                {
                    if (percentage >= 70 && percentage < 80)
                    {
                        sprintf(title, "Tester for %s", comp);
                    }
                }
            }
            else if (percentage >= 10 && percentage < 70)
            {
                // Second-level job offers
                if (percentage >= 50 && percentage <= 70)
                {
                    sprintf(title, "Manager for %s", comp);
                }
                else if (percentage >= 30 && percentage < 50)
                {
                    sprintf(title, "Supervisor for %s", comp);
                }
                else
                {
                    if (percentage >= 10 && percentage < 30)
                    {
                        sprintf(title, "Tester for %s", comp);
                    }
                }
            }
            else
            {
                strcpy(title, "Invalid");
            }

            // Insert the job into the BST
            jobTree = insertJob(jobTree, title);

            // Push job details onto the stack
            push(&jobStack, newUser->name, newUser->id, title);

            // Store job details in the linked list
            jobDetails = storeJobDetails(jobDetails, newUser->name, newUser->id, title);
            // jobs[i].title = title ;
            strcpy(jobs[i].title, title);
        }
    }

    // Display all job details stored in the BST
    printf("\nAll Job Details in tree:\n");
    printJobTree(jobTree);

    // Display user name, ID, and job title from the linked list
    printf("\nUser Job Details from Linked List:\n");
    printJobDetails(jobDetails);
    printf("\n");

    if (jobs == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < numJobs; ++i)
    {
        printf("Enter details for Job %d:\n", i + 1);
        jobs[i].id = 'A' + i;
        printf("Enter deadline for Job %c: ", jobs[i].id);
        scanf("%d", &jobs[i].deadline);

        // strcpy(jobs[i].title, title);

        if (strcmp(jobs[i].title, "Manager for Google") == 0 || strcmp(jobs[i].title, "Manager for Amazon") == 0 || strcmp(jobs[i].title, "Manager for Microsoft") == 0 || strcmp(jobs[i].title, "Manager for EDISN") == 0 || strcmp(jobs[i].title, "Manager for TLC") == 0 || strcmp(jobs[i].title, "Manager for VISA") == 0)
        {
            jobs[i].profit = 1000;
        }
        else if (strcmp(jobs[i].title, "Supervisor for EDISN") == 0 || strcmp(jobs[i].title, "Supervisor for TLC") == 0 || strcmp(jobs[i].title, "Supervisor for VISA") == 0 || strcmp(jobs[i].title, "Supervisor for Google") == 0 || strcmp(jobs[i].title, "Supervisor for Microsoft") == 0 || strcmp(jobs[i].title, "Supervisor for Amazon") == 0)
        {
            jobs[i].profit = 500;
        }
        else if (strcmp(jobs[i].title, "Tester for EDISN") == 0 || strcmp(jobs[i].title, "Tester for TLC") == 0 || strcmp(jobs[i].title, "Tester for VISA") == 0 || strcmp(jobs[i].title, "Tester for Google") == 0 || strcmp(jobs[i].title, "Tester for Microsoft") == 0 || strcmp(jobs[i].title, "Tester for Amazon") == 0)
        {
            jobs[i].profit = 100;
        }
        else
        {
            jobs[i].profit = 0;
            printf("Invalid job title. Defaulting profit to 0.\n");
        }
        printf("Original Jobs:\n");
        printf("Job %c with Deadline %d, Title %s, and Profit %d\n", jobs[i].id, jobs[i].deadline, jobs[i].title, jobs[i].profit);
    }

    // printf("Original Jobs:\n");
    // for (int i = 0; i < numJobs; ++i)
    // {
    //     printf("Job %c with Deadline %d, Title %s, and Profit %d\n", jobs[i].id, jobs[i].deadline, jobs[i].title, jobs[i].profit);
    // }

    jobSequencingWithDeadlines(jobs, numJobs);

    free(jobs);

    // Free the memory used by the linked list
    while (head != NULL)
    {
        struct User *tempUser = head;
        head = head->next;
        free(tempUser);
    }

    // TODO: Free the memory used by the BST and the linked list of job details
    // (This part needs to be implemented based on your specific requirements)

    return 0;
}