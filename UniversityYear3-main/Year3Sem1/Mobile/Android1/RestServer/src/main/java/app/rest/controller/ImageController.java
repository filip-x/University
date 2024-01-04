package app.rest.controller;

import app.rest.model.Image;
import app.rest.repository.ImageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.util.Base64;
import java.util.Optional;

@CrossOrigin(originPatterns = "*")
@RestController
@RequestMapping("/images")
public class ImageController {

    ImageRepository imageRepository;
    MultipartFile file;
    @Autowired
    ImageController(ImageRepository imageRepository) {
        this.imageRepository = imageRepository;
    }

    @GetMapping("/{id}")
    public ResponseEntity<byte[]> getImage(HttpServletResponse response, @PathVariable("id") Long id) {
        Optional<Image> imageOptional = imageRepository.findById(id);

        return imageOptional
                .map(image ->
                        ResponseEntity
                                .ok()
                                .contentType(MediaType.valueOf(MediaType.IMAGE_PNG_VALUE))
                                .body(Base64.getDecoder().decode(image.getBase64Image())))
                .orElseGet(() ->
                        ResponseEntity
                                .notFound()
                                .build());
    }

    @PostMapping
    public String uploadImage(@RequestParam("image") MultipartFile image) throws IOException {
        Image savedImage = imageRepository.save(Image.builder().base64Image(Base64.getEncoder().encodeToString(image.getBytes())).build());
        return "/images/" + savedImage.getId();
    }
}
