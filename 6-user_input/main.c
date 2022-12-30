#include <stdio.h>

int main(void){
    char name[50];
    int age;

    // Dont confuse it with sscanf
    printf("What is your name?");
    scanf("%s", name);

    // In case it was not obvious, the thing that helped me understand when to
    // use a pointer vs the actual varibales was the fact that a function
    // cannot alter another variable by name, but it can edit a point in memory
    // so if you want a funciton to edit a value it needs a pointer, not a value
    //
    printf("What is your age?");
    scanf("%d", &age);

    printf("Wow, you look so young %s!! Are you sure you are really ONLY %d?\n", name, age);


    // This is a bad method because what if they add text longer than your
    // buffer? That is a no no, instead use fgets and sscanf

    int max_size = 256;
    char user_name[max_size], input[max_size];
    int user_age;

    printf("Hello? And who might you be?");
    // Normally, you should not have two here. I only do because for some 
    // reason, when you use the two version back to back it some arbritrary
    // character (changes everytime) is read in via standard input, not sure
    // why, maybe its my computer or keyboard, but having it twice works here.
    // If you only use the bottom half (aka) the correct method, you don't need
    // both.
    fgets(input, max_size, stdin);
    fgets(input, max_size, stdin);
    sscanf(input, "%s\n", user_name);

    printf("Well Hello '%s'! How old are you now?", user_name);
    while(1){
        fgets(input, max_size, stdin);
        if(sscanf(input, "%d\n", &user_age) == 1){
            break;
        } else {
            printf("Sorry, I didn't recognize that as a number - try again!\n");
        }
    }
    printf("Wow %s! I can't believe you are %d! You have grown so much!\n", user_name, user_age);

    return 0;
}
