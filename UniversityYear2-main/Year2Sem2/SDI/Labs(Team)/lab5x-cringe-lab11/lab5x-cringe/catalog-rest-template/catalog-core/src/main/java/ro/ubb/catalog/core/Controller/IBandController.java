package ro.ubb.catalog.core.Controller;

import ro.ubb.catalog.core.Entities.Band;


public interface IBandController {
    Band addBand(int id, String name ) throws Exception;
    Band updateBand(int id,String name)throws  Exception;
    void removeBand(int id);
    Iterable<Band>getAllBands() throws Exception;
}
