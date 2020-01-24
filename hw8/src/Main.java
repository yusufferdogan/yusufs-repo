
public class Main {
    public static void TestSetI()
    {
        Integer [] a = {1,2,-2,8,78,96,54,145,985,7563,-142,1478,3210};
        GtuSet<Integer> arr = new GtuSet<>(a);
        arr.Print();
        System.out.println("THE MAX SİZE İS : " + arr.max_size());
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
        arr.insert(11);
        arr.insert(12);
        arr.Print();
        System.out.println();
        arr.erase(1);
        arr.erase(11);
        arr.erase(13);
        arr.erase(-2);
        arr.Print();
        System.out.println();
        arr.clear();
        arr.Print();
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
    }
    public static void TestSetD()
    {
        Double [] a = {1.0, 2.2, 78.41, 96.00, 54.0, 145.01, 985.002, 7563.541 ,-142.0, 1478.0, 3210.0};
        GtuSet<Double> arr = new GtuSet<>(a);
        arr.Print();
        System.out.println("THE MAX SİZE İS : " + arr.max_size());
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
        arr.insert(11.20);
        //arr.insert(11.20); if you open that block you will get an exception
        arr.insert(12.1);
        arr.insert(13.41);
        arr.insert(14.789);
        arr.insert(15.951);
        arr.Print();
        System.out.println();
        arr.erase(1.0);
        arr.erase(985.002);
        arr.erase(1478.0);
        arr.erase(11.2);
        arr.Print();
        System.out.println();
        arr.clear();
        arr.Print();
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());

    }
    public static void TestvectorI()
    {
        Integer [] a = {1,2,-2,8,78,96,54,145,985,7563,-142,1478,3210};
        GTUVector<Integer> arr = new GTUVector<>(a);
        arr.Print();
        System.out.println("THE MAX SİZE İS : " + arr.max_size());
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
        arr.insert(11);
        arr.insert(11);
        arr.insert(12);
        arr.Print();
        System.out.println();
        arr.erase(1);
        arr.erase(11);
        arr.erase(13);
        arr.erase(-2);
        arr.Print();
        System.out.println();
        arr.clear();
        arr.Print();
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
    }
    public static void TestVectorD(){
        Double [] a = {1.0, 2.2, 78.41, 96.00, 54.0, 145.01, 985.002, 7563.541 ,-142.0, 1478.0, 3210.0};
        GtuSet<Double> arr = new GtuSet<>(a);
        arr.Print();
        System.out.println("THE MAX SİZE İS : " + arr.max_size());
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());
        arr.insert(11.20);
        arr.insert(12.1);
        arr.insert(13.41);
        arr.insert(14.789);
        arr.insert(15.951);
        arr.Print();
        System.out.println();
        arr.erase(1.0);
        arr.erase(985.002);
        arr.erase(1478.0);
        arr.erase(11.2);
        arr.Print();
        System.out.println();
        arr.clear();
        arr.Print();
        System.out.println("İS ARRAY EMPTY ? :" + arr.empty());

    }
    public static void main(String [] args)
    {
        TestSetI();
        System.out.println("----------------------------------------------------\n\n");
        System.out.println("----------------------------------------------------\n\n");
        TestSetD();
        System.out.println("----------------------------------------------------\n\n");
        System.out.println("----------------------------------------------------\n\n");
        System.out.println("----------------------------------------------------\n\n");
        System.out.println("----------------------------------------------------\n\n");
        TestvectorI();
        System.out.println("----------------------------------------------------\n\n");
        System.out.println("----------------------------------------------------\n\n");
        TestVectorD();
    }
}
