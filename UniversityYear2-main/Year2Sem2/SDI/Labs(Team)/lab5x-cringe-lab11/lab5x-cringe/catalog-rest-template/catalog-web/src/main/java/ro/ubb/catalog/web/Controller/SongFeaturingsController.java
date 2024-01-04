package ro.ubb.catalog.web.Controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import ro.ubb.catalog.core.Controller.Controller;
import ro.ubb.catalog.core.Controller.IController;
import ro.ubb.catalog.core.Entities.Song;
import ro.ubb.catalog.web.Converter.SongConverter;
import ro.ubb.catalog.web.Converter.SongFeaturingConverter;
import ro.ubb.catalog.web.DTOs.SetDto;
import ro.ubb.catalog.web.DTOs.SongDto;
import ro.ubb.catalog.web.DTOs.SongFeaturingDto;

import java.util.Collection;

@RestController
public class SongFeaturingsController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    private IController controller;

    @Autowired
    private SongFeaturingConverter featuringConverter;

    @RequestMapping(value = "/featurings", method = RequestMethod.POST)
    SongFeaturingDto addSongFeaturing(@RequestBody SongFeaturingDto featuringDto) throws Exception {
        // TODO: Log parameters
        var songfeaturing = featuringConverter.convertDtoToModel(featuringDto);

        var result = controller.addFeaturing(songfeaturing.getSong().getId(), songfeaturing.getArtist().getId());

        var resultModel = featuringConverter.convertModelToDto(result);

        // TODO: Log result model
        return resultModel;
    }
}
