import Navbar from '../components/navbar.jsx'
import Quotes from '../components/quotes.jsx'
import Footer from "../components/footer.jsx"

export default function Index () {
    return(
        <>
            <div>
              <Navbar />  
            </div>
            <div>
              <Quotes />  
            </div>
            <div>
                <Footer />
            </div>
        </>
    )
}