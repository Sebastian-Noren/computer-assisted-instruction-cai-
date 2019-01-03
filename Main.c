#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAXS 60
#define TEST 15
#define PRACTICE 10
#define HISTORY "history.txt"
#define CUR_USER "current_user.txt"

//PRE Func
void practiceMenu();
void testMenu();
void exitProgram();
void printMainMenu();
void correctResponse();
void wrongResponse();
void practice();
void test();
void caiSubtractionTest();
void displayHistory();

char answerName[12];
FILE * fp;
time_t currentTime;

typedef struct
{
    int pct,
        test;
    char name[12],
         date[12];
} testHistory;

// qsort compare function sorting array struct by percent
int compare_result (const void *a, const void *b)
{
    const testHistory   *as = a,
                        *bs = b;

    /* return descending sort (conditionals avoids potential overflow)
     * for ascending sort use (as > bs) - (as < bs)
     */
    return (as->pct < bs->pct) - (as->pct > bs->pct);
}

// MAIN PROGRAM
int main(){

    int choice;
    remove(CUR_USER);
    printf("----- Welcome to Computer Assisted Math Program -----\n");
    printf("\t We are hoping you have a good day.\n\n");
// Ask name
    printf("What are your name?\n");
    printf(">> ");
    gets(&answerName);
    printf("\nWelcome, %s!\n",answerName);

    while(1){
//Pick in the menu
        printMainMenu();
        printf("\nPick what you want to do today?\n");
        printf(">> ");
        scanf(" %d", &choice);

        switch(choice){
        case 1 :
            practiceMenu();
            break;
        case 2 :
            testMenu();
            break;
        case 3 :
            displayHistory(choice);
            printf("Press Enter to continue..!\n\n");
            getch();
            break;
        case 4 :
            displayHistory(choice);
            printf("Press Enter to continue..!\n\n");
            getch();
            break;
        case 5 :
            displayHistory(choice);
            printf("Press Enter to continue..!\n\n");
            getch();
            break;
        case 6 :
            printf("Have a nice day!\n\n");
            exit(0);
            break;
        default :
            printf("what do you want to do?\n");
        }//End switch
    }
    printf("\n**Terminate Program**");
    return 0;

}//END MAIN

//--------------------------------FUNCTIONS!!!!---------------------------------------//

//--------------------------------PRACTICE!!!!---------------------------------------//

// PRACTICE MENU
void practiceMenu()
{
    int choice2;
    while (1)
    {
//Pick in the menu
        printf("\n-------- Practice Menu --------\n");
        printf(">> 1. Addition\n");
        printf(">> 2. Subtraction\n");
        printf(">> 3. Addition and subtraction\n");
        printf(">> 4. Go back\n");
        printf("-------------------------------\n");
        printf("\nPick what you want to practice?\n");
        printf(">> ");
        scanf(" %d", &choice2);

        switch (choice2){
        case 1 :
            printf("Now, you will be given 10 addition questions to solve.\n");
            practice(choice2);
            break;
        case 2 :
            printf("Now, you will be given 10 subtraction questions to solve.\n");
            practice(choice2);
            break;
        case 3 :
            printf("Now, you will be given 10 mixed questions to solve.\n");
            practice(choice2);
            break;
        case 4 :
            break;
        default :
            printf("Stop playing around!\n");
        }//End switch
        break;
    }// end loop
    return;
}

//PRACTICE
void practice(int choice2){

    srand(time(NULL));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int svar, temp, rightAnswer = 0;

    while (rightAnswer < PRACTICE){
        int mixed = rand() % 2;

        if (choice2 == 1 || choice2 == 3 && mixed == 0){
            printf("How much is %d + %d? Answer = ", a, b);
            scanf(" %d", &svar);
        }
        else if (choice2 == 2 || choice2 == 3 && mixed == 1){
            if (b > a){
                temp = b;
                b = a;
                a = temp;
            }
            printf("How much is %d - %d? Answer = ", a, b);
            scanf(" %d", &svar);
        }
        if (svar == a + b || svar == a - b){
            correctResponse();
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            rightAnswer++;
        }
        else{
            wrongResponse();
        }
    }
    printf("\nPractice done!\n");
    return;
}

//--------------------------------TEST!!!!---------------------------------------//

// TEST MENU
void testMenu(){

    int choice3;
    while (1){
//Pick in the menu
        printf("\n-------- Test Menu ------------\n");
        printf(">> 1. Addition\n");
        printf(">> 2. Subtraction\n");
        printf(">> 3. Addition and subtraction\n");
        printf(">> 4. Go back\n");
        printf("-------------------------------\n");
        printf("\nPick what you want to do a test on?\n");
        printf(">> ");
        scanf(" %d", &choice3);

        switch (choice3){
        case 1 :
            printf("Now, you will be tested with 15 questions to solve.\n\n");
            test(choice3);
            break;
        case 2 :
            printf("Now, you will be tested with 15 questions to solve.\n\n");
            test(choice3);
            break;
        case 3 :
            printf("Now, you will be tested with 15 mixed questions to solve.\n\n");
            test(choice3);
            break;
        case 4 :
            break;
        default :
            printf("Stop playing around!\n");
        }//End switch
        break;
    }// end loop
    return;
}

