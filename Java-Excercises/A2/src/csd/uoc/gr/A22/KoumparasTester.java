package csd.uoc.gr.A22;

import csd.uoc.gr.A22.Exceptions.KoumparasIsBrokenException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsFullException;
import csd.uoc.gr.A22.Exceptions.KoumparasIsNotBroken;

public class KoumparasTester {
    public static void main(String[] args) throws KoumparasIsBrokenException, KoumparasIsFullException {
        Koumparas koump = new Koumparas();
        try {
            koump.add(new Money(2));
            koump.add(new Money(4));
            koump.isFull();
            koump.isBroken();
            koump.Break();


        } catch (KoumparasIsFullException e) {
            throw new RuntimeException(e);
        } catch (KoumparasIsBrokenException e) {
            throw new RuntimeException(e);
        } catch (KoumparasIsNotBroken e) {
            throw new RuntimeException(e);
        }


    }
}

