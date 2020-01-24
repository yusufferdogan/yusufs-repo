public class Main {
    public static boolean GlobalFunc(AbstractBoard[] pBoard) {
        /**
         * @author Ahmet yusuf erdogan
         * @version 1.0
         * @since 17.01.2020
         * Global function that takes board references as a parameter
         * @param pboard is an array of Abstract board object references
         * @returns boolean value which these boards are sequantial or not
         */
        // int this function i tried to compare the board and if they are sequance of each other
        // it returns true .You can see it in the test files
        int x, x1, y, y1;
        boolean flag = true;
        for (int i = 0; i < pBoard.length - 1 ; i++)
        // compare until the last board
        {
            try{
                // finding coodinates
                pBoard[i].FindCoord();
                // taking coodinates
                x = pBoard[i].getCoord_x();
                y = pBoard[i].getCoord_y();

                // i am gonna compare this two boards
                pBoard[i + 1].FindCoord();
                x1 = pBoard[i + 1].getCoord_x();
                y1 = pBoard[i + 1].getCoord_y();
                // checking coodinates
                if ((x == x1 && y == y + 1) || (x == x1 && y == y - 1) ||
                        (x == x1 - 1 && y == y1) || (x == x1 + 1 && y == y1)) {
                    flag = true;
                } else
                    flag = false;
            }
            catch (NullPointerException e){
                System.out.println("NullPointerException");
            }
        }
        if (!pBoard[pBoard.length-1].isSolved())
        {
            flag = false;
        }
        return flag;
    }
    public static void main(String[] args){
        AbstractBoard x[] = new AbstractBoard[3];
         x[0] = new BoardArray1D("loadfile1");
         System.out.println("-----------------------------------------------------------------------------------------\n\n");
         System.out.println("the number of the board array objects is "+x[0].getNumberofboards());

         System.out.println(x[0].toString());
         x[0].setMove('d');
         System.out.println("the move is : "+x[0].getMove());
         x[0].FindCoord();
         System.out.println("the coordinates are x : "+ x[0].getCoord_x()+ " y: " + x[0].getCoord_y());
         x[0].move();
         System.out.println(x[0].toString());

         System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[0].toString());
        x[0].setMove('u');
        System.out.println("the move is : "+ x[0].getMove());
        x[0].FindCoord();
        System.out.println("the coordinates are x : "+ x[0].getCoord_x()+ " y: " + x[0].getCoord_y());
        x[0].move();
        System.out.println(x[0].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[0].toString());
        x[0].setMove('r');
        System.out.println("the move is : "+ x[0].getMove());
        x[0].FindCoord();
        System.out.println("the coordinates are x : "+ x[0].getCoord_x()+ " y: " + x[0].getCoord_y());
        x[0].move();
        System.out.println(x[0].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[0].toString());
        x[0].setMove('l');
        System.out.println("the move is : "+ x[0].getMove());
        x[0].FindCoord();
        System.out.println("the coordinates are x : "+ x[0].getCoord_x()+ " y: " + x[0].getCoord_y());
        x[0].move();
        System.out.println(x[0].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");
        System.out.println("-----------------------------------------------------------------------------------------\n\n");
        System.out.println("-----------------------------------------------------------------------------------------\n\n");
        System.out.println("-----------------------------------------------------------------------------------------\n\n");
        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        x[1] = new BoardArray2D("loadfile2");
        System.out.println("the number of the board array objects is "+x[1].getNumberofboards());

        System.out.println(x[1].toString());
        x[1].setMove('d');
        System.out.println("the move is : "+ x[0].getMove());
        x[1].FindCoord();
        System.out.println("the coordinates are x : "+ x[1].getCoord_x()+ " y: " + x[1].getCoord_y());
        x[1].move();
        System.out.println(x[1].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[1].toString());
        x[1].setMove('u');
        System.out.println("the move is : "+x[1].getMove());
        x[1].FindCoord();
        System.out.println(x[1].getCoord_x()+ " " + x[1].getCoord_y());
        x[1].move();
        System.out.println(x[1].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[1].toString());
        x[1].setMove('r');
        System.out.println("the move is : "+x[1].getMove());
        x[1].FindCoord();
        System.out.println("the coordinates are x : "+ x[1].getCoord_x()+ " y: " + x[1].getCoord_y());
        x[1].move();
        System.out.println(x[1].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[1].toString());
        x[1].setMove('l');
        System.out.println("the move is : "+x[1].getMove());
        x[1].FindCoord();
        System.out.println("the coordinates are x : "+ x[1].getCoord_x()+ " y: " + x[1].getCoord_y());
        x[1].move();
        System.out.println(x[1].toString());


        System.out.println("-----------------------------------------------------------------------------------------");
        System.out.println("-----------------------------------------------------------------------------------------");
        System.out.println("-----------------------------------------------------------------------------------------\n\n");
        x[2] = new BoardArray1D("loadfile3");
        System.out.println("the number of the board array objects is "+x[2].getNumberofboards());

        System.out.println(x[2].toString());
        x[2].setMove('d');
        System.out.println("the move is : "+ x[0].getMove());
        x[2].FindCoord();
        System.out.println("the coordinates are x : "+ x[2].getCoord_x()+ " y: " + x[2].getCoord_y());
        x[2].move();
        System.out.println(x[2].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[2].toString());
        x[2].setMove('u');
        System.out.println("the move is : "+x[2].getMove());
        x[2].FindCoord();
        System.out.println(x[2].getCoord_x()+ " " + x[2].getCoord_y());
        x[2].move();
        System.out.println(x[2].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[2].toString());
        x[2].setMove('r');
        System.out.println("the move is : "+x[2].getMove());
        x[2].FindCoord();
        System.out.println("the coordinates are x : "+ x[2].getCoord_x()+ " y: " + x[2].getCoord_y());
        x[2].move();
        System.out.println(x[2].toString());

        System.out.println("-----------------------------------------------------------------------------------------\n\n");

        System.out.println(x[2].toString());
        x[2].setMove('l');
        System.out.println("the move is : "+x[2].getMove());
        x[2].FindCoord();
        System.out.println("the coordinates are x : "+ x[2].getCoord_x()+ " y: " + x[2].getCoord_y());
        x[2].move();
        System.out.println(x[2].toString());

        x[0] = new BoardArray1D("loadfile1");
        x[1] = new BoardArray2D("loadfile2");
        x[2] = new BoardArray2D("loadfile3");

        x[0].writeToFile("savefile");
        x[1].writeToFile("savefile2");
        x[2].writeToFile("savefile3");

        if (x[0].Equals(x[1])){
            System.out.println("equals");
        }
        else {
            System.out.println("not equals");
        }

        if (GlobalFunc(x)){
            System.out.println("GlobalFunc returned true this means boards are sequential ");
        }
        else{
            System.out.println("GlobalFunc returned false this means boards are not sequential ");
        }


    }
}
