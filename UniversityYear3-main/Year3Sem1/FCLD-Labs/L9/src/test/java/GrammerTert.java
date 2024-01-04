import app.Lab6.Concat;
import app.Lab6.Grammer;
import app.Lab6.GrammerFileConverter;
import org.junit.jupiter.api.Test;

import java.io.FileNotFoundException;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.*;

public class GrammerTert {
    @Test
    void initialTest() throws FileNotFoundException {
        Grammer grammar = GrammerFileConverter.read("g1.txt");
        System.out.println(grammar);
        assertNotNull(grammar);
        assertTrue(grammar.isCFG());
    }

    @Test
    void newTest() throws FileNotFoundException {
        Grammer grammar = GrammerFileConverter.read("g2.txt");
        System.out.println(grammar);
        assertNotNull(grammar);
        assertTrue(grammar.isCFG());
    }

    @Test
    void testConcatenationClass() {
        Concat a = new Concat(Set.of("A", "B", "C"));
        Concat b = new Concat(Set.of("B", "A", "C"));
        assertEquals(a, b);
    }
}
