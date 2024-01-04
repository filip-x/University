import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SongArtistRemoveComponent } from './song-artist-remove.component';

describe('SongArtistRemoveComponent', () => {
  let component: SongArtistRemoveComponent;
  let fixture: ComponentFixture<SongArtistRemoveComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SongArtistRemoveComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SongArtistRemoveComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
