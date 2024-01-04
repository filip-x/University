import {NgModule} from '@angular/core';
import {RouterModule, Routes} from '@angular/router';
import {ArtistsComponent} from './people/artists.component';
import {ArtistDetailComponent} from './people/artist-detail/artist-detail.component';
import {MainMenuComponent} from './main-menu/main-menu.component';
import {ArtistListComponent} from './people/artist-list/artist-list.component';
import {ArtistAddComponent} from './people/artist-add/artist-add.component';
import {ArtistUpdateComponent} from './people/artist-update/artist-update.component';
import {FilterArtistComponent} from "./filter-artist/filter-artist.component";
import {SortSongsComponent} from "./sort-songs/sort-songs.component";


const routes: Routes = [
  // { path: '', redirectTo: '/home', pathMatch: 'full' },
  {path: 'artists', component: ArtistsComponent},
  {path: 'artists/show', component: ArtistListComponent},
  {path: 'artists/add', component: ArtistAddComponent},
  {path: '', component: MainMenuComponent},
  {path: 'artists/detail/:id', component: ArtistDetailComponent},
  {path: 'artists/update/:id', component: ArtistUpdateComponent},
  {path: 'artists/filter', component: FilterArtistComponent},
  {path: 'songs/sort', component: SortSongsComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule {
}
