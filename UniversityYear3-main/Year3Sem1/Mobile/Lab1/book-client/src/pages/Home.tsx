import {IonButton ,IonContent, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import ExploreContainer from '../components/ExploreContainer';
import './Home.css';
import React from "react";

const Home: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle class={"ion-text-center"}>BookShelf</IonTitle>
          <IonButton color={"dark"} slot={"end"} routerLink={"/new"} routerDirection={"none"}>
                Add Book
            </IonButton>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <ExploreContainer />
      </IonContent>
    </IonPage>
  );
};

export default Home;
