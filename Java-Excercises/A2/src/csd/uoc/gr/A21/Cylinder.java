package csd.uoc.gr.A21;

public class Cylinder extends SolidShape {
    private float radius;
    private double height;

    public Cylinder(float x, float y, float z,float radius,double height) {
        super(x, y, z);
        setHeight(height);
        setRadius(radius);
    }
    public float getRadius() {
        return this.radius;
    }
    public double getHeight() {
        return this.height;
    }
    public void setHeight(double height) {
        this.height = height;
    }
    public void setRadius(float radius) {
        this.radius = radius;
    }

    @Override
    public int getNumberOfFaces() {
        return 2;
    }

    @Override
    public int getNumberOfVertices() {
        return super.getNumberOfVertices();
    }

    @Override
    public int getNumberOfEdges() {
        return 2;
    }

    @Override
    public void setVolume(double volume) {
        super.setVolume(volume);
    }

    @Override
    public float getVolume() {
        return (float) (Math.PI*radius*height);
    }

    public String toString() {
        return "Cylinder shape centered at (" + getX() + "," + getY() + "," + getZ() + ") with\n" + "faces: " + getNumberOfFaces()+"\n" + "vertices: " + getNumberOfVertices()+"\n" +"edges :" + getNumberOfEdges()+"\n" + "volume :" + getVolume()+"\n" + "radius :" + getRadius()+"\n" + "height: " + getHeight();
    }
}
