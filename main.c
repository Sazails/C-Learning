#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// returning functions must be above main function if without signature

// signature to allow function to be written bellow main() function
double doubleNumber(double number);
int max(int num1, int num2);
int equal(int num1, int num2);

struct User
{
    char name[32];
    int age;
    double rating;
};

int main()
{
start:
    printf("\n\n\n\nC learning project.\n");
    goto options;

options:
    printf("1) Print hello world\n");
    printf("2) Print shape\n");
    printf("3) Dynamic story variables\n");
    printf("4) Simple variable printing\n");
    printf("5) Simple math\n");
    printf("6) Simple input\n");
    printf("7) Basic calculator\n");
    printf("8) Mad lib game\n");
    printf("9) Simple array\n");
    printf("10) Countdown test\n");
    printf("11) Print string\n");
    printf("12) Double number\n");
    printf("13) Max\n");
    printf("14) Equal\n");
    printf("15) Create user from struct\n");
    printf("16) Basic loop\n");
    printf("17) Number guessing game\n");
    printf("18) 2D array\n");
    printf("19) Memory address\n");
    printf("20) Write/Read files\n");

    int selectedFunction;
    printf("Enter the number of which function to run : ");
    scanf("%d", &selectedFunction);

    printf("\n\n");

    switch(selectedFunction)
    {
    case 1 :
        printHelloWorld();
        break;
    case 2 :
        printShape();
        break;
    case 3 :
        storyDynamicVariables();
        break;
    case 4 :
        simpleVariablePrinting();
        break;
    case 5 :
        simpleMath();
        break;
    case 6 :
        simpleInput();
        break;
    case 7 :
        basicCalculator();
        break;
    case 8 :
        madLibGame();
        break;
    case 9 :
        simpleArray();
        break;
    case 10 :
        countdownTest();
        break;
    case 11 :
        printString("test string");
        break;
    case 12 :
        printf("Double of 4 : %f", doubleNumber(4));
        break;
    case 13 :
        printf("Max -5 or 5 : %f", max(-5, 5));
        break;
    case 14 :
        printf("5 is equal to 5 : %d", equal(5, 5));
        break;
    case 15 :
        creatingUserFromStruct();
        break;
    case 16 :
        basicLoop();
        break;
    case 17 :
        numberGuessingGame();
        break;
    case 18 :
        doubleArray();
        break;
    case 19 :
        memoryAddress();
        break;
    case 20 :
        writeReadFiles();
        break;
    default :
        printf("Select a function that exists.");
    }

    printf("\n\n");
    printf("Press any button to continue.");
    getch();
    goto start;
    return 0;
}

void writeReadFiles()
{
    // w = write to file (will overwrite all previous saved information)
    // a = append to file (adds text to previous saved data)
    // r = read from file

    // writing to file
    FILE * fPointer = fopen("user.txt", "w");
    fprintf(fPointer, "Davis, pass123\nMad Man, password");

    FILE * fPointer2 = fopen("user2.txt", "a");
    fprintf(fPointer2, "Testing, Once, Again!\n");

    fclose(fPointer);
    fclose(fPointer2);

    // reading from file
    FILE * fPointer3 = fopen("user.txt", "r");

    char line[255];
    fgets(line, 255, fPointer3);
    printf("%s", line);

    fclose(fPointer3);
}

void memoryAddress()
{
    char name[] = "Baven";
    double rating = 4.2;
    int id = 202;

    char * pName = &name;
    double * pRating = &rating;
    int * pId = &id;

    // %p for printing out a pointer
    // & gets the variable memory address

    printf("Value => Address\n");
    printf("name : %s | Address : %p\n", name, &name);
    printf("rating : %f | Address : %p\n", rating, &rating);
    printf("id : %d | Address : %p\n", id, &id);

    printf("\nAddress => Value\n");
    printf("name : %p | Value : %s\n", pName, pName);
    printf("rating : %p | Value : %f\n", pRating, *pRating);
    printf("id : %p | Value : %d\n", pId, *pId);

}

void doubleArray()
{
    int numbers[4][2] =
    {
        {1, 4},
        {2, 3},
        {3, 2},
        {4, 1}
    };

    printf("At [1][1] : %d\n", numbers[1][1]);

    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 2; y++)
        {
            printf("%d, ", numbers[x][y]);
        }
        printf("\n");
    }
}

void numberGuessingGame()
{
    int secretNumber = 5;
    int guess;
    int guessCount = 0;
    int guessLimit = 5;
    int outOfGuesses = 0;

    printf("The secret number is between %d and %d, good luck!\n",
           secretNumber - 5, secretNumber + 5);

    while(guess != secretNumber && outOfGuesses == 0)
    {
        if(guessCount < guessLimit)
        {
            printf("Enter the number : ");
            scanf("%d", &guess);
            guessCount++;
        }
        else
        {
            outOfGuesses = 1;
        }
    }

    if(outOfGuesses == 0)
    {
        printf("You have won in %d tries.\n", guessCount);
    }
    else
    {
        printf("You have lost, ran out of guesses!");
    }

}

