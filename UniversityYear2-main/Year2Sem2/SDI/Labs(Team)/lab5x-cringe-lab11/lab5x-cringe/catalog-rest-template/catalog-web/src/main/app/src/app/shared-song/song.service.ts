import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Observable} from 'rxjs';
import {Song} from './song';
import {map} from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})

@Injectable()
export class SongService {
  private songsUrl = 'http://localhost:8080/api/songs';
  constructor(private httpClient: HttpClient) { this.getSortedSongs(); }

  public sortedSong: Song[];
  getSongs(): Observable<Array<Song>> {
    return this.httpClient.get<Array<Song>>(this.songsUrl);
  }

  getSortedSongs(): void {
    this.getSongs().subscribe(songs => {
      this.sortedSong = songs;
      console.log(songs);
      this.sortedSong.sort((a, b) => a.name.localeCompare(b.name));
    });
  }

  getSong(id: number): Observable<Song> {
    // @ts-ignore
    return this.getSongs().pipe(
      map(people => people.find(person => person.id === id))
    );
  }
}
