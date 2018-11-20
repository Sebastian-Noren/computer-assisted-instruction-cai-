#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TEST 15
#define PRACTICE 10

//PRE Func
void practiceMenu();
void testMenu();
void exitProgram();
void printMainMenu();
void correctResponse();
void wrongResponse();
void caiAdditionPractice();
void caiSubtractionPractice();
void caiMixedPractice();
void caiAdditionTest();
void caiSubtractionTest();
void caiMixedTest();

char answerName[20];

// MAIN PROGRAM
int main() {

    int choice;

    printf("----- Welcome to Computer Assisted Math Program -----\n");
    printf("\t We are hoping you have a good day.\n\n");
// Ask name
    printf("What are your name?\n");
    printf(">> ");
    scanf(" %s", &answerName);
    printf("\n Welcome, %s!\n",answerName);

    while(1){
//Pick in the menu
        printMainMenu();
        printf("Pick what you want to do today?\n");
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
                exitProgram();
                break;
            default : printf("Stop playing around\n");
        }//End switch
    }
    printf("\n**Terminate Program**");
    return 0;

}//END MAIN

//--------------------------------FUNCTIONS!!!!---------------------------------------//

//--------------------------------PRACTICE!!!!---------------------------------------//

// PRACTICE MENU
void practiceMenu() {
    int choice2;
    while (1) {
//Pick in the menu
        printf("\n----- Practice Menu -----\n");
        printf(">> 1. Addition\n");
        printf(">> 2. Subtraction\n");
        printf(">> 3. Addition and subtraction\n");
        printf("--------------------------\n");
        printf("\nPick what you want to practice?\n");
        printf(">> ");
        scanf(" %d", &choice2);

        switch (choice2) {
            case 1 :
                caiAdditionPractice();
                break;
            case 2 :
                caiSubstractionPractice();
                break;
            case 3 :
                caiMixedPractice();
                break;
            default :
                printf("Stop playing around!\n");
        }//End switch
        break;
    }// end loop
    return;
}

// ADDITION PRACTICE
void caiAdditionPractice() {

    printf("Now, you will be given 10 addition questions to solve.\n");
    srand(time(NULL));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int svar, rightAnswer = 0;

    while (rightAnswer < PRACTICE) {
        printf("How much is %d + %d? Answer = ", a, b);
        scanf(" %d", &svar);

        if (svar == a + b) {
            correctResponse();
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            rightAnswer++;
        } else {
            wrongResponse();
        }
    }
    return;
}

// SUBTRACTION PRACTICE
void caiSubstractionPractice() {

    printf("Now, you will be given 10 subtraction questions to solve.\n");
    srand(time(NULL));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int svar, temp, rightAnswer = 0;

    while (rightAnswer < PRACTICE) {
        if (b > a) {
            temp = b;
            b = a;
            a = temp;
        }
        printf("How much is %d - %d? Answer = ", a, b);
        scanf(" %d", &svar);

        if (svar == a - b) {
            correctResponse();
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            rightAnswer++;
        } else {
            wrongResponse();
        }
    }
    return;
}

// MIXED ADDITION & SUBTRACTION PRACTICE
void caiMixedPractice() {

    printf("Now, you will be given 10 mixed questions to solve.\n");
    int svar, temp, rightAnswer = 0;

    srand(time(NULL));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    while (rightAnswer < PRACTICE) {

        int mixed = rand() % 2;

        if (mixed == 0) {
            while (1) {
                printf("How much is %d + %d? Answer = ", a, b);
                scanf(" %d", &svar);

                if (svar == a + b) {
                    correctResponse();
                    a = rand() % 100 + 1;
                    b = rand() % 100 + 1;
                    rightAnswer++;
                    break;
                } else {
                    wrongResponse();
                }
            }// END ADDITION LOOP
        }// EnN Addition
        else if (mixed == 1) {

            while (1) {
                if (b > a) {
                    temp = b;
                    b = a;
                    a = temp;
                }
                printf("How much is %d - %d? Answer = ", a, b);
                scanf(" %d", &svar);

                if (svar == a - b) {
                    correctResponse();
                    a = rand() % 100 + 1;
                    b = rand() % 100 + 1;
                    rightAnswer++;
                    break;
                } else {
                    wrongResponse();
                }

            }// END SUBTRACTION LOOP
        } // END SUBTRACTION
    } //END ANSWER LOOP
    return;
}

//--------------------------------TEST!!!!---------------------------------------//

// TEST MENU
void testMenu() {
    int choice3;
    while (1) {
//Pick in the menu
        printf("\n------ Test Menu -------\n");
        printf(">> 1. Test Addition\n");
        printf(">> 2. Test Subtraction\n");
        printf(">> 3. Test Addition and subtraction\n");
        printf("--------------------------\n");
        printf("\nPick what you want to do a test on?\n");
        printf(">> ");
        scanf(" %d", &choice3);

        switch (choice3) {
            case 1 :
                caiAdditionTest();
                break;
            case 2 :
                caiSubtractionTest();
                break;
            case 3 :
                caiMixedTest();
                break;
            default :
                printf("Stop playing around!\n");
        }//End switch
        break;
    }// end loop
    return;
}

