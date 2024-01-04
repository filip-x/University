import React from 'react';
import {IonCard, IonCardContent, IonCardHeader, IonCardSubtitle, IonCardTitle, IonHeader, IonImg, IonRouterLink} from "@ionic/react";
import {Book} from "../../book/book";

const ShowBook = (props:any) =>{
    const book: Book = props.book;
    const seeMore: boolean = props.seeMore;
    if(seeMore || seeMore == undefined){
        book.title = book.title?. substr(0,20);
    }

    return(
        <IonRouterLink routerLink={"/details/"+book.id} routerDirection={"none"}>
            <IonCard>
        <IonCardHeader>
            <IonCardTitle>{book.title}</IonCardTitle>
            <IonCardSubtitle>By {book.authorName}</IonCardSubtitle>
        </IonCardHeader>
        <IonCardContent>
            {book.description}
        </IonCardContent>
        </IonCard>
    </IonRouterLink>
    );
}

export default ShowBook;