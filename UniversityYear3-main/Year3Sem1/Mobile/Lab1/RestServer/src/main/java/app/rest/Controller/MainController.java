package app.rest.Controller;


import app.rest.SocketTexthandler;
import app.rest.model.Book;
import app.rest.repository.BookRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.socket.TextMessage;

import java.util.List;
import java.util.Optional;

@CrossOrigin(originPatterns = "*")
@RestController
@RequestMapping("/books")
public class MainController {
    BookRepository bookRepository;
    SocketTexthandler socketTexthandler;
    @Autowired

    MainController(BookRepository bookRepository, SocketTexthandler socketTexthandler){
        this.bookRepository = bookRepository;
        this.socketTexthandler = socketTexthandler;
    }


    @RequestMapping(method = RequestMethod.POST)
    Book addBook(@RequestBody Book book){
        book.setId(null);
        Book newBook = bookRepository.save(book);
        socketTexthandler.sendToAll(new TextMessage("new-book"));
        return newBook;
    }

    @RequestMapping(method = RequestMethod.GET)
    List<Book> getAllBook(){
        return bookRepository.findAll();
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    Optional<Book> getOneBook(@PathVariable Long id) {
        return bookRepository.findById(id);
    }

    @RequestMapping(value="/{id}",method = RequestMethod.DELETE)

    void deletePost(@PathVariable Long id){
        socketTexthandler.sendToAll(new TextMessage("delete-book"));
        bookRepository.deleteById(id);
    }

    @RequestMapping(method = RequestMethod.PUT)
    Optional<Book> updateBook(@RequestBody Book post) {
        if (post != null) {
            socketTexthandler.sendToAll(new TextMessage("update-book"));
            return Optional.of(bookRepository.save(post));
        }
        return Optional.empty();
    }
    }
