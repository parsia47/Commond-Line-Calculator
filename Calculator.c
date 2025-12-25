#include <stdio.h>
#include <math.h>
#include <stdlib.h>


char mainMenu()
{

    char option;

    do
    {

        puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
        puts("U) - Unary Mathematical Operations, such as square root, and log.");
        puts("A) - Advanced Mathematical Operations, using variables, arrays.");
        puts("V) - Define variables and assign them values.");
        puts("E) - Exit");

        puts("\nPlease select your option ( B , U , A , V, E ): ");

        scanf(" %c", &option);


        if(option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E')
        {

            printf("\nInvalid input. Please try again.\n\n");

            while(getchar() != '\n');

        }

    }
    while(option != 'B' && option != 'U' && option != 'A' && option != 'V' && option != 'E');


    return option;

}



float optionB(float num1, float num2, char operation)
{

    float result = 0;


    // Based on input of operation, does a binary operation on the two given values
    switch (operation)
    {

        // Adds given values
        case '+':

            result = num1 + num2;

            break;

        // Subtracts given values
        case '-':

            result = num1 - num2;

            break;

        // Multiplies given values
        case '*':

            result = num1 * num2;

            break;

        // Divides given values
        case '/':

            do
            {

                if(num2 == 0)
                {

                    printf("\nMath Error. ");

                    printf("Division by zero yields an undefined value.\n");

                    return 0;

                }

                else
                {

                    result = num1 / num2;

                    break;

                }

            }
            while(num2 == 0);

            break;

        // Takes remainder of given values
        case '%':

            result = fmod(num1, num2);

            break;

        // Multiplies num1 by itself num2 times
        case 'P':

            result = pow(num1, num2);

            break;

        // Calculates maximum in between two values
        case 'X':

            if(num1 > num2)
            {

                result = num1;

            }

            else
            {

                result = num2;

            }

            break;

        // Calculates minimum in between two values
        case 'I':

            if(num1 < num2)
            {

                result = num1;

            }

            else
            {

                result = num2;

            }

            break;
    }

    // Prints the result to the user
    return result;

}



float optionU(float num1, char operation)
{

    float result = 0;

    // Lists input possibilities to calculate Unary operations
    switch (operation)
    {

        // To take the square root of given value
        case 'S':

            if(num1 < 0)
            {

                printf("\nMath Error. ");

                printf("The square root of a negative number is an imaginary number.\n");

                return 0;

            }

            else
            {

                result = sqrt(num1);

            }

            break;

        // To take the log of the value
        case 'L':

            if(num1 <= 0)
            {

                printf("\nMath Error. ");

                printf("The logarithm of 0 and any negative number results in no solution.\n");

                return 0;

            }

            else
            {

                result = log(num1);

            }

            break;

        // Take the exponentiation of value
        case 'E':

            result = exp(num1);

            break;

        // Gets the ceiling of the value
        case 'C':

            result = ceil(num1);

            break;

        // Floors the value
        case 'F':

            result = floor(num1);

            break;

    }

    return result;

}



void optionE()
{

    printf("\nThanks for using my Simple Calculator. Hope to see you soon again, Goodbye! \n");

}



int main()
{
    // num1 and num2 are for B and num1 for U. result is used to show final calculation
    float num1, num2, result = 0;

    //These help guide the program on what the user wants to do
    char option, operation, memorySlot1, memorySlot2, subOption;

    // Sets variables to zero to avoid potential errors
    float a = 0.00, b = 0.00, c = 0.00, d = 0.00, e = 0.00;

    // Helps the program differentiate between variable values
    float value, value0, value1, value2, value3, value4;

    // Lists possible choices
    float mem[5] = {a, b, c, d, e};

    // They make it possible to calculate both float and characters
    float aNum1, aNum2;
    float num1Val, num2Val;


    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Parsia Zahedi");
    puts("Assignment: Assignment 3");
    puts("Date: 2023");

    puts("-------------------------------------------------------------------------");
    puts("\nSelect one of the following items:");


    // The choices a user could do to start calculation
    do
    {

        // Stores given input in option
        option = mainMenu();

        // Goes through each option to start calculating
        switch (option)
        {

            case 'B':

                printf("\nPlease enter the first number: \n");


                // Validate input to ensure a numeric value is entered
                while (scanf(" %f", &num1) != 1)
                {

                    // Error message to ask the user to input the right input
                    printf("\nInvalid input. Please try again.\n");

                    // Gets the first number to start a binary operation
                    printf("\nPlease enter the first number: \n");

                    // Needed to clean the buffer
                    while(getchar() != '\n');

                }

                // Lists operation to choose from
                puts("\nBinary Mathematical Operations:");
                puts("+) - For addition.");
                puts("-) - For subtraction.");
                puts("*) - For multiplication.");
                puts("/) - For division.");
                puts("%) - For modular.");
                puts("P) - For power.");
                puts("X) - For maximum.");
                puts("I) - For minimum.");

                printf("\nPlease select the operation ( + , - , * , /, %%, P, X, I ): \n");

                // Takes operation that lets the user do the calcultions
                scanf(" %s", &operation);


                // Resticts anything other than the listed operation from being entered
                while (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%' && operation != 'P' && operation != 'X' && operation != 'I')
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease select the operation ( + , - , * , /, %%, P, X, I ): \n");

                    while(getchar() != '\n');

                    scanf(" %c", &operation);

                }

                // Takes second number to add to the first number
                printf("\nPlease enter the second number: \n");


                // Restricts any type of input other than float type numbers
                while (scanf("%f", &num2) != 1)
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease enter the second number: \n");

                    while(getchar() != '\n');

                }

                printf("\nThe result is %f\n\n", optionB(num1, num2, operation));

                break;

            // Calculates Unary Mathematical Operations
            case 'U':

                // Lists options available to choose from
                puts("\nUnary Mathematical Operations:");
                puts("S) - For square root (vx).");
                puts("L) - For logarithm base e (logx, or lnx).");
                puts("E) - For exponentiation (e^x).");
                puts("C) - For the smallest integer value greater than or equal to x (ceiling(x)).");
                puts("F) - For the largest integer value less than or equal to x (floor(x)).");

                printf("\nPlease enter the operation ( S, L, E, C, F ): \n");

                scanf(" %s", &operation);


                // Restricts anything other than specified characters
                while (operation != 'S' && operation != 'L' && operation != 'E' && operation != 'C' && operation != 'F')
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease enter the operation ( S, L, E, C, F ): \n");

                    while(getchar() != '\n');

                    scanf(" %c", &operation);

                }

                // Needs one number to calcuate Unary operations
                printf("\nPlease enter a number: \n");


                // Ensures only float and digit numbers allowed
                while (scanf("%f", &num1) != 1)
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease enter a number: \n");

                    while(getchar() != '\n');

                }

                printf("\nThe result is %f\n\n", optionU(num1, operation));

                break;


            // This option calculates operations including variables
            case 'A':

                puts("\nSelect one of the following items:");
                puts("B) - Binary Mathematical Operations, such as addition and subtraction with variables.");
                puts("U) - Unary Mathematical Operations, such as square root, and log with variables.");
                puts("E) - Exit to Main Menu.");

                printf("\nPlease select your option ( B, U, E ) \n");


                // Loop to swap between options B, U, or E
                do
                {

                    scanf("%s", &subOption);

                    // Restricts anything other than specified options
                    while (subOption != 'B' && subOption != 'U' && subOption != 'E')
                    {

                        printf("\nInvalid input. Please try again.\n");

                        puts("\nSelect one of the following items:");
                        puts("B) - Binary Mathematical Operations, such as addition and subtraction with variables.");
                        puts("U) - Unary Mathematical Operations, such as square root, and log with variables.");
                        puts("E) - Exit to Main Menu.");

                        printf("\nPlease select your option ( B, U, E ) \n");

                        while(getchar() != '\n');

                        scanf(" %c", &subOption);

                    }

                    // Swaps to calculate similar operations with variables
                    switch (subOption)
                    {

                        case 'B':

                            // Asks for a float, digit, or character to perform an operation
                            printf("\nPlease enter the first number / character: \n");

                            // Becomes true if given a float/digit value to calculate a binary operation
                            int flag = scanf(" %f", &aNum1);

                            // Looks for an alternative input since it did not get a number
                            if (flag != 1)
                            {

                                // Checks if it a character
                                flag = scanf(" %c", &memorySlot1);

                                // Restricts user by checking if the character matches the listed variables
                                if (flag != 1 || (memorySlot1 < 'a' || memorySlot1 > 'e'))
                                {

                                    printf("\nInvalid input. Please try again.\n");

                                    printf("\nPlease enter the first number / character: \n");

                                    while (getchar() != '\n');

                                    continue;

                                }

                                aNum1 = 0;
                            }

                            else
                            {

                                num1Val = aNum1;

                            }

                            // Checks the given variable and assigns it a value gotten from part V
                            if (memorySlot1 == 'a' && aNum1 == 0)
                            {

                                num1Val = value0;

                            }

                            else if (memorySlot1 == 'b' && aNum1 == 0)
                            {

                                num1Val = value1;

                            }

                            else if (memorySlot1 == 'c' && aNum1 == 0)
                            {

                                num1Val = value2;

                            }

                            else if (memorySlot1 == 'd' && aNum1 == 0)
                            {

                                num1Val = value3;

                            }

                            else if (memorySlot1 == 'e' && aNum1 == 0)
                            {

                                num1Val = value4;

                            }

                            // Gives the user the options available
                            puts("\nBinary Mathematical Operations with variables:");
                            puts("+) - For addition.");
                            puts("-) - For subtraction.");
                            puts("*) - For multiplication.");
                            puts("/) - For division.");
                            puts("%) - For modular.");
                            puts("P) - For power.");
                            puts("X) - For maximum.");
                            puts("I) - For minimum.");

                            printf("\nPlease enter the operation ( + , - , * , /, %%, P, X, I ): \n");

                            flag = 1;

                            scanf("%s", &operation);

                            // Gets the second number from the user
                            printf("\nPlease enter the second number / character: \n");

                            flag = scanf(" %f", &aNum2);

                            // It checks if the given value is not a float type integer
                            if (flag != 1)
                            {

                                flag = scanf(" %c", &memorySlot2);

                                // Restricts anything other than the variables
                                if (flag != 1 || (memorySlot2 < 'a' || memorySlot2 > 'e'))
                                {

                                    printf("Invalid input. Please try again.\n");

                                    while (getchar() != '\n');

                                    continue;

                                }

                                printf("\n%c = ", memorySlot2);

                                printf("%f\n", value);

                                aNum2 = 0;
                            }

                            else
                            {

                                num2Val = aNum2;

                            // Checks the second number's variable and assigns it value
                            }

                            if (memorySlot2 == 'a' && aNum2 == 0)
                            {

                                num2Val = value0;

                            }

                            else if (memorySlot2 == 'b' && aNum2 == 0)
                            {

                                num2Val = value1;

                            }

                            else if (memorySlot2 == 'c' && aNum2 == 0)
                            {

                                num2Val = value2;

                            }

                            else if (memorySlot2 == 'd' && aNum2 == 0)
                            {

                                num2Val = value3;

                            }
                            else if (memorySlot2 == 'e' && aNum2 == 0)
                            {

                                num2Val = value4;

                            }

                            // Loops through the binary operations
                            do
                            {

                                flag = 1;

                                // Does the same operations as Binary operations but with variables
                                switch (operation)
                                {

                                    case '+':

                                        result = num1Val + num2Val;

                                        break;

                                    case '-':

                                        result = num1Val - num2Val;

                                        break;

                                    case '*':

                                        result = num1Val * num2Val;

                                        break;

                                    case '/':

                                        do
                                        {

                                            if(num2Val == 0)
                                            {

                                                printf("\nMath Error. ");

                                                printf("Division by zero yields an undefined value.\n");

                                            }

                                            else
                                            {

                                                result = num1Val / num2Val;

                                                break;

                                            }

                                        }
                                        while(num2Val == 0);

                                        break;

                                    case '%':

                                        result = fmod(num1Val, num2Val);

                                        break;

                                    case 'P':

                                        result = pow(num1Val, num2Val);

                                        break;

                                    case 'X':

                                        if(num1Val > num2Val)

                                        {

                                            result = num1Val;

                                        }

                                        else
                                        {

                                            result = num2Val;

                                        }

                                        break;

                                    case 'I':

                                        if(num1Val < num2Val)
                                        {

                                            result = num1Val;

                                        }

                                        else
                                        {

                                            result = num2Val;

                                        }
                                        break;
                                }

                                printf("\nThe result is %f", result);

                                puts("\n\nSelect one of the following items:");
                                puts("B) - Binary Mathematical Operations, such as addition and subtraction with variables.");
                                puts("U) - Unary Mathematical Operations, such as square root, and log with variables.");
                                puts("E) - Exit to Main Menu.");

                                printf("\nPlease select your option ( B, U, E ) \n");

                                break;

                            }
                            // Loops if flag becomes false
                            while(flag == 0);

                            break;

                        // Does Unary Operations with variables
                        case 'U':

                            // Goes through a loop to ask the user to do the same operation or not
                            do
                            {

                            puts("\nUnary Mathematical Operations with variables:");
                            puts("S) - For square root (vx).");
                            puts("L) - For logarithm base e (logx, or lnx).");
                            puts("E) - For exponentiation (e^x).");
                            puts("C) - For the smallest integer value greater than or equal to x (ceiling(x)).");
                            puts("F) - For the largest integer value less than or equal to x (floor(x)).");

                            printf("\nPlease enter the operation ( S, L, E, C, F ): \n");

                            scanf("%s", &operation);


                            // Restricts anything other than given operations
                            while (operation != 'S' && operation != 'L' && operation != 'E' && operation != 'C' && operation != 'F')
                            {

                                printf("\nInvalid input. Please try again.\n\n");

                                printf("Please enter the operation ( S, L, E, C, F ): \n");

                                while(getchar() != '\n');

                                scanf(" %c", &operation);

                            }

                            // Asks for number to start performing Unary operations
                            printf("\nPlease enter a number: \n");

                            flag = scanf(" %f", &aNum1);

                            // This code makes it possible to use variables
                            if (flag != 1)
                            {
                                flag = scanf(" %c", &memorySlot1);

                                if (flag != 1 || (memorySlot1 < 'a' || memorySlot1 > 'e'))
                                {

                                    printf("Invalid input. Please try again.\n");

                                    while (getchar() != '\n');

                                    continue;

                                }

                                printf("\n%c = ", memorySlot1);

                                printf("%f\n", value);

                                aNum1 = 0;

                            }

                            else
                            {

                                num1Val = aNum1;

                            }

                            // Checks which variable given and assigns value
                            if (memorySlot1 == 'a' && aNum1 == 0)
                            {

                                num1Val = value0;

                            }

                            else if (memorySlot1 == 'b' && aNum1 == 0)
                            {

                                num1Val = value1;

                            }

                            else if (memorySlot1 == 'c' && aNum1 == 0)
                            {

                                num1Val = value2;
                            }

                            else if (memorySlot1 == 'd' && aNum1 == 0)
                            {

                                num1Val = value3;

                            }

                            else if (memorySlot1 == 'e' && aNum1 == 0)
                            {

                                num1Val = value4;

                            }

                            // Goes through Unary operation and switches between same operations with variables
                            switch (operation)
                            {

                                case 'S':


                                    if(num1Val < 0)
                                    {

                                        printf("Math Error. ");

                                        printf("The square root of a negative number is an imaginary number.\n");

                                    }

                                    else
                                    {

                                        result = sqrt(num1Val);

                                    }

                                    break;

                                case 'L':


                                    if(num1Val <= 0)
                                    {

                                        printf("Math Error. ");

                                        printf("The logarithm of 0 and any negative number results in no solution.\n");

                                    }

                                    else
                                    {

                                        result = log(num1Val);

                                    }

                                    break;

                                case 'E':

                                    result = exp(num1Val);

                                    break;

                                case 'C':

                                    result = ceil(num1Val);

                                    break;

                                case 'F':

                                    result = floor(num1Val);

                                    break;

                                // If none of the cases are true, it gives error message and repeats
                                default:

                                    printf("\n\nInvalid input. Please try again.\n");

                                    printf("Please enter the operation ( S, L, E, C, F ): \n");

                                    scanf("%s", &operation);

                                    break;

                            }

                            printf("\nThe result is %f", result);

                            printf("\n\nWould you like to do another operation? ( Y/N )\n");

                            scanf("%s", &operation);


                            while (operation != 'n' && operation != 'N' && operation != 'y' && operation != 'Y')
                            {

                                printf("\nInvalid input. Please try again.\n");

                                printf("\nWould you like to do another operation? ( Y/N )\n");

                                while(getchar() != '\n');

                                scanf(" %c", &operation);

                            }


                        }


                        // Ends the loop once user enters n or N
                        while(operation != 'n' && operation != 'N');

                        printf("\nPlease select your option ( B, U, E ) \n");

                        break;

                        // To make the user exit the sub-menu
                        case 'E':

                            printf("\nBack to Main Menu.\n\n");

                            break;

                    }

                }

                // Allows the user to exit the sub-menu after they enter the desired option
                while(subOption != 'E');


                break;

            // Makes it possible to put value into variables
            case 'V':

                // To get one of the options from the user
                printf("\nPlease enter the memory slot (a, b, c, d, e)\n");

                scanf(" %c", &memorySlot2);

                // Restricts anythng other than the options available
                while (memorySlot2 != 'a' && memorySlot2 != 'b' && memorySlot2 != 'c' && memorySlot2 != 'd' && memorySlot2 != 'e')
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease enter the memory slot (a, b, c, d, e)\n");

                    while(getchar() != '\n');

                    scanf(" %c", &memorySlot2);

                }

                printf("\nPlease enter the value for the slot:\n");

                // Ensures the user gives a number for variable value
                while (scanf("%f", &value) != 1)
                {

                    printf("\nInvalid input. Please try again.\n");

                    printf("\nPlease enter the value for the slot:\n");

                    while(getchar() != '\n');

                }

                // Goes through the given variable and assigns the given value to it
                switch (memorySlot2)
                {
                    case 'a':

                        value0 = value;

                        mem[0] = value0;

                        printf("\na = %f\n\n", mem[0]);

                        break;

                    case 'b':

                        value1 = value;

                        mem[1] = value1;

                        printf("\nb = %f\n\n", mem[1]);

                        break;

                    case 'c':

                        value2 = value;

                        mem[2] = value2;

                        printf("\nc = %f\n\n", mem[2]);

                        break;

                    case 'd':

                        value3 = value;

                        mem[3] = value3;

                        printf("\nd = %f\n\n", mem[3]);

                        break;
                    case 'e':

                        value4 = value;

                        mem[4] = value4;

                        printf("\ne = %f\n\n", mem[4]);

                        break;

                }

                break;

            // When given this character, it ends program
            case 'E':

                // Displays a goodbye message
                optionE();

         }

    }
    // Lets the user end the program after they enter e or E
    while(option != 'E');

}
