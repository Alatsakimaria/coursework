package csd.uoc.gr.A21;



public class Sphere extends SolidShape{
    private float radius;

    public Sphere(float x, float y, float z, float radius) {
        super(x, y, z);
        setRadius(radius);
        toString();
    }

    public float getRadius() {
        return this.radius;
    }

    public void setRadius(float radius) {
        this.radius = radius;
    }


    @Override
    public void setVolume(double volume) {
        super.setVolume(volume);
    }

    @Override
    public float getVolume() {
        return (float) (4/3 * Math.PI * Math.pow(radius,3));
    }

    @Override
    public int getNumberOfFaces() {
        return 1;
    }

    @Override
    public String toString() {
        return  "Sphere shape centered at (" + getX() + "," + getY() + "," + getZ() + ") with\n" + "faces: " + getNumberOfFaces()+ "\n" + "vertices: " + getNumberOfVertices()+ "\n" +"edges :" + getNumberOfEdges() +"\n" + "volume :" + getVolume() + "\n" + "radius :" + getRadius();
    }
}
