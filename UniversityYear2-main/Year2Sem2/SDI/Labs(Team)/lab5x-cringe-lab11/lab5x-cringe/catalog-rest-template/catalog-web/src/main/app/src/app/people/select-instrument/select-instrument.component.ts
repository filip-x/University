import { Component, OnInit } from '@angular/core';
import {Artist} from '../shared/artist';
import {ArtistService} from '../shared/artist.service';
import {ActivatedRoute, Params, Router} from '@angular/router';
import {Location} from '@angular/common';
import {Instrument} from '../shared/instrument';
import {switchMap} from 'rxjs/operators';

@Component({
  selector: 'app-select-instrument',
  templateUrl: './select-instrument.component.html',
  styleUrls: ['./select-instrument.component.css']
})
export class SelectInstrumentComponent implements OnInit {

  errorMessage: string;
  instruments: Array<Instrument>;
  selectedInstrument: Instrument;
  artistId: number;

  constructor(private artistService: ArtistService,
              private router: Router,
              private location: Location,
              private route: ActivatedRoute) { }

  ngOnInit(): void {
    this.artistId = Number(this.route.snapshot.paramMap.get('id'));
    // this.route.queryParams.subscribe(params => {
    //     this.artistId = params.id;
    //   });
    this.getInstruments();
  }

  getInstruments(): void {
    this.artistService.getInstruments().subscribe(
      instruments => this.instruments = instruments,
      error => this.errorMessage = error as any
    );
  }

  onSelect(instrument: Instrument): void {
    this.selectedInstrument = instrument;
    this.artistService.addInstrumentToArtist(this.artistId, instrument.id);
  }

  goBack(): void {
    this.router.navigate(['/']);
  }

}