// ADDITION TEST
void caiAdditionTest() {

    printf("Now, you will be tested with 15 questions to solve.\n\n");

    int svar[TEST], correct[TEST], i = 0;
    float rightanswer = 0.0;
    float result = 0.0;
    srand(time(NULL));
    int a[TEST];
    int b[TEST];

    while (i < TEST) {

        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;
        printf("How much is %d + %d? Answer = ", a[i], b[i]);
        scanf(" %d", &svar[i]);
        correct[i] = a[i] + b[i];

        if (svar[i] == correct[i]) {
            correctResponse();
            rightanswer++;
            i++;
        } else {
            printf("No. Wrong!\n");
            i++;
        }
    }
    result = (rightanswer / TEST) * 100;
    printf("\nTest completed you had %.f%% right %s.\n", result, answerName);
    printf("Detailed questions and answers:\n\n");

    printf("%s:\t  %s: \t%s:\n", "Question", "Correct Answer", "Your Answer");
    for (i = 0; i < TEST; i++) {
        printf("%d. %d + %d\t\t%d\t\t   %d\n", i + 1, a[i], b[i], correct[i], svar[i]);
    }
    return;
}

// SUBTRACTION TEST
void caiSubtractionTest() {

    printf("Now, you will be tested with 15 questions to solve.\n\n");

    int svar[TEST], correct[TEST], temp[TEST], i = 0;
    float rightanswer = 0.0;
    float result = 0.0;
    srand(time(NULL));
    int a[TEST];
    int b[TEST];

    while (i < TEST) {

        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;

        if (b[i] > a[i]) {
            temp[i] = b[i];
            b[i] = a[i];
            a[i] = temp[i];
        }
        printf("How much is %d - %d? Answer = ", a[i], b[i]);
        scanf(" %d", &svar[i]);
        correct[i] = a[i] - b[i];

        if (svar[i] == correct[i]) {
            correctResponse();
            rightanswer++;
            i++;
        } else {
            printf("No. Wrong!\n");
            i++;
        }
    }

    result = (rightanswer / TEST) * 100;

    printf("\nTest completed you had %.f%% right %s.\n", result, answerName);
    printf("Detailed questions and answers:\n\n");

    printf("%s:\t  %s: \t%s:\n", "Question", "Correct Answer", "Your Answer");
    for (i = 0; i < TEST; i++) {
        printf("%d. %d - %d\t\t%d\t\t   %d\n", i + 1, a[i], b[i], correct[i], svar[i]);
    }
    return;
}

// MIXED ADDITION & SUBTRACTION TEST
void caiMixedTest() {

    printf("Now, you will be tested with 15 mixed questions to solve.\n\n");
    int svar[TEST], correct[TEST], temp[TEST], i = 0;
    float rightAnswer = 0.0;
    float result = 0.0;
    int a[TEST];
    int b[TEST];
    char c[TEST];

    srand(time(NULL));
    while (i < TEST) {

        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;

        int mixed = rand() % 2;
        if (mixed == 0) {

            printf("How much is %d + %d? Answer = ", a[i], b[i]);
            scanf(" %d", &svar[i]);
            correct[i] = a[i] + b[i];
            c[i] = '+';

            if (svar[i] == correct[i]) {
                correctResponse();
                rightAnswer++;
                i++;
            } else {
                printf("No. Wrong!\n");
                i++;
            }

        }// EnN Addition

        else if (mixed == 1) {

            if (b[i] > a[i]) {
                temp[i] = b[i];
                b[i] = a[i];
                a[i] = temp[i];
            }
            printf("How much is %d - %d? Answer = ", a[i], b[i]);
            scanf(" %d", &svar[i]);
            correct[i] = a[i] - b[i];
            c[i] = '-';

            if (svar[i] == correct[i]) {
                correctResponse();
                rightAnswer++;
                i++;
            } else {
                printf("No. Wrong!\n");
                i++;
            }
        } // END SUBTRACTION
    } //END ANSWER LOOP
    result = (rightAnswer / TEST) * 100;


    printf("\nTest completed you had a %.f%% right %s.\n", result, answerName);
    printf("Detailed questions and answers:\n\n");

    printf("%s:\t  %s: \t%s:\n", "Question", "Correct Answer", "Your Answer");
    for (i = 0; i < TEST; i++) {
        printf("%d. %d %c %d\t\t%d\t\t   %d\n", i + 1, a[i], c[i], b[i], correct[i], svar[i]);
    }
    return;
}

//--------------------------------SYSTEM!!!!---------------------------------------//

// EXIT PROGRAM
void exitProgram() {
    char answer;
    printf("Do you want to quit? (y/n) \n");
    printf(">> ");
    scanf(" %c", &answer);

    if ((answer == 'y')) {
        printf("Have a nice day!\n\n");
        exit(0);
    }
    return;
}

//GUI MAIN MENU
void printMainMenu() {
    printf("\n------ Main Menu -------\n");
    printf(">> 1. Do practices\n");
    printf(">> 2. Complete a test\n");
    printf(">> 3. Quit Program\n");
    printf("------------------------\n\n");
    return;
}

// ANSWER CORRECT grade 5
void correctResponse() {
    int c = rand() % 6;
    if (c == 0) {
        printf("Very good!\n");
    } else if (c == 1) {
        printf("Excellent!\n");
    } else if (c == 2) {
        printf("Nice Work!\n");
    } else if (c == 3) {
        printf("Well Done!\n");
    } else if (c == 4) {
        printf("Great!\n");
    } else if (c == 5) {
        printf("Keep up the good work!\n");
    }
    return;
}

// ANSWERS WRONG grade 5
void wrongResponse() {

    int d = rand() % 4;
    if (d == 0) {
        printf("No. Please try Again!\n");
    } else if (d == 1) {
        printf("Wrong! try once again\n");
    } else if (d == 2) {
        printf("Don´t give up!\n");
    } else if (d == 3) {
        printf("No. Keep trying!\n");
    }
    return;
}
