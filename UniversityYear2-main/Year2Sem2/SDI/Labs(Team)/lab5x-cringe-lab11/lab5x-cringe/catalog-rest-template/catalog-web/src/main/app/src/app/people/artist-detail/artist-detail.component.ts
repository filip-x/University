import {Component, Input, OnInit} from '@angular/core';
import {ArtistService} from '../shared/artist.service';
import {ActivatedRoute, Params, Router} from '@angular/router';
import {Artist} from '../shared/artist';
import {switchMap} from 'rxjs/operators';
import {Location} from '@angular/common';

@Component({
  selector: 'app-artist-detail',
  templateUrl: './artist-detail.component.html',
  styleUrls: ['./artist-detail.component.css']
})
export class ArtistDetailComponent implements OnInit {

  artist: Artist;
  instrumentName: string;
  constructor(private artistService: ArtistService,
              private route: ActivatedRoute,
              private location: Location,
              private router: Router) {
  }

  ngOnInit(): void {
    this.route.params
      .pipe(switchMap((params: Params) => this.artistService.getArtist(+params.id)))
      .subscribe(person => {
        this.artist = person;
        this.artistService.getArtistInstrument(this.artist.id).subscribe((instrument) => this.instrumentName = instrument.name);
      });
  }

  goBack(): void {
    this.location.back();
  }

  delete(): void {
    this.artistService.deleteArtist(this.artist);
    this.router.navigate(['/artists/show']);
  }

  update(): void {
    this.router.navigate([`/artists/update/${this.artist.id}`]);
  }

  addInstrument(): void {
    this.router.navigate([`/select-instrument/${this.artist.id}`]);
  }
}
