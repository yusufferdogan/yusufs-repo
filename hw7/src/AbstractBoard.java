import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;
/**
 *@author Ahmet yusuf erdogan
 *@version 1.0
 *@since 17.01.2020
 *İD : 1804042654
 */
public abstract class AbstractBoard {
    /**
     * @param width stores the width of the board
     * @param height stores the width of the board
     * @param coord_x stores the x coordinate  of the board
     * @param coord_y stores the y coordinate of the board
     * @param numberofboards stores the count of board
     * @param numberofmoves stores the count of moves
     * @param Move stores the move of the next step as the L,R,D,U
     * @Param Numberofobj stores the number of objecects that created so far
     */
    protected
    int  width;
    int  height;
    int  coord_x;
    int  coord_y;
    static int  numberofboards;
    static int  numberofmoves;
    char Move;

    public int getWidth() {
        return width;
    }
    /**
     * getWidth
     * @return width
     */
    public int getHeight() {
        return height;
    }

    public int getCoord_x() {
        return coord_x;
    }

    public int getCoord_y() {
        return coord_y;
    }

    public static int getNumberofboards() {
        return numberofboards;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public void setCoord_x(int coord_x) {
        this.coord_x = coord_x;
    }

    public void setCoord_y(int coord_y) {
        this.coord_y = coord_y;
    }

    public void setMove(char move) {
        Move = move;
    }

    public char getMove() {
        return Move;
    }

    public

    abstract void readFromFile(String filename) ;
    abstract void reset();
    abstract void move();
    abstract void setboard();
    abstract int cell(int y,int x);

    void setsize()
    {
        /**
         * sets
         * @param width
         * and
         * @param height
         */
        Scanner in = new Scanner(System.in);
        System.out.println("Enter width\n");
        width = in.nextInt();
        System.out.println("Enter height\n");
        height = in.nextInt();
    }

    public boolean writeToFile(String filename) {
        /**
         * @returns does board saved to file properly or not
         */
        File file = new File(filename);
        FileWriter fr = null;
        try {
            fr = new FileWriter(file);
            for (int i = 0; i < getHeight(); i++) {
                for (int j = 0; j < getWidth(); j++) {
                    if (cell(i,j) == -1)//blank
                    {
                        fr.write("bb");
                        fr.write(" ");
                    } else if (cell(i,j) < 10) {
                        fr.write("0");
                        fr.write(Integer.toString(cell(i,j)));
                        fr.write(" ");
                    } else if (cell(i,j) >= 10) {
                        fr.write(Integer.toString(cell(i,j)));
                        fr.write(" ");
                    }
                }
                fr.write("\n");
            }
            return true;
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        } finally {
            //close resources
            try {
                fr.close();
                System.out.println("Board configuration is saved to :"+filename);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public void FindCoord() {
        /**
         * @returns nothing but finds the blank's coordinates of board
         */
        for(int i = 0;i < getHeight() ;i++)
        {
            for(int j = 0;j < getWidth() ;j++)
            {
                if(cell(i,j) == -1)
                {
                    //System.out.print(i+" " +j);
                    setCoord_x(j);
                    setCoord_y(i);
                    return;
                }
            }
        }
    }
    public static boolean isNumeric(String strNum) {
        /**
         * @returns bool is string is numeric or not
         */
        if (strNum == null)
        {
            return false;
        }
        try {
            int d = Integer.parseInt(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
    public boolean Equals(AbstractBoard other) {
        for(int i = 0;i < getHeight() ;i++)
        {
            for(int j = 0;j < getWidth() ;j++)
            {
                if (other.cell(i,j) != this.cell(i,j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     *
     * @return board is in solution or not
     */

    public boolean isSolved()
    {
        int goal[][] = new int[9][9];
        int k = 1;
        int count = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (cell(i,j) == 0 || cell(i,j) == -1) {
                    goal[i][j] = cell(i,j);
                }
                else {
                    goal[i][j] = k++;;
                }
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (goal[i][j] == cell(i,j))   {
                    count++ ;
                }
            }
        }
        if (count == width*height) {
            return true;
        }
        else {
            return false;
        }
    }
}
