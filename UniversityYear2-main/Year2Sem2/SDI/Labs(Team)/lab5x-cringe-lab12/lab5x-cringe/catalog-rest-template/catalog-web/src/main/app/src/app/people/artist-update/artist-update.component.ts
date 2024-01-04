import { Component, OnInit } from '@angular/core';
import {switchMap} from 'rxjs/operators';
import {ActivatedRoute, Params, Router} from '@angular/router';
import {Artist} from '../shared/artist';
import {ArtistService} from '../shared/artist.service';
import {Location} from '@angular/common';
import {AbstractControl, FormControl, FormGroup, Validators} from '@angular/forms';

@Component({
  selector: 'app-artist-update',
  templateUrl: './artist-update.component.html',
  styleUrls: ['./artist-update.component.css']
})
export class ArtistUpdateComponent implements OnInit {
  artist: Artist;
  artistId: number | undefined;
  artistForm = new FormGroup({
    artistName: new FormControl('', [Validators.required, Validators.minLength(3)])
  });

  constructor(private artistService: ArtistService,
              private route: ActivatedRoute,
              private location: Location,
              private router: Router) { }

  ngOnInit(): void {
    this.route.params
      .pipe(switchMap((params: Params) => this.artistService.getArtist(+params.id)))
      .subscribe(artist => {
        this.artistForm.patchValue({
          artistName: artist.name,
        });
        this.artistId = artist.id;
      });
  }

  update(): void {
    this.artistService.updateArtist(new Artist(this.artistId, this.artistForm.get('artistName').value));
    this.router.navigate(['/artists']);
  }

  goBack(): void {
    this.router.navigate(['/artists']);
  }

  get artistName(): AbstractControl { return this.artistForm.get('artistName'); }
}
