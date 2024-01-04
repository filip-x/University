import { Component, OnInit } from '@angular/core';
import {ArtistService} from './shared/artist.service';
import {ActivatedRoute, Router} from '@angular/router';
import {Location} from '@angular/common';

@Component({
  selector: 'app-people',
  templateUrl: './artists.component.html',
  styleUrls: ['./artists.component.css']
})
export class ArtistsComponent implements OnInit {

  constructor(private personService: ArtistService,
              private route: ActivatedRoute,
              private location: Location,
              private router: Router) { }

  ngOnInit(): void {
  }

  goBack(): void {
    this.router.navigate(['/']);
  }
}
