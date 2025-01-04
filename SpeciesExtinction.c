#include <stdio.h>

// Enum for states for better readability
typedef enum {
    S1, S2, S3, S4, S5, S6, S7
} State;

// Function to transition the DFA based on the trigger
State transition(State currentState, int trigger) {
    switch(currentState) {
        case S1:
            switch(trigger) {
                case 1: return S2; // Habitat Destruction
                case 2: return S3; // Climate Change
                case 3: return S4; // Pollution
                case 4: return S5; // Overexploitation
                case 5: return S6; // Invasive Species
                default: return S1;
            }
        case S2:
            return S7;
        case S3:
            return S7;
        case S4:
            return S7;
        case S5:
            return S7;
        case S6:
            return S7;
        default:
            return S7;
    }
}

int main() {
    State currentState = S1;

    printf("Species Extinction Simulation\n");
    printf("1: Habitat Destruction, 2: Climate Change, 3: Pollution, 4: Overexploitation, 5: Invasive Species\n");
    
    while (currentState != S7) {
        printf("\nEnter the trigger number (0 to show current state without changing it): ");
        int trigger;
        scanf("%d", &trigger);

        // Check for exit condition
        if (trigger == 0) {
            printf("Current state: %d\n", currentState);
            continue;
        }

        if (trigger < 1 || trigger > 5) {
            printf("Invalid trigger. Please enter a number between 0 and 5.\n");
            continue;
        }

        currentState = transition(currentState, trigger);

        // Display the current state
        if (currentState == S7) {
            printf("Species extinction reached.\n");
        } else {
            printf("Current state: %d\n", currentState);
        }
    }

    return 0;
}