//TEST
void test(int choice3){

    int svar[TEST], correct[TEST],temp[TEST], i = 0;
    float rightanswer = 0.0;
    float result = 0.0;
    srand(time(NULL));
    int a[TEST];
    int b[TEST];
    char c[TEST];
    while (i < TEST){
        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;
        int mixed = rand() % 2;

        if (choice3 == 1 || choice3 == 3 && mixed == 0){

            printf("How much is %d + %d? Answer = ", a[i], b[i]);
            scanf(" %d", &svar[i]);
            c[i] = '+';
            correct[i] = a[i] + b[i];
        }
        else if (choice3 == 2 || choice3 == 3 && mixed == 1){

            if (b[i] > a[i]){
                temp[i] = b[i];
                b[i] = a[i];
                a[i] = temp[i];
            }
            printf("How much is %d - %d? Answer = ", a[i], b[i]);
            scanf(" %d", &svar[i]);
            c[i] = '-';
            correct[i] = a[i] - b[i];
        }
        if (svar[i] == correct[i]){
            correctResponse();
            rightanswer++;
            i++;
        }
        else{
            printf("No. Wrong!\n");
            i++;
        }
    }

    result = (rightanswer / TEST) * 100;
    printf("\nTest completed you had %.f%% right %s.\n", result, answerName);
    printf("Detailed questions and answers:\n\n");

    // Date and save to file!
    char date[12];
    time( &currentTime );
    struct tm *time_ptr;
    time_ptr = localtime(&currentTime);
    strftime(date, 12, "%d/%m/%Y", time_ptr);
    fp = fopen(CUR_USER, "a");
    fprintf(fp,"%.f%% \t  %-12.12s\t %d \t  %s\n",result, answerName, choice3, date);
    fclose(fp);
    fp = fopen(HISTORY, "a");
    fprintf(fp,"%.f%% \t  %-12.12s\t %d \t  %s\n",result, answerName, choice3, date);
    fclose(fp);
    // End print to file
    printf("Question:\t  Correct Answer:    Your Answer:\n");
    for (i = 0; i < TEST; i++){
        printf("%d. %d %c %d\t\t%d \t\t %d\n", i + 1, a[i], c[i], b[i], correct[i], svar[i]);
    }
    printf("\nTest done!\n");
    printf("Press Enter to continue..!\n\n");
    getch();
    return;
}

//--------------------------------SYSTEM!!!!---------------------------------------//

// Display test grade 3 and 5
void displayHistory(int choice)
{
    testHistory user[MAXS] = {{ .pct = 0 }};   //array of struct
    size_t n = 0;
    if(choice == 3 || choice == 5){
        fp = fopen(HISTORY, "r");
        // validate file open for reading
        if (!fp){
            perror ("File open failed");
            printf("Do a test first!\n");
            return;
        }
    }
    else if(choice ==4){
        fp = fopen(CUR_USER, "r");
        // validate file open for reading
        if (!fp){
            perror ("File open failed");
            printf("Do a test first!\n");
            return;
        }
    }
    //fill up to MAXS struct from file
    while (n < MAXS && fscanf (fp, "%d%% %s %d %s", &user[n].pct,
                               user[n].name, &user[n].test, user[n].date) == 4)
    {
        n++;
    }
    if (fp != stdin){
        fclose (fp);   //close file if not stdin
    }
    if(choice == 5){
    // sort by calling compare_result to sort by percent (descending order) and sets n to 5.
    qsort (user, n, sizeof *user, compare_result);
    n = 5;
    }
    // output results
    printf("Result:   User:        Test type:      Date:\n\n");
    for (size_t i = 0; i < n; i++){
        printf ("%3d%%      %-12s    %2d        %s\n",
                user[i].pct, user[i].name, user[i].test, user[i].date);
    }
    printf("\n\n");
    return;
}

//GUI MAIN MENU
void printMainMenu()
{
    printf("\n---------- Main Menu ----------\n");
    printf(">> 1) Do practices\n");
    printf(">> 2) Complete a test\n");
    printf(">> 3) Display test history\n");
    printf(">> 4) Display my history\n");
    printf(">> 5) Display top 5 result\n");
    printf(">> 6) Quit Program\n");
    printf("-------------------------------\n");
    return;
}

// ANSWER CORRECT grade 5
void correctResponse()
{
    int c = rand() % 6;
    if (c == 0)
    {
        printf("Very good!\n");
    }
    else if (c == 1)
    {
        printf("Excellent!\n");
    }
    else if (c == 2)
    {
        printf("Nice Work!\n");
    }
    else if (c == 3)
    {
        printf("Well Done!\n");
    }
    else if (c == 4)
    {
        printf("Great!\n");
    }
    else if (c == 5)
    {
        printf("Keep up the good work!\n");
    }
    return;
}

// ANSWERS WRONG grade 5
void wrongResponse()
{
    int d = rand() % 4;
    if (d == 0)
    {
        printf("No. Please try Again!\n");
    }
    else if (d == 1)
    {
        printf("Wrong! try once again!\n");
    }
    else if (d == 2)
    {
        printf("Do not give up!\n");
    }
    else if (d == 3)
    {
        printf("No. Keep trying!\n");
    }
    return;
}
