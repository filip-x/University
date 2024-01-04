import React, {useEffect, useRef, useState} from 'react';
import {
    IonButton,
    IonInput,
    IonItem,
    IonList, IonPage,
    IonText
} from "@ionic/react";
import { Book } from '../../book/book';
import {useHistory, useParams} from "react-router";
import { getBook, updateBook} from '../../book/bookApi';

const UpdateBook = (props: any) => {
    const params: any = useParams();
    const [book, setBook] = useState(new Book());
    const bookTitle = useRef(null);
    const bookAuthorName = useRef(null);
    const bookDescription = useRef(null);
    const history = useHistory();
    useEffect(() => {
        getBook(params.id).then(r => {
            setBook(r);
        })
    }, []);
    return (
        <IonPage>
            <IonText class={"ion-text-center"}>
                <h1>Update a post</h1>
            </IonText>
            <IonList>
                <IonItem>
                    <IonInput ref={bookTitle} type={"text"} placeholder={"Post Title"} value={book.title}/>
                </IonItem>
                <IonItem>
                    <IonInput ref={bookAuthorName} type={"text"} placeholder={"Author Name"} value={book.authorName}/>
                </IonItem>
                <IonItem>
                    <IonInput ref={bookDescription} type={"text"} placeholder={"Description"} value={book.description}/>
                </IonItem>
            </IonList>
            <br/>
            <IonButton expand={"block"} color={"dark"} onClick={() => handleClick(book, bookTitle, bookAuthorName, bookDescription, history)}>
                Update
            </IonButton>
        </IonPage>
    );
}

const handleClick = (book: Book, bookTitle: any, bookAuthorName: any, bookDescription: any, history: any) => {
    book.description = bookDescription.current.value;
    book.title = bookTitle.current.value;
    book.authorName = bookAuthorName.current.value;
    updateBook(book);
    history.push("/")
}
export default UpdateBook;