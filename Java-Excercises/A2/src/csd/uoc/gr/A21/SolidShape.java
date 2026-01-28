package csd.uoc.gr.A21;

public class SolidShape {
    private float x,y,z;
    private int faces,vertices,edges;
    private float volume;

    public SolidShape() {
    }

    public float getX() {
        return this.x;
    }

    public float getY() {
        return this.y;
    }

    public float getZ() {
        return this.z;
    }

    public int getNumberOfFaces(){ return 0;}
    public int getNumberOfVertices(){
        return 0;
    }
    public int getNumberOfEdges(){
        return 0;
    }
    public float getVolume() {
        return 0.0F;
    }

    public void setFaces(int faces) {
        this.faces = faces;
    }

    public void setVertices(int vertices) {
        this.vertices = vertices;
    }

    public void setEdges(int edges) {
        this.edges = edges;
    }

    public void setVolume(double volume) {
        this.volume = (float) volume;
    }

    public void setX(float x) {
        this.x = x;
    }

    public void setY(float y) {
        this.y = y;
    }

    public void setZ(float z) {
        this.z = z;
    }


    public SolidShape(float x, float y, float z){
        setX(x);
        setY(y);
        setZ(z);
        setFaces(faces);
        setVertices(vertices);
        setEdges(edges);
        setVolume(volume);
        toString();
    }

    public String toString() {
        return "Solid shape centered at (" + getX() + "," + getY() + "," + getZ() + ") with\n" + "faces: " + getNumberOfFaces()+"\n" + "vertices: " + getNumberOfVertices() + "\n" + "edges: " + getNumberOfEdges() + "\n" + "volume :" + getVolume();
    }

}
