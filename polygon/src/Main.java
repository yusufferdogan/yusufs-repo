public class Main {
    public static void main(String[] args){
        Polygon[] Pbase;
        Pbase = new Polygon[2];
        Pbase[0] = new Rectangle(3,5,8.2,9.5);
        Pbase[0].CalculateArea();
        System.out.println(Pbase[0].toString());

        Pbase[1] = new Triangle(17,-23,4.2,5.3,7.6);
        Pbase[1].CalculateArea();
        System.out.println("\n"+ Pbase[1].toString());
    }
}
