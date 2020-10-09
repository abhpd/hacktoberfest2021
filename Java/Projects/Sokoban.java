import java.io.*;
import java.io.PrintStream;
import java.io.UnsupportedEncodingException;

public class Sokoban {
  public static void main(String[] args) {
    Game game = new Game();

    Player player = new Player();

    try {
      game.start(player);
    } catch (Exception e) {
    }
  }
}

class Game {
  /*
   * 0 - wall - # | 1 - bg - . | 2 - player - P | 3 - block to push - X | 4 -
   * target - O
   */
  int[][] gameBoard;

  public void setGameBoard(int[][] tempBoard) {
    gameBoard = tempBoard;
  }

  public int[][] generateMap(int rows, int cols) {
    int[][] Map = new int[rows][cols];

    for (int i = 0; i < cols; i++) {
      Map[0][i] = 0;
    }

    for (int i = 1; i < rows - 1; i++) {
      Map[i][0] = 0;
      Map[i][cols - 1] = 0;
      for (int j = 1; j < cols - 1; j++) {
        Map[i][j] = 1;
      }
    }

    for (int i = 0; i < cols; i++) {
      Map[rows - 1][i] = 0;
    }

    for (int i = 0; i < 1; i++) {
      int PosRow = (int) (Math.random() * ((cols - 1) - 1) + 1);
      int PosCol = (int) (Math.random() * ((rows - 1) - 1) + 1);

      if (Map[PosRow][PosCol] == 1) {
        Map[PosRow][PosCol] = 2;
        i++;
      }
    }

    for (int i = 0; i < 1; i++) {
      int PosRow = (int) (Math.random() * ((cols - 2) - 2) + 2);
      int PosCol = (int) (Math.random() * ((rows - 2) - 2) + 2);

      if (Map[PosRow][PosCol] == 1) {
        Map[PosRow][PosCol] = 3;
        i++;
      }
    }

    for (int i = 0; i < 1; i++) {
      int PosRow = (int) (Math.random() * ((cols - 1) - 1) + 1);
      int PosCol = (int) (Math.random() * ((rows - 1) - 1) + 1);

      if (Map[PosRow][PosCol] == 1) {
        Map[PosRow][PosCol] = 4;
        i++;
      }
    }

    for (int i = 0; i < 3; i++) {
      int PosRow = (int) (Math.random() * ((cols - 1) - 1) + 1);
      int PosCol = (int) (Math.random() * ((rows - 1) - 1) + 1);

      if (Map[PosRow][PosCol] == 1) {
        Map[PosRow][PosCol] = 5;
        i++;
      }
    }

    return Map;
  }

  public String render(int[][] board) throws UnsupportedEncodingException {
    String rendered = "\n";

    for (int[] row : board) {
      for (int col : row) {
        if (col == 0) {
          rendered = rendered + " # ";
        } else if (col == 1) {
          rendered = rendered + " . ";
        } else if (col == 2) {
          rendered = rendered + " P ";
        } else if (col == 3) {
          rendered = rendered + " X ";
        } else if (col == 4) {
          rendered = rendered + " O ";
        } else if (col == 5) {
          rendered = rendered + " D ";
        }
      }
      rendered = rendered + "\n";
    }

    return rendered;
  }

