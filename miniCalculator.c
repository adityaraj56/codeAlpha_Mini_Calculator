#include <stdio.h>

void show_menu(void) {
    printf("\n=============================\n");
    printf("       MINI CALCULATOR       \n");
    printf("=============================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%) [Integers Only]\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    printf("Enter your choice (1-6): ");
}

int main(void) {
    int choice;
    double num1, num2, result;
    int int1, int2, mod_result;

    while (1) {
        show_menu();

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a numerical option.\n");
            while (getchar() != '\n'); // Clear input stream buffer
            continue;
        }

        if (choice == 6) {
            printf("Terminating program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please select an option between 1 and 6.\n");
            continue;
        }

        // Modulus operation uses integer operands
        if (choice == 5) {
            printf("Enter first integer: ");
            scanf("%d", &int1);
            printf("Enter second integer: ");
            scanf("%d", &int2);

            if (int2 == 0) {
                printf("Error: Modulo by zero is undefined.\n");
            } else {
                mod_result = int1 % int2;
                printf("Result: %d %% %d = %d\n", int1, int2, mod_result);
            }
            continue;
        }

        // Arithmetic operations using double-precision floats
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0.0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
        }
    }

    return 0;
}