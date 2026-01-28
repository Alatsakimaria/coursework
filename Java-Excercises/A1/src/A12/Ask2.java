package A12;

import java.util.Arrays;
import java.util.Scanner;
import java.text.Normalizer;

public class Ask2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String s = str.toLowerCase();
        System.out.println(s.toLowerCase());
        s = Normalizer.normalize(s, Normalizer.Form.NFD);
        s = s.replaceAll("\\p{InCombiningDiacriticalMarks}", "");
        System.out.println(s);

        if (isPalindromikiFrash(s)) {
            System.out.println("H frash einai palindromiki");
        } else {
            System.out.println("H Frash den einai palindromiki");
        }
        long time = System.nanoTime();
        System.out.println(time);


    }

    public static boolean isPalindromikiFrash(String s) {
        char[] sA = new char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            sA[i] = s.charAt(i);
        }
        char[] sReverse = new char[s.length()];
        for (int j = 0; j < s.length(); j++) {
            sReverse[j] = sA[s.length() - j -1];
        }
        if (Arrays.equals(sA, sReverse)) {
            return true;
        } else {
            return false;
        }
    }

}