public abstract class Polygon {

    protected int Coord_x;
    protected int Coord_y;
    protected double Area;

    protected abstract void CalculateArea();

    public void PrintCoordinates(){
        System.out.println("Coordinates are : " + Coord_x + Coord_y);
    }

    public void setCoord_x(int coord_x) {
        Coord_x = coord_x;
    }

    public void setCoord_y(int coord_y) {
        Coord_y = coord_y;
    }

    @Override
    public String toString() {
        return "Polygon{" +
                "Coord_x=" + Coord_x +
                ", Coord_y=" + Coord_y +
                ", Area=" + Area+
                '}';
    }
}
