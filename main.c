#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int range, luckyNumber, guess, attempts = 0;
    int lowerlimit = 0, upperlimit;

    // Seed the random number generator, using the time as a seed ensures that the sequence of random numbers will be different each time the program is run, because the time is always changing
    srand(time(0));

    // Step 1: Get the user input range for guessing
    printf("Please key in a positive number for the range: ");
    scanf("%d", &range);

    // Generate a random lucky number within the selected range
    upperlimit = range;
    luckyNumber = rand() % (range + 1);

    // Step 3: Ask the user to start guessing
    printf("Please guess a lucky number between %d - %d: ", lowerlimit, upperlimit);

    while (1) {
        scanf("%d", &guess);
        attempts++;

        // Check if the guess is within the current range
        if (guess >= lowerlimit && guess <= upperlimit) {
            if (guess == luckyNumber) {
                // The user guessed the correct lucky number
                printf("Yes! You have successfully guessed the lucky number %d after %d attempts !!!\n", luckyNumber, attempts);
                break;
            } else if (guess < luckyNumber) {
                // Update the lower limit
                lowerlimit = guess;
            } else {
                // Update the upper limit
                upperlimit = guess;
            }
            printf("Please guess a lucky number between %d and %d: ", lowerlimit, upperlimit);
        } else {
            // Guess is out of the range
            printf("Please guess a lucky number between %d and %d: ", lowerlimit, upperlimit);
        }
    }
    return 0;
}
