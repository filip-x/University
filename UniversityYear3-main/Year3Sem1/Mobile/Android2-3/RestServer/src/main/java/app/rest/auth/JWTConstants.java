package app.rest.auth;

public interface JWTConstants {
    long EXPIRATION_TIME = 900_000_000L;
    String SECRET = "SECRET_KEY";
    String HEADER_STRING = "Authorization";
    String TOKEN_PREFIX = "Bearer ";
    String SIGN_UP_URL = "/signup";
    String LOGIN_URL = "/login";
}
