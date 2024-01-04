import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SongArtistAddComponent } from './song-artist-add.component';

describe('SongArtistAddComponent', () => {
  let component: SongArtistAddComponent;
  let fixture: ComponentFixture<SongArtistAddComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SongArtistAddComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SongArtistAddComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
