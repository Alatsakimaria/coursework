package a21;

import javax.swing.*;

public class a21 {
    public static void main(String[] aa){
        JFrame frame = new JFrame();
        JButton button1 = new JButton("Click me!");
        button1.addActionListener(e -> {
            System.out.println("Hello Java 8!");
            new Thread(()-> {
                System.out.println("Τρέχω παράλληλα");
                main(null);
            }).start();
        });
        frame.add(button1);
        frame.setSize(200,200);
        frame.setVisible(true);
    }
}
