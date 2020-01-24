
public class Phonedirectory {
    private String[][] arr;
    private int numberofperson = 0;

    public void add(String name,String number)
    {
        String[][] sum;
        if (!IsNameExist(name))
        {
            if (numberofperson == 0){
                sum = new String[numberofperson+1][2];
                sum[numberofperson][0] = name;
                sum[numberofperson][1] = number;
            }
            else{
                sum = new String[numberofperson+1][2];
                for (int i = 0;i < numberofperson ; i++){
                    for (int j = 0;j < 2; j++){
                        sum[i][j] = arr[i][j];
                    }
                }
                sum[numberofperson][0] = name;
                sum[numberofperson][1] = number;
            }
            arr = sum;
            numberofperson++;
        }
        else {
            System.out.println("name : " + name + " already exist");
        }
    }

    public void Print()
    {
        System.out.println("numberofperson : " + numberofperson);
        System.out.println("----------------------------------------");
        for (int i = 0;i < numberofperson ; i++){
            for (int j = 0;j < arr[i].length; j++){
                System.out.println(arr[i][j]);
            }
            System.out.println("----------------------------------------");
        }

    }
    public String SearchWithName(String name)
    {
        for (int i = 0; i < numberofperson ; i++)
        {
            if (name.equals(arr[i][0]))
            {
                return arr[i][1];
            }
        }
        return "name does not exist";
    }
    public String SearchWithNumber(String number)
    {
        for (int i = 0; i < numberofperson ; i++)
        {
            if (number.equals(arr[i][1]))
            {
                return arr[i][0];
            }
        }
        return "number does not exist";
    }
    public boolean IsNameExist(String name)
    {
        for (int i = 0; i < numberofperson ; i++)
        {
            if (name.equals(arr[i][0]))
            {
                return true;
            }
        }
        return false;
    }
    public int Index(String name){
        for (int i = 0; i < numberofperson ; i++)
        {
            if (name.equals(arr[i][0])){
                return i;
            }
        }
        return -1;
    }
    public void AddNumberToName(String name,String number)
    {
        if (IsNameExist(name))
        {
            int index = Index(name);
            int howManyNumber = arr[index].length;
            String temp[] = new String[howManyNumber+1];
            int i = 0;
            for (String x : arr[index])
            {
                temp[i] = x;
                i++;
            }
            temp[howManyNumber] = number;
            arr[index] = temp;
        }
        else {
            System.out.println("name does not exist");
        }

    }
    public void Concat(Phonedirectory pd2)
    {
        Phonedirectory sum = new Phonedirectory();
        sum.arr = new String[arr.length+pd2.arr.length][];
        for (int i = 0; i < arr.length ; i++){
            sum.arr[i] = new String[arr[i].length];
            sum.arr[i] = arr[i];
        }
        for (int x = arr.length, j = 0; x < arr.length+pd2.arr.length ; x++)
        {
            //for (int j = 0; j < pd2.arr.length ; j++){
                sum.arr[x] = pd2.arr[j++]; //new String[pd2.arr[j].length];
               // sum.arr[x] = ;


            numberofperson++;
        }
        arr = null;
        arr = sum.arr;
    }
}
