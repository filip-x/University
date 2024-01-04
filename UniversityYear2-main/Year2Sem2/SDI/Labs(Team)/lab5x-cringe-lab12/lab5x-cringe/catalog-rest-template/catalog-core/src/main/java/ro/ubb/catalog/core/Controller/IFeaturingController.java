package ro.ubb.catalog.core.Controller;

import ro.ubb.catalog.core.Entities.SongFeaturing;

public interface IFeaturingController {
    SongFeaturing addFeaturing(int songId, int artistId) throws Exception;
}
