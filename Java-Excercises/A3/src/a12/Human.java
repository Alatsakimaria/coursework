package a12;

interface LivingBeing{
    public void grow();
    public void reproduce();
    public void respondToEnvironment();
}
interface MaterialObject{
    public double getMass();
}


public class Human implements LivingBeing,MaterialObject {
    @Override
    public void grow() {

    }
    @Override
    public void reproduce() {

    }

    @Override
    public void respondToEnvironment() {

    }

    @Override
    public double getMass() {
        return 0;
    }
}
