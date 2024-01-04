import { Component, OnInit } from '@angular/core';
import {Artist} from "../people/shared/artist";
import {ArtistService} from "../people/shared/artist.service";
import {Router} from "@angular/router";
import {Location} from "@angular/common";

@Component({
  selector: 'app-filter-artist',
  templateUrl: './filter-artist.component.html',
  styleUrls: ['./filter-artist.component.css']
})
export class FilterArtistComponent implements OnInit {
  errorMessage: string;
  artists: Array<Artist>;
  selectedArtist: Artist;

  constructor(private artistService: ArtistService,
              private router: Router,
              private location: Location) { }

  ngOnInit(): void {
    this.getArtists();
  }

  getArtists(): void {
    this.artistService.getArtistWithMostSongs().subscribe(
      person => this.artists = new Array<Artist>(person),
      error => this.errorMessage = error as any
    );
  }

  goBack(): void {
    this.router.navigate(['/artists']);
  }

}
