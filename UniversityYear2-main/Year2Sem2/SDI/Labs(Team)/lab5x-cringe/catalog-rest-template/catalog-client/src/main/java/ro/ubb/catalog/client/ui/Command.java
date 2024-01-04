package ro.ubb.catalog.client.ui;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;

/**
 * Base class for storing a command
 */

@Component
public abstract class Command {
    protected RestTemplate restTemplate = new RestTemplate();

    protected String key;
    protected String description;
    protected String url;

    public Command(String key, String descr, String url){ // TODO: refactor the URL out of the constructor.
        this.key = key;
        this.description = descr;
        this.url = url;
    }

    public abstract void execute() throws Exception;

    public String getKey() {
        return key;
    }

    public String getDescription() {
        return description;
    }
}
