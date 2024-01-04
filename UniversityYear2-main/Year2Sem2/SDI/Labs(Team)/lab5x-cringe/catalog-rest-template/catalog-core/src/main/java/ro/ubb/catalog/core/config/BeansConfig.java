package ro.ubb.catalog.core.config;

import org.springframework.context.annotation.*;
import ro.ubb.catalog.core.Controller.Controller;
import ro.ubb.catalog.core.Controller.IController;

@Configuration
public class BeansConfig {
    @Bean
    IController controller() {
        return new Controller();
    }
}