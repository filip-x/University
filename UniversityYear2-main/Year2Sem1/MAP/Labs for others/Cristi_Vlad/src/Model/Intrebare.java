package Model;

import java.util.List;

public class Intrebare {
    String intrebare;
    List<String> raspunsuri;
    List<String> raspunsuriCorecte;

    public Intrebare(String intrebare ,List<String> raspunsuri, List<String> raspunsuriCorecte)
    {
        this.intrebare = intrebare;
        this.raspunsuri = raspunsuri;
        this.raspunsuriCorecte = raspunsuriCorecte;

    }

    public String getIntrebare()
    {
        return this.intrebare;
    }
    public List<String> getRaspunsuri()
    {
        return this.raspunsuri;
    }
    public List<String> getRaspunsuriCorecte()
    {
        return this.raspunsuriCorecte;
    }
}
