import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { ArtistsComponent } from './people/artists.component';
import { ArtistDetailComponent } from './people/artist-detail/artist-detail.component';
import {FormsModule, ReactiveFormsModule} from '@angular/forms';
import { ArtistListComponent } from './people/artist-list/artist-list.component';
import {AppRoutingModule} from './app-routing.module';
import {ArtistService} from './people/shared/artist.service';
import {HttpClientModule} from '@angular/common/http';
import { MainMenuComponent } from './main-menu/main-menu.component';
import { ArtistAddComponent } from './people/artist-add/artist-add.component';
import { ArtistUpdateComponent } from './people/artist-update/artist-update.component';
import {RouterModule} from "@angular/router";
import { SongArtistAddComponent } from './M-M_Song-Artist/song-artist-add/song-artist-add.component';
import { SongArtistRemoveComponent } from './M-M_Song-Artist/song-artist-remove/song-artist-remove.component';
import { SongArtistListComponent } from './M-M_Song-Artist/song-artist-list/song-artist-list.component';
import { FilterArtistComponent } from './filter-artist/filter-artist.component';
import { SortSongsComponent } from './sort-songs/sort-songs.component';
import {SongService} from "./shared-song/song.service";
import { SelectInstrumentComponent } from './people/select-instrument/select-instrument.component';

@NgModule({
  declarations: [
    AppComponent,
    ArtistsComponent,
    ArtistDetailComponent,
    ArtistListComponent,
    MainMenuComponent,
    ArtistAddComponent,
    ArtistUpdateComponent,
    SongArtistAddComponent,
    SongArtistRemoveComponent,
    SongArtistListComponent,
    FilterArtistComponent,
    SortSongsComponent,
    SelectInstrumentComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    AppRoutingModule,
    ReactiveFormsModule,
    RouterModule
  ],
  providers: [ArtistService, SongService],
  bootstrap: [AppComponent]
})
export class AppModule { }
