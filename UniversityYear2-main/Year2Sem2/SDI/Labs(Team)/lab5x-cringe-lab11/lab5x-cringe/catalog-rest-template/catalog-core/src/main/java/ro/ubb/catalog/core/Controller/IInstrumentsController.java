package ro.ubb.catalog.core.Controller;

import ro.ubb.catalog.core.Entities.Instrument;

public interface IInstrumentsController {
    Instrument addInstrument(int id,String name ) throws Exception;
    Instrument updateInstrument(int id,String name)throws  Exception;
    void removeInstrument(int id);
    Iterable<Instrument>getAllInstruments() throws Exception;
}
