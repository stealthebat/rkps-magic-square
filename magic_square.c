#include <stdio.h>

void printBoard(int A[]);
void checkWin(int A[], int* W);

int main() {
    printf("\t\t\tMAGIC SQUARE\n");
    printf("\t\tCREATIVE COMPUTING  MORRISTOWN NEW JERSEY\n");

    int A[9] = {0}; 
    int B[9] = {0}; 
    int M = 0, W = 0;
	int R1 = 0, Q1 = 0;
	
    printf("\n\n\n");
	printf("GAME OF MAGIC SQUARE\n\n");
    printf("PLAYERS ALTERNATLEY CHOOSE AN INTEGER (1 TO 9)\n");
    printf("THAT HAS NOT BEEN PREVIOUSLY USED AND PLACE IT\n");
    printf("IN ANY UNFILLED CELL OF A TIC-TAC-TOE BOARD.\n");
    printf("THE GOAL IS TO MAKE THE SUM OF EACH ROW, COLUMN,\n");
    printf("AND DIAGONAL EQUAL TO 15.\n\n");
    printf("THAT PLAYER LOSES WHO FIRST MAKES THE SUM OF THE\n");
    printf("THREE FIGURES IN ANY ROW, COLUMN, OR DIAGONAL\n");
    printf("SOMETHING OTHER THAN 15.\n\n");
    printf("A TIE GAME DRAWS A MAGIC SQUARE!!\n\n");
	
	printf("THE COMPUTER WILL ASK YOU ON EACH MOVE WHICH\n");
    printf("CELL YOU WISH TO OCCUPY, AND THE NUMBER YOU WISH\n");
    printf("LIKE '3,7' IF YOU WISHED TO PUT A 7 IN CELL 3.\n\n");
    printf("HERE ARE THE CELL NUMBERS:\n\n");
    printf("1 2 3\n");
    printf("4 5 6\n");
    printf("7 8 9\n");

label35:
    for (int i = 0; i < 9; i++) {
        A[i] = 0;
        B[i] = 0;
    }
	M = 0;
	W = 0;
	
label43:	
	while (1) {
        printf("\nINPUT YOUR MOVE -- CELL AND NUMBER? ");
        int I, N;
        scanf("%d,%d", &I, &N);

        if (I < 1 || I > 9 || N < 1 || N > 9) {
            printf("ILLEGAL MOVE ... AGAIN\n");
            continue;
        }
        if (A[I - 1] == 0 && B[N - 1] == 0) {
            A[I - 1] = N;
            B[N - 1] = 1; 
            M++; 
            break; 
        } else {
            printf("ILLEGAL MOVE ... AGAIN\n");
        }
    }
	
	printBoard(A);
    checkWin(A, &W);
	
    if (W == 1) {
        printf("SORRY, YOU LOSE -- NICE TRY.\n");
        goto label115;
    }
	
	if (M >= 5) {
		printf("A TIE GAME -- BUT WE'VE DRAWN A MAGIC SQUARE!\n");
		goto label115;
	}
	
	R1 = 0;
	Q1 = 0;

    for (int Q = 1; Q <= 9; Q++) {
        if (A[Q - 1] > 0) {
            continue;
        }

        for (int R = 1; R <= 9; R++) {
            if (B[R - 1] > 0) {
                continue;
            }

            A[Q - 1] = R;
            checkWin(A, &W);

            if (W == 0) {
				R1 = R;
				Q1 = Q;
                goto label105;
            }

            Q1 = Q; R1 = R; W = 0; A[Q - 1] = 0;
        }
    }

    W = 1;
	A[Q1 - 1] = R1;
	
label105:
    B[R1 - 1] = 1;
    printf("I MOVE TO CELL  %d  WITH A  %d\n", Q1, R1);
    printBoard(A);

    if (W == 0) {
        goto label43; // Equivalent to GOTO 103
    }
    printf("I LOSE -- YOU WIN!!\n\n");
	
label115:
    for (int I = 1; I <= 15; I++) {
        printf("%c", 7);
    }
    printf("LET'S PLAY AGAIN. . .\n");
    goto label35;
}



void printBoard(int A[]) {
    printf("\n");
    for (int j = 0; j < 3; j++) {
        printf(" %d             %d             %d\n", A[j * 3], A[j * 3 + 1], A[j * 3 + 2]);
    }
	printf("\n");
}


void checkWin(int A[], int *W) {
    for (int X = 1; X <= 8; X++) {
        int J, K, L;

        switch (X) {
            case 1:
                J = 1; K = 2; L = 3; break;
            case 2:
                K = 4; L = 7; break;
            case 3:
                K = 5; L = 9; break;
            case 4:
                J = 4; L = 6; break;
            case 5:
                J = 2; L = 8; break;
            case 6:
                J = 3; L = 7; break;
            case 7:
                J = 7; L = 9; break;
            case 8:
                J = 7; K = 8; break;
        }

        if (A[J - 1] == 0 || A[K - 1] == 0 || A[L - 1] == 0) {
            continue;
        }

        if (A[J - 1] + A[K - 1] + A[L - 1] != 15) {
            *W = 1; 
        }
    }
}