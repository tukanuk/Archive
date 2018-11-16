package ca.uwindsor.david11n;

public class TicTacToe
{
    /*** Private instance Variables ***/

    private static final int R = 3;
    private static final int C = 3;

    private char[][] gameBoard = new char[R][C];

    private final char playerOne;
    private final char playerTwo;

    private boolean playerOneTurn = true;

    /*** Constructors ***/

    public TicTacToe()
    {
        playerOne = 'o';
        playerTwo = 'x';
    }

    /**
     * setupBoard: resets the board
     */
    public void setupBoard()
    {
        for (int r = 0 ; r < R ; ++r)
        {
            for (int c = 0 ; c < C ; ++c)
            {
                gameBoard[r][c] = ' ';
            }
        }
    }

    /**
     * whoTurn: who's turn is it
     */

    public char whoTurn()
    {
        if (playerOneTurn){
            return 'o';
        }
        else
            return 'x';
    }

    /**
     * takeTurn:
     * @param row which row the turn will be in
     * @param column which column the turn will be in
     * @param player 'o' or 'x'
     * @return 1 for valid move, 0 for invalid move
     */
    public void takeTurn(int row, int column, char player)
    {

        if ( row > R - 1 || row < 0 || column > C - 1 || column < 0 )
        {
            return;
        }

        if (gameBoard[row][column] == ' ')
        {
            gameBoard[row][column] = player;

            if (playerOneTurn)
            {
                playerOneTurn = false;
            }
            else
            {
                playerOneTurn = true;
            }

            return;
        }
        else
        {
            return;
        }
    }

    /**
     * drawBoard: draws the current state of the board
     */
    public void drawBoard()
    {
        for (int r = 0 ; r < R ; ++r)
        {
            System.out.printf(" %c | %c | %c", gameBoard[r][0], gameBoard[r][1], gameBoard[r][2]);

            if (r == 0 || r == 1)
            {
                System.out.print("\n-------------\n");
            }
        }
    }

    /**
     * determineWin:
     * @Return 'o' for playerOne wins, 'x' for playerTwo wins, 0 for no winner, 1 for tie game
     */
    public char determineWin()
    {
        // determines horizontal winner
        for (int r = 0 ; r < R ; ++r)
        {
            if (gameBoard[r][0] == gameBoard[r][1] && gameBoard[r][0] == gameBoard[r][2] && gameBoard[r][0] != ' ')
            {
                if (gameBoard[r][0] == 'o')
                {
                    return playerOne;
                }
                else
                {
                    return playerTwo;
                }
            }
        }

        // determine vertical winner
        for (int c = 0 ; c < C ; ++c)
        {
            if (gameBoard[0][c] == gameBoard[1][c] && gameBoard[0][c] == gameBoard[2][c] && gameBoard[0][c] != ' ')
            {
                if (gameBoard[0][c] == 'o')
                {
                    return playerOne;
                }
                else
                {
                    return playerTwo;
                }
            }
        }

        // determine diagonal winner
        if ( ((gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] ) ||
             (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0] ) )  && gameBoard[1][1] != ' ')
        {
            if (gameBoard[1][1] == 'o')
            {
                return playerOne;
            }
            else
            {
                return playerTwo;
            }
        }

        if ( gameBoard[0][0] != ' ' && gameBoard[0][1] != ' ' && gameBoard[0][2] != ' ' &&
             gameBoard[1][0] != ' ' && gameBoard[1][1] != ' ' && gameBoard[1][2] != ' ' &&
             gameBoard[2][0] != ' ' && gameBoard[2][1] != ' ' && gameBoard[2][2] != ' ')
        {
            return 1;
        }

        return 0;
    }
}
