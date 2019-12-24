import static java.lang.Math.sqrt;

public class Triangle extends Polygon {
    private double side1;
    private double side2;
    private double side3;

    Triangle(int Coord_x ,int Coord_y,double side1,double side2, double side3){
        setSide1(side1);
        setSide2(side2);
        setSide3(side3);
        setCoord_x(Coord_x);
        setCoord_y(Coord_y);
    }
    Triangle(){}
    @Override
    public void CalculateArea(){
        double u = (side1+side2+side3)/2;
        Area = sqrt(u*(u-side1)*(u-side2)*(u-side3));
        //System.out.println("area is : " + Area);
    }

    public void setSide1(double side1) {
        this.side1 = side1;
    }

    public void setSide2(double side2) {
        this.side2 = side2;
    }

    public void setSide3(double side3) {
        this.side3 = side3;
    }

}
