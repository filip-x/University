import React, {useEffect, useState} from 'react';
import axios, {AxiosResponse} from "axios";
import {useHistory, useParams} from "react-router";
import DisplayCard from "../ShowBook/showBook";
import {Book} from "../../book/book";
import {IonPage, IonRouterLink, IonText} from "@ionic/react";
import { deleteBook, getBook } from '../../book/bookApi';
import ShowBook from '../ShowBook/showBook';


const DetailBook = (porps:any) =>{
    const [book, setBook] = useState(<></>);
    const params: any  = useParams();
    const history = useHistory();
    console.log(params);

     useEffect(() => {
        getBook(params.id).then((r: Book) => setBook(<ShowBook truncate={false} book={r} />))
         console.log("Test");
     }, [params]);

    return(
        <IonPage style  ={{justifyCOntent: 'unset'}}>
            {book}
            <div className= "ion-text-center">
            <IonRouterLink style={{ color: 'white' }} routerLink={`/update/${params.id}`}>edit</IonRouterLink>
            <IonText  class={"ion-padding-start ion-padding-end"}>|</IonText>
            <IonText onClick={() => { deleteBook(params.id); history.push("/"); }}>delete</IonText>
            </div>
        </IonPage>

    );
}
export default DetailBook;