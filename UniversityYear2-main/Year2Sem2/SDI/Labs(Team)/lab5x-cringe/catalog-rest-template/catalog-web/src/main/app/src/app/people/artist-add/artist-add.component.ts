import { Component, OnInit } from '@angular/core';
import {Artist} from '../shared/artist';
import {ArtistService} from '../shared/artist.service';
import {ActivatedRoute, Router} from '@angular/router';
import {Location} from '@angular/common';
import {map} from 'rxjs/operators';

@Component({
  selector: 'app-person-add',
  templateUrl: './artist-add.component.html',
  styleUrls: ['./artist-add.component.css']
})
export class ArtistAddComponent implements OnInit {
  model: Artist;

  constructor(private artistService: ArtistService,
              private route: ActivatedRoute,
              private location: Location,
              private router: Router) {
    this.model = new Artist();
  }

  ngOnInit(): void {
  }

  goBack(): void {
    this.router.navigate(['/artists']);
  }

  add(): void {
    this.artistService.addArtist(this.model);
    this.router.navigate(['/artists']);
  }
}
