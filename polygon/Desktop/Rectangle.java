public class Rectangle extends Polygon {
    private double side1;
    private double side2;

    public Rectangle(int i, int i1, double v, double v1) {
        setCoord_x(i);
        setCoord_y(i1);
        setSide1(v);
        setSide2(v1);
    }

    @Override
    protected void CalculateArea() {
        Area = side1*side2;
    }

    public void setSide1(double side1) {
        this.side1 = side1;
    }

    public void setSide2(double side2) {
        this.side2 = side2;
    }
}
