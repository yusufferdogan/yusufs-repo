public class Main {

    public static void main(String[] args){
        Phonedirectory pd = new Phonedirectory();

        pd.add("yusuf","1234");
        pd.add("sadsa","9197179");
        pd.add("erdoğan","2403");
        pd.AddNumberToName("yusuf", "4567");
        pd.Print();
        System.out.println("number of the given name is : "+ pd.SearchWithName("erdoğan"));
        System.out.println("name of the given number is : "+ pd.SearchWithNumber("1234"));

        System.out.println("-----------------------------------------\n\n\n\n\n");

        Phonedirectory village = new Phonedirectory();

        village.add("yusufdasdf","1234");
        village.add("sadsa","9197179");
        village.add("erdoğan","2403");
        village.AddNumberToName("yusuf", "4567");

        village.Print();
        System.out.println("number of the given name is : "+ village.SearchWithName("erdoğan"));
        System.out.println("name of the given number is : "+ village.SearchWithNumber("1234"));

        System.out.println("-----------------------------------------\n\n\n\n\n");
        pd.Concat(village);
        pd.Print();

    }

}