void basicLoop()
{
    int numb = 0;
    while(numb < 5)
    {
        printf("numb : %d\n", numb);
        numb++;
    }

    do
    {
        printf("numb : %d\n", numb);
        numb--;
    }
    while(numb > 0);

    for(int i = 0; i > -5; i--)
    {
        printf("I : %d\n", i);
    }

    int numbers[] = {2, 4, 8, 16, 32};
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", numbers[i]);
    }
}

void creatingUserFromStruct()
{
    struct User user;
    user.age = 20;
    user.rating = 4.7;
    strcpy(user.name, "Tom Holt");

    printf("Name : %s\n", user.name);
    printf("Age : %d\n", user.age);
    printf("Rating : %f\n", user.rating);
}

int equal(int num1, int num2)
{
    return num1 == num2;
}

// returns bigger number
int max(int num1, int num2)
{
    int result;

    if(num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

double doubleNumber(double number)
{
    return number * 2;
}

void printString(char string[])
{
    printf("%s", string);
}

void countdownTest()
{
    static int countdown = 5;
    printf("%d\n", countdown);
    while(countdown > 0)
    {
        countdown--;
        countdownTest();
    }
}

void simpleArray()
{
    int numbers[] = { 4, 8, 12, 16, 20};
    printf("%d", numbers[1]);
}

void madLibGame()
{
    char smell[18];
    char object[18];
    char emotion[18];

    /*
    for input the & in front of variables is needed
    except when entering a character array (string)
    */

    printf("Enter a smell : ");
    scanf("%s", smell);

    printf("Enter an object : ");
    scanf("%s", object);

    printf("Enter an emotion: ");
    scanf("%s", emotion);

    printf("I smell %s,\n", smell);
    printf("I live in a %s,\n", object);
    printf("This makes me %s.\n", emotion);
}

void basicCalculator()
{
    double num1;
    double num2;
    char mathFormat;

    printf("Enter first number : ");
    scanf("%lf", &num1);
    printf("Enter math operator : ");
    scanf(" %c", &mathFormat);
    printf("Enter second number : ");
    scanf("%lf", &num2);

    switch(mathFormat)
    {
    case '+' :
        printf("Answer : %f", num1 + num2);
        break;
    case '-' :
        printf("Answer : %f", num1 - num2);
        break;
    case '*' :
        printf("Answer : %f", num1 * num2);
        break;
    case '/' :
        printf("Answer : %f", num1 / num2);
        break;
    default :
        printf("Operator does not exist!");
        break;
    }
}

void simpleInput()
{
    // TODO : Figure out how to properly use the input scanning without weird looking bugs
    char userName[24] = "User";
    int userAge;
    double userRating;
    char userGroup;
    char userSecurityId[8];

    // fgets = get the whole line as a string
    // 24 is the max char limit to the input
    // stdin = get input from console
    // sizeof(userName) / sizeof(userName[0]) = get array size of userName
    printf("Enter your name : ");
    fgets(userName, sizeof(userName) / sizeof(userName[0]), stdin);

    printf("Enter your age : ");
    scanf("%d", &userAge);

    printf("Enter your rating : ");
    scanf("%lf", &userRating);

    printf("Enter your group : ");
    scanf(" %c", &userGroup);

    /*
    the %c has a space before it so it doesn't read the \n character
    left in the stream from the last scanf call
    */

    // userSecurityId is fixed to 8 character limit
    printf("Enter your security id : ");
    scanf("%s", &userSecurityId);

    printf("\n==============================\n");
    printf("User Details\n");
    printf("Name : %s\n", userName);
    printf("Age : %d\n", userAge);
    printf("Rating : %lf\n", userRating);
    printf("Group : %c\n", userGroup);
    printf("Security ID : %s\n", userSecurityId);
    printf("==============================\n");
}

void simpleMath()
{
    // pow = cube number
    // sqrt = square root
    // ceil = ceiling rounds number up
    // floor = floor rounds number down

    printf("%f\n", pow(3,3));
    printf("%f\n", sqrt(16));
    printf("%f\n", ceil(1.511));
    printf("%f\n", floor(1.511));
}

void simpleVariablePrinting()
{
    int age = 40;
    double rating = 4.7;
    char group = 'B';
    char groupName[] = "Bimbo";
    const int maxGroupId = 999;

    // %lf = double
    // &f = float
    // for printing you can use %f for float and double
    // scanning requires the correct format of the variable

    // double has 64 bit precision
    // float has 32 bit precision

    printf("Age : %d | Rating : %lf | Group : %c | Group name : %s | Max Group ID : %d\n",
           age, rating, group, groupName, maxGroupId);
}

void storyDynamicVariables()
{
    char characterName[] = "Johan";
    int characterAge = 20;

    // %s is string
    // %d is integer

    printf("Welcome to the haven %s.\n", characterName);
    printf("You are %d years old.\n", characterAge);
    printf("But you can skip from %d to %d years old.\n", characterAge, characterAge + 2);
}

void printShape()
{
    printf("*****\n");
    printf("*   *\n");
    printf("*   *\n");
    printf("*****\n");
}

void printHelloWorld()
{
    printf("Hello world!\n");
}
