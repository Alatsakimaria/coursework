package csd.uoc.gr.A21;

public class Drawing extends SolidShape{
    int totalF=0;
    int totalV=0;
    int totalE=0;
    double totalVol=0.0;
    int activeCapacity =0;
    public Drawing(float x, float y, float z) {
        super(x, y, z);
    }
    public Drawing(){}

    public void add(SolidShape s){
        if (activeCapacity <999){
            activeCapacity = activeCapacity  +1;
            totalF=totalF+ s.getNumberOfFaces();
            totalV = totalV + s.getNumberOfVertices();
            totalE = totalE + s.getNumberOfEdges();
            totalVol = totalVol + s.getVolume();


        }
    }

    @Override
    public String toString() {
        return "Number of shapes: " + activeCapacity +"\n" + "Total faces: " + totalF + " \n" + "Total vertices: " + totalV + "\n" + "Total edges: " +totalE  +"\n" + "Total volume: " +totalVol + "\n";
    }
}
