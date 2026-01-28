package a22;

import java.util.ArrayList;

class a22 {
    public static void main(String[] args) {
        ArrayList<Double> items = new ArrayList<>();
        for (int i = 0; i < 30; i++){
            items.add(i*i/3.3);
        }
        double max = items.stream().max(Double::compareTo).orElse(Double.NEGATIVE_INFINITY);
        double min = items.stream().min(Double::compareTo).orElse(Double.POSITIVE_INFINITY);
        double sum = items.stream().mapToDouble(Double::doubleValue).sum();
        double avg = sum / items.size();
        System.out.println("Minimum = " + min);
        System.out.println("Maximum = " + max);
        System.out.println("Average = " + sum/(double)items.size());
    }
}
