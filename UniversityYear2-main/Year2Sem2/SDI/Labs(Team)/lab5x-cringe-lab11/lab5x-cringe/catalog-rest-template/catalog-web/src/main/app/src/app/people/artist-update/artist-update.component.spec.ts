import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ArtistUpdateComponent } from './artist-update.component';

describe('PersonUpdateComponent', () => {
  let component: ArtistUpdateComponent;
  let fixture: ComponentFixture<ArtistUpdateComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ArtistUpdateComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(ArtistUpdateComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
