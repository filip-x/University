import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Observable} from 'rxjs';
import {Artist} from './artist';
import {map} from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})

@Injectable()
export class ArtistService {
  private artistsUrl = 'http://localhost:8080/api/artists';
  constructor(private httpClient: HttpClient) { }

  getArtists(): Observable<Array<Artist>> {
    return this.httpClient.get<Array<Artist>>(this.artistsUrl);
  }

  addArtist(artist: Artist): void {
    this.httpClient.post<Artist>(this.artistsUrl, artist).subscribe();
  }


  getArtist(id: number): Observable<Artist> {
    // @ts-ignore
    return this.getArtists().pipe(
      map(people => people.find(person => person.id === id))
    );
  }

  getArtistWithMostSongs(): Observable<Artist> {
    // @ts-ignore
    return this.httpClient.get<Artist>(this.artistsUrl + "/most");
  }

  deleteArtist(person: any): void {
    this.httpClient.delete<any>(this.artistsUrl + `/${person.id}`).subscribe();
  }

  updateArtist(person: Artist): void {
    this.httpClient.put<Artist>(this.artistsUrl + `/${person.id}`, person).subscribe();
  }
}
