import { useState, useEffect } from 'react'
    
export default function Quote() {
    const [quote, setQuote] = useState("");
    const [author, setAuthor] = useState("");
    
    useEffect(() => {
      fetch("http://api.quotable.io/random")
        .then((res) => res.json())
        .then (
            (quote) => {
                setQuote(quote.content);
                setAuthor(quote.author);  
            }
        )
    }, []);

    let fetchNewQuote = () => {
        fetch("http://api.quotable.io/random")
          .then(res => res.json())
          .then(
            (quote) => {
              setQuote(quote.content);  
              setAuthor(quote.author);
            }
        )
    }

    return (
        <>
        <div className="quote-container">
            <div className="border">
                <h2 className="quote">{quote}</h2>
                <p className="author">-{author}-</p>
            </div><br/>
            <button className="btn" onClick={fetchNewQuote}><p className="button-text">New Quote</p></button>
        </div>
            
        </>
    )
}
