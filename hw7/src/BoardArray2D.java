import java.io.File;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 * @author AHMET YUSUF ERDOĞAN ON 12/01/2020
 * @version 1.0
 * @since 2020-01-17
 * İD : 1804042654
 */

public class BoardArray2D extends AbstractBoard {
    private int[][] Array2D;

    public BoardArray2D(String filename)
    {
        Scanner in = new Scanner(System.in);
        char c = 'y';
        if (c == 'y')
        {
            readFromFile(filename);
        }
        else if (c == 'n')
        {
            System.out.println("Enter the height and width for BoardArray1D\n");
            setsize();
            Array2D = new int[getHeight()][getWidth()];
            setboard();
        }
        numberofboards++;
    }

    @Override
    public void readFromFile(String filename)
    {
        /**
         * reads from the file and saves it to array by 2 dimensional configuration
         */
        int[] temp = new int[81];
        try {
            File text = new File(filename);
            Scanner scnr = new Scanner(text);

            int lineNumber = 0;
            int x = 0;
            String[] line =  new String[10];
            while (scnr.hasNextLine())
            {
                line[lineNumber] = scnr.nextLine();
                String[] words = line[lineNumber].split("\\s");
                for (String word:words){
                    if (!isNumeric(word))
                        temp[x] = -1;
                    else{
                        int result = Integer.parseInt(word);
                        if (result != 0) {
                            temp[x] = result;
                        }
                    }
                    x++;
                }
                lineNumber++;
            }
            setHeight(lineNumber);
            setWidth(x / height);
            Array2D = new int[getHeight()][getWidth()];
            for(int i = 0; i < getHeight() ;i++)
            {
                for(int j = 0;j < getWidth() ;j++)
                {
                    Array2D[i][j] = temp[i*getHeight()+j];
                }
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    /**
     * reset the board
     */

    @Override
    public void reset() {
        for(int i = 0; i < getHeight() ;i++)
        {
            for(int j = 0;j < getWidth() ;j++)
            {
                Array2D[i][j] = (i * height) + j + 1;
            }
        }
    }

    /**
     *
     * @param arr array
     * @param y1 first number's y coordinate
     * @param x1 first number's x coordinate
     * @param y2 second number's y coordinate
     * @param x2 second number's y coordinate
     */
    public static void swap(int[][] arr,int y1,int x1,int y2,int x2){
        int temp =  arr[x1][y1];
        arr[x1][y1] = arr[x2][y2];
        arr[x2][y2] = temp;
    }

    /**
     * move the blank
     */

    @Override
    public void move() {
        FindCoord();
        switch (Move){
            case 'u':
            case 'U':
                //up
                if (coord_y -1 >= 0 && Array2D[coord_y-1][coord_x] != 0)
                {
                    swap(Array2D,coord_x,coord_y,coord_x,coord_y-1);
                    coord_y -= 1;
                }
                break;
            case 'd':
            case 'D':
                //down
                if(coord_y+1 < height && Array2D[coord_y+1][coord_x] != 0)
                {
                    swap(Array2D,coord_x,coord_y,coord_x,coord_y+1);
                    coord_y += 1;
                }
                break;
            case 'l':
            case 'L':
                if(coord_x -1 >= 0 && Array2D[coord_y][coord_x-1] != 0)
                {
                    swap(Array2D,coord_x,coord_y,coord_x-1,coord_y);
                    coord_x -= 1;
                }
                break;
            case 'R':
            case 'r':
                if(coord_x+1 < width && Array2D[coord_y][coord_x+1] != 0)
                {
                    swap(Array2D,coord_x,coord_y,coord_x+1,coord_y);
                    coord_x += 1;
                }
                break;
        }
        numberofmoves++;
    }

    @Override
    public String toString() {
        String str = "Array is \n\n";
        System.out.println();
        for(int i = 0;i < height ;i++){
            for(int j = 0;j < width ;j++){
                if(cell(i,j) == -1){//blank
                    str += "| bb";
                }
                else {
                    if (cell(i,j)< 10)
                    {
                        str += "| 0";
                        str += Integer.toString(cell(i,j));
                    }
                    else{
                        str += "| ";
                        str += Integer.toString(cell(i,j));
                    }
                }
                if(j == getWidth()-1){
                    str += "|";
                    str += "\n";
                }
            }
        }
        return str;
    }

    /**
     * sets the board randomly
     */
    @Override
    public void setboard() {
        for(int i = 0;i < getHeight() ;i++)
        {
            for(int j = 0;j < getWidth() ;j++)
            {
                Random rand = new Random();
                Array2D[i][j]= rand.nextInt(width*height);
            }
        }

    }

    @Override
    int cell(int y, int x) {
        return Array2D[y][x];
    }
}
