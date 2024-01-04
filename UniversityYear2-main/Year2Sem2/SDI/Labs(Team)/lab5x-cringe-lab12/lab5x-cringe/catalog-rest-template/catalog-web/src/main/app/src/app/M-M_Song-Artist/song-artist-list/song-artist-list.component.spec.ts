import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SongArtistListComponent } from './song-artist-list.component';

describe('SongArtistListComponent', () => {
  let component: SongArtistListComponent;
  let fixture: ComponentFixture<SongArtistListComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SongArtistListComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SongArtistListComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
