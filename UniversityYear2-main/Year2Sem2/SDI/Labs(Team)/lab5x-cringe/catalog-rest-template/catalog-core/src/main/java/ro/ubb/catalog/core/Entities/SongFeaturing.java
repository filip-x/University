package ro.ubb.catalog.core.Entities;

import javax.persistence.Entity;
import java.util.HashMap;
import java.util.UUID;

@Entity
public class SongFeaturing extends BaseEntity<UUID> {
    private static UUID featuringId = UUID.randomUUID();
    private Integer songId;
    private Integer artistId;

    public SongFeaturing() {
        super(SongFeaturing.getNewFeaturingId());
        songId = 0;
        artistId = 0;
    }

    public SongFeaturing(UUID id, int songId, int artistId) {
        super(id);
        this.artistId = artistId;
        this.songId = songId;
    }

    public SongFeaturing(int songId, int artistId) {
        super(SongFeaturing.getNewFeaturingId());
        this.artistId = artistId;
        this.songId = songId;
    }

    public void setSongId(Integer value) {
        this.songId = value;
    }

    public void setArtistId(Integer value) {
        this.artistId = value;
    }

    public UUID getFeaturingId() {
        return featuringId;
    }

    public Integer getSongId() {
        return songId;
    }

    public Integer getArtistId() {
        return artistId;
    }

    public static synchronized UUID getNewFeaturingId() {
        SongFeaturing.featuringId = UUID.randomUUID();
        return SongFeaturing.featuringId;
    }

    @Override
    public HashMap<String, String> getAttributes() {
        HashMap<String, String> attributes = new HashMap<>();

        attributes.put("id", featuringId.toString());
        attributes.put("song_id", songId.toString());
        attributes.put("artist_id", artistId.toString());

        return attributes;
    }
}
