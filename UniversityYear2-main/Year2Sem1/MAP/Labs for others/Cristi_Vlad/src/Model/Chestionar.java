package Model;

import java.util.List;

public class Chestionar {

    int id;
    int nrChestionar;
    int nrIntrebariGresite;
    int nrIntrebariCorecte;
    List<Intrebare> intrebarile;

    public Chestionar(int id,int nrChestionar, int nrIntrebariGresite,int nrIntrebariCorecte,List<Intrebare>intrebarile)
    {
        this.id = id;
        this.nrChestionar = nrChestionar;
        this.nrIntrebariGresite = nrIntrebariGresite;
        this.nrIntrebariCorecte = nrIntrebariCorecte;
        this.intrebarile = intrebarile;
    }

    public int getId()
    {
        return this.id;

    }
    public void setId(int value)
    {
        this.id = value;
    }
    public int getNrChestionar()
    {
        return this.nrChestionar;
    }
    public void setNrChestionar(int value)
    {
        this.nrChestionar = value;
    }
    public int getNrIntrebariGresite()
    {
        return this.nrIntrebariGresite;
    }
    public void setNrIntrebariGresite(int value)
    {
        this.nrIntrebariGresite = value;
    }
    public int getNrIntrebariCorecte()
    {
        return this.nrIntrebariCorecte;
    }
    public void setNrIntrebariCorecte(int value)
    {
        this.nrIntrebariCorecte = value;
    }

    Intrebare searchIntrebari(int index)
    {
       if(index>0 && index<=26)
       {
           return this.intrebarile.get(index);
       }
       return null;
    }
}
