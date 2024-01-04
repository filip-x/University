package app;

import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Objects;

@Data
public class AcceptedToken {

    private String typeOfToken;
    private String valueOfDataType;

    public AcceptedToken(String type, String value) {
        this.typeOfToken = type;
        this.valueOfDataType = value;

    }
    public AcceptedToken(String type, Character value) {
        this.typeOfToken = type;
        this.valueOfDataType = value.toString();
    }
    public AcceptedToken(String type, Integer value) {
        this.typeOfToken = type;
        this.valueOfDataType = value.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        AcceptedToken token = (AcceptedToken) o;
        return Objects.equals(getTypeOfToken(), token.getTypeOfToken()) && Objects.equals(getValueOfDataType(), token.getValueOfDataType());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getTypeOfToken(), getValueOfDataType());
    }
}
