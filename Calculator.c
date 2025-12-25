#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* ================= MAIN MENU ================= */

char displayMainMenu()
{
    char userChoice;

    do
    {
        puts("B) Binary mathematical operations (add, subtract, etc.)");
        puts("U) Unary mathematical operations (sqrt, log, etc.)");
        puts("A) Advanced operations using variables");
        puts("V) Define variables and assign values");
        puts("E) Exit program");

        printf("\nSelect an option (B, U, A, V, E): ");
        scanf(" %c", &userChoice);

        if (userChoice != 'B' && userChoice != 'U' &&
            userChoice != 'A' && userChoice != 'V' &&
            userChoice != 'E')
        {
            printf("\nInvalid input detected. Please try again.\n\n");
            while (getchar() != '\n');
        }

    } while (userChoice != 'B' && userChoice != 'U' &&
             userChoice != 'A' && userChoice != 'V' &&
             userChoice != 'E');

    return userChoice;
}

/* ================= BINARY OPERATIONS ================= */

float calculateBinary(float firstValue, float secondValue, char mathOp)
{
    float result = 0;

    switch (mathOp)
    {
        case '+': result = firstValue + secondValue; break;
        case '-': result = firstValue - secondValue; break;
        case '*': result = firstValue * secondValue; break;

        case '/':
            if (secondValue == 0)
            {
                printf("\nMath Error: Division by zero is undefined.\n");
                return 0;
            }
            result = firstValue / secondValue;
            break;

        case '%': result = fmod(firstValue, secondValue); break;
        case 'P': result = pow(firstValue, secondValue); break;
        case 'X': result = (firstValue > secondValue) ? firstValue : secondValue; break;
        case 'I': result = (firstValue < secondValue) ? firstValue : secondValue; break;
    }

    return result;
}

/* ================= UNARY OPERATIONS ================= */

float calculateUnary(float value, char mathOp)
{
    float result = 0;

    switch (mathOp)
    {
        case 'S':
            if (value < 0)
            {
                printf("\nMath Error: Square root of a negative value is invalid.\n");
                return 0;
            }
            result = sqrt(value);
            break;

        case 'L':
            if (value <= 0)
            {
                printf("\nMath Error: Logarithm undefined for zero or negative values.\n");
                return 0;
            }
            result = log(value);
            break;

        case 'E': result = exp(value); break;
        case 'C': result = ceil(value); break;
        case 'F': result = floor(value); break;
    }

    return result;
}

/* ================= EXIT MESSAGE ================= */

void printExitMessage()
{
    printf("\nThank you for using the Command-Line Calculator.\n");
    printf("Program terminated successfully. Goodbye!\n");
}

/* ================= MAIN FUNCTION ================= */

int main()
{
    float firstValue, secondValue, finalResult = 0;
    char mainChoice, mathOp, varSlot1, varSlot2, subMenuChoice;

    float storedA = 0, storedB = 0, storedC = 0, storedD = 0, storedE = 0;
    float inputValue;

    float variables[5] = {0};

    puts("Welcome to the Command-Line Calculator (CLC)");
    puts("Programmer: Parsia Zahedi");
    puts("Project: C Programming Calculator");
    puts("--------------------------------------------------");

    do
    {
        mainChoice = displayMainMenu();

        switch (mainChoice)
        {
            /* ===== BINARY ===== */
            case 'B':
                printf("\nEnter first number: ");
                while (scanf("%f", &firstValue) != 1)
                {
                    printf("Invalid input. Enter a numeric value: ");
                    while (getchar() != '\n');
                }

                puts("\nBinary Operations:");
                puts("+  -  *  /  %  P(power)  X(max)  I(min)");
                printf("Choose operation: ");
                scanf(" %c", &mathOp);

                printf("Enter second number: ");
                while (scanf("%f", &secondValue) != 1)
                {
                    printf("Invalid input. Enter a numeric value: ");
                    while (getchar() != '\n');
                }

                finalResult = calculateBinary(firstValue, secondValue, mathOp);
                printf("\nResult: %f\n\n", finalResult);
                break;

            /* ===== UNARY ===== */
            case 'U':
                puts("\nUnary Operations:");
                puts("S(sqrt)  L(log)  E(exp)  C(ceil)  F(floor)");
                printf("Choose operation: ");
                scanf(" %c", &mathOp);

                printf("Enter number: ");
                while (scanf("%f", &firstValue) != 1)
                {
                    printf("Invalid input. Enter a numeric value: ");
                    while (getchar() != '\n');
                }

                finalResult = calculateUnary(firstValue, mathOp);
                printf("\nResult: %f\n\n", finalResult);
                break;

            /* ===== VARIABLES ===== */
            case 'V':
                printf("\nSelect variable slot (a, b, c, d, e): ");
                scanf(" %c", &varSlot1);

                printf("Enter value: ");
                while (scanf("%f", &inputValue) != 1)
                {
                    printf("Invalid input. Enter a numeric value: ");
                    while (getchar() != '\n');
                }

                switch (varSlot1)
                {
                    case 'a': storedA = inputValue; variables[0] = inputValue; break;
                    case 'b': storedB = inputValue; variables[1] = inputValue; break;
                    case 'c': storedC = inputValue; variables[2] = inputValue; break;
                    case 'd': storedD = inputValue; variables[3] = inputValue; break;
                    case 'e': storedE = inputValue; variables[4] = inputValue; break;
                    default:
                        printf("Invalid variable slot.\n");
                }

                printf("%c = %f stored successfully\n\n", varSlot1, inputValue);
                break;

            case 'E':
                printExitMessage();
                break;
        }

    } while (mainChoice != 'E');

    return 0;
}
