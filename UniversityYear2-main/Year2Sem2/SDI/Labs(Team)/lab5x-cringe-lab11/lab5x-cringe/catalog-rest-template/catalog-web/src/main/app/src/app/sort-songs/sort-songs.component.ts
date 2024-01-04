import { Component, OnInit } from '@angular/core';
import {Artist} from "../people/shared/artist";
import {ArtistService} from "../people/shared/artist.service";
import {Router} from "@angular/router";
import {Location} from "@angular/common";
import {Song} from "../shared-song/song";
import {SongService} from "../shared-song/song.service";

@Component({
  selector: 'app-sort-songs',
  templateUrl: './sort-songs.component.html',
  styleUrls: ['./sort-songs.component.css']
})
export class SortSongsComponent implements OnInit {
  errorMessage: string;
  songs: Array<Song>;
  selectedSong: Song;

  constructor(public songService: SongService,
              private router: Router,
              private location: Location) { }

  ngOnInit(): void {
  }

  goBack(): void {
    this.router.navigate(['']);
  }
}
