import React, { useRef } from "react";
import {
    IonButton,
    IonCard,
    IonCardTitle,
    IonContent,
    IonHeader,
    IonInput,
    IonItem,
    IonList,
    IonText,
    IonTitle,
    IonRouterLink,
    IonPage
} from "@ionic/react";

import { Book } from "../../book/book";
import axios from "axios";
import { useHistory } from "react-router";
import { addBook } from "../../book/bookApi";

const AddBook = () => {
    const bookTitle = useRef(null);
    const bookAuthorName = useRef(null);
    const bookDescription = useRef(null);
    const history = useHistory();
    return (
        <IonPage>
            <IonText class={"ion-text-center"}>
                <h1>Add a new post</h1>
            </IonText>
            <IonList>
                <IonItem>
                    <IonInput ref={bookTitle} type={"text"} placeholder={"Book Title"} />
                </IonItem>
                <IonItem>
                    <IonInput ref={bookAuthorName} type={"text"} placeholder={"Author Name"} />
                </IonItem>
                <IonItem>
                    <IonInput ref={bookDescription} type={"text"} placeholder={"Description"} />
                </IonItem>
            </IonList>
            <br />
            <IonButton expand={"block"} color={"dark"} onClick={() => handleClick(bookTitle, bookAuthorName, bookDescription, history)}>
                    Add
            </IonButton>
            
        </IonPage>
    );
}

const handleClick = (bookTitle: any, bookAuthorName: any, bookDescription: any, history: any) => {
    let book: Book = new Book();
    book.title = bookTitle.current.value;
    book.authorName = bookAuthorName.current.value;
    book.description = bookDescription.current.value;
    // axios.post("http://localhost:8080/books",book)// for request to the server
    addBook(book)
    console.log(book);
    history.push("/");
}
export default AddBook;