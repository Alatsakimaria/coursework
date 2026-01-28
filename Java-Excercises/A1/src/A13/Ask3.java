package A13;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
import A12.Ask2;

public class Ask3 extends Ask2{
    public static void main(String[] args){
        try {
            long start = System.currentTimeMillis();

            FileInputStream fis=new FileInputStream("/Users/mariaalatsaki/Desktop/InteliJ_Template_A1/src/Resources/gr.dic");
            Scanner sc = new Scanner(fis);
            int count = 0;
            int sum= 0;
            int palindromikes = 0;
            int mo = 0;
            int pososto = 0;

            while (sc.hasNextLine()) {
                count = count + 1;
                String curLine = sc.nextLine();
                if(isPalindromikiFrash(curLine)){
                    palindromikes = palindromikes + 1;
                    System.out.println(curLine);
                }
                pososto = palindromikes / count;
            }

            System.out.println("To plithos ton leksewn einai: " + count);
            /*System.out.println("To meso megethos ton leksewn einai: " + mo);*/
            System.out.println("To plithos ton palindromikon leksewn einai: " + palindromikes);
            System.out.println("To pososto ton palindromikon leksewn einai:  " + pososto);
            sc.close();
            long end = System.currentTimeMillis();
            float sec = (end - start) / 1000F;
            System.out.println(sec + " seconds");

        } catch (IOException e) {
            System.out.println(e);
        }

    }

}