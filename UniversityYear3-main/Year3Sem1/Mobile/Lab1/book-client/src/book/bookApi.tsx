import { Book } from "./book";
import axios, { AxiosResponse } from "axios";
import React from "react";

const  itemUrl = 'http://localhost:8080/books';


export const getAllBooks = async () => {
    let result: AxiosResponse<any> = await axios.get(itemUrl);
    return result.data.map((r: any) =>
        Object.assign(new Book(), r)
    );
}

export const getBook = async (id: number) => {
    let result: AxiosResponse<any> = await axios.get(`${itemUrl}/${id}`);
    return Object.assign(new Book(), result.data);
}

export const deleteBook= (id: number) => {
    axios.delete(`${itemUrl}/${id}`).then(null);
}

export const addBook = (book: Book) => {
    axios.post(itemUrl, book).then(null);
}

export const updateBook = (book: Book) => {
    axios.put(itemUrl, book).then(null);
}