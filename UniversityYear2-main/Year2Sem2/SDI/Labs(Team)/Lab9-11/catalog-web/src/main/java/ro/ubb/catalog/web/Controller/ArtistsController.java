package ro.ubb.catalog.web.Controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ro.ubb.catalog.core.Controller.Controller;
import ro.ubb.catalog.core.Controller.IArtistsController;
import ro.ubb.catalog.core.Controller.IController;
import ro.ubb.catalog.core.Entities.Artist;
import ro.ubb.catalog.core.Entities.Song;
import ro.ubb.catalog.web.Converter.ArtistConverter;
import ro.ubb.catalog.web.Converter.SongConverter;
import ro.ubb.catalog.web.DTOs.ArtistDto;
import ro.ubb.catalog.web.DTOs.SetDto;
import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Collection;
import java.util.Set;

@RestController
public class ArtistsController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    private IController controller;

    @Autowired
    private ArtistConverter artistConverter;

    @RequestMapping(value = "/artists", method = RequestMethod.POST)
    ArtistDto addArtist(@RequestBody ArtistDto artistDto) throws Exception {
        var artist = artistConverter.convertDtoToModel(artistDto);

        var result = controller.addArtist(artist.getId(), artist.getName());

        var resultModel = artistConverter.convertModelToDto(result);

        // TODO: Log result model
        return resultModel;
    }

    @RequestMapping(value = "/artists/{id}", method = RequestMethod.PUT)
    public ArtistDto updateArtist(@PathVariable Integer id,
                                @RequestBody ArtistDto dto) throws Exception {
        var artist = artistConverter.convertDtoToModel(dto);
        return
                artistConverter.convertModelToDto(
                        controller.updateArtist(
                                id, artist.getName()
                        ));
    }

    @RequestMapping(value = "/artists/{id}", method = RequestMethod.DELETE)
    ResponseEntity<?> deleteArtist(@PathVariable Integer id) {
        controller.removeArtist(id);
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @RequestMapping(value = "/artists")
    public SetDto<Integer, ArtistDto> getAllArtists() throws Exception {
        return new SetDto<>(
                artistConverter.convertModelsToDtos(
                        (Collection<Artist>) controller.getAllArtists()
                )
        );
    }
}
