import app.Lab6.Grammer;
import app.Lab6.GrammerFileConverter;
import app.Lab7.ModelConfiguration;
import app.Lab7.ParserOutput;
import app.Lab7.RecursiveDescent;
import app.lab8.GrammarToRules;
import org.junit.jupiter.api.Test;

import java.io.FileNotFoundException;

// aici facem parsarea
public class IntegrationTest {
    @Test
    public void g1_test() throws FileNotFoundException {
        RecursiveDescent recursiveDescent = RecursiveDescent.builder().build();
        Grammer grammar = GrammerFileConverter.read("g1.txt");
        GrammarToRules r = new GrammarToRules(grammar);
        var e = r.getMainRule();
        recursiveDescent.setInputText("0011");
        recursiveDescent.setInitialInput(e);
        ModelConfiguration result = recursiveDescent.run();
        System.out.println(ParserOutput.build(result.getWorkingStack()));
    }
}
