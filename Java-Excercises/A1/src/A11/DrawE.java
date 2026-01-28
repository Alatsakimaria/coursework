package A11;


import javax.swing.JOptionPane; import javax.swing.UIManager;
import java.awt.geom.CubicCurve2D;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.io.PrintWriter;
import java.util.Scanner;

 public class DrawE{

    public  static void main(String[] args ){
        char M = args[0].charAt(0);
        int L = Integer.parseInt(args[1]);

        if(args.length != 2){
            System.out.println("wrong number of arguments");
            System.exit(56);
        }

        if(L <= 5 || L>= 20){
            System.out.println("Invalid number");
            System.exit(4);
        }


        if(M == 'c'){
            consoleOutput(L);
        } else if (M == 'w'){
            windowOutput(L);
        } else if(M == 'f'){
            outputHTML(L);
        } else if(M == 'g'){
            GraphicE(L);
        } else {
            System.out.println("Error please try again");
            System.exit(4);
        }
    }
    static String stringF(int L) {
        StringBuilder f = new StringBuilder();
        //top line
        for (int j = 0; j < L; j++) {
            f.append("*");
        }
        f.append("\n");
        for (int i = 1; i < L; i++) {
            if (i == L / 2) {
                for (int j = 0; j < L / 2 + 1; j++) {
                    f.append("*");
                }
                f.append("\n");
            } else {
                f.append("*\n");
            }
        }
        for(int j=0; j < L; j++){
            f.append("*");

        }
        return f.toString();
    }
    public static void consoleOutput(int L){
        System.out.println(stringF(L));
    }
    public static void windowOutput(int L) {
        JOptionPane.showMessageDialog(null, stringF(L) , "Output", JOptionPane.INFORMATION_MESSAGE);
    }


    public static void outputHTML(int L) {
        PrintWriter writer;
        try {
            writer = new PrintWriter(System.getProperty("user.dir")+"\\src\\A11\\E.html", "UTF-8");
            writer.println("<!DOCTYPE html>\n" +
                    "<html>\n" +
                    "<head>\n" +
                    "<meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\"/>\n" +
                    "</head>\n" +
                    "<body><font size=\""+ L +"\">E with font size = " + L + "</font></body>\n" +
                    "</html>\n");
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: "+e);
        }

    }

    public static void GraphicE(int i) {
        Frame f = new Frame("Ζωγραφίζοντας το E") {
            public void paint(Graphics g) {
                Graphics2D g2 = (Graphics2D) g;
                CubicCurve2D a = new CubicCurve2D.Double();
                a.setCurve(10, 30, 100,
                        100, 30, 30, 30 * i, 30); //middle line
                g2.draw(new Line2D.Double(10, 30, 10, 30 * i));  //vertical line
                CubicCurve2D c = new CubicCurve2D.Double();
                c.setCurve(10, 15 * i, 100,
                        200, 30, 10, 30 * i, 15 * i); //middle line
                CubicCurve2D p = new CubicCurve2D.Double();
                p.setCurve(10, 30 * i, 100,
                        300, 30, 5, 30 * i, 30 * i); //middle line
                g2.draw(c);
                g2.draw(a);
                g2.draw(p);
            }
        };
        f.setSize(400, 400);
        f.setVisible(true);
    }
    public static int newL(char M){
        int input;
        if (!(M =='w')){
            System.out.println("Give a new value to L");
            Scanner in = new Scanner(System.in);
            input = in.nextInt();
        }else{
            input = Integer.parseInt(JOptionPane.showInputDialog("Give a new value to L",4));
        }
        return input;
    }
}


