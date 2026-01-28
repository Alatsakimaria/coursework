package csd.uoc.gr.A22;

import csd.uoc.gr.A22.Exceptions.KoumparasIsBrokenException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsFullException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsNotBroken;

public  class Koumparas extends KoumparasADT {
    public Koumparas(){

    }
    Money koumparas[] = new Money[100];
    int currentMoney = 0;
    boolean broken=false;

    double totalvalue=0;

    public void add(Money k) throws KoumparasIsFullException, KoumparasIsBrokenException {
        isFull();
        koumparas[currentMoney] = k;
        currentMoney = currentMoney +1;


    }
    public void isFull() throws KoumparasIsFullException {
        if (currentMoney > 99) {
            throw new KoumparasIsFullException();

        }
    }

    public void Break() {
        for(int i=0; i<currentMoney; i++){
            totalvalue =  totalvalue + koumparas[i].getValue();
        }
        broken = true;
        System.out.println(totalvalue);
        currentMoney = 0;
        totalvalue=0;
    }
    public void isBroken()throws KoumparasIsBrokenException, KoumparasIsNotBroken {
        if(broken){
            throw new KoumparasIsBrokenException();
        }else{
            throw new KoumparasIsNotBroken();
        }
    }

}
