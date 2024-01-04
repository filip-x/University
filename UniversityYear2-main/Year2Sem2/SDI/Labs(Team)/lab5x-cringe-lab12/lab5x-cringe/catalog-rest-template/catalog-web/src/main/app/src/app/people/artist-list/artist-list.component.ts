import { Component, OnInit } from '@angular/core';
import {ArtistService} from '../shared/artist.service';
import {Router} from '@angular/router';
import {Artist} from '../shared/artist';
import {Location} from '@angular/common';

@Component({
  selector: 'app-artist-list',
  templateUrl: './artist-list.component.html',
  styleUrls: ['./artist-list.component.css']
})

export class ArtistListComponent implements OnInit {
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
    this.artistService.getArtists().subscribe(
      people => this.artists = people,
      error => this.errorMessage = error as any
    );
  }

  onSelect(person: Artist): void {
    this.selectedArtist = person;
    this.router.navigate(['/artists/detail', this.selectedArtist.id]);
  }

  goBack(): void {
    this.router.navigate(['/artists']);
  }


}
