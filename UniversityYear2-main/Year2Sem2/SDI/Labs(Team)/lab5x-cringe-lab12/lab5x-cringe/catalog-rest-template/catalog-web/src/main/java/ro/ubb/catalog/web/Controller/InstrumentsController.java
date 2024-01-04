package ro.ubb.catalog.web.Controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ro.ubb.catalog.core.Controller.Controller;
import ro.ubb.catalog.core.Controller.IController;
import ro.ubb.catalog.core.Entities.Instrument;
import ro.ubb.catalog.web.Converter.InstrumentConverter;
import ro.ubb.catalog.web.DTOs.InstrumentDto;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

@RestController
public class InstrumentsController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    private IController controller;

    @Autowired
    private InstrumentConverter instrumentConverter;

    @RequestMapping(value = "/instruments", method = RequestMethod.POST)
    InstrumentDto addInstrument(@RequestBody InstrumentDto instrumentDto) throws Exception {
        var instrument = instrumentConverter.convertDtoToModel(instrumentDto);

        var result = controller.addInstrument(instrument.getId(), instrument.getName());

        var resultModel = instrumentConverter.convertModelToDto(result);

        // TODO: Log result model
        return resultModel;
    }

    @RequestMapping(value = "/instruments/{id}", method = RequestMethod.PUT)
    public InstrumentDto updateInstrument(@PathVariable Integer id,
                                  @RequestBody InstrumentDto dto) throws Exception {
        var instrument = instrumentConverter.convertDtoToModel(dto);
        return
                instrumentConverter.convertModelToDto(
                        controller.updateInstrument(
                                id, instrument.getName()
                        ));
    }

    @RequestMapping(value = "/instruments/{id}", method = RequestMethod.DELETE)
    ResponseEntity<?> deleteInstrument(@PathVariable Integer id) {
        controller.removeInstrument(id);
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @RequestMapping(value = "/instruments")
    public List<InstrumentDto> getAllInstruments() throws Exception {
        return new ArrayList<>(instrumentConverter.convertModelsToDtos(
                (Collection<Instrument>) controller.getAllInstruments()
        ));
    }
}
