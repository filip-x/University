import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SelectInstrumentComponent } from './select-instrument.component';

describe('SelectInstrumentComponent', () => {
  let component: SelectInstrumentComponent;
  let fixture: ComponentFixture<SelectInstrumentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SelectInstrumentComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SelectInstrumentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
