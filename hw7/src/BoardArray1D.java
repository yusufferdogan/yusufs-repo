import java.io.*;
import java.util.Random;
import java.util.Scanner;
import java.lang.String;
/**
 * @author AHMET YUSUF ERDOĞAN ON 12/01/2020
 * @version 1.0
 * @since 2020-01-17
 * İD : 1804042654
 */

public class BoardArray1D extends AbstractBoard
{
    private
    int [] Array1D;

    public BoardArray1D(String filename)
    {
        /**
         * reads from the file and saves it to array by 1 dimensional configuration
         */
        Scanner in = new Scanner(System.in);
        //System.out.println("do you wanna fill the Board from file ? (y/n)\n");
        //char c = in.next().charAt(0);
        char c = 'y';
        if (c == 'y')
        {
            readFromFile(filename);
        }
        else if (c == 'n')
        {
            System.out.println("Enter the height and width for BoardArray1D\n");
            setsize();
            Array1D = new int[getHeight()*getWidth()];
            setboard();
            // print();
        }
        numberofboards++;
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
     *
     * @param filename is the name of the file
     *                 reads from file and save numbers to the board
     */
    @Override
    public void readFromFile(String filename)
    {
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
            Array1D = new int[getHeight()*getWidth()];
            for (int count = 0; count < getWidth()*getHeight() ; count++) {
                Array1D[count] = temp[count];
            }

        }
        catch (IOException e)
        {
            System.out.println("File not found");
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
                Array1D[i * height + j] = (i * height) + j + 1;
            }
        }
    }

    /**
     * takes
     * @param arr array
     * @param x first index
     * @param y second index
     */
    public static void swap(int[] arr,int x,int y){
        int temp =  arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
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
                if (coord_y -1 >= 0 && Array1D[(coord_y-1)*height+coord_x+1] != 0)
                {
                    swap(Array1D,coord_y*height+coord_x,(coord_y-1)*height+coord_x);
                    coord_y -= 1;
                }
                break;
            case 'd':
            case 'D':
                //down
                if(coord_y+1 < height && (Array1D[(coord_y+1)*height+coord_x+1])!= 0)
                {
                    swap(Array1D,coord_y*height+coord_x,(coord_y+1)*height+coord_x);
                    coord_y += 1;
                }
                break;
            case 'l':
            case 'L':
                if(coord_x -1 >= 0 && Array1D[coord_y*height+coord_x] != 0)
                {
                    swap(Array1D,coord_y*height+coord_x-1,coord_y*height+coord_x);
                    coord_x -= 1;
                }
                break;
            case 'R':
            case 'r':
                if(coord_x+1 < width && Array1D[coord_y*height+coord_x+2] != 0)
                {
                    swap(Array1D,coord_y*height+coord_x,coord_y*height+coord_x+1);
                    coord_x += 1;
                }
                break;
        }
        numberofmoves++;
    }

    /**
     *
     * @param y y coordinate
     * @param x x coordinate
     * @return element at this index
     */
    @Override
    public int cell(int y,int x) {
        return this.Array1D[y*height+x];
    }

    /**
     * set the board randomly
     */

    @Override
    public void setboard() {
        for(int i = 0;i < getHeight() ;i++)
        {
            for(int j = 0;j < getWidth() ;j++)
            {
                Random rand = new Random();
                Array1D[i*height+j]= rand.nextInt(width*height);
            }
        }

    }
}
