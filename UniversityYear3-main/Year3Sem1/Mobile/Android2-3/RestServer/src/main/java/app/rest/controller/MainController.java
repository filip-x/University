package app.rest.controller;

import app.rest.SocketTextHandler;
import app.rest.model.Post;
import app.rest.repository.PostRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.PageRequest;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.socket.TextMessage;

import java.security.Principal;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@CrossOrigin(originPatterns = "*")
@RestController
@RequestMapping("/posts")
public class MainController {
    PostRepository postRepository;
    SocketTextHandler socketTextHandler;

    @Autowired
    MainController(PostRepository postRepository, SocketTextHandler socketTextHandler) {
        this.postRepository = postRepository;
        this.socketTextHandler = socketTextHandler;
    }

    @RequestMapping(method = RequestMethod.POST)
    Optional<Post> addPost(@RequestBody Post post, Principal principal) {
        post.setId(null);
        post.setAuthorName(principal.getName());
        Optional<Post> newPost = Optional.ofNullable(postRepository.save(post));
        try {
            socketTextHandler.sendToUser(post.getAuthorName(), new TextMessage("[new-post]"));
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
        return newPost;
    }

    @RequestMapping(value="/search/{term}", method = RequestMethod.GET)
    List<Post> getAllPost(@PathVariable String term, Principal principal) {
        System.out.println(principal.getName());
        return postRepository.findAllByTitleContainsAndAuthorName(term, principal.getName());
    }

    @RequestMapping(method = RequestMethod.GET)
    List<Post> getAllPostSearch(Principal principal) {
        System.out.println(principal.getName());
        return postRepository.findAllByAuthorName(principal.getName());
    }

    @RequestMapping(value = "/pages/{page}", method = RequestMethod.GET)
    List<Post> getAllPostOnPage(@PathVariable Long page, Principal principal) {
        System.out.println(principal.getName());
        return postRepository.findAllByAuthorName(principal.getName(), PageRequest.of(Math.toIntExact(page), 5));
    }

    @RequestMapping(value = "/api/filter", method = RequestMethod.GET)
    List<Post> getAllFiltered(Principal principal) {
        System.out.println(principal.getName());
        return postRepository.findAllByAuthorName(principal.getName()).stream().filter((Post p) -> p.getTitle().equals(p.getDescription())).collect(Collectors.toList());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    Optional<Post> getOnePost(@PathVariable Long id) {
        return postRepository.findById(id);
    }

    @RequestMapping(value="/{id}",method = RequestMethod.DELETE)
    void deletePost(@PathVariable Long id){
        if (postRepository.findById(id).isPresent()) {
            try {
                socketTextHandler.sendToUser(postRepository.findById(id).get().getAuthorName(), new TextMessage("[delete-post]"));
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
        postRepository.deleteById(id);
    }

    @RequestMapping(method = RequestMethod.PUT)
    Optional<Post> updatePost(@RequestBody Post post) {
        if (post != null) {
            if (postRepository.findById(post.getId()).isPresent()) {
                post.setAuthorName(postRepository.findById(post.getId()).get().getAuthorName());
                try {
                    socketTextHandler.sendToUser(postRepository.findById(post.getId()).get().getAuthorName(), new TextMessage("[update-post]"));
                } catch (RuntimeException e) {
                    System.out.println(e.getMessage());
                }

            }
            return Optional.of(postRepository.save(post));
        }
        return Optional.empty();
    }
}