  public void start(Player player) throws UnsupportedEncodingException {
    setGameBoard(generateMap(7, 7));

    Positions positions = new Positions();

    GameHelper helper = new GameHelper();

    for (int i = 0; i < gameBoard.length; i++) {
      for (int j = 0; j < gameBoard[i].length; j++) {
        if (gameBoard[i][j] == 2) {
          player.position[0] = i;
          player.position[1] = j;
        } else if (gameBoard[i][j] == 3) {
          positions.BlockPos[0] = i;
          positions.BlockPos[1] = j;
        } else if (gameBoard[i][j] == 4) {
          positions.TargetPos[0] = i;
          positions.TargetPos[1] = j;
        } else if (gameBoard[i][j] == 5) {
          if (positions.DeathBlock[0][0] == 0 && positions.DeathBlock[0][1] == 0) {
            positions.DeathBlock[0][0] = i;
            positions.DeathBlock[0][1] = j;
          } else {
            positions.DeathBlock[1][0] = i;
            positions.DeathBlock[1][1] = j;
          }
        }
      }
    }

    String renderedBoardBegining = render(gameBoard);

    PrintStream out = new PrintStream(System.out, true, "UTF-8");
    out.println(renderedBoardBegining);

    while (player.isAlive) {
      String UserInput = helper.getUserInput("Type in: w, a, s, d or stop:");

      MoveDecesion(UserInput, player, positions);

      String renderedBoard = render(gameBoard);

      out.println(renderedBoard);

      if (positions.BlockPos[0] == positions.TargetPos[0] && positions.BlockPos[1] == positions.TargetPos[1]) {
        player.isAlive = false;
        System.out.println("You win!");
      } else {
        for (int[] position : positions.DeathBlock) {
          if (player.position[0] == position[0] && player.position[1] == position[1]) {
            System.out.println("You loose!");
            player.isAlive = false;
          }
        }
      }
    }
  }

  public void MoveDecesion(String direction, Player player, Positions positions) {
    int[] up = { -1, 0 };
    int[] down = { 1, 0 };
    int[] left = { 0, -1 };
    int[] right = { 0, 1 };

    if (direction.equals("stop")) {
      System.out.println("Stopped");
      player.isAlive = false;
    } else if (direction.equals("a")) {
      gameBoard = player.move(gameBoard, left, player, positions);
    } else if (direction.equals("s")) {
      gameBoard = player.move(gameBoard, down, player, positions);
    } else if (direction.equals("d")) {
      gameBoard = player.move(gameBoard, right, player, positions);
    } else if (direction.equals("w")) {
      gameBoard = player.move(gameBoard, up, player, positions);
    }
  }
}

class Player {
  boolean isAlive = true;
  int[] position = { 0, 0 };

  public int[][] move(int[][] board, int[] direction, Player player, Positions positions) {
    int[] position = player.position;

    board[position[0]][position[1]] = 1;

    position[0] = position[0] + direction[0];
    position[1] = position[1] + direction[1];

    if (board[position[0]][position[1]] == 0) {
      position[0] = position[0] - direction[0];
      position[1] = position[1] - direction[1];
    } else if (board[position[0]][position[1]] == 3) {
      positions.BlockPos[0] = positions.BlockPos[0] + direction[0];
      positions.BlockPos[1] = positions.BlockPos[1] + direction[1];

      if (board[positions.BlockPos[0]][positions.BlockPos[1]] == 0) {
        position[0] = position[0] - direction[0];
        position[1] = position[1] - direction[1];

        positions.BlockPos[0] = positions.BlockPos[0] - direction[0];
        positions.BlockPos[1] = positions.BlockPos[1] - direction[1];
      }

      board[positions.BlockPos[0]][positions.BlockPos[1]] = 3;
    } else if (board[position[0]][position[1]] == 4) {
      position[0] = position[0] - direction[0];
      position[1] = position[1] - direction[1];
    }

    board[position[0]][position[1]] = 2;

    return board;
  }
}

class Positions {
  int[] BlockPos = { 0, 0 };
  int[] TargetPos = { 0, 0 };
  int[][] DeathBlock = { { 0, 0 }, { 0, 0 } };
}

class GameHelper {
  public String getUserInput(String prompt) {
    String inputLine = null;
    System.out.print(prompt + " ");
    try {
      BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
      inputLine = is.readLine();
      if (inputLine.length() == 0) {
        return null;
      }
    } catch (IOException e) {
      System.out.println("IOException: " + e);
    }
    return inputLine.toLowerCase();
  }
}