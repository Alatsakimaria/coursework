package csd.uoc.gr.A21;

public class Cube extends SolidShape{
    private int side;
    public Cube(float x, float y, float z,int side) {
        super(x, y, z);
        setSide(side);
        toString();
    }
    public void setVolume(double volume) {
        super.setVolume(volume);
    }

    @Override
    public float getVolume() {
        return (float) Math.pow(side,3);
    }

    public int getSide() {
        return this.side;
    }

    public void setSide(int side) {
        this.side = side;
    }
    public int getNumberOfFaces() {
        return 6;
    }
    @Override
    public int getNumberOfVertices() {
        return 8;
    }
    @Override
    public int getNumberOfEdges() {
        return 12;
    }

    public String toString() {
        return "Cube shape centered at (" + getX() + "," + getY() + "," + getZ() + ") with\n" + "faces: " + getNumberOfFaces()+"\n" + "vertices: " + getNumberOfVertices()+ "\n" +"edges :" + getNumberOfEdges()+"\n" + "volume :" + getVolume()+"\n" + "radius : 0 "+"\n" + "side: "+ getSide();
    }

}
