#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printStuff(char moves[9]){
	printf("  %c | %c | %c\n", moves[0], moves[1], moves[2]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", moves[3], moves[4], moves[5]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", moves[6], moves[7], moves[8]);
	
}

char invertPlayer(char player){
	if(player == 'X'){
		return 'O';
	}
	return 'X';
}

int hasWon(char moves[9]){
	int i = 0;
	int lines[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
  };
  for (i = 0; i < 8; i++) {
    int a = lines[i][0];
    int b = lines[i][1];
    int c = lines[i][2];
    if (moves[b] == moves[c] && moves[a] == moves[b] && moves[a] == moves[c] && moves[a] != ' ') {
      return 1;
    }
  }
  return 0;
}

int scanInt(){
	int i = 0;
	 for (;;) //infinite loop, equivalent to while(1)
    {
    	
        int c;
        //prompt user for input
        	

        //attempt to read and convert input
        if ( scanf( "%d", &i ) == 1 )
        {
            //verify that remainder of input only consists of
            //whitespace characters
            while ( ( c = getchar() ) != EOF && c != '\n' )
            {
                if ( !isspace(c) )
                {
                    //we cannot use "break" here, because we want
                    //to break out of the outer loop, not the inner
                    //loop
                    goto invalid_input;
                }
            }

            //input is valid
            break;
        }

    invalid_input:

        //print error message
       
        //discard remainder of line
        do
        {
            c = getchar();

        } while ( c != EOF && c != '\n' );
    }
    return i;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	char moves[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' , ' '};
	char initialMoves[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char started[10] = " ";
	int playing = 0;
	char player = 'X';
	
	//before play
	while(strcmp(started, " ") == 0){
	system("cls");
	printf("Bem vindo ao meu Jogo da Velha\n");
	printf("Estas são as possíveis posições do jogo:\n");
	printStuff(initialMoves);
	printf("Digite algo para começar");
	scanf("%s", &started);
	}
	
	//start play
	system("cls");
	playing = 1;
	while(playing == 1){
		int currentMove = 0;
		system("cls");
		if(hasWon(moves) == 1){
			playing = 0;
			
		}
		else{
		printf("Posições do jogo:\n");
		printStuff(initialMoves);
		printf("\n");
		printf("Jogador: %c\n\n", player);
		printStuff(moves);
		printf("\n");
		printf("Onde você quer jogar?\n");
   		currentMove = scanInt();
		
		if(currentMove > 0 && currentMove <= 9){
			
		
		if(moves[currentMove - 1] == ' '){
		moves[currentMove - 1] = player;
	
		
		player = invertPlayer(player);
	
		
	}
}
}
	printf("O ganhador é: %c", invertPlayer(player));
	
	
	
		
	}
	return 0;
}

