import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SortSongsComponent } from './sort-songs.component';

describe('SortSongsComponent', () => {
  let component: SortSongsComponent;
  let fixture: ComponentFixture<SortSongsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SortSongsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SortSongsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
