package ro.ubb.catalog.web.Controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ro.ubb.catalog.core.Controller.Controller;
import ro.ubb.catalog.core.Controller.IController;
import ro.ubb.catalog.core.Entities.Band;
import ro.ubb.catalog.web.Converter.BandConverter;
import ro.ubb.catalog.web.DTOs.BandDto;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
@RestController

public class BandsController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    private IController controller;

    @Autowired
    private BandConverter bandConverter;

    @RequestMapping(value = "/bands", method = RequestMethod.POST)
    BandDto addBand(@RequestBody BandDto bandDto) throws Exception {
        var band = bandConverter.convertDtoToModel(bandDto);

        var result = controller.addBand(band.getId(), band.getName());

        var resultModel = bandConverter.convertModelToDto(result);

        // TODO: Log result model
        return resultModel;
    }

    @RequestMapping(value = "/bands/{id}", method = RequestMethod.PUT)
    public BandDto updateBand(@PathVariable Integer id,
                                  @RequestBody BandDto dto) throws Exception {
        var band = bandConverter.convertDtoToModel(dto);
        return
                bandConverter.convertModelToDto(
                        controller.updateBand(
                                id, band.getName()
                        ));
    }

    @RequestMapping(value = "/bands/{id}", method = RequestMethod.DELETE)
    ResponseEntity<?> deleteBand(@PathVariable Integer id) {
        controller.removeBand(id);
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @RequestMapping(value = "/bands")
    public List<BandDto> getAllBands() throws Exception {
        return new ArrayList<>(bandConverter.convertModelsToDtos(
                (Collection<Band>) controller.getAllBands()
        ));
    }
}
