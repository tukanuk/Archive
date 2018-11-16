package ca.uwindsor.david11n;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
	    // setup the game
        TicTacToe game = new TicTacToe();
        Scanner in = new Scanner(System.in);
        char winStatus;
        game.setupBoard();
        String move;
        String[] moveArray;
        int xMove = -1;
        int yMove = -1;

	    // Start the game
        System.out.println("Welcome to TicTacToe!");
        System.out.println("Turns are entered as y(0-2),x(0-2)");
        game.drawBoard();

        // TODO: document
        do {
            System.out.print("\nPlayer " + game.whoTurn() + "'s turn: ");
            in.useDelimiter("\\D"); // uses and non-digit character as a delimiter

            try
            {
                xMove = in.nextInt();
                yMove = in.nextInt();
            }
            catch (InputMismatchException e)
            {
                System.out.println("Invalid input. Turns are entered as x(0-2),y(0-2)");
                xMove = -1;
                yMove = -1;
            }

            game.takeTurn(xMove, yMove, game.whoTurn());
            game.drawBoard();
        } while (game.determineWin() == 0);

        winStatus = game.determineWin();

        if (winStatus == 'x' || winStatus == 'o')
        {
            System.out.println("\nPlayer " + winStatus + " has won the game!");
        }
        else if (winStatus == 1)
        {
            System.out.println("\nThe game has ended in a tie!");
        }

        in.close();

    }
}
