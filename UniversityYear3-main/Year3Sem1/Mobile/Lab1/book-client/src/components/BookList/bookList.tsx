import React, {useEffect, useState} from 'react';
import styles from './CardList.module.css';
import {Book} from "../../book/book";
import {IonInfiniteScroll, IonInfiniteScrollContent} from "@ionic/react";
import {AxiosResponse} from "axios";
import ShowBook from '../ShowBook/showBook';
import { getAllBooks } from '../../book/bookApi';
import { setupSocket } from '../../book/socket';
const axios = require('axios').default;
// nu ii eficent
//zapacesc server-ul - mai bine un pop up sau un mesaj 

const BookList = () =>{
    const [bookList,setBookList]  = useState([]);
    //use efect executa dupa ce se rendeaza
    useEffect( () =>{
        getAllBooks().then((bookList) =>{
            setBookList(bookList.map((r:any, index:number)=> <ShowBook key={index} book={r}/>))
        });
        setupSocket(() =>{
            getAllBooks().then((bookList)=>{
                setBookList(bookList.map((r:any, index:number)=><ShowBook key={index} book={r}/> ))
                console.log(bookList);
                
            });
        })
    },[]);
    return(
        <IonInfiniteScroll>
            <IonInfiniteScrollContent>
                {bookList}
            </IonInfiniteScrollContent>
        </IonInfiniteScroll>
    );
}
export default BookList;
