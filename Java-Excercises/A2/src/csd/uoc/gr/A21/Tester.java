package csd.uoc.gr.A21;

public class Tester {
    public static void main(String[] args){
        System.out.println(new SolidShape(2, 1, (float) 5.12));
        System.out.println(new Sphere(2, 1, (float) 5.12,10));
        System.out.println(new Cube(2,1,(float)5.12,4));
        System.out.println(new Cylinder(2,1,(float)5.12,4,10));
        Drawing t = new Drawing();
        t.add(new Sphere(1,3,4,6));
        t.add(new Cube(3,6,7,8));
        t.add(new Cylinder(4,5,7,1,5));
        System.out.println(t.toString());

        Drawing t1= new Drawing();
        for(int j=0; j<50; j++) {
            t1.add(new Sphere(2, 3, (float) 5.12, j));
        }
        System.out.println("\n(c-i):\n" + t1.toString());

        Drawing t2 = new Drawing();
        for(int i=0; i<50; i++){
            if(i % 2 == 0){
                t2.add((new Sphere(2,3,(float) 5.4,10)));
            }else{
                t2.add((new Cube(1,2,3,i)));
            }
        }
        System.out.println("\n(c-ii):\n" + t2.toString());
    }
}
