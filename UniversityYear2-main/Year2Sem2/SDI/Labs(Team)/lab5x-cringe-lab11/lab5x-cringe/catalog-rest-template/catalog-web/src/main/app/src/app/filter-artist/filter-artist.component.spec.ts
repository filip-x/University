import { ComponentFixture, TestBed } from '@angular/core/testing';

import { FilterArtistComponent } from './filter-artist.component';

describe('FilterArtistComponent', () => {
  let component: FilterArtistComponent;
  let fixture: ComponentFixture<FilterArtistComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ FilterArtistComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(FilterArtistComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
