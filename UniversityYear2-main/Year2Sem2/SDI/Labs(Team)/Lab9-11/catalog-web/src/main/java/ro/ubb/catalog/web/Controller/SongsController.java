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
import ro.ubb.catalog.web.DTOs.SetDto;
import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Collection;

@RestController
public class SongsController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    private IController controller;

    @Autowired
    private SongConverter songsConverter;

    @RequestMapping(value = "/songs", method = RequestMethod.POST)
    SongDto addSong(@RequestBody SongDto songDto) throws Exception {
        // TODO: Log parameters
        var song = songsConverter.convertDtoToModel(songDto);

        var result = controller.addSong(song.getId(), song.getName(), song.getDuration());

        var resultModel = songsConverter.convertModelToDto(result);

        // TODO: Log result model
        return resultModel;
    }

    @RequestMapping(value = "/songs/{id}", method = RequestMethod.PUT)
    public SongDto updateSong(@PathVariable Integer id,
                           @RequestBody SongDto dto) throws Exception {
        var song = songsConverter.convertDtoToModel(dto);
        return
                songsConverter.convertModelToDto(
                        controller.updateSong(
                                id, song.getName()
                        ));

    }

    @RequestMapping(value = "/songs/{id}", method = RequestMethod.DELETE)
    ResponseEntity<?> deleteStudent(@PathVariable Integer id) {
        controller.removeSong(id);
        return new ResponseEntity<>(HttpStatus.OK);
    }

    @RequestMapping(value = "/songs")
    public SetDto<Integer, SongDto> getAllSongs() throws Exception {
        return new SetDto<>(
                songsConverter.convertModelsToDtos(
                        (Collection<Song>) controller.getAllSongs()
                )
        );
    }
}
